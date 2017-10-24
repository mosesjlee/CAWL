//
//  CAWLFlanger.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLFlanger.hpp"

CAWLFlanger::CAWLFlanger()
{
    sine = new CAWLSineWaveOsc();
    sine->setFreq(1.0);
}

void processBuffer(float * buf, const unsigned int numSamples)
{
    
}

CAWLFlanger::~CAWLFlanger()
{
    delete sine;
}

void CAWLFlanger::setModulationDepth(double newModDepth)
{
    modDepth = newModDepth;
}

void CAWLFlanger::setMixLevel(double mixLevel)
{
    
}

void CAWLFlanger::setModulationSpeed(double newModSpeed)
{
    modSpeed = newModSpeed;
}






