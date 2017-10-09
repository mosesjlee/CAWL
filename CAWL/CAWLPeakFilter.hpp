//
//  CAWLPeakFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 10/6/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLPeakFilter_hpp
#define CAWLPeakFilter_hpp

#include <stdio.h>
#include "CAWLBiQuadFilter.hpp"

class CAWLPeakFilter : public CAWLBiQuadFilter
{
    double theta;
    double mu;
    double zeta;
    double beta;
    double gamma;
    double qFactor;
    
    void calculateCoefficients();
public:
    CAWLPeakFilter();
    ~CAWLPeakFilter();
    void setQFactor(float newQFactor);
};
#endif /* CAWLPeakFilter_hpp */
