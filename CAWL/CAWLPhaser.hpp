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
    void processBuffer(float * audioStreamBuf, const unsigned int numSamples);
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
	
	//WIll pirkles
	double centerFreqs[6];
	double modDepths[6];
};

#endif /* CAWLPhaser_hpp */
