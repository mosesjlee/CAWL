//
//  CAWLWahWah.hpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLWahWah_hpp
#define CAWLWahWah_hpp

#include "CAWLTimeVariableFilter.hpp"
#include "CAWLBandPassFilter.hpp"

class CAWLWahWah : public CAWLTimeVariableFilter
{
public:
    CAWLWahWah();
    ~CAWLWahWah();
    void processBuffer(float * buf, const unsigned int numSamples);
    
private:
    CAWLBandPassFilter * bandPass;
};
#endif /* CAWLWahWah_hpp */
