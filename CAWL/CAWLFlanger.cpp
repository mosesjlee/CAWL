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
    cMixLevel = 1.0;
    cDryMix = 0.2;
    cFeedbackGain = 0.0;
    cFeedForwardGain = 0.7;
    sine->setWaveTableFreq(modSpeed);
	cDelayLine->setDelayTimeInSamples(modDepth/2);
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






