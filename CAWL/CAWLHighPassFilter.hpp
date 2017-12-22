/*
 CAWLHighPassFilter.hpp
 CAWL

 Created by Moses Lee on 10/4/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLHighPassFilter. This is my implementation of a high pass
 filter based on Second Order Linkwitz-Rile High Pass Filter
 found in Will Pirkle's equations for biquad filter coefficients
 from Designing Audio Effect Plug-ins in C++ pg. 186
*/

#ifndef CAWLHighPassFilter_hpp
#define CAWLHighPassFilter_hpp

#include "CAWLBiQuadFilter.hpp"

class CAWLHighPassFilter : public CAWLBiQuadFilter
{
public:
    CAWLHighPassFilter();
    ~CAWLHighPassFilter();
    
private:    
    void calculateCoefficients();
};

#endif /* simpleEq_hpp */
