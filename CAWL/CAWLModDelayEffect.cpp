//
//  CAWLModDelayEffect.cpp
//  CAWL
//
//  Created by Moses Lee on 10/28/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLModDelayEffect.hpp"

void CAWLModDelayEffect::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double zDelayedSample = 0.0;
    double xHCurrSample = cLastSampleOfBlock;
    double yCurrOutput = 0.0;
    for(int i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i];
        zDelayedSample = cDelayLine->processNextSample(xHCurrSample);
        xHCurrSample = xCurrSample + zDelayedSample * cFeedbackGain;
        yCurrOutput = zDelayedSample * cFeedForwardGain;
        buf[i] = yCurrOutput + xCurrSample * cDryMix;
        
        cDelayLine->setDelayTimeInMilliseconds(modulatedTime());
    }
    cLastSampleOfBlock = xHCurrSample;
}

void CAWLModDelayEffect::setModulationDepth(double newModDepth)
{
    modDepth = newModDepth;
    cDelayLine->setDelayTimeInMilliseconds(modDepth/2);
}

void CAWLModDelayEffect::setMixLevel(double mixLevel)
{
    cDryMix = mixLevel;
}

void CAWLModDelayEffect::setModulationSpeed(double newModSpeed)
{
    modSpeed = newModSpeed;
    sine->setWaveTableFreq(modSpeed);
}


