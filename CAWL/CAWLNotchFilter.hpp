//
//  CAWLNotchFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 11/5/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLNotchFilter_hpp
#define CAWLNotchFilter_hpp

#include "CAWLBiQuadFilter.hpp"

class CAWLNotchFilter : public CAWLBiQuadFilter
{
public:
    CAWLNotchFilter();
    ~CAWLNotchFilter();
private:
    void calculateCoefficients();
};

#endif /* CAWLNotchFilter_hpp */
