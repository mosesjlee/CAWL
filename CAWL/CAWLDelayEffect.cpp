//
//  CAWLDelayEffect.cpp
//  CAWL
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLDelayEffect.hpp"
CAWLDelayEffect::CAWLDelayEffect():
feedbackMix(0.5),
wetMix(0.5),
dryMix(1.0)
{
    ucf = new CAWLUniversalCombFilter();
    ucf->setDryMix(dryMix);
    ucf->setFeedForwardGain(wetMix);
    ucf->setFeedbackGain(feedbackMix);
    ucf->setMixLevel(0);
    
}

CAWLDelayEffect::~CAWLDelayEffect()
{
    delete ucf;
}

void CAWLDelayEffect::processBuffer(float * buf, const unsigned int numSamples)
{
    ucf->processBuffer(buf, numSamples);
}

void CAWLDelayEffect::setWetMixLevel(double newWetMix)
{
    ucf->setFeedForwardGain(wetMix);
}

void CAWLDelayEffect::setFeedbackLevel(double newFeedbackMix)
{
    ucf->setFeedbackGain(feedbackMix);
}

void CAWLDelayEffect::setDryMix(double dryMix)
{
    ucf->setDryMix(dryMix);
}

void CAWLDelayEffect::setDelayTime(double newDelayTime)
{
    delayTime = newDelayTime;
    ucf->setDelay(delayTime);
}

