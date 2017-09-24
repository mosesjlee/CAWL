//
//  CAWLAmpSimulator.cpp
//  CAWL
//
//  Created by Moses Lee on 9/16/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLValveTubeSimulator.hpp"
#define kMaxGainLevel 0.0050
#define kMinGainLevel 0.0001
CAWLValveTubeSimulator::CAWLValveTubeSimulator():
mGain(kMinGainLevel)
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
    
    
    for(unsigned i = 0; i < numOfSamples; i++)
    {
        xCurrSample = buf[i];
        //if(xCurrSample <= 1.0 && xCurrSample >= 0.320018)
        if(xCurrSample <= 1.0 && xCurrSample >= upperLimit)
        {
            xCurrSample = upperClipVal;
        }
        else if (xCurrSample >= lowerLimit && xCurrSample < 0.907423989749)
        {
            xCurrSample = correctCoeff * xCurrSample * xCurrSample + gainCoeff * xCurrSample;
        }
        else if(xCurrSample >= -1.0 && xCurrSample <= lowerLimit)
        {
            float a = -.75*(1-pow((1-(fabs(xCurrSample) - 0.032847)),12));
            float b = (1.0/3.0) * (fabs(xCurrSample)-0.032847);
            xCurrSample = a + b + 0.01;
        }
        else if(xCurrSample < -1.0)
        {
            xCurrSample = -0.9818;
        }
    
        //For some reason the low mix level of the tube simulator yields the best results
        buf[i] = xCurrSample * mGain + buf[i] * (1-mGain);
    }
}

//This will blend in the amount of valve simulation
//This acts like a gain for our purposes
void CAWLValveTubeSimulator::setGain(float newGain)
{
    if(newGain > 1.0)
        mGain = 1.0;
    else if(newGain < 0.0)
        mGain = 0.0;
    else
        mGain = newGain * kMaxGainLevel;
}






