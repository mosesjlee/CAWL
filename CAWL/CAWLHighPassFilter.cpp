//
//  CAWLHighPassFilter.cpp
//  SimpleOsc
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLHighPassFilter.hpp"

CAWLHighPassFilter::CAWLHighPassFilter()
{
    centerFrequency = 120;
    calculateCoefficients();
}

CAWLHighPassFilter::~CAWLHighPassFilter()
{
}

void CAWLHighPassFilter::calculateCoefficients()
{
    theta_c  = M_PI * centerFrequency/sampleRate;
    omega    = M_PI * centerFrequency;
    kappa    = omega/tan(theta_c);
    phi      = (kappa * kappa) + (omega * omega) + (2 * (kappa * omega));
    a_0 = kappa * kappa/phi;
    a_1 = -2 * kappa * kappa/phi;
    a_2 = kappa * kappa / phi;
    b_1 = ((-2 * kappa * kappa) + (2 * omega * omega))/phi;
    b_2 = ((-2 * kappa * omega) + (kappa*kappa) + (omega * omega))/phi;
    c_0 = 1.0;
    d_0 = 0.0;
}
