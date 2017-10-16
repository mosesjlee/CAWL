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
    void setNewAmpGain(float gain);
    void setTurnOnAmp(bool onOff);
    void setNewDelayTime(float time);
    void setDelayOnOff(bool onOff);
    void setDelayWetMixLevel(double wetMixLevel);
    void setDelayFeedbackGain(double gain);
    
private:
    CAWLAmpSimulator ampSim;
    CAWLEqualizer equalizer;
    CAWLIIRCombFilter iir;
    bool isDelayOn = false;
    bool isAmpOn = false;
};

#endif /* CAWLSoundBoard_hpp */
