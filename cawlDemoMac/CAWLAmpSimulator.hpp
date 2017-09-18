//
//  CAWLAmpSimulator.hpp
//  CAWL
//
//  Created by Moses Lee on 9/16/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLAmpSimulator_hpp
#define CAWLAmpSimulator_hpp

#include <stdio.h>
#include "CAWLSoundModule.hpp"

class CAWLAmpSimulator
{
public:
    CAWLAmpSimulator();
    ~CAWLAmpSimulator();
    void setGain(float newGain);
    void setVolume(float newVolume);
    void setDistortion(float newDistortion);
    void setMixLevel(float newMixLevel);
    void processBuffer(float * buf, const unsigned int numOfSamples);
    
private:
    float mVolume;
    float mGain;
    float mDistortion;
    float mMixLevel;
};
#endif /* CAWLAmpSimulator_hpp */
