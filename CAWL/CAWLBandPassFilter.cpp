//
//  CAWLBandPassFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 11/5/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLBandPassFilter.hpp"

CAWLBandPassFilter::CAWLBandPassFilter()
{
    
}

CAWLBandPassFilter::~CAWLBandPassFilter()
{
    
}

void CAWLBandPassFilter::calculateCoefficients()
{
    double K = tan(M_PI * centerFrequency/sampleRate);
    qFactor = .707;//centerFrequency/sampleRate;
    a_0 = K/(K*K*qFactor + K + qFactor);
    a_1 = 0.0;
    a_2 = -a_0;
    b_1 = (2 * qFactor * (K*K -1))/(K*K*qFactor + K + qFactor);
    b_2 = (K*K*qFactor-K+qFactor)/(K*K*qFactor + K + qFactor);
    c_0 = 1.0;
    d_0 = 0.0;
}

void CAWLBandPassFilter::setQFactor(double newQFactor)
{
    qFactor = .707;
    calculateCoefficients();
}
