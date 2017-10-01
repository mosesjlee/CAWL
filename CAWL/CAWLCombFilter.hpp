//
//  CAWLFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 9/30/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLFilter_hpp
#define CAWLFilter_hpp
#include "CAWLSoundModule.hpp"
#include "CAWLDelayLine.hpp"
class CAWLCombFilter : public CAWLSoundModule
{
public:
    void processBuffer(float * buf, const unsigned int numSamples) = 0;
    void setDelay(unsigned int delay) { delayLine.setDelayTime(delay); }
    void setGain(float gain) { mGain = gain; };
protected:
    CAWLDelayLine delayLine;
    unsigned int delay;
    float mGain;
};

#include <stdio.h>

#endif /* CAWLFilter_hpp */
