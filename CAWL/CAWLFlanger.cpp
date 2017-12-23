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

/*
 Default constructor initialized with default
 values for flanger
 */
CAWLFlanger::CAWLFlanger()
{
    cSine = new CAWLSineWaveOsc();
    cModSpeed = 1.0;
    cModDepth = 10.0;
    cMixLevel = 1.0;
    cDryMix = 0.2;
    cFeedbackGain = 0.0;
    cFeedForwardGain = 0.7;
    cSine->setWaveTableFreq(cModSpeed);
	cDelayLine->setDelayTimeInSamples(cModDepth/2);
}

/*
 Default destructor
 */
CAWLFlanger::~CAWLFlanger()
{
    delete cSine;
}

/*
 Returns the updated delay time for the flanger
 @return the new delay time for flanger
 */
double CAWLFlanger::modulatedTime()
{
    return cModDepth/2 + (cModDepth/2 * cSine->getNextSample());
}






