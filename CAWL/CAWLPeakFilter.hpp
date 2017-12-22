/*
 CAWLPeakFilter.hpp
 CAWL

 Created by Moses Lee on 10/6/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLPeakFilter. My implementation of peak filter based on
 Udo Zölzer equations for biquad filter coefficients from
 DAFX pg. 66
*/

#ifndef CAWLPeakFilter_hpp
#define CAWLPeakFilter_hpp

#include "CAWLBiQuadFilter.hpp"

class CAWLPeakFilter : public CAWLBiQuadFilter
{
public:
    CAWLPeakFilter();
    ~CAWLPeakFilter();
    void setQFactor(double newQFactor);
    
private:
    //Q Factor for the peak filter
    double cQFactor;
    
    void calculateCoefficients();
};
#endif /* CAWLPeakFilter_hpp */
