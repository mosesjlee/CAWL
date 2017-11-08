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
#include <pthread.h>
class CAWLWahWah : public CAWLTimeVariableFilter
{
public:
    CAWLWahWah();
    ~CAWLWahWah();

    
private:
    CAWLBandPassFilter * bandPass;
};
#endif /* CAWLWahWah_hpp */
