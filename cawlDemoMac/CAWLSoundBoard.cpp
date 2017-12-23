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

}

CAWLSoundBoard::~CAWLSoundBoard()
{
    
}

#pragma mark SOUND_PROCESSING
void CAWLSoundBoard::processBuffer(float * buf, const unsigned int numSamples)
{
    if(isDelayOn && !isDelayBypassed) {
        delayEffect->processBuffer(buf, numSamples);
    }
    if(isAmpOn && !isAmpBypassed) {
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

void CAWLSoundBoard::byPassAmp(bool bypass)
{
	
}

#pragma mark DELAY_CONTROLS
void CAWLSoundBoard::setNewDelayTime(float time)
{
    delayEffect->setDelayTime(time);
}

void CAWLSoundBoard::setDelayWetMixLevel(double wetMixLevel)
{
    delayEffect->setWetMixLevel(wetMixLevel);
}

void CAWLSoundBoard::setDelayFeedbackGain(double gain)
{
    delayEffect->setFeedbackLevel(gain);
}

void CAWLSoundBoard::setDelayDryMixGain(double newDryGain)
{
	delayEffect->setDryMix(newDryGain);
}

void CAWLSoundBoard::turnOnDelay(bool onOff)
{
	if(delayEffect == NULL)
        delayEffect = new CAWLDelayEffect();
    isDelayOn = onOff;
}

void CAWLSoundBoard::bypassDelay(bool bypass)
{
	
}

#pragma mark EQ_CONTROL
void CAWLSoundBoard::turnOnEqualizer(bool onOff)
{
	if(!isEqOn)
	{
		if(equalizer != NULL) delete equalizer;
		equalizer = NULL;
	}
	else
	{
		equalizer = new CAWLEqualizer();
	}
	isEqOn = onOff;
}

void CAWLSoundBoard::bypassEqualizer(bool bypass)
{
	isEqBypassed = bypass;
}

void CAWLSoundBoard::setLowShelfCenterFreq(double centFreq)
{
	equalizer->setLowShelfCenterFreq(centFreq);
}

void CAWLSoundBoard::setHighShelfCenterFreq(double centFreq)
{
	equalizer->setHighShelfCenterFreq(centFreq);
}

void CAWLSoundBoard::setLowMidCenterFreq(double centFreq)
{
	equalizer->setlowMidCenterFreq(centFreq);
}

void CAWLSoundBoard::setHighMidCenterFreq(double centFreq)
{
	equalizer->setHighMidCenterFreq(centFreq);
}

void CAWLSoundBoard::setLowShelfGain(double newGain)
{
	equalizer->setLowShelfGain(newGain);
}

void CAWLSoundBoard::setHighShelfGain(double newGain)
{
	equalizer->setHighShelfGain(newGain);
}

void CAWLSoundBoard::setLowMidGain(double newGain)
{
	equalizer->setlowMidGain(newGain);
}

void CAWLSoundBoard::setHighMidGain(double newGain)
{
	
}

void CAWLSoundBoard::setLowQFactor(double newGain)
{
	
}

void CAWLSoundBoard::setHighQFactor(double newGain)
{
	
}

#pragma mark CHORUS_CONTROL
void CAWLSoundBoard::turnOnChorus(bool onOff)
{
    
}

void CAWLSoundBoard::bypassChorus(bool bypass)
{
	
}

void CAWLSoundBoard::setChorusModulationSpeed(double newModSpeed)
{
	
}

void CAWLSoundBoard::setChorusModulationDepth(double newDepth)
{
	
}

#pragma mark FLANGER_CONTROL
void CAWLSoundBoard::turnOnFlanger(bool onOff)
{
    if(onOff) {
        if(flanger == NULL) flanger = new CAWLFlanger();
    } else {
        if(flanger) delete flanger;
        flanger = NULL;
    }
    isFlangerOn = onOff;
}

void CAWLSoundBoard::bypassFlanger(bool bypass)
{
	
}

void CAWLSoundBoard::setFlangerModulationSpeed(double newModSpeed)
{
	flanger->setModulationSpeed(newModSpeed);
}

void CAWLSoundBoard::setFlangerModulationDepth(double newDepth)
{
	flanger->setModulationDepth(newDepth);
}

#pragma mark PHASER_CONTROL
void CAWLSoundBoard::turnOnPhaser(bool onOff)
{
    
}

void CAWLSoundBoard::bypassPhaser(bool bypass)
{
	
}

void CAWLSoundBoard::setPhaserDepth(double depthLevel)
{
	
}

void CAWLSoundBoard::setPhaserRate(double phaserRate)
{
	
}


#pragma mark REVERB_CONTROL
void CAWLSoundBoard::turnOnReverb(bool onOff)
{
    
}

void CAWLSoundBoard::bypassReverb(bool bypass)
{
	
}

void CAWLSoundBoard::setReverbTime(double reverbTime)
{
	
}

void CAWLSoundBoard::setReverbTone(double toneLevel)
{
	
}

#pragma mark COMPRESSOR_CONTROL
void CAWLSoundBoard::turnOnCompressor(bool onOff)
{
    
}

void CAWLSoundBoard::bypassCompressor(bool bypass)
{
	
}

void CAWLSoundBoard::setCompressorThreshold(double newThreshold)
{
	compressor->setCompressorThreshold(newThreshold);
}

void CAWLSoundBoard::setCompressorGain(double newGain)
{
	compressor->setMakeUpGain(newGain);
}

void CAWLSoundBoard::setCompressorKnee(double newKnee)
{
	compressor->setKneeLevel(newKnee);
}

void CAWLSoundBoard::setCompressorRatio(double newRatio)
{
	compressor->setCompressorRatio(newRatio);
}

#pragma mark WAH_WAH_CONTROL
void CAWLSoundBoard::turnOnWah(bool onOff)
{
    
}

void CAWLSoundBoard::bypassWah(bool bypass)
{
	
}

void CAWLSoundBoard::setWahCenterFreq(double newCenterFreq)
{
	wahWah->setCenterFreq(newCenterFreq);
}

void CAWLSoundBoard::setWahModulationDepth(double newModDepth)
{
	wahWah->setModulationDepth(newModDepth);
}

void CAWLSoundBoard::setWahModulationRate(double newModRate)
{
	wahWah->setModulationRate(newModRate);
}

void CAWLSoundBoard::setWahMixLevel(double newMixLevel)
{
	wahWah->setMixLevel(newMixLevel);
}

#pragma mark OVERDRIVE_CONTROL
void CAWLSoundBoard::turnOnOverdrive(bool onOff)
{
    
}

void CAWLSoundBoard::bypassOverdrive(bool bypass)
{
	
}

void CAWLSoundBoard::setOverdriveGain(double newGain)
{
	
}

void CAWLSoundBoard::setOverdriveToneLevel(double newToneLevel)
{
	
}
#pragma mark FUZZ_CONTROL
void CAWLSoundBoard::turnOnFuzz(bool onOff)
{
    
}

void CAWLSoundBoard::bypassFuzz(bool bypass)
{
	
}

void CAWLSoundBoard::setFuzzGain(double newGain)
{
	
}

void CAWLSoundBoard::setFuzzToneLevel(double newToneLevel)
{
	
}






