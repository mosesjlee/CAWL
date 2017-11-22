//
//  CAWLAllPassFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 11/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLAllPassFilter_hpp
#define CAWLAllPassFilter_hpp

#include <stdio.h>
#include "CAWLBiQuadFilter.hpp"

class CAWLAllPassFilter : public CAWLBiQuadFilter
{
public:
    CAWLAllPassFilter();
    ~CAWLAllPassFilter();
    void processBuffer(float * buf, const unsigned int numSamples);
    double processNextSample(double inputSample);
    
protected:
    void calculateCoefficients();
};

#endif /* CAWLAllPassFilter_hpp */
