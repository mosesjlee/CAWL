//
//  CAWLLowShelfFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 10/5/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLLowShelfFilter_hpp
#define CAWLLowShelfFilter_hpp

#include <stdio.h>
#include "CAWLBiQuadFilter.hpp"

class CAWLLowShelfFilter : public CAWLBiQuadFilter
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
    CAWLLowShelfFilter();
    ~CAWLLowShelfFilter();
    void setGain(float newGain);
    void setCutOffFreq(float newFreq);
};

#endif /* CAWLLowShelfFilter_hpp */
