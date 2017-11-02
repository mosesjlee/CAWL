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
    void setModulationDepth(double newModDepth);
    void setMixLevel(double mixLevel);
    void setModulationSpeed(double newModSpeed);
    void processBuffer(float * buf, const unsigned int numSamples);
    double flangedValue();
private:
    CAWLSineWaveOsc * sine;
    double modDepth;
    double modSpeed;
    double mixLevel;
};

#endif /* CAWLModDelayEffect_hpp */
