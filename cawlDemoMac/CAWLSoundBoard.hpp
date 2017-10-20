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
#include "CAWLIIRCombFilter.hpp"

class CAWLSoundBoard
{
public:
    CAWLSoundBoard();
    ~CAWLSoundBoard();
    void processBuffer(float * buf, const unsigned int numSamples);
    
    //Amp Controls
    void setNewAmpGain(float gain);
    void setTurnOnAmp(bool onOff);
    void selectAmpType(int type);
    
    //Delay controls
    void setNewDelayTime(float time);
    void setDelayOnOff(bool onOff);
    void setDelayWetMixLevel(double wetMixLevel);
    void setDelayFeedbackGain(double gain);
    
    //Equalizer Controls
    void turnOnEqualizer(bool onOff);
    void setLowShelfCenterFreq(double centFreq);
    void setHighShelfCenterFreq(double centFreq);
    void setLowMidCenterFreq(double centFreq);
    void setHighMidCenterFreq(double centFreq);
    void setLowShelfGain(double centFreq);
    void setHighShelfGain(double centFreq);
    void setLowMidGain(double centFreq);
    void setHighMidGain(double centFreq);
    void setLowQFactor(double centFreq);
    void setHighQFactor(double centFreq);
    
    //Chorus controls
    void turnOnChorus(bool onOff);
    
    //Flanger Controls
    void turnOnFlanger(bool onOff);
    
    //Phaser Controls
    void turnOnPhaser(bool onOff);
    
    //Reverb Controls
    void turnOnReverb(bool onOff);
    
    //Compressor Controls
    void turnOnCompressor(bool onOff);
    void setThreshold();
    void setCompressorGain();
    void setCompressorKnee();
    void setCompressorRatio();
    
private:
    CAWLAmpSimulator * ampSim;
    CAWLEqualizer * equalizer;
    CAWLIIRCombFilter iir;
    
    bool isDelayOn = false;
    bool isAmpOn = false;
    bool isEqOn = false;
    bool isChorusOn = false;
    bool isFlangerOn = false;
    bool isReverbOn = false;
    bool isCompressorOn = false;
};

#endif /* CAWLSoundBoard_hpp */
