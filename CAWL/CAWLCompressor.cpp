//
//  CAWLCompressor.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLCompressor.hpp"
#include "CAWLSoundModule.hpp"
CAWLCompressor::CAWLCompressor()
{
    averageTime         = 0.015;
    attackTime          = 0.0;
    releaseTime         = 0.0;
    attackCoeff         = 0.0;
    releaseCoeff        = 0.0;
    compressorThreshold = 0.0;
    compressorRatio     = 0.0;
    compressorSlope     = 0.0;
    xrms                = 0.0;
    gain                = 1.0;
    kneeLevel           = 0.0;
    numeratorValue      = -2.2 * (1.0/DEFAULT_SR);
    makeupGain          = 1.0;
    
    delayLine.setDelayTimeInSamples(150);
}

CAWLCompressor::~CAWLCompressor()
{
    
}

inline double CAWLCompressor::min(double x, double y)
{
    return x < y ? x : y;
}

//From Udo Zölzer's DAFX page 112
void CAWLCompressor::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yCurrOut = 0.0;
    double coeff = 0.0;

    for(int i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i];
        xrms = (1.0 - averageTime) * xrms + averageTime * xCurrSample * xCurrSample;
        double X = 10 * log10(xrms);
        double G = min(0, (compressorSlope * (compressorThreshold - X)));
        double f = pow(10, G/20);
        if (f < gain)
            coeff = attackCoeff;
        else
            coeff = releaseCoeff;
        gain = (1.0 - coeff) * gain + coeff * f;
        yCurrOut = gain * delayLine.processNextSample(xCurrSample);
        buf[i] = yCurrOut;
    }
}

void CAWLCompressor::setAttackTime(double newAttackTime)
{
    if (newAttackTime < 0)
        attackTime = 0;
    else
        attackTime = newAttackTime;
    attackCoeff = 1 - exp(numeratorValue/(attackTime *.001));
//    attackCoeff = exp(log(0.01)/(attackTime * DEFAULT_SR * .001));
}

void CAWLCompressor::setReleaseTime(double newReleaseTime)
{
    if(newReleaseTime < 0)
        releaseTime = 0;
    else
        releaseTime = newReleaseTime;
    
    releaseCoeff = 1 - exp(numeratorValue/(releaseTime *.001));
//    attackCoeff = exp(log(0.01)/(releaseTime * DEFAULT_SR * .001));
}

void CAWLCompressor::setCompressorThreshold(double newThreshold)
{
    
    compressorThreshold = newThreshold;
}

void CAWLCompressor::setCompressorRatio(double newRatio)
{
    compressorRatio = newRatio;
    compressorSlope = 1.0 - (1.0/compressorRatio);
}


