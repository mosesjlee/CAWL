//
//  CAWLOverdrive.cpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLOverdrive.hpp"
#include <math.h>
CAWLOverdrive::CAWLOverdrive()
{
    
}

CAWLOverdrive::~CAWLOverdrive()
{
    
}

//From Udo Zölzer's book DAFX page 125
void CAWLOverdrive::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double absSample = 0.0;
    double yCurrOutput = 0.0;
    
    for(int i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i];
        absSample = fabs(absSample);
        if(absSample >= 0.0 && absSample <= (1.0/3.0))
            yCurrOutput = 2.0 * xCurrSample;
        if(absSample >= (1.0/3.0) && absSample <= (2.0/3.0))
            yCurrOutput = (3.0-(2.0 - 3.0 * xCurrSample) * (2.0 - 3.0 * xCurrSample))/3.0;
        if(absSample >= (2.0/3.0) && absSample <= 1.0)
            yCurrOutput = xCurrSample < 0.0 ? -1.0 : 1.0;
    }
}
