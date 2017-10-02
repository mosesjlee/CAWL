//
//  CAWLUniversalCombFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 9/30/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLUniversalCombFilter.hpp"

CAWLUniversalCombFilter::CAWLUniversalCombFilter()
{
    lastSampleOfBlock = 0.0;
    mFeedbackGain = 1;
    mMixLevel = 1;
    mFeedForwardGain = 0.0;
}

CAWLUniversalCombFilter::~CAWLUniversalCombFilter()
{
    
}

void CAWLUniversalCombFilter::processBuffer(float * buf, const unsigned int numSamples)
{
    float yCurrSample = 0.0;
    float xCurrSample = lastSampleOfBlock;
    float xHCurrSample = 0.0;
    float zDelayedSample = 0.0;
    for(unsigned i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i];
        xHCurrSample = xCurrSample + zDelayedSample * mFeedbackGain;
        zDelayedSample = delayLine.processNextSample(xHCurrSample);
        yCurrSample = zDelayedSample * mFeedForwardGain + xHCurrSample * mMixLevel;
        buf[i] = yCurrSample;
    }
    lastSampleOfBlock = xHCurrSample;
}
