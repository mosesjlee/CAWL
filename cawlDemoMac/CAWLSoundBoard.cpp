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
        ampSim->processBuffer(buf, numSamples);
    }
}

#pragma mark AMP_CONTROLS
void CAWLSoundBoard::setNewAmpGain(float gain)
{
    ampSim->setGain(gain);
}

void CAWLSoundBoard::setTurnOnAmp(bool onOff)
{
    if(!onOff)
    {
        if(ampSim != NULL) delete ampSim;
        ampSim = NULL;
    }
    else
    {
        ampSim = new CAWLAmpSimulator();
    }
    isAmpOn = onOff;
}

#pragma mark DELAY_CONTROLS
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

#pragma mark EQ_CONTROL
void CAWLSoundBoard::turnOnEqualizer(bool onOff)
{
    
}

#pragma mark CHORUS_CONTROL
void CAWLSoundBoard::turnOnChorus(bool onOff)
{
    
}

#pragma mark FLANGER_CONTROL
void CAWLSoundBoard::turnOnFlanger(bool onOff)
{
    
}

#pragma mark PHASER_CONTROL
void CAWLSoundBoard::turnOnPhaser(bool onOff)
{
    
}

#pragma mark REVERB_CONTROL
void CAWLSoundBoard::turnOnReverb(bool onOff)
{
    
}

#pragma mark COMPRESSOR_CONTROL
void CAWLSoundBoard::turnOnCompressor(bool onOff)
{
    
}




