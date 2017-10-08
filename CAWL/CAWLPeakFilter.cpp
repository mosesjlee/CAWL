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
    gamma   = (0.5 + beta) * (cos(theta));
    a_0     = 0.5 - beta;
    a_1     = 0.0;
    a_2     = -1.0 * (0.5 - beta);
    b_1     = -2.0 * gamma;
    b_2     = 2.0 * beta;
    c_0     = mu - 1.0;
#else
    d_0     = 1.0;

    //From üdo zolzer's book page 66
    double K = tan(M_PI * centerFrequency/sampleRate);
    double volume = pow(10.0, mGain/20.0);
    if(mGain > 0.0)
    {
        a_0     = ((1 + (volume/qFactor)*K) + K * K)/(1 + ((1.0/qFactor)*K) + K * K);
        a_1     = (2.0 * (K * K + 1.0))/(1 + ((1.0/qFactor)*K) + K * K);
        a_2     = ((1 - (volume/qFactor)*K) + K * K)/(1 + ((1.0/qFactor)*K) + K * K);
        b_1     = (2.0 * (K * K + 1.0))/(1 + ((1.0/qFactor)*K) + K * K);
        b_2     = (1 - ((1.0/qFactor)*K) + K * K)/(1 + ((1.0/qFactor)*K) + K * K);
        c_0     = (K - 1)/(K + 1);
    }
    else
    {
        a_0     = 0.5 - beta;
        a_1     = 0.0;
        a_2     = -1.0 * (0.5 - beta);
        b_1     = -2.0 * gamma;
        b_2     = 2.0 * beta;
        c_0     = (K - volume)/(K + volume);
    }
    
#endif
}

void CAWLPeakFilter::setQFactor(float newQFactor)
{
    qFactor = newQFactor;
    calculateCoefficients();
}
