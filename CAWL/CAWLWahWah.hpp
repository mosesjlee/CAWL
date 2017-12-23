/*
  CAWLWahWah.hpp
  CAWL

  Created by Moses Lee on 10/21/17.
  Copyright © 2017 Moses Lee. All rights reserved.
 CAWLWahWah class that simulates a wah wah effect
*/

#ifndef CAWLWahWah_hpp
#define CAWLWahWah_hpp
#include "CAWLTriangleWaveOsc.hpp"
#include "CAWLSoundModule.hpp"

class CAWLWahWah : public CAWLSoundModule
{
public:
    CAWLWahWah();
    ~CAWLWahWah();
    virtual void processBuffer(float * audioStreamBuf, const unsigned int numSamples);
    void setCenterFreq(double newCenterFreq);
    void setModulationDepth(double newModDepth);
    void setModulationRate(double newModRate);
    void setMixLevel(double newMixLevel);
    
private:
    void calculateCoefficients();
    CAWLTriangleWaveOsc * triangeWave;
    double rate;
    double mixLevel;
    double modDepth;
    
    //Digital State Variable Filter based on udo zolzer page 50
    double y_h;
    double y_b;
    double y_l;
    double y_b_n1;
    double y_l_n1;
    double max_y_b;
    double centerFrequency;
    double anchorFrequency;
};
#endif /* CAWLWahWah_hpp */
