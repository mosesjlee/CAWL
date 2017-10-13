//
//  CAWLLowPassFilter.hpp
//
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLLowPassFilter_hpp
#define CAWLLowPassFilter_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "CAWLBiQuadFilter.hpp"

class CAWLLowPassFilter : public CAWLBiQuadFilter
{
private:
    void calculateCoefficients();
    
public:
    CAWLLowPassFilter(double cutOffFreq);
    CAWLLowPassFilter();
    ~CAWLLowPassFilter();
};

#endif /* simpleEq_hpp */
