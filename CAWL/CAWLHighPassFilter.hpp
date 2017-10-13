//
//  CAWLHighPassFilter.hpp
//  SimpleOsc
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLHighPassFilter_hpp
#define CAWLHighPassFilter_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "CAWLBiQuadFilter.hpp"

class CAWLHighPassFilter : public CAWLBiQuadFilter
{
private:
    void calculateCoefficients();
    
public:
    CAWLHighPassFilter(double cutOffFreq);
    ~CAWLHighPassFilter();
};

#endif /* simpleEq_hpp */
