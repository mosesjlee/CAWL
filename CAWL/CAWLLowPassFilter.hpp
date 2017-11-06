//
//  CAWLLowPassFilter.hpp
//
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLLowPassFilter_hpp
#define CAWLLowPassFilter_hpp

#include "CAWLBiQuadFilter.hpp"

class CAWLLowPassFilter : public CAWLBiQuadFilter
{
public:
    CAWLLowPassFilter();
    ~CAWLLowPassFilter();
    
private:
    void calculateCoefficients();
};

#endif /* simpleEq_hpp */
