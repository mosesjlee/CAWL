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
    delayHsu = new DelayLine(MAX_DELAY_IN_SAMPLES);
    delayLine = new CAWLDelayLine();
}

CAWLUniversalCombFilter::~CAWLUniversalCombFilter()
{
    delete delayLine;
}

void CAWLUniversalCombFilter::processBuffer(float * buf, const unsigned int numSamples)
{
    double yCurrSample = 0.0;
    double xCurrSample = 0.0;
    double xHCurrSample = lastSampleOfBlock;
    double zDelayedSample = 0.0;
    for(unsigned i = 0; i < numSamples; i++)
    {
//		if(debugCounter == 1122)
//			printf("STOP\n");
        xCurrSample = buf[i];
        //zDelayedSample = delayHsu->tick(xHCurrSample);;
        zDelayedSample = delayLine->processNextSample(xHCurrSample);
		xHCurrSample = xCurrSample + zDelayedSample * mFeedbackGain;
        yCurrSample = zDelayedSample * mFeedForwardGain + xHCurrSample * mMixLevel;
        buf[i] = yCurrSample + xCurrSample * dryMix;
		debugCounter++;
    }
	
    lastSampleOfBlock = xHCurrSample;
}

void CAWLUniversalCombFilter::setDryMix(double newDryMix)
{
    if(newDryMix > 1.0) dryMix = 1.0;
    else if(newDryMix < 0.0) dryMix = 0.0;
    else dryMix = newDryMix;
}



