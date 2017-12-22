/*
 CAWLFIRCombFilter.hpp
 CAWL

 Created by Moses Lee on 9/17/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLFIRCombFilter. Inherits from CAWLCombFilter.
 This is my implementation of a Finite Impulse Response
 filter based on Udo Zölzer from DAFX book pg. 71
*/

#ifndef CAWLFIRCombFilter_hpp
#define CAWLFIRCombFilter_hpp

#include "CAWLCombFilter.hpp"

class CAWLFIRCombFilter : public CAWLCombFilter
{
public:
    CAWLFIRCombFilter();
    ~CAWLFIRCombFilter();
    void processBuffer(float * audioStreambuf, const unsigned int numSamples);
};
#endif /* CAWLFIRFilter_hpp */
