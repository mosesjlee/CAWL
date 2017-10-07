//
//  CAWLHighShelfFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 10/5/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLHighShelfFilter.hpp"
CAWLHighShelfFilter::CAWLHighShelfFilter()
{
    
}

CAWLHighShelfFilter::~CAWLHighShelfFilter()
{
    
}

void CAWLHighShelfFilter::calculateCoefficients()
{
    theta   = 2 * M_PI * centerFrequency/sampleRate;
    mu      = pow(10.0, (double) mGain/20.0);
    beta    = (1.0 + mu)/4.0;
    delta   = beta * tan(theta/2.0);
    gamma   = (1.0 - delta)/(1.0 + delta);
    a_0     = (1 + gamma)/2.0;
    a_1     = -1.0 * ((1 + gamma)/2.0);
    a_2     = 0.0;
    b_1     = -1.0 * gamma;
    b_2     = 0.0;
    c_0     = mu - 1.0;
    d_0     = 1.0;
}


    
