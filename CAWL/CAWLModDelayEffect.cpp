//
//  CAWLModDelayEffect.cpp
//  CAWL
//
//  Created by Moses Lee on 10/28/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLModDelayEffect.hpp"

/*
 Main processing block
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLModDelayEffect::processBuffer(float * audioStreambuf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double zDelayedSample = 0.0;
    double xHCurrSample = cLastSampleOfBlock;
    double yCurrOutput = 0.0;
    for(int i = 0; i < numSamples; i++)
    {
        xCurrSample = audioStreambuf[i];
        zDelayedSample = cDelayLine->processNextSample(xHCurrSample);
        xHCurrSample = xCurrSample + zDelayedSample * cFeedbackGain;
        yCurrOutput = zDelayedSample * cFeedForwardGain;
        audioStreambuf[i] = yCurrOutput + xCurrSample * cDryMix;
        
        cDelayLine->setDelayTimeInMilliseconds(modulatedTime());
    }
    cLastSampleOfBlock = xHCurrSample;
}

/*
 Sets the modulation depth of the effect
 @param newModDepth -> the new modulation depth
 */
void CAWLModDelayEffect::setModulationDepth(double newModDepth)
{
    cModDepth = newModDepth;
    cDelayLine->setDelayTimeInMilliseconds(cModDepth/2);
}

/*
 Sets the mix level of the effect
 @param mixLevel -> the new mix level
 */
void CAWLModDelayEffect::setMixLevel(double mixLevel)
{
    cDryMix = mixLevel;
}

/*
 Sets the modulation speed of the effect
 @param newModSpeed -> the new moduation speed
 */
void CAWLModDelayEffect::setModulationSpeed(double newModSpeed)
{
    cModSpeed = newModSpeed;
    cSine->setWaveTableFreq(cModSpeed);
}


