//
//  CAWLIIRCombFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLIIRCombFilter_hpp
#define CAWLIIRCombFilter_hpp
#include "CAWLCombFilter.hpp"
#include <stdio.h>
class CAWLIIRCombFilter : public CAWLCombFilter
{
public:
    CAWLIIRCombFilter();
    ~CAWLIIRCombFilter();
    void processBuffer(float * buf, const unsigned int numSamples);
private:
    float mMixLevel;
    CAWLDelayLine delayLine;
};
#endif /* CAWLIIRFilter_hpp */
