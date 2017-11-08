//
//  CAWLBandPassFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 11/5/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLBandPassFilter_hpp
#define CAWLBandPassFilter_hpp

#include "CAWLBiQuadFilter.hpp"

class CAWLBandPassFilter : public CAWLBiQuadFilter
{
public:
    CAWLBandPassFilter();
    ~CAWLBandPassFilter();
    void setQFactor(double newQFactor);
private:
    void calculateCoefficients();
    double qFactor;
};

#endif /* CAWLBandPassFilter_hpp */
