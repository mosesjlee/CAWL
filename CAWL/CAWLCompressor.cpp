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
    double currCompressorSlope = compressorSlope;
    for(int i = 0; i < numSamples; i++)
    {
        xCurrSample = buf[i];
        xrms = (1.0 - averageTime) * xrms + averageTime * xCurrSample * xCurrSample;
        double X = 10 * log10(xrms);
        if(kneeLevel > 0 && X > (compressorThreshold - kneeLevel/2.0) &&
           X < (compressorThreshold < compressorThreshold + kneeLevel/2.0))
            currCompressorSlope = calculateKneeGain(X);
        double G = min(0, (currCompressorSlope * (compressorThreshold - X)));
        double f = pow(10, G/20);
        if (f < gain)
            coeff = attackCoeff;
        else
            coeff = releaseCoeff;
        gain = (1.0 - coeff) * gain + coeff * f;
        yCurrOut = gain * delayLine.processNextSample(xCurrSample);
        buf[i] = yCurrOut * makeupGain;
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

void CAWLCompressor::setKneeLevel(double newKneeLevel)
{
    kneeLevel = newKneeLevel;
}

void CAWLCompressor::setMakeUpGain(double newMakeupGain)
{
    if(newMakeupGain < 0) makeupGain = 1;
    else makeupGain = newMakeupGain;
}

//From Will Pirkle's plugin constants. This is his implementation of
//lagrange interpolation
inline double lagrpol(double* x, double* y, int n, double xbar)
{
    int i,j;
    double fx=0.0;
    double l=1.0;
    for (i=0; i<n; i++)
    {
        l=1.0;
        for (j=0; j<n; j++)
        {
            if (j != i)
                l *= (xbar-x[j])/(x[i]-x[j]);
        }
        fx += l*y[i];
    }
    return (fx);
}

//Algorithm from Will Pirkle's Designing Audio Effect Plugins pg. 460
double CAWLCompressor::calculateKneeGain(double sample)
{
    double x[2] = {0.0, 0.0};
    double y[2] = {0.0, 0.0};
    x[0] = compressorThreshold - kneeLevel/2.0;
    x[1] = compressorThreshold + kneeLevel/2.0;
    x[1] = min(0, x[1]);
    y[0] = 0;
    y[1] = compressorSlope;
    
    //Perform lagrange
    return lagrpol(x, y, 2, sample);
}

