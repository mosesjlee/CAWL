//
//  CAWLWahWah.hpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLWahWah_hpp
#define CAWLWahWah_hpp
#include "CAWLTriangleWaveOsc.hpp"
#include "CAWLSoundModule.hpp"

class CAWLWahWah : public CAWLSoundModule
{
public:
    CAWLWahWah();
    ~CAWLWahWah();
    virtual void processBuffer(float * buf, const unsigned int numSamples);
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
    
    //Digital State Variable Filter
    double y_h;
    double y_b;
    double y_l;
    double y_b_n1;
    double y_l_n1;
    double max_y_b;
    double centerFrequency;
    double anchorFrequency;
    
    //copied
    float freq;
    float startphase;
    float depth;
    float freqofs;
    float res;
    
    float b0;
    float b1;
    float b2;
    float a0;
    float a1;
    float a2;
    float mCurRate;
    float lfoskip;
    int skipcount = 0;
    float phase;
    float xn1;
    float xn2;
    float yn1;
    float yn2;
};
#endif /* CAWLWahWah_hpp */
