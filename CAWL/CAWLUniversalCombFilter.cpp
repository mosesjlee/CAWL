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
    double yCurrSample = 0.0;
    double xCurrSample = 0.0;
    double xHCurrSample = lastSampleOfBlock;
    double zDelayedSample = 0.0;
    for(unsigned i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i];
        zDelayedSample = delayLine.processNextSample(xHCurrSample);
		xHCurrSample = xCurrSample + zDelayedSample * mFeedbackGain;
        yCurrSample = zDelayedSample * mFeedForwardGain + xHCurrSample * mMixLevel;
        buf[i] = yCurrSample;
    }
	
    lastSampleOfBlock = xHCurrSample;
}
