//
//  CAWLFIRCombFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLFIRCombFilter.hpp"
CAWLFIRCombFilter::CAWLFIRCombFilter()
{
    mFeedForwardGain = 1.0;
    lastSampleOfBlock = 0.0;
    delayLine = new CAWLDelayLine();
    delayLine->setDelayTimeInMilliseconds(0);
}

CAWLFIRCombFilter::~CAWLFIRCombFilter()
{
    
}

void CAWLFIRCombFilter::processBuffer(float * buf, const unsigned int numSamples)
{
    float yCurrSample = lastSampleOfBlock;
    for(unsigned int i = 0; i < numSamples; i++)
    {
        float xCurrSample = buf[i];
        float zCurrSample = delayLine->processNextSample(xCurrSample);
        yCurrSample = zCurrSample * mFeedForwardGain + xCurrSample;
        buf[i] = yCurrSample;
    }
    lastSampleOfBlock = yCurrSample;
}
    

