//
//  CAWLEqualizer.cpp
//  CAWL
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLEqualizer.hpp"
#define MAX_LOW_SHELF_FREQ 200
#define MAX_LOW_MID_FREQ
#define MAX_HIGH_MID_FREQ
#define MAX_HIGH_SHELF_FREQ 20000

#define MIN_LOW_SHELF_FREQ 0
#define MIN_LOW_MID_FREQ
#define MIN_HIGH_MID_FREQ
#define MIN_HIGH_SHELF_FREQ 13000


CAWLEqualizer::CAWLEqualizer()
{
    lowShelfCenterFreq = 100.0;
    lowMidCenterFreq   = 1000.0;
    highMidCenterFreq  = 8000.0;
    highShelfCenterFreq = 15000.0;
    lowShelf.setCutOffFreq(lowShelfCenterFreq);
    lowMid.setCutOffFreq(lowMidCenterFreq);
    highMid.setCutOffFreq(highMidCenterFreq);
    highShelf.setCutOffFreq(highShelfCenterFreq);
    lowShelf.setGain(0.0);
    lowMid.setGain(0.0);
    highMid.setGain(0.0);
    highShelf.setGain(0.0);
}

CAWLEqualizer::~CAWLEqualizer()
{
    
}

void CAWLEqualizer::processBuffer(float * buf, const unsigned int numSamples)
{
    lowShelf.processBuffer(buf, numSamples);
    lowMid.processBuffer(buf, numSamples);
    highMid.processBuffer(buf, numSamples);
    highShelf.processBuffer(buf, numSamples);
}

void CAWLEqualizer::setLowShelfCenterFreq(double centerFreq)
{
    lowShelf.setCutOffFreq(centerFreq);
}

void CAWLEqualizer::setHighShelfCenterFreq(double centerFreq)
{
    highShelf.setCutOffFreq(centerFreq);
}

void CAWLEqualizer::setlowMidCenterFreq(double centerFreq)
{
    lowMid.setCutOffFreq(centerFreq);
}
void CAWLEqualizer::setHighMidCenterFreq(double centerFreq)
{
    highMid.setCutOffFreq(centerFreq);
}

void CAWLEqualizer::setLowShelfGain(double newGain)
{
    lowShelf.setGain(newGain);
}

void CAWLEqualizer::setHighShelfGain(double newGain)
{
    highShelf.setGain(newGain);
}

void CAWLEqualizer::setlowMidGain(double newGain)
{
    lowMid.setGain(newGain);
}

void CAWLEqualizer::setHighMidGain(double newGain)
{
    highMid.setGain(newGain);
}

void CAWLEqualizer::setLowMidQFactor(double newQFactor)
{
    lowMid.setQFactor(newQFactor);
}

void CAWLEqualizer::setHighMidQFactor(double newQFactor)
{
    highMid.setQFactor(newQFactor);
}

