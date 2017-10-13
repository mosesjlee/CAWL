//
//  CAWLEqualizer.cpp
//  CAWL
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLEqualizer.hpp"

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
    
}

void CAWLEqualizer::setHighShelfCenterFreq(double centerFreq)
{
    
}

void CAWLEqualizer::setlowMidCenterFreq(double centerFreq)
{
    
}
void CAWLEqualizer::setHighMidCenterFreq(double centerFreq)
{
    
}

void CAWLEqualizer::setLowShelfGain(double newGain)
{
    
}

void CAWLEqualizer::setHighShelfGain(double newGain)
{
    
}

void CAWLEqualizer::setlowMidGain(double newGain)
{
    
}

void CAWLEqualizer::setHighMidGain(double newGain)
{
    
}

void CAWLEqualizer::setLowMidQFactor(double newQFactor)
{
    
}

void CAWLEqualizer::setHighMidQFactor(double newQFactor)
{
    
}

