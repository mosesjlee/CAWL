//
//  CAWLSoundBoard.hpp
//  CAWL
//
//  Created by Moses Lee on 9/16/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLSoundBoard_hpp
#define CAWLSoundBoard_hpp

#include <stdio.h>

#include "CAWLAmpSimulator.hpp"
#include "CAWLEqualizer.hpp"
#include "CAWLDelayEffect.hpp"
#include "CAWLChorus.hpp"
#include "CAWLFlanger.hpp"
#include "CAWLReverb.hpp"
#include "CAWLPhaser.hpp"
#include "CAWLCompressor.hpp"
#include "CAWLWahWah.hpp"
#include "CAWLFuzz.hpp"
#include "CAWLOverdrive.hpp"

class CAWLSoundBoard
{
public:
    CAWLSoundBoard();
    ~CAWLSoundBoard();
    void processBuffer(float * audioStreaBuf, const unsigned int numSamples);
    
    //Amp Controls
    void setNewAmpGain(float gain);
    void setTurnOnAmp(bool onOff);
	void byPassAmp(bool bypass);
    void selectAmpType(int type);
    
    //Delay controls
	void turnOnDelay(bool onOff);
	void bypassDelay(bool bypass);
    void setNewDelayTime(float time);
    void setDelayWetMixLevel(double wetMixLevel);
    void setDelayFeedbackGain(double gain);
	void setDelayDryMixGain(double newDryGain);
    
    //Equalizer Controls
    void turnOnEqualizer(bool onOff);
	void bypassEqualizer(bool bypass);
    void setLowShelfCenterFreq(double centFreq);
    void setHighShelfCenterFreq(double centFreq);
    void setLowMidCenterFreq(double centFreq);
    void setHighMidCenterFreq(double centFreq);
    void setLowShelfGain(double newGain);
    void setHighShelfGain(double newGain);
    void setLowMidGain(double newGain);
    void setHighMidGain(double newGain);
    void setLowQFactor(double newQFactor);
    void setHighQFactor(double newQFactor);
    
    //Chorus controls
    void turnOnChorus(bool onOff);
	void bypassChorus(bool bypass);
	void setChorusModulationSpeed(double newModSpeed);
	void setChorusModulationDepth(double newDepth);
    
    //Flanger Controls
    void turnOnFlanger(bool onOff);
	void bypassFlanger(bool bypass);
	void setFlangerModulationSpeed(double newModSpeed);
	void setFlangerModulationDepth(double newDepth);
    
    //Phaser Controls
    void turnOnPhaser(bool onOff);
	void bypassPhaser(bool bypass);
	void setPhaserDepth(double depthLevel);
	void setPhaserRate(double phaserRate);
    
    //Reverb Controls
    void turnOnReverb(bool onOff);
	void bypassReverb(bool bypass);
	void setReverbTime(double reverbTime);
	void setReverbTone(double toneLevel);
    
    //Compressor Controls
    void turnOnCompressor(bool onOff);
	void bypassCompressor(bool bypass);
    void setCompressorThreshold(double newThreshold);
    void setCompressorGain(double newGain);
    void setCompressorKnee(double newKnee);
    void setCompressorRatio(double newRatio);
    
    //Wah wah controls
    void turnOnWah(bool onOff);
	void bypassWah(bool bypass);
    void setWahCenterFreq(double newCenterFreq);
    void setWahModulationDepth(double newModDepth);
    void setWahModulationRate(double newModRate);
    void setWahMixLevel(double newMixLevel);
    
    //Overdrive controls
    void turnOnOverdrive(bool onOff);
	void bypassOverdrive(bool bypass);
	void setOverdriveGain(double newGain);
	void setOverdriveToneLevel(double newToneLevel);
	
    //Fuzz controls
    void turnOnFuzz(bool onOff);
	void bypassFuzz(bool bypass);
	void setFuzzGain(double newGain);
	void setFuzzToneLevel(double newToneLevel);
    
private:
    //Amp sim
    CAWLAmpSimulator    *ampSim;
    
    //Effects sim
    CAWLEqualizer       *equalizer;
    CAWLDelayEffect     *delayEffect;
    CAWLCompressor      *compressor;
    CAWLReverb          *reverb;
    CAWLChorus          *chorus;
    CAWLPhaser          *phaser;
    CAWLFlanger         *flanger;
    CAWLWahWah          *wahWah;
    CAWLOverdrive       *overdrive;
    CAWLFuzz            *fuzz;
    
    //Is on
    bool isAmpOn        = false;
    bool isEqOn         = false;
    bool isChorusOn     = false;
    bool isFlangerOn    = false;
    bool isReverbOn     = false;
    bool isDelayOn      = false;
    bool isWahOn        = false;
    bool isCompressorOn = false;
    bool isPhaserOn     = false;
    bool isOverdriveOn  = false;
    bool isFuzzOn       = false;
	
	//Is by passed
	bool isAmpBypassed        = false;
	bool isEqBypassed         = false;
	bool isChorusBypassed     = false;
	bool isFlangerBypassed    = false;
	bool isReverbBypassed     = false;
	bool isDelayBypassed      = false;
	bool isWahBypassed        = false;
	bool isCompressorBypassed = false;
	bool isPhaserBypassed     = false;
	bool isOverdriveBypassed  = false;
	bool isFuzzBypassed       = false;
};

#endif /* CAWLSoundBoard_hpp */
