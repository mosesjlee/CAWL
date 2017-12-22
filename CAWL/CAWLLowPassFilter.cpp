//
//  CAWLLowPassFilter.cpp
//  CAWLLowPassFilter
//
//  Created by Moses Lee on 10/4/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLLowPassFilter.hpp"

/*
 Default constructor. Set a default center frequency
 */
CAWLLowPassFilter::CAWLLowPassFilter()
{
    cGain = 0.0;                //Start at 0
    cCenterFrequency = 0.0;      //In Hz
    calculateCoefficients();
}

/*
 Default destructor.
 */
CAWLLowPassFilter::~CAWLLowPassFilter()
{
}

/*
 Calculate the coeffiencts. Based on Second Order Linkwitz-Rile Low Pass
 Filter found in Will Pirkle's equations for biquad filter coefficients
 from Designing Audio Effect Plug-ins in C++ pg. 186
 */
void CAWLLowPassFilter::calculateCoefficients()
{
    double thetaC = M_PI * cCenterFrequency/cSampleRate;
    double omega   = M_PI * cCenterFrequency;
    double kappa   = omega/tan(thetaC);
    double phi     = (kappa * kappa) + (omega * omega) + (2 * (kappa * omega));
    a0 = omega * omega/phi;
    a1 = 2 * omega * omega/phi;
    a2 = omega * omega / phi;
    b1 = ((-2 * kappa * kappa) + (2 * omega * omega))/phi;
    b2 = ((-2 * kappa * omega) + (kappa*kappa) + (omega * omega))/phi;
    c0 = 1.0;
    d0 = 0.0;
}


