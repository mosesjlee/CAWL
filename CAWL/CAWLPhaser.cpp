//
//  CAWLPhaser.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLPhaser.hpp"

#define MAX_PHASER_MOD_RATE 10
#define MIN_PHASER_MOD_RATE 0.25
#define MAX_PHASER_MOD_DEPTH 100
#define MIN_PHASER_MOD_DEPTH 50
#define NUM_OF_FILTERS 4

/*
 Default constructor
 */
CAWLPhaser::CAWLPhaser()
{
	triangleWave = new CAWLTriangleWaveOsc();
<<<<<<< HEAD
    triangleWave->setWaveTableFreq(0.5);
    modDepth = 200;
=======
    triangleWave->setWaveTableFreq(MAX_PHASER_MOD_RATE);
    centerFrequency = 2200;
    modDepth = 2000;
	centerFreqs[0] = 808; //16Hz to 1.6 KHz
	centerFreqs[1] = 1666.6; //33Hz to 3.3 KHz
	centerFreqs[2] = 2424; //48 Hz to 4.8 KHz
	centerFreqs[3] = 4949; //98 Hz to 9.8 KHz
	centerFreqs[4] = 8080; //160 Hz to 16 KHz
//	centerFreqs[5]
	modDepths[0] = 792;
	modDepths[1] = 1633;
	modDepths[2] = 2376;
	modDepths[3] = 4851;
>>>>>>> 46f6bb5cf331a57513684d9b5312d3cc3fd6da84
    allPassFilters = (CAWLAllPassFilter **) malloc(sizeof(CAWLAllPassFilter *) * NUM_OF_FILTERS);
    for(int i = 0; i < NUM_OF_FILTERS; i++)
    {
        allPassFilters[i] = new CAWLAllPassFilter();
<<<<<<< HEAD
=======
//        allPassFilters[i]->setCenterFreq(centerFrequency);
		allPassFilters[i]->setCenterFreq(centerFreqs[i]);
>>>>>>> 46f6bb5cf331a57513684d9b5312d3cc3fd6da84
    }
    allPassFilters[0]->setCenterFreq(792);
    allPassFilters[1]->setCenterFreq(1633);
    allPassFilters[2]->setCenterFreq(2376);
    allPassFilters[3]->setCenterFreq(4851);
    centerFreqs[0] = 792;
    centerFreqs[1] = 1633;
    centerFreqs[2] = 2376;
    centerFreqs[3] = 4851;
}

/*
 Default destructor
 */
CAWLPhaser::~CAWLPhaser()
{
    for(int i = 0 ; i < NUM_OF_FILTERS; i++)
    {
        delete allPassFilters[i];
    }
    delete [] allPassFilters;
    delete triangleWave;
}

/*
 Main processing block
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLPhaser::processBuffer(float * audioStreamBuf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yCurrOutput = lastFeedbackOutput;
    for(unsigned int i = 0; i < numSamples; i++)
    {
        xCurrSample = audioStreamBuf[i];
        double nextSample = xCurrSample;
        double nextValue = triangleWave->getNextSample();
        for(int j = 0; j < NUM_OF_FILTERS; j++)
        {
            nextSample = allPassFilters[j]->processNextSample(nextSample);
            allPassFilters[j]->setCenterFreq(nextValue * modDepth + centerFreqs[j]);
        }
        audioStreamBuf[i] = nextSample * 0.7 + xCurrSample * 0.3;
        yCurrOutput = audioStreamBuf[i];
    }
    lastFeedbackOutput = yCurrOutput;
}

/*
 */
void CAWLPhaser::setModDepth(double newModDepth)
{
    if(newModDepth > MAX_PHASER_MOD_DEPTH)
        modDepth = MAX_PHASER_MOD_DEPTH;
    else if(newModDepth < MIN_PHASER_MOD_DEPTH)
        modDepth = MIN_PHASER_MOD_DEPTH;
    else
        modDepth = newModDepth;
}

/*
 */
void CAWLPhaser::setModRate(double newModRate)
{
    if(newModRate > MAX_PHASER_MOD_RATE)
        modRate = MAX_PHASER_MOD_RATE;
    else if(newModRate < MIN_PHASER_MOD_RATE)
        modRate = MIN_PHASER_MOD_RATE;
    else
        modRate = newModRate;
}

/*
 */
void CAWLPhaser::setMixLevel(double newMixLevel)
{
    if(newMixLevel > 1.0)
        mixLevel = 1.0;
    else if(newMixLevel < 0.0)
        mixLevel = 0.0;
    else
        mixLevel = newMixLevel;
}











