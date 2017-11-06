//
//  CAWLPhaser.hpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLPhaser_hpp
#define CAWLPhaser_hpp
#include "CAWLTimeVariableFilter.hpp"
#include "CAWLNotchFilter.hpp"
class CAWLPhaser : public CAWLTimeVariableFilter
{
public:
    CAWLPhaser();
    ~CAWLPhaser();
    void processBuffer(float * buf, const unsigned int numSamples);
    
private:
    CAWLNotchFilter * notchFilter;
};

#endif /* CAWLPhaser_hpp */
