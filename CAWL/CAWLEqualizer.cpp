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
    cLowShelfCenterFreq = 100.0;
    cLowMidCenterFreq   = 1000.0;
    cHighMidCenterFreq  = 8000.0;
    cHighShelfCenterFreq = 15000.0;
    cLowShelf.setCenterFreq(cLowShelfCenterFreq);
    cLowMid.setCenterFreq(cLowMidCenterFreq);
    cHighMid.setCenterFreq(cHighMidCenterFreq);
    cHighShelf.setCenterFreq(cHighShelfCenterFreq);
    cLowShelf.setGain(0.0);
    cLowMid.setGain(0.0);
    cHighMid.setGain(0.0);
    cHighShelf.setGain(0.0);
}

CAWLEqualizer::~CAWLEqualizer()
{
    
}

void CAWLEqualizer::processBuffer(float * buf, const unsigned int numSamples)
{
    cLowShelf.processBuffer(buf, numSamples);
    cLowMid.processBuffer(buf, numSamples);
    cHighMid.processBuffer(buf, numSamples);
    cHighShelf.processBuffer(buf, numSamples);
}

void CAWLEqualizer::setLowShelfCenterFreq(double centerFreq)
{
    cLowShelf.setCenterFreq(centerFreq);
}

void CAWLEqualizer::setHighShelfCenterFreq(double centerFreq)
{
    cHighShelf.setCenterFreq(centerFreq);
}

void CAWLEqualizer::setlowMidCenterFreq(double centerFreq)
{
    cLowMid.setCenterFreq(centerFreq);
}
void CAWLEqualizer::setHighMidCenterFreq(double centerFreq)
{
    cHighMid.setCenterFreq(centerFreq);
}

void CAWLEqualizer::setLowShelfGain(double newGain)
{
    cLowShelf.setGain(newGain);
}

void CAWLEqualizer::setHighShelfGain(double newGain)
{
    cHighShelf.setGain(newGain);
}

void CAWLEqualizer::setlowMidGain(double newGain)
{
    cLowMid.setGain(newGain);
}

void CAWLEqualizer::setHighMidGain(double newGain)
{
    cHighMid.setGain(newGain);
}

void CAWLEqualizer::setLowMidQFactor(double newQFactor)
{
    cLowMid.setQFactor(newQFactor);
}

void CAWLEqualizer::setHighMidQFactor(double newQFactor)
{
    cHighMid.setQFactor(newQFactor);
}

