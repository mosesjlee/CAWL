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
    double xHCurrSample = lastSampleOfBlock;
    double yCurrOutput = 0.0;
    for(int i = 0; i < numSamples; i++)
    {
//        if(debugCounter == 44)
//            printf("STOP\n");
        xCurrSample = buf[i];
        zDelayedSample = delayLine->processNextSample(xHCurrSample);
        //zDelayedSample = delayHsu->tick(xHCurrSample);
        xHCurrSample = xCurrSample + zDelayedSample * mFeedbackGain;
        yCurrOutput = zDelayedSample * mFeedForwardGain;
        buf[i] = yCurrOutput + xCurrSample * dryMix;
        
        delayLine->setDelayTimeInMilliseconds(modulatedTime());
        //delayHsu->setDelayLineDelay(flangedValue() * 44100.0/1000.0);
        debugCounter++;
    }
    lastSampleOfBlock = xHCurrSample;
}

void CAWLModDelayEffect::setModulationDepth(double newModDepth)
{
    modDepth = newModDepth;
    delayLine->setDelayTimeInMilliseconds(modDepth/2);
}

void CAWLModDelayEffect::setMixLevel(double mixLevel)
{
    dryMix = mixLevel;
}

void CAWLModDelayEffect::setModulationSpeed(double newModSpeed)
{
    modSpeed = newModSpeed;
    sine->setFreq(modSpeed);
}


