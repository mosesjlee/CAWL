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
currReadPos(0),
currWritePos(0),
currDelayInSamples(0)
{
    delayLine = new float[(int) maxDelayInSamples];
    
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
    currDelayInSamples = delayTime * DEFAULT_SR/MILLISECONDS;
    
    //Enforce that the max delay is 1 sample less than the max delay
    if(currDelayInSamples > MAX_DELAY_IN_SAMPLES)
        currDelayInSamples = MAX_DELAY_IN_SAMPLES - 1;
    
    //Update the read and write index
    currReadPos = currWritePos - (currDelayInSamples-1);
    
    if(currReadPos < 0.0)
        currReadPos = MAX_DELAY_IN_SAMPLES - fabs(currReadPos);
}

void CAWLDelayLine::setDelayTimeInSamples(float delaySamples)
{
    currDelayInSamples = delaySamples;
    //Enforce that the max delay is 1 sample less than the max delay
    if(currDelayInSamples > MAX_DELAY_IN_SAMPLES)
        currDelayInSamples = MAX_DELAY_IN_SAMPLES - 1;
    
    //Update the read and write index
    currReadPos = currWritePos - (currDelayInSamples-1);
    
    if(currReadPos < 0.0)
        currReadPos = MAX_DELAY_IN_SAMPLES - fabs(currReadPos);
}

inline float CAWLDelayLine::linear_interp(float x_1, float y_1, float x_2, float y_2, float frac)
{
    float retval = 0.0;
    float denominator = x_1 - x_2;
    float numerator = y_1 * (x_2 - frac) + y_2 * (frac - x_1);
    //0 Check
    if(fabs(denominator - 0.0) < 1e-6)
        return 0.0;
    
    retval = numerator/denominator;
    return retval;
}

float CAWLDelayLine::processNextSample(float currSample)
{
    float yCurrOutput = 0.0;

    delayLine[(int) currWritePos] = currSample;
    
    //Get the current read position
//    currReadPos = currWritePos - currDelayInSamples;
//    if(currReadPos < 0.0)
//        currReadPos = MAX_DELAY_IN_SAMPLES - fabs(currReadPos);
    
    
    float fracDelay = currReadPos - (int) currReadPos;
    
    if(fracDelay > 0.000000)
    {
        float lookAheadPos = (currReadPos + 1.0) > maxDelayInSamples ? 0 : (currReadPos + 1.0);
        yCurrOutput = linear_interp(delayLine[(int) currReadPos],
                                    currReadPos,
                                    delayLine[(int) lookAheadPos],
                                    lookAheadPos,
                                    fracDelay);
    }
    else
        yCurrOutput = delayLine[(int) currReadPos];
    
    currReadPos = (currReadPos + 1.0) >= maxDelayInSamples ?  (0 + fracDelay) : (currReadPos + 1.0);
    currWritePos = (currWritePos + 1.0) >= maxDelayInSamples ? 0 : (currWritePos + 1.0);
    return yCurrOutput;
}



