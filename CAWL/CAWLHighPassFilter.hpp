//
//  CAWLHighPassFilter.hpp
//  SimpleOsc
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

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
    double theta_c;
    double omega;
    double kappa;
    double phi;
};

#endif /* simpleEq_hpp */
