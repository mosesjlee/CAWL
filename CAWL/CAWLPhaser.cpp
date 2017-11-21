//
//  CAWLPhaser.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLPhaser.hpp"

#define MAX_PHASER_MOD_RATE 2
#define MIN_PHASER_MOD_RATE 0.75

CAWLPhaser::CAWLPhaser()
{
	triangleWave = new CAWLTriangleWaveOsc();
    triangleWave->setFreq(MIN_PHASER_MOD_RATE);
}

CAWLPhaser::~CAWLPhaser()
{
    
}

void CAWLPhaser::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yCurrOutput = 0.0;
    for(unsigned int i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i];
    }
}

void CAWLPhaser::setModDepth(double newModDepth)
{
    
}

void CAWLPhaser::setModRate(double newModRate)
{
    
}

void CAWLPhaser::setMixLevel(double newMixLevel)
{
    
}











