/*
 CAWLHighShelfFilter.hpp
 CAWL

 Created by Moses Lee on 10/5/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLHighShelfFilter. My implementation of high shelving
 filter based on Will Pirkle's equations for biquad
 filter coefficients from Designing Audio Effect Plug-ins in C++
 pg. 190
*/

#ifndef CAWLHighShelfFilter_hpp
#define CAWLHighShelfFilter_hpp

#include "CAWLBiQuadFilter.hpp"

class CAWLHighShelfFilter : public CAWLBiQuadFilter
{
public:
    CAWLHighShelfFilter();
    ~CAWLHighShelfFilter();
    
private:
    void calculateCoefficients();
};
#endif /* CAWLHighShelfFilter_hpp */
