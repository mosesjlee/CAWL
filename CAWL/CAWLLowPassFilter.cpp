//
//  CAWLLowPassFilter.cpp
//  CAWLLowPassFilter
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLLowPassFilter.hpp"
CAWLLowPassFilter::CAWLLowPassFilter(double cutOffFreq)
{
    centerFrequency = cutOffFreq; //Default;
    calculateCoefficients();
}

CAWLLowPassFilter::CAWLLowPassFilter()
{
    
}

CAWLLowPassFilter::~CAWLLowPassFilter()
{
}

void CAWLLowPassFilter::calculateCoefficients()
{
    double theta_c         = M_PI * centerFrequency/sampleRate;
    double omega    = M_PI * centerFrequency;
    double kappa    = omega/tan(theta_c);
    double phi      = (kappa * kappa) + (omega * omega) + (2 * (kappa * omega));
    a_0 = omega * omega/phi;
    a_1 = 2 * omega * omega/phi;
    a_2 = omega * omega / phi;
    b_1 = ((-2 * kappa * kappa) + (2 * omega * omega))/phi;
    b_2 = ((-2 * kappa * omega) + (kappa*kappa) + (omega * omega))/phi;
    c_0 = 1.0;
    d_0 = 0.0;
}


