//
//  CAWLBiQuadFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLBiQuadFilter_hpp
#define CAWLBiQuadFilter_hpp

#include <stdio.h>
#include "CAWLDelayLine.hpp"
#include "CAWLSoundModule.hpp"

class CAWLBiQuadFilter : public CAWLSoundModule
{
public:
    CAWLBiQuadFilter();
    ~CAWLBiQuadFilter();
private:
    CAWLDelayLine delayLine;
}

#endif /* CAWLBiQuadFilter_hpp */
