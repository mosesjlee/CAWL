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
    void setDelayTimeInMilliseconds(float delayTime);
    void setDelayTimeInSamples(float delaySamples);
    double processNextSample(double currSample);
    
private:
    inline double linear_interp(float x_1, float y_1, float x_2, float y_2, float frac);
    
    double * delayLine;
    float currWritePos;
    float currDelayInSamples;
    float maxDelayInSamples;
};
#endif /* CAWLDelayLine_hpp */
