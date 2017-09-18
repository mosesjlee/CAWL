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
#include "CAWLSoundModules.hpp"
class CAWLDelayLine : public CAWLSoundModule
{
public:
    CAWLDelayLine();
    ~CAWLDelayLine();
    void setDelayTime(unsigned int delayTime);
    void processBuffers(float * buf, const unsigned int numOfSamples);
    
private:
    float * delayLine;
    float currReadPos;
    float currWritePos;
    int currDelayInSamples;
    unsigned int maxDelayInSamples;
};
#endif /* CAWLDelayLine_hpp */
