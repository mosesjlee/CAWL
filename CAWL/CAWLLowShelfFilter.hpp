/*
 CAWLLowShelfFilter.hpp
 CAWL

 Created by Moses Lee on 10/5/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLLowShelfFilter. My implementation of low shelving
 filter based on Will Pirkle's equations for biquad
 filter coefficients from Designing Audio Effect Plug-ins in C++
 pg. 190
*/

#ifndef CAWLLowShelfFilter_hpp
#define CAWLLowShelfFilter_hpp

#include "CAWLBiQuadFilter.hpp"

class CAWLLowShelfFilter : public CAWLBiQuadFilter
{
public:
    CAWLLowShelfFilter();
    ~CAWLLowShelfFilter();
    
private:
    void calculateCoefficients();
};

#endif /* CAWLLowShelfFilter_hpp */
