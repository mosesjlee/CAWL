/*
 CAWLModDelayEffect.hpp
 CAWL

 Created by Moses Lee on 10/28/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLModDelayEffect class is the base class for classes
 that utilize modulated delay effects. 
*/

#ifndef CAWLModDelayEffect_hpp
#define CAWLModDelayEffect_hpp
#include "CAWLSineWaveOsc.hpp"
#include "CAWLUniversalCombFilter.hpp"

class CAWLModDelayEffect : public CAWLUniversalCombFilter
{
public:
    virtual void setMixLevel(double mixLevel);
    virtual void setModulationSpeed(double newModSpeed);
    virtual void setModulationDepth(double newModDepth);
    
    
    virtual void processBuffer(float * buf, const unsigned int numSamples);
    
    virtual double modulatedTime() = 0;
protected:
    CAWLSineWaveOsc * sine;
    double cModDepth;
    double cModSpeed;
    double cMixLevel;
};

#endif /* CAWLModDelayEffect_hpp */
