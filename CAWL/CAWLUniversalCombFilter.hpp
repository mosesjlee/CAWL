//
//  CAWLUniversalCombFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 9/30/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLUniversalCombFilter_hpp
#define CAWLUniversalCombFilter_hpp

#include "CAWLCombFilter.hpp"

class CAWLUniversalCombFilter : public CAWLCombFilter
{
public:
    CAWLUniversalCombFilter();
    ~CAWLUniversalCombFilter();
    virtual void processBuffer(float * buf, const unsigned int numSamples);
    void setDryMix(double newDryMix);
    
protected:
    double dryMix;
};
#endif /* CAWLUniversalCombFilter_hpp */
