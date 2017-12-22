//
//  CAWLChorus.cpp
//  CAWL
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLChorus.hpp"
#define MIN_DELAY 7
#define MAX_DELAY 40
#define MAX_MOD_DEPTH (MAX_DELAY - MIN_DELAY)

CAWLChorus::CAWLChorus()
{
    sine = new CAWLSineWaveOsc();
    modSpeed = 1.0;
    modDepth = 30;
    cMixLevel = 1.0;
    cDryMix = 0.3;
    cFeedbackGain = 0.0;
    cFeedForwardGain = 0.7;
    sine->setWaveTableFreq(modSpeed);
    cDelayLine->setDelayTimeInSamples(modDepth/2 + MIN_DELAY);
}

CAWLChorus::~CAWLChorus()
{
    delete sine;
}


double CAWLChorus::modulatedTime()
{
    return (modDepth/2 + (modDepth/2 * sine->getNextSample())) + MIN_DELAY;
}



