/*
  CAWLPhaser.hpp
  CAWL

  Created by Moses Lee on 10/15/17.
  Copyright © 2017 Moses Lee. All rights reserved.
*/

#ifndef CAWLPhaser_hpp
#define CAWLPhaser_hpp
#include "CAWLTriangleWaveOsc.hpp"
#include "CAWLAllPassFilter.hpp"
#include "CAWLSoundModule.hpp"
class CAWLPhaser
{
public:
    CAWLPhaser();
    ~CAWLPhaser();
    void processBuffer(float * buf, const unsigned int numSamples);
    void setModDepth(double newModDepth);
    void setModRate(double newModRate);
    void setMixLevel(double newMixLevel);
    
private:
    CAWLTriangleWaveOsc * triangleWave;
    CAWLAllPassFilter **allPassFilters;
    double centerFrequency;
    double modDepth;
    double modRate;
    double mixLevel;
    double lastFeedbackOutput;
    double centerFreqs[4];
};

#endif /* CAWLPhaser_hpp */
