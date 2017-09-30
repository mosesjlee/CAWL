//
//  CAWLFIRCombFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLFIRCombFilter_hpp
#define CAWLFIRCombFilter_hpp

#include <stdio.h>
#include "CAWLCombFilter.hpp"

class CAWLFIRCombFilter : public CAWLCombFilter
{
public:
    CAWLFIRCombFilter();
    ~CAWLFIRCombFilter();
    void processBuffer(float * buf, const unsigned int numSamples);
    void setNewDelay(float delay);
};
#endif /* CAWLFIRFilter_hpp */
