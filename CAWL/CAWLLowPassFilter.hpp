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
#include "CAWLIIRCombFilter.hpp"

class CAWLLowPassFilter : public CAWLIIRCombFilter
{
private:
    float theta_c;
    float gamma;
    float a_0;
    float b_1;
    float cutOffFrequency;
    void calculateCoefficients();
    
public:
    CAWLLowPassFilter(float cutOffFreq);
    ~CAWLLowPassFilter();
    void changeCutOffFreq(float newFreq);
};

#endif /* simpleEq_hpp */
