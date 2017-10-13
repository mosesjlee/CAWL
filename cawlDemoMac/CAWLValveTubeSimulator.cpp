//
//  CAWLAmpSimulator.cpp
//  CAWL
//
//  Created by Moses Lee on 9/16/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLValveTubeSimulator.hpp"
CAWLValveTubeSimulator::CAWLValveTubeSimulator():
mMixLevel(1.0),
mGain(1)
{
}

CAWLValveTubeSimulator::~CAWLValveTubeSimulator()
{
}

/*
 * This is David Yeh and Jyri Pakarinen's way of asymetrical clipping
 * This code is from Computer Music Journal from the article:
 * A Review of Digital Techniques for Modeling Vacuum-Tube Guitar Amplifiers
 * This is not original work from me.
 */
void CAWLValveTubeSimulator::processBuffer(float * buf, const unsigned int numOfSamples)
{
    double xCurrSample = 0.0;
    double upperLimit = 0.320018;
    double lowerLimit = -0.08905;
    double upperClipVal = 0.630035;
    double gainCoeff = 3.9375;
    double correctCoeff = -6.153;
    double peakSample = fabs(buf[0]);
    
    for(unsigned i = 0; i < numOfSamples; i++)
    {
        peakSample = fabs(buf[i]) > peakSample ? fabs(buf[i]) : peakSample;
    }
    
    
    for(unsigned i = 0; i < numOfSamples; i++)
    {
        xCurrSample = (buf[i] * mGain)/peakSample;
        if(xCurrSample >= upperLimit)
        {
            xCurrSample = upperClipVal;
        }
        else if (xCurrSample >= lowerLimit && xCurrSample < upperLimit)
        {
            xCurrSample = correctCoeff * xCurrSample * xCurrSample + gainCoeff * xCurrSample;
        }
        else if(xCurrSample >= -1.0 && xCurrSample <= lowerLimit)
        {
            double a = (1-pow((1-(fabs(xCurrSample) - 0.032847)),12));
            double b = (1.0/3.0) * (fabs(xCurrSample)-0.032847);
            xCurrSample = -0.75*(a + b) + 0.01;
        }
        
        //For some reason the low mix level of the tube simulator yields the best results
        buf[i] = xCurrSample * mMixLevel + buf[i] * (1-mMixLevel);
        xCurrSample = 0.0;
    }
}


