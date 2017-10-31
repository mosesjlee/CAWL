//
//  CAWLDelayLine.cpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLDelayLine.hpp"

#include <math.h>



CAWLDelayLine::CAWLDelayLine():
maxDelayInSamples(MAX_DELAY_IN_SAMPLES),
currWritePos(0),
currDelayInSamples(0)
{
    //Allocate buffer
    delayLine = new double[(int) maxDelayInSamples];
    
    //0 out the buffer
    for(int i = 0; i < maxDelayInSamples; i++)
        delayLine[i] = 0.0;
}


CAWLDelayLine::~CAWLDelayLine()
{
    delete [] delayLine;
}

void CAWLDelayLine::setDelayTimeInMilliseconds(float delayTime)
{
    //Input is in milliseconds so convert that to samples
    setDelayTimeInSamples(delayTime * DEFAULT_SR/MILLISECONDS);
	
	//printf("delay time: %f\n", delayTime);
}

void CAWLDelayLine::setDelayTimeInSamples(float delaySamples)
{
	//if(delaySamples < 1) currDelayInSamples = 1;
    currDelayInSamples = delaySamples;
	
    //Enforce that the max delay is 1 sample less than the max delay
    if(currDelayInSamples > MAX_DELAY_IN_SAMPLES)
        currDelayInSamples = MAX_DELAY_IN_SAMPLES - 2;
}

inline double CAWLDelayLine::linear_interp(float x_1, float y_1, float x_2, float y_2, float frac)
{
    double retval = 0.0;
    double numerator = y_1 * (x_2 - frac) + y_2 * (frac - x_1);
	
    return numerator;
}

double CAWLDelayLine::processNextSample(double currSample)
{
    double yCurrOutput = 0.0;

    delayLine[(int) currWritePos] = currSample;
	
    //Get the current read position
	double currReadPos = currWritePos - (currDelayInSamples);// - 1.0);
    if(currReadPos < 0.0)
        currReadPos = currReadPos + (double) (MAX_DELAY_IN_SAMPLES);
    
    //Check if there is a fractional delay
    double fracDelay = currReadPos - (int) currReadPos;

	
        double lookAheadPos = (int)(currReadPos + 1.0) % (int) (maxDelayInSamples+1);
        double x_1 = (int) currReadPos;
        double y_1 = delayLine[(int) currReadPos];
        double x_2 = (int) (lookAheadPos);
		double y_2 = lookAheadPos >= maxDelayInSamples ? delayLine[0] : delayLine[(int) lookAheadPos];

        if(lookAheadPos < currReadPos)
        {
            yCurrOutput = linear_interp(0,
                                        y_1,
                                        x_2,
                                        y_2,
                                        fracDelay);
        }
        else
        {
            yCurrOutput = linear_interp(x_1,
                                        y_1,
                                        x_2,
                                        y_2,
                                        currReadPos);
        }


	currWritePos = (int) (currWritePos + 1.0) % (int) (MAX_DELAY_IN_SAMPLES);
    
    //Return the output
    if(yCurrOutput > 1.0) yCurrOutput = 1.0;
    if(yCurrOutput < -1.0) yCurrOutput = -1.0;
    return yCurrOutput;
}



