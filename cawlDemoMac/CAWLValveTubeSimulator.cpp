//
//  CAWLAmpSimulator.cpp
//  CAWL
//
//  Created by Moses Lee on 9/16/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLValveTubeSimulator.hpp"
CAWLValveTubeSimulator::CAWLValveTubeSimulator():
mMixLevel(0.5),
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
    float xCurrSample = 0.0;
    float upperLimit = 0.320018;
    float lowerLimit = -0.08905;
    float upperClipVal = 0.630035;
    float gainCoeff = 3.9375;
    float correctCoeff = -6.153;
    float peakSample = fabs(buf[0]);
    
    for(unsigned i = 1; i < numOfSamples; i++)
    {
        peakSample = fabs(buf[i]) > peakSample ? fabs(buf[i]) : peakSample;
    }
    
    //if(peakSample < 0.001) peakSample *= ;
    for(unsigned i = 0; i < numOfSamples; i++)
    {
        xCurrSample = (buf[i] * 0.5)/peakSample;
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
            float a = (1-pow((1-(fabs(xCurrSample) - 0.032847)),12));
            float b = (1.0/3.0) * (fabs(xCurrSample)-0.032847);
            xCurrSample = -0.75*(a + b) + 0.01;
        }
        
        //For some reason the low mix level of the tube simulator yields the best results
        buf[i] = xCurrSample * mMixLevel + buf[i] * (1-mMixLevel);
        xCurrSample = 0.0;
    }
}






