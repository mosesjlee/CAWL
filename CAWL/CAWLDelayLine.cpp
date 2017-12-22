//
//  CAWLDelayLine.cpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLDelayLine.hpp"

#include <math.h>

/*
    Constructor. Set it to all default values
 */
CAWLDelayLine::CAWLDelayLine()
{
    //Set Default values
    cMaxDelayInSamples = MAX_DELAY_IN_SAMPLES;
    cCurrWritePos = 0;
    cCurrDelayInSamples = 0;
    
    //Allocate buffer
    cDelayLine = new double[(int) cMaxDelayInSamples];
    
    //0 out the buffer
    for(int i = 0; i < cMaxDelayInSamples; i++)
        cDelayLine[i] = 0.0;
}

/*
 Destructor
 */
CAWLDelayLine::~CAWLDelayLine()
{
    delete [] cDelayLine;
}

/*
 Sets the delay time by taking in time in milliseconds and converting it to
 samples.
 @param delayTime -> delay time in milliseconds
 */
void CAWLDelayLine::setDelayTimeInMilliseconds(float delayTime)
{
    //Input is in milliseconds so convert that to samples
    setDelayTimeInSamples(delayTime * DEFAULT_SR/MILLISECONDS);
}

/*
 Sets the delay time in samples
 @param delaySamples -> delay time in number of samples
 */
void CAWLDelayLine::setDelayTimeInSamples(float delaySamples)
{
    cCurrDelayInSamples = delaySamples;
	
    //Enforce that the max delay is 1 sample less than the max delay
    if(cCurrDelayInSamples > MAX_DELAY_IN_SAMPLES)
        cCurrDelayInSamples = MAX_DELAY_IN_SAMPLES - 1;
}
/*
 Linear inerpolation
 @param x1   -> First x coordinate in this case time
 @param y1   -> First y coordinate in this came amplitude
 @param x2   -> Second x coordinate in this case time
 @param y2   -> Second y coordinate in this case amplitude
 @param frac -> The fractional time in between the first and second time stamp
 */
inline double CAWLDelayLine::linearInterp(float x1, float y1, float x2, float y2, float frac)
{
    return y1 * (x2 - frac) + y2 * (frac - x1);
}

/*
 Takes in the current sample that will be stored and returns the
 next sample from the delay line to be outputted
 @param  currSample -> the sample to be stored
 @return the delayed sample at delay cCurrDelayInSamples
 */
double CAWLDelayLine::processNextSample(double currSample)
{
    double yCurrOutput = 0.0;

    cDelayLine[(int) cCurrWritePos] = currSample;
	
    //Get the current read position
	double currReadPos = cCurrWritePos - (cCurrDelayInSamples);
    if(currReadPos < 0.0)
        currReadPos = currReadPos + (double) (MAX_DELAY_IN_SAMPLES);
    
    //Check if there is a fractional delay
    double fracDelay = currReadPos - (int) currReadPos;
    
    //Get the next sample and the next sample for linear interpolation
    double lookAheadPos = (int)(currReadPos + 1.0) % (int) (cMaxDelayInSamples+1);
    double x1 = (int) currReadPos;
    double y1 = cDelayLine[(int) currReadPos];
    double x2 = (int) (lookAheadPos);
	double y2 = lookAheadPos >= cMaxDelayInSamples ? cDelayLine[0] : cDelayLine[(int) lookAheadPos];

    //Linear interpolate
    if(lookAheadPos < currReadPos)
    {
        yCurrOutput = linearInterp(0, y1, x2, y2, fracDelay);
    }
    else
    {
        yCurrOutput = linearInterp(x1, y1, x2, y2, currReadPos);
    }

    //Update write index
	cCurrWritePos = (int) (cCurrWritePos + 1.0) % (int) (MAX_DELAY_IN_SAMPLES);
    
    //Return the output
    if(yCurrOutput > 1.0) yCurrOutput = 1.0;
    if(yCurrOutput < -1.0) yCurrOutput = -1.0;
    return yCurrOutput;
}



