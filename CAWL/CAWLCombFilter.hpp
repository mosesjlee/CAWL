//
//  CAWLFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 9/30/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLFilter_hpp
#define CAWLFilter_hpp
#include <stdio.h>
#include "CAWLSoundModule.hpp"
#include "CAWLDelayLine.hpp"

class CAWLCombFilter : public CAWLSoundModule
{
public:
    virtual void setDelay(unsigned int delay);
    virtual void setGain(float gain);
    
protected:
    CAWLDelayLine delayLine;
    unsigned int delay;
    float lastSampleOfBlock;
    float mGain;
};



#endif /* CAWLFilter_hpp */
