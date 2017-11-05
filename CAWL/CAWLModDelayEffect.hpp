//
//  CAWLModDelayEffect.hpp
//  CAWL
//
//  Created by Moses Lee on 10/28/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLModDelayEffect_hpp
#define CAWLModDelayEffect_hpp
#include "CAWLSineWaveOsc.hpp"
#include "CAWLUniversalCombFilter.hpp"

class CAWLModDelayEffect : public CAWLUniversalCombFilter
{
public:
    virtual void setMixLevel(double mixLevel);
    virtual void setModulationSpeed(double newModSpeed);
    virtual double modulatedTime() = 0;
    virtual void setModulationDepth(double newModDepth);
    virtual void processBuffer(float * buf, const unsigned int numSamples);
protected:
    CAWLSineWaveOsc * sine;
    double modDepth;
    double modSpeed;
    double mixLevel;
};

#endif /* CAWLModDelayEffect_hpp */
