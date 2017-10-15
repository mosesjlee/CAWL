//
//  CAWLDelayLine.cpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLDelayLine.hpp"

#include <math.h>

#define MAX_DELAY_IN_SAMPLES 44100.0f * 2

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
    //delete [] delayLine;
}

void CAWLDelayLine::setDelayTimeInMilliseconds(float delayTime)
{
    //Input is in milliseconds so convert that to samples
    setDelayTimeInSamples(delayTime * DEFAULT_SR/MILLISECONDS);
}

void CAWLDelayLine::setDelayTimeInSamples(float delaySamples)
{
    currDelayInSamples = delaySamples;
    //Enforce that the max delay is 1 sample less than the max delay
    if(currDelayInSamples > MAX_DELAY_IN_SAMPLES)
        currDelayInSamples = MAX_DELAY_IN_SAMPLES - 1;
}

inline double CAWLDelayLine::linear_interp(float x_1, float y_1, float x_2, float y_2, float frac)
{
    double retval = 0.0;
    double denominator = x_2 - x_1;
    double numerator = y_1 * (x_2 - frac) + y_2 * (frac - x_1);
    //0 Check
    if(fabs(denominator - 0.0) < 1e-6)
        return 0.0;
    
    retval = numerator/denominator;
    return retval;
}

double CAWLDelayLine::processNextSample(double currSample)
{
    double yCurrOutput = 0.0;

    delayLine[(int) currWritePos] = currSample;
    
    //Get the current read position
    float currReadPos = currWritePos - (currDelayInSamples - 1.0);
    if(currReadPos < 0.0)
        currReadPos = MAX_DELAY_IN_SAMPLES - fabs(currReadPos);
    
    //Check if there is a fractional delay
    float fracDelay = currReadPos - (int) currReadPos;
    
    if(fracDelay > 0.00000000)
    {
        float lookAheadPos = (currReadPos + 1.0) > maxDelayInSamples ? 0 + fracDelay : currReadPos + 1.0;
        yCurrOutput = linear_interp((int) currReadPos,
                                    delayLine[(int) currReadPos],
                                    lookAheadPos,
                                    delayLine[(int) lookAheadPos],
                                    currReadPos + fracDelay);
    }
    else
        yCurrOutput = delayLine[(int) currReadPos];
    
    //Update the write position
    currWritePos = (currWritePos + 1.0) >= maxDelayInSamples ? 0 : (currWritePos + 1.0);
    
    //Return the output
    return yCurrOutput;
}



