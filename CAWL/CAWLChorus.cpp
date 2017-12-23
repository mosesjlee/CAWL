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
    cSine = new CAWLSineWaveOsc();
    cModSpeed = 1.0;
    cModDepth = 30;
    cMixLevel = 1.0;
    cDryMix = 0.3;
    cFeedbackGain = 0.0;
    cFeedForwardGain = 0.7;
    cSine->setWaveTableFreq(cModSpeed);
    cDelayLine->setDelayTimeInSamples(cModDepth/2 + MIN_DELAY);
}

/*
 Default destructor
 */
CAWLChorus::~CAWLChorus()
{
    delete cSine;
}

/*
 Returns the modulated time for chorus.
 @return -> the new modulated time
 */
double CAWLChorus::modulatedTime()
{
    return (cModDepth/2 + (cModDepth/2 * cSine->getNextSample())) + MIN_DELAY;
}



