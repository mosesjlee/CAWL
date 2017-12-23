//
//  CAWLCompressor.cpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLCompressor.hpp"
#include "CAWLSoundModule.hpp"
#define MIN_COMP_THRESHOLD
#define MAX_COMP_THRESHOLD

/*
 Default Constructor
 */
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

/*Default destructor*/
CAWLCompressor::~CAWLCompressor()
{
}

/*
 Returns the min of the 2 double values
 @param x -> the first value
 @param y -> the second value
 @return -> the bigger value
 */
inline double CAWLCompressor::min(double x, double y)
{
    return x < y ? x : y;
}

/*
 From Udo Zölzer's DAFX page 112. This is the main processing block
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLCompressor::processBuffer(float * audioStreamBuf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yCurrOut = 0.0;
    double coeff = 0.0;
    double currCompressorSlope = compressorSlope;
    for(int i = 0; i < numSamples; i++)
    {
        xCurrSample = audioStreamBuf[i];
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
        audioStreamBuf[i] = yCurrOut * makeupGain;
    }
}

/*
 Sets the new attack time of the compressor
 @param newAttackTime -> the new attack time of the compressor
 */
void CAWLCompressor::setAttackTime(double newAttackTime)
{
    if (newAttackTime < 0)
        attackTime = 0;
    else
        attackTime = newAttackTime;
    attackCoeff = 1 - exp(numeratorValue/(attackTime *.001));
//    attackCoeff = exp(log(0.01)/(attackTime * DEFAULT_SR * .001));
}

/*
 Sets the new release time of the compressor
 @param newReleaseTime -> the new release time
 */
void CAWLCompressor::setReleaseTime(double newReleaseTime)
{
    if(newReleaseTime < 0)
        releaseTime = 0;
    else
        releaseTime = newReleaseTime;
    
    releaseCoeff = 1 - exp(numeratorValue/(releaseTime *.001));
//    attackCoeff = exp(log(0.01)/(releaseTime * DEFAULT_SR * .001));
}

/*
 Sets the compressor threshold
 @param newThreshold -> the new compressor threshold
 */
void CAWLCompressor::setCompressorThreshold(double newThreshold)
{
    
    compressorThreshold = newThreshold;
}

/*
 Set compressor ratio
 @param newRatio -> the new compressor ratio
 */
void CAWLCompressor::setCompressorRatio(double newRatio)
{
    compressorRatio = newRatio;
    compressorSlope = 1.0 - (1.0/compressorRatio);
}

/*
 Set the knee level of the compressor
 @param newKneeLevel -> the new knee level
 */
void CAWLCompressor::setKneeLevel(double newKneeLevel)
{
    kneeLevel = newKneeLevel;
}

/*
 Set the make up gain
 @param newMakeupGain -> the new make up gain
 */
void CAWLCompressor::setMakeUpGain(double newMakeupGain)
{
    if(newMakeupGain < 0) makeupGain = 1;
    else makeupGain = newMakeupGain;
}


/*
 From Will Pirkle's plugin constants. This is his implementation of
 lagrange interpolation to calculate the points around the compressor
 knee
 @param x    -> the buffer that holds the x coordinates
 @param y    -> the buffer that holds the y coordinates
 @param n    -> size of the buffer
 @param xbar -> the sample in between
 @return -> the value in between the
 */
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

/*
 Algorithm from Will Pirkle's Designing Audio Effect Plugins pg. 460
 to calculate the knee sample around the knee.
 @param sample -> the current input sample
 @return the interpolated value
 */
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

