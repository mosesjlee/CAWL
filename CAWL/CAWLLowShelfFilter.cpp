//
//  CAWLLowShelfFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 10/5/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLLowShelfFilter.hpp"
CAWLLowShelfFilter::CAWLLowShelfFilter()
{
    cGain = 0.0;                //Start at 0
    cCenterFrequency = 0.0;      //In Hz
    calculateCoefficients();
}

CAWLLowShelfFilter::~CAWLLowShelfFilter()
{
    
}

/*
 Calculates the biquad coefficients.  CAWLLowShelfFilter.
 Based on Will Pirkle's equations for biquad filter coefficients
 from Designing Audio Effect Plug-ins in C++ pg. 190
 */
void CAWLLowShelfFilter::calculateCoefficients()
{
    double theta = 2 * M_PI * cCenterFrequency/cSampleRate;
    double mu    = pow(10.0, (double) cGain/20.0);
    double beta  = 4/(1.0 + mu);
    double delta = beta * tan(theta/2.0);
    double gamma = (1.0 - delta)/(1.0 + delta);
    a0           = (1.0 - gamma)/2.0;
    a1           = a0;
    a2           = 0.0;
    b1           = -1 * gamma;
    b2           = 0.0;
    c0           = mu - 1.0;
    d0           = 1.0;
}


