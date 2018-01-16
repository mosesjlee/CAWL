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
    if(equalizer != NULL) delete equalizer;
    if(delayEffect != NULL) delete delayEffect;
    if(compressor != NULL) delete compressor;
    if(reverb != NULL) delete reverb;
    if(chorus != NULL) delete chorus;
    if(phaser != NULL) delete phaser;
    if(flanger != NULL) delete flanger;
    if(wahWah != NULL) delete wahWah;
    if(overdrive != NULL) delete overdrive;
    if(fuzz != NULL) delete fuzz;
    if(ampSim != NULL) delete ampSim;
}

#pragma mark SOUND_PROCESSING
void CAWLSoundBoard::processBuffer(float * audioStreamBuf, const unsigned int numSamples)
{
    if(isCompressorOn) {
        compressor->processBuffer(audioStreamBuf, numSamples);
    }
    if(isOverdriveOn) {
        overdrive->processBuffer(audioStreamBuf, numSamples);
    }
    if(isFuzzOn) {
        fuzz->processBuffer(audioStreamBuf, numSamples);
    }
    if(isChorusOn) {
        chorus->processBuffer(audioStreamBuf, numSamples);
    }
    if(isEqOn) {
        equalizer->processBuffer(audioStreamBuf, numSamples);
    }
    if(isReverbOn) {
        reverb->processBuffer(audioStreamBuf, numSamples);
    }
    if(isFlangerOn) {
        flanger->processBuffer(audioStreamBuf, numSamples);
    }
    if(isWahOn) {
        wahWah->processBuffer(audioStreamBuf, numSamples);
    }
    if(isPhaserOn) {
        phaser->processBuffer(audioStreamBuf, numSamples);
    }
    if(isDelayOn) {
        delayEffect->processBuffer(audioStreamBuf, numSamples);
    }
    if(isAmpOn) {
        ampSim->processBuffer(audioStreamBuf, numSamples);
    }
}

#pragma mark AMP_CONTROLS
void CAWLSoundBoard::setNewAmpGain(float gain)
{
    ampSim->setGain(gain);
}

void CAWLSoundBoard::setTurnOnAmp(bool onOff)
{
	if(ampSim == NULL)
        ampSim = new CAWLAmpSimulator();
    isAmpOn = onOff;
}

void CAWLSoundBoard::selectAmpType(int model)
{
	ampSim->setAmpModel(model);
}

void CAWLSoundBoard::setAmpBass(double newBass)
{
	ampSim->setAmpBass(newBass);
}

void CAWLSoundBoard::setAmpMids(double newMids)
{
	ampSim->setAmpMid(newMids);
}

void CAWLSoundBoard::setAmpTreble(double newTreble)
{
	ampSim->setAmpTreble(newTreble);
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

#pragma mark EQ_CONTROL
void CAWLSoundBoard::turnOnEqualizer(bool onOff)
{
    if(equalizer == NULL)
        equalizer = new CAWLEqualizer();
	isEqOn = onOff;
}

void CAWLSoundBoard::setEqLowShelfCenterFreq(double centFreq)
{
	equalizer->setLowShelfCenterFreq(centFreq);
}

void CAWLSoundBoard::setEqHighShelfCenterFreq(double centFreq)
{
	equalizer->setHighShelfCenterFreq(centFreq);
}

void CAWLSoundBoard::setEqLowMidCenterFreq(double centFreq)
{
	equalizer->setlowMidCenterFreq(centFreq);
}

void CAWLSoundBoard::setEqHighMidCenterFreq(double centFreq)
{
	equalizer->setHighMidCenterFreq(centFreq);
}

void CAWLSoundBoard::setEqLowShelfGain(double newGain)
{
	equalizer->setLowShelfGain(newGain);
}

void CAWLSoundBoard::setEqHighShelfGain(double newGain)
{
	equalizer->setHighShelfGain(newGain);
}

void CAWLSoundBoard::setEqLowMidGain(double newGain)
{
	equalizer->setlowMidGain(newGain);
}

void CAWLSoundBoard::setEqHighMidGain(double newGain)
{
    equalizer->setHighMidGain(newGain);
}

void CAWLSoundBoard::setEqLowQFactor(double newQFactor)
{
    equalizer->setLowMidQFactor(newQFactor);
}

void CAWLSoundBoard::setEqHighQFactor(double newQFactor)
{
	equalizer->setHighMidQFactor(newQFactor);
}

#pragma mark CHORUS_CONTROL
void CAWLSoundBoard::turnOnChorus(bool onOff)
{
    if(chorus == NULL)
        chorus = new CAWLChorus();
    isChorusOn = onOff;
}

void CAWLSoundBoard::setChorusModulationSpeed(double newModSpeed)
{
    chorus->setModulationSpeed(newModSpeed);
}

void CAWLSoundBoard::setChorusModulationDepth(double newDepth)
{
    chorus->setModulationDepth(newDepth);
}

void CAWLSoundBoard::setChorusMixLevel(double mixLevel)
{
    chorus->setMixLevel(mixLevel);
}

#pragma mark FLANGER_CONTROL
void CAWLSoundBoard::turnOnFlanger(bool onOff)
{
    if(flanger == NULL)
        flanger = new CAWLFlanger();
    isFlangerOn = onOff;
}

void CAWLSoundBoard::setFlangerModulationSpeed(double newModSpeed)
{
	flanger->setModulationSpeed(newModSpeed);
}

void CAWLSoundBoard::setFlangerModulationDepth(double newDepth)
{
	flanger->setModulationDepth(newDepth);
}

void CAWLSoundBoard::setFlangerMixLevel(double newMixLevel)
{
    flanger->setMixLevel(newMixLevel);
}

#pragma mark PHASER_CONTROL
void CAWLSoundBoard::turnOnPhaser(bool onOff)
{
    if(phaser == NULL)
        phaser = new CAWLPhaser();
    
    isPhaserOn = onOff;
    
}

void CAWLSoundBoard::setPhaserDepth(double depthLevel)
{
    phaser->setModDepth(depthLevel);
}

void CAWLSoundBoard::setPhaserRate(double phaserRate)
{
    phaser->setModRate(phaserRate);
}

void CAWLSoundBoard::setPhaserMixLevel(double mixLevel)
{
    phaser->setMixLevel(mixLevel);
}

#pragma mark REVERB_CONTROL
void CAWLSoundBoard::turnOnReverb(bool onOff)
{
    if(reverb == NULL)
        reverb = new CAWLReverb();
    isReverbOn = onOff;
}

void CAWLSoundBoard::setReverbTime(double reverbTime)
{
    reverb->setReverbTime(reverbTime);
}

void CAWLSoundBoard::setReverbTone(double toneLevel)
{
    reverb->adjustReverbTone(toneLevel);
}

void CAWLSoundBoard::setReverbMixLevel(double mixLevel)
{
    reverb->setReverbMix(mixLevel);
}

#pragma mark COMPRESSOR_CONTROL
void CAWLSoundBoard::turnOnCompressor(bool onOff)
{
    if(compressor == NULL)
        compressor = new CAWLCompressor();
    isCompressorOn = onOff;
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
    if(wahWah == NULL)
        wahWah = new CAWLWahWah();
    isWahOn = onOff;
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
    if(overdrive == NULL)
        overdrive = new CAWLOverdrive();
    isOverdriveOn = onOff;
}

void CAWLSoundBoard::setOverdriveGain(double newGain)
{
    overdrive->adjustOverdriveGain(newGain);
}

void CAWLSoundBoard::setOverdriveToneLevel(double newToneLevel)
{
	overdrive->adjustOverdriveTone(newToneLevel);
}
#pragma mark FUZZ_CONTROL
void CAWLSoundBoard::turnOnFuzz(bool onOff)
{
    if(fuzz == NULL)
        fuzz = new CAWLFuzz();
    isFuzzOn = onOff;
}

void CAWLSoundBoard::setFuzzGain(double newGain)
{
    fuzz->setGain(newGain);
}

void CAWLSoundBoard::setFuzzToneLevel(double newToneLevel)
{
    fuzz->adjustFuzzTone(newToneLevel);
}

void CAWLSoundBoard::setFuzzMixLevel(double newMixLevel)
{
    fuzz->setMixLevel(newMixLevel);
}





