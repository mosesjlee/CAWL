/*
 CAWLSoundBoard.hpp
 CAWL

 Created by Moses Lee on 9/16/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLSoundBoard is the main class that aggregates
 all the effects to be controlled by an external
 class
*/

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
    void selectAmpType(int type);
    
    //Delay controls
	void turnOnDelay(bool onOff);
    void setNewDelayTime(float time);
    void setDelayWetMixLevel(double wetMixLevel);
    void setDelayFeedbackGain(double gain);
	void setDelayDryMixGain(double newDryGain);
    
    //Equalizer Controls
    void turnOnEqualizer(bool onOff);
    void setEqLowShelfCenterFreq(double centFreq);
    void setEqHighShelfCenterFreq(double centFreq);
    void setEqLowMidCenterFreq(double centFreq);
    void setEqHighMidCenterFreq(double centFreq);
    void setEqLowShelfGain(double newGain);
    void setEqHighShelfGain(double newGain);
    void setEqLowMidGain(double newGain);
    void setEqHighMidGain(double newGain);
    void setEqLowQFactor(double newQFactor);
    void setEqHighQFactor(double newQFactor);
    
    //Chorus controls
    void turnOnChorus(bool onOff);
	void setChorusModulationSpeed(double newModSpeed);
	void setChorusModulationDepth(double newDepth);
    void setChorusMixLevel(double mixLevel);
    
    //Flanger Controls
    void turnOnFlanger(bool onOff);
	void setFlangerModulationSpeed(double newModSpeed);
	void setFlangerModulationDepth(double newDepth);
    
    //Phaser Controls
    void turnOnPhaser(bool onOff);
	void setPhaserDepth(double depthLevel);
	void setPhaserRate(double phaserRate);
    void setPhaserMixLevel(double mixLevel);
    
    //Reverb Controls
    void turnOnReverb(bool onOff);
	void setReverbTime(double reverbTime);
	void setReverbTone(double toneLevel);
    
    //Compressor Controls
    void turnOnCompressor(bool onOff);
    void setCompressorThreshold(double newThreshold);
    void setCompressorGain(double newGain);
    void setCompressorKnee(double newKnee);
    void setCompressorRatio(double newRatio);
    
    //Wah wah controls
    void turnOnWah(bool onOff);
    void setWahCenterFreq(double newCenterFreq);
    void setWahModulationDepth(double newModDepth);
    void setWahModulationRate(double newModRate);
    void setWahMixLevel(double newMixLevel);
    
    //Overdrive controls
    void turnOnOverdrive(bool onOff);
	void setOverdriveGain(double newGain);
	void setOverdriveToneLevel(double newToneLevel);
	
    //Fuzz controls
    void turnOnFuzz(bool onOff);
	void setFuzzGain(double newGain);
	void setFuzzToneLevel(double newToneLevel);
    void setFuzzMixLevel(double newMixLevel);
    
private:
    //Amp sim
    CAWLAmpSimulator    *ampSim;
    
    //Effects sim
    CAWLEqualizer       *equalizer      = NULL;
    CAWLDelayEffect     *delayEffect    = NULL;
    CAWLCompressor      *compressor     = NULL;
    CAWLReverb          *reverb         = NULL;
    CAWLChorus          *chorus         = NULL;
    CAWLPhaser          *phaser         = NULL;
    CAWLFlanger         *flanger        = NULL;
    CAWLWahWah          *wahWah         = NULL;
    CAWLOverdrive       *overdrive      = NULL;
    CAWLFuzz            *fuzz           = NULL;
    
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
};

#endif /* CAWLSoundBoard_hpp */
