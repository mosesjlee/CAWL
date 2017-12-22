/*
  CAWLIIRCombFilter.hpp
  CAWL

  Created by Moses Lee on 9/17/17.
  Copyright © 2017 Moses Lee. All rights reserved.
 CAWLIIRCombFilter. Inherits from CAWLCombFilter
 This is my implementation of an Infinite Impulse Response
 filter. Based on Udo Zölzer IIR Filter from DAFX book
 pg. 72
*/

#ifndef CAWLIIRCombFilter_hpp
#define CAWLIIRCombFilter_hpp
#include "CAWLCombFilter.hpp"

class CAWLIIRCombFilter : public CAWLCombFilter
{
public:
    CAWLIIRCombFilter();
    ~CAWLIIRCombFilter();
    void processBuffer(float * audioStreambuf, const unsigned int numSamples);
};
#endif /* CAWLIIRFilter_hpp */
