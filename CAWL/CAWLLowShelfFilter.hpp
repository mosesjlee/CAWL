//
//  CAWLLowShelfFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 10/5/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLLowShelfFilter_hpp
#define CAWLLowShelfFilter_hpp

#include "CAWLBiQuadFilter.hpp"

class CAWLLowShelfFilter : public CAWLBiQuadFilter
{
public:
    CAWLLowShelfFilter();
    ~CAWLLowShelfFilter();
    
private:
    double theta;
    double mu;
    double beta;
    double delta;
    double gamma;
    
    void calculateCoefficients();
};

#endif /* CAWLLowShelfFilter_hpp */
