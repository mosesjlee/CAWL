//
//  CAWLSoundBoard.cpp
//  CAWL
//
//  Created by Moses Lee on 9/16/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLSoundBoard.hpp"

CAWLSoundBoard::CAWLSoundBoard()
{
    iir.setDelay(400);
    iir.setMixLevel(0.9);
    iir.setFeedbackGain(0.5);
}

CAWLSoundBoard::~CAWLSoundBoard()
{
    
}

void CAWLSoundBoard::processBuffer(float * buf, const unsigned int numSamples)
{
    if(isDelayOn) {
        iir.processBuffer(buf, numSamples);
    }
    if(isAmpOn) {
        ampSim.processBuffer(buf, numSamples);
    }
}

void CAWLSoundBoard::setNewAmpGain(float gain)
{
    ampSim.setGain(gain);
}

void CAWLSoundBoard::setTurnOnAmp(bool onOff)
{
    isAmpOn = onOff;
}

void CAWLSoundBoard::setNewDelayTime(float time)
{
    iir.setDelay(time);
}

void CAWLSoundBoard::setDelayWetMixLevel(double wetMixLevel)
{
    
}

void CAWLSoundBoard::setDelayFeedbackGain(double gain)
{
    
}

void CAWLSoundBoard::setDelayOnOff(bool onOff)
{
    isDelayOn = onOff;
}
