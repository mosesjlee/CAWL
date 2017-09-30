//
//  CAWLDelayLine.hpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLDelayLine_hpp
#define CAWLDelayLine_hpp

#include <stdio.h>
#include "CAWLSoundModule.hpp"
class CAWLDelayLine
{
public:
    CAWLDelayLine();
    ~CAWLDelayLine();
    void setDelayTime(unsigned int delayTime);
    float processNextSample(float currSample);
    
private:
    inline float linear_interp(float x_1, float y_1, float x_2, float y_2, float frac);
    
    float * delayLine;
    float currReadPos;
    float currWritePos;
    float currDelayInSamples;
    float maxDelayInSamples;
};
#endif /* CAWLDelayLine_hpp */
