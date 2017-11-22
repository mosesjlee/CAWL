//
//  CAWLPhaser.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLPhaser.hpp"

#define MAX_PHASER_MOD_RATE 2
#define MIN_PHASER_MOD_RATE 0.25
#define NUM_OF_FILTERS 4

CAWLPhaser::CAWLPhaser()
{
	triangleWave = new CAWLTriangleWaveOsc();
    triangleWave->setFreq(MIN_PHASER_MOD_RATE);
    centerFrequency = 2200;
    modDepth = 2000;
    allPassFilters = (CAWLAllPassFilter **) malloc(sizeof(CAWLAllPassFilter *) * NUM_OF_FILTERS);
    for(int i = 0; i < NUM_OF_FILTERS; i++)
    {
        allPassFilters[i] = new CAWLAllPassFilter();
        allPassFilters[i]->setCutOffFreq(centerFrequency);
    }
}

CAWLPhaser::~CAWLPhaser()
{
    for(int i = 0 ; i < NUM_OF_FILTERS; i++)
    {
        delete allPassFilters[i];
    }
    delete [] allPassFilters;
    delete triangleWave;
}

void CAWLPhaser::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yCurrOutput = 0.0;
    for(unsigned int i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i] + (0.9 * lastFeedbackOutput);
        yCurrOutput = xCurrSample;
        for(int j = 0; j < NUM_OF_FILTERS; j++)
        {
            yCurrOutput = allPassFilters[j]->processNextSample(yCurrOutput);
            allPassFilters[j]->setCutOffFreq(triangleWave->getNextSample() * modDepth + centerFrequency);
        }
        buf[i] = yCurrOutput * 0.9 + xCurrSample * 0.1;
        lastFeedbackOutput = yCurrOutput;
    }
}

void CAWLPhaser::setModDepth(double newModDepth)
{
    if(newModDepth > 1.0)
        modDepth = 1.0;
    else if(newModDepth < 0.0)
        modDepth = 0.0;
    else
        modDepth = newModDepth;
}

void CAWLPhaser::setModRate(double newModRate)
{
    if(newModRate > 1.0)
        modRate = 1.0;
    else if(newModRate < 0.0)
        modRate = 0.0;
    else
        modRate = newModRate;
}

void CAWLPhaser::setMixLevel(double newMixLevel)
{
    if(newMixLevel > 1.0)
        mixLevel = 1.0;
    else if(newMixLevel < 0.0)
        mixLevel = 0.0;
    else
        mixLevel = newMixLevel;
}











