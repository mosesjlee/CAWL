//
//  CAWLHighShelfFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 10/5/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLHighShelfFilter_hpp
#define CAWLHighShelfFilter_hpp

#include <stdio.h>
#include "CAWLBiQuadFilter.hpp"

class CAWLHighShelfFilter : public CAWLBiQuadFilter
{
    double theta;
    double mu;
    double beta;
    double delta;
    double gamma;
    float centerFrequency;
    float mGain;

    void calculateCoefficients();

public:
    CAWLHighShelfFilter();
    ~CAWLHighShelfFilter();
    void setGain(float newGain);
    void setCutOffFreq(float newFreq);
};
#endif /* CAWLHighShelfFilter_hpp */
