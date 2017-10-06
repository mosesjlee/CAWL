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
#include "CAWLLowPassFilter.hpp"

class CAWLHighPassFilter : public CAWLIIRCombFilter
{
private:
    float theta_c;
    float gamma;
    float a_0;
    float b_1;
    float cutOffFrequency;
    void calculateCoefficients();
    
public:
    CAWLHighPassFilter(float cutOffFreq);
    ~CAWLHighPassFilter();
    void changeCutOffFreq(float newFreq);
    void setFeedbackGain(float newGain);
};

#endif /* simpleEq_hpp */
