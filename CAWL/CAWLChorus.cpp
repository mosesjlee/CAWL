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

/*
 Default constructor initialized with default
 values for chorus
 */
CAWLChorus::CAWLChorus()
{
    sine = new CAWLSineWaveOsc();
    cModSpeed = 1.0;
    cModDepth = 30;
    cMixLevel = 1.0;
    cDryMix = 0.3;
    cFeedbackGain = 0.0;
    cFeedForwardGain = 0.7;
    sine->setWaveTableFreq(cModSpeed);
    cDelayLine->setDelayTimeInSamples(cModDepth/2 + MIN_DELAY);
}

CAWLChorus::~CAWLChorus()
{
    delete sine;
}


double CAWLChorus::modulatedTime()
{
    return (cModDepth/2 + (cModDepth/2 * sine->getNextSample())) + MIN_DELAY;
}



