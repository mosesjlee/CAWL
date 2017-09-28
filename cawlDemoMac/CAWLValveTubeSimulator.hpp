//
//  CAWLValveTubeSimulator.hpp
//  CAWL
//
//  Created by Moses Lee on 9/16/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLValveTubeSimulator_hpp
#define CAWLValveTubeSimulator_hpp

#include <stdio.h>
#include "CAWLSoundModule.hpp"

class CAWLValveTubeSimulator : public CAWLSoundModule
{
public:
    CAWLValveTubeSimulator();
    ~CAWLValveTubeSimulator();
    void setGain(float newGain);
    float getGain() { return mGain; }
    virtual void processBuffer(float * buf, const unsigned int numOfSamples);
    
private:
    float mGain;
    float mMixLevel;
};
#endif /* CAWLAmpSimulator_hpp */
