/*
 CAWLLowPassFilter.hpp
 CAWL

 Created by Moses Lee on 10/4/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 CAWLLowPassFilter. This is my implementation of a low pass
 filter based on Second Order Linkwitz-Rile low Pass Filter
 found in Will Pirkle's equations for biquad filter coefficients
 from Designing Audio Effect Plug-ins in C++ pg. 186
*/

#ifndef CAWLLowPassFilter_hpp
#define CAWLLowPassFilter_hpp

#include "CAWLBiQuadFilter.hpp"

class CAWLLowPassFilter : public CAWLBiQuadFilter
{
public:
    CAWLLowPassFilter();
    ~CAWLLowPassFilter();
    
private:
    void calculateCoefficients();
};

#endif /* simpleEq_hpp */
