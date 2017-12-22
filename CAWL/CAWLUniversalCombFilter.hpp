/*
  CAWLUniversalCombFilter.hpp
  CAWL

  Created by Moses Lee on 9/30/17.
  Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLUniversalCombFilter. Inherits from CAWLCombFilter
 This is my implementation of the Universal combfilter based on the
 diagrams from Udo Zölzer DAFX Book pg. 73 
*/

#ifndef CAWLUniversalCombFilter_hpp
#define CAWLUniversalCombFilter_hpp

#include "CAWLCombFilter.hpp"

class CAWLUniversalCombFilter : public CAWLCombFilter
{
public:
    CAWLUniversalCombFilter();
    ~CAWLUniversalCombFilter();
    virtual void processBuffer(float * audioStreambuf, const unsigned int numSamples);
    void setDryMix(double newDryMix);
    
protected:
    double cDryMix;
};
#endif /* CAWLUniversalCombFilter_hpp */
