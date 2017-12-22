//
//  CAWLPeakFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 10/6/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLPeakFilter.hpp"

/*
 Default constructor
 */
CAWLPeakFilter::CAWLPeakFilter()
{
}

/*
 Default destructor
 */
CAWLPeakFilter::~CAWLPeakFilter()
{
}

/*
 Calculates the coefficients for the biquad
 for a high shelf. Based on Udo Zölzer equations
 for biquad filter coefficients from DAFX pg. 66
 */
void CAWLPeakFilter::calculateCoefficients()
{
    //From üdo zolzer's book page 66
    double K = tan(M_PI * cCenterFrequency/cSampleRate);
    double volume = pow(10.0, cGain/20.0);
    double d_factor = 1 + (1/cQFactor) * K + K * K;
    double e_factor = 1 + (1/(cQFactor * volume)) * K + K * K;
    
    double alpha = 1 + volume/cQFactor * K + K * K;
    double beta = 2 * (K * K - 1.0);
    double gamma = 1 - volume/cQFactor * K + K * K;
    double phi = 1 - (1/cQFactor)*K + K * K;
    double eta = 1 - (1/(volume * cQFactor))*K + K * K;
    
    if(cGain >= 0.0)
    {
        a0     = alpha/d_factor;
        a1     = beta/d_factor;
        a2     = gamma/d_factor;
        b1     = beta/d_factor;
        b2     = phi/d_factor;
    }
    else
    {
        a0     = d_factor/e_factor;
        a1     = beta/e_factor;
        a2     = phi/e_factor;
        b1     = beta/e_factor;
        b2     = eta/e_factor;
    }
    c0 = 1.0;
    d0 = 0.0;
}

/*
 Sets the new q factor for the peak filter
 @param newQFactor -> the new q factor
 */
void CAWLPeakFilter::setQFactor(double newQFactor)
{
    cQFactor = newQFactor;
    calculateCoefficients();
}
