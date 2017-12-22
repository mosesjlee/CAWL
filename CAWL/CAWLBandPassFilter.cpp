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
    double K = tan(M_PI * cCenterFrequency/cSampleRate);
    qFactor = 0.707;//centerFrequency/sampleRate;
    a0 = K/(K*K*qFactor + K + qFactor);
    a1 = 0.0;
    a2 = -a0;
    b1 = (2 * qFactor * (K*K -1))/(K*K*qFactor + K + qFactor);
    b2 = (K*K*qFactor-K+qFactor)/(K*K*qFactor + K + qFactor);
    c0 = 1;
    d0 = 0;
}

void CAWLBandPassFilter::setQFactor(double newQFactor)
{
    qFactor = .707;
    calculateCoefficients();
}
