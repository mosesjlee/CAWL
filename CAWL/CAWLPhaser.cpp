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
#define MAX_PHASER_MOD_DEPTH 2000
#define MIN_PHASER_MOD_DEPTH 1000
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
        xCurrSample = buf[i] + lastFeedbackOutput;
        yCurrOutput = xCurrSample;
        for(int j = 0; j < NUM_OF_FILTERS; j++)
        {
            yCurrOutput = allPassFilters[j]->processNextSample(yCurrOutput);
            double nextValue = triangleWave->getNextSample();
            allPassFilters[j]->setCutOffFreq(nextValue * modDepth + centerFrequency);
        }
        buf[i] = yCurrOutput * 0.5 + xCurrSample * 0.5;
        lastFeedbackOutput = yCurrOutput * .8;
    }
}

void CAWLPhaser::setModDepth(double newModDepth)
{
    if(newModDepth > MAX_PHASER_MOD_DEPTH)
        modDepth = MAX_PHASER_MOD_DEPTH;
    else if(newModDepth < MIN_PHASER_MOD_DEPTH)
        modDepth = MIN_PHASER_MOD_DEPTH;
    else
        modDepth = newModDepth;
}

void CAWLPhaser::setModRate(double newModRate)
{
    if(newModRate > MAX_PHASER_MOD_RATE)
        modRate = MAX_PHASER_MOD_RATE;
    else if(newModRate < MIN_PHASER_MOD_RATE)
        modRate = MIN_PHASER_MOD_RATE;
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











