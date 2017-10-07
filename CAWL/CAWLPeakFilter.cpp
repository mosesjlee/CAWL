//
//  CAWLPeakFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 10/6/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLPeakFilter.hpp"

void CAWLPeakFilter::calculateCoefficients()
{
    theta   = 2 * M_PI * centerFrequency/sampleRate;
    mu      = pow(10.0, (double) mGain/20.0);
    zeta    = 4.0/(1 + mu);
    beta    = 0.5 * (1-zeta*tan(theta/2 * qFactor))/(1 + zeta * tan(theta/2 * qFactor));
    gamma   = (0.5 + beta) * cos(theta);
}
