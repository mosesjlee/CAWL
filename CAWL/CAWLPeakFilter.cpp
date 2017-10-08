//
//  CAWLPeakFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 10/6/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLPeakFilter.hpp"
CAWLPeakFilter::CAWLPeakFilter()
{
    
}

CAWLPeakFilter::~CAWLPeakFilter()
{
    
}

void CAWLPeakFilter::calculateCoefficients()
{
#if 0
    theta   = 2 * M_PI * centerFrequency/sampleRate;
    mu      = pow(10.0, (double) mGain/20.0);
    zeta    = 4.0/(1.0 + mu);
    
    //Clamp for tan(pi/2)
    float tanArg = theta/(2.0 * qFactor);
    if(tanArg >= M_PI/2.0)
        tanArg = 0.95*M_PI/2.0;
    double num = 1.0 - (zeta * tan(tanArg));
    double den = 1.0 + (zeta * tan(tanArg));
    beta    = 0.5 * num/den;
    double cosTheta = cos(theta);
    gamma   = (0.5 + beta) * cosTheta;
    a_0     = 0.5 - beta;
    a_1     = 0.0;
    a_2     = -1.0 * (0.5 - beta);
    b_1     = -2.0 * gamma;
    b_2     = 2.0 * beta;
    c_0     = mu - 1.0;
    d_0     = 1.0;
#else

    //From üdo zolzer's book page 66
    double K = tan(M_PI * centerFrequency/sampleRate);
    double volume = pow(10.0, mGain/20.0);
    double d_factor = 1 + (1/qFactor) * K + K * K;
    double e_factor = 1 + (1/(qFactor * volume)) * K + K * K;
    
    double alpha = 1 + volume/qFactor * K + K * K;
    beta = 2 * (K * K - 1.0);
    gamma = 1 - volume/qFactor * K + K * K;
    double phi = 1 - (1/qFactor)*K + K * K;
    double eta = 1 - (1/(volume * qFactor))*K + K * K;
    
    if(mGain >= 0.0)
    {
        a_0     = alpha/d_factor;
        a_1     = beta/d_factor;
        a_2     = gamma/d_factor;
        b_1     = beta/d_factor;
        b_2     = phi/d_factor;
    }
    else
    {
        a_0     = d_factor/e_factor;
        a_1     = beta/e_factor;
        a_2     = phi/e_factor;
        b_1     = beta/e_factor;
        b_2     = eta/e_factor;
    }
    c_0 = 1.0;
    d_0 = 0.0;
#endif
    
}

void CAWLPeakFilter::setQFactor(float newQFactor)
{
    qFactor = newQFactor;
    calculateCoefficients();
}
