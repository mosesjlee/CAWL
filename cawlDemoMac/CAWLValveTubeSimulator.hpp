/*
  CAWLValveTubeSimulator.hpp
  CAWL

  Created by Moses Lee on 9/16/17.
  Copyright © 2017 Moses Lee. All rights reserved.
*/

#ifndef CAWLValveTubeSimulator_hpp
#define CAWLValveTubeSimulator_hpp

#include "CAWLSoundModule.hpp"

class CAWLValveTubeSimulator : public CAWLSoundModule
{
public:
    CAWLValveTubeSimulator();
    ~CAWLValveTubeSimulator();
    void setGain(float newGain);
    double getGain() { return mGain; }
    virtual void processBuffer(float * buf, const unsigned int numOfSamples);
    
private:
    double mGain;
    double mMixLevel;
    //float peakSample;
};
#endif /* CAWLAmpSimulator_hpp */
