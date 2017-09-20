//
//  CAWLAmpSimulator.cpp
//  CAWL
//
//  Created by Moses Lee on 9/16/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLAmpSimulator.hpp"
#define kEPSILON 0.00000000001
CAWLAmpSimulator::CAWLAmpSimulator():
mVolume(0.6),
mGain(1.7),
mDistortion(8),
mMixLevel(0.5)
{
    
}

CAWLAmpSimulator::~CAWLAmpSimulator()
{
    
}

void CAWLAmpSimulator::processBuffer(float * buf, const unsigned int numOfSamples)
{
    float xCurrSample = 0.0;
    float qWorkPoint = -0.2;
    float yCurrOutput = 0.0;
    float zFactor = 0.0;
    float maxCurrSample = 0.0;
    float qLevel = 0.0;
    
    //Find the largest value
    maxCurrSample = fabs(buf[0]);
    for(unsigned i = 1; i < numOfSamples; i++)
    {
        if(maxCurrSample < fabs(buf[i]))
            maxCurrSample = fabs(buf[i]);
    }
    
    //Normalize the samples
    
    //Step through numOfSamples sample
    for(unsigned i = 0; i < numOfSamples; i++)
    {
        //Copy the sample over
        xCurrSample = buf[i];
        qLevel = xCurrSample * mGain/maxCurrSample;
        
        if(xCurrSample < (qWorkPoint + kEPSILON) && xCurrSample > (qWorkPoint - kEPSILON))
        {
            yCurrOutput = (1/mDistortion) + (qWorkPoint/(1 - exp(mDistortion * qWorkPoint)));
        }
        else
        {
            yCurrOutput = (qLevel - qWorkPoint)/(1 - exp(-(mDistortion) * (qLevel-qWorkPoint))) +
            (qWorkPoint/(1-exp(mDistortion * qWorkPoint)));
        }
    
        //Fill it back in the buffer
        if(yCurrOutput > 1.0)
            yCurrOutput = 1.0;
        if(yCurrOutput < -1.0)
            yCurrOutput = -1.0;
        //printf("%f\n", yCurrOutput);
        buf[i] = yCurrOutput * mMixLevel + xCurrSample * (1.0 - mMixLevel);
    }
}

void CAWLAmpSimulator::setGain(float newGain)
{
    if(newGain > 1.0)
        mGain = 1.0;
    else if(newGain < 0.0)
        mGain = 0.0;
    else
        mGain = newGain;
}

void CAWLAmpSimulator::setVolume(float newVolume)
{
    if(newVolume > 1.0)
        mVolume = 1.0;
    else if(newVolume < 0.0)
        mVolume = 0.0;
    else
        mVolume = newVolume;
}

void CAWLAmpSimulator::setDistortion(float newDistortion)
{
    if(newDistortion > 1.0)
        mDistortion = 1.0;
    else if(newDistortion < 0.0)
        mDistortion = 0.0;
    else
        mDistortion = newDistortion;
}

void CAWLAmpSimulator::setMixLevel(float newMixLevel)
{
    if(newMixLevel > 1.0)
        mMixLevel = 1.0;
    else if(newMixLevel < 0.0)
        mMixLevel = 0.0;
    else
        mMixLevel = newMixLevel;
}






