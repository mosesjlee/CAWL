/*
 CAWLBiQuadFilter.hpp
 CAWL

 Created by Moses Lee on 10/4/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLBiQuadFilter. This is my implementation of a
 2nd order biquad filter. Referenced algorithm from
 http://www.earlevel.com/main/2003/02/28/biquads/ and
 from Will Pirkle's Designing Audio Effect Plugins in C++
 pg. 189
 This is the base class for all other filters that use
 biquad structure as their basis.
 
 All classes inheriting this must implement calculateCoefficients
*/

#ifndef CAWLBiQuadFilter_hpp
#define CAWLBiQuadFilter_hpp

#include "CAWLDelayLine.hpp"
#include "CAWLSoundModule.hpp"

class CAWLBiQuadFilter : public CAWLSoundModule
{
public:
    CAWLBiQuadFilter();
    ~CAWLBiQuadFilter();
	virtual void processBuffer(float * audioStreamBuf, const unsigned int numSamples);
    virtual void setGain(double newGain);
    virtual void setCenterFreq(double newFreq);
    virtual void calculateCoefficients() = 0; 
    
protected:
    //Filter coefficients
    double a0 = 0.0;
    double a1 = 0.0;
    double a2 = 0.0;
    double b1 = 0.0;
    double b2 = 0.0;
    double c0 = 0.0;
    double d0 = 0.0;
    
    //Filter gain and center frequencies
    double cGain;
    double cCenterFrequency;
    
    //Intermediary buffer
    double x_a_0 = 0.0;
    double x_a_1 = 0.0;
    double x_a_2 = 0.0;
    double x_b_1 = 0.0;
    double x_b_2 = 0.0;
    
    //Delayed samples
    double cDelayedSample1 = 0.0;
    double cDelayedSample2 = 0.0;
	
};
#endif /* CAWLBiQuadFilter_hpp */
