//
//  CAWLFlanger.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLFlanger.hpp"
#define MIN_DELAY 0
#define MAX_DELAY 10
#define MAX_MOD_DEPTH (MAX_DELAY - MIN_DELAY)
CAWLFlanger::CAWLFlanger()
{
    sine = new CAWLSineWaveOsc();
    modSpeed = 1.0;
    modDepth = 10.0;
    mMixLevel = 1.0;
    dryMix = 0.2;
    mFeedbackGain = 0.0;
    mFeedForwardGain = 0.7;
    sine->setFreq(modSpeed);
	delayLine->setDelayTimeInSamples(modDepth/2);
}


CAWLFlanger::~CAWLFlanger()
{
    delete sine;
}

double CAWLFlanger::modulatedTime()
{
    //printf("new delay %f\n",modDepth/2 + (modDepth/2 * sine->getNextSample()));
    return modDepth/2 + (modDepth/2 * sine->getNextSample());
}






