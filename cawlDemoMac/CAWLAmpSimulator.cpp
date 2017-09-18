//
//  CAWLAmpSimulator.cpp
//  CAWL
//
//  Created by Moses Lee on 9/16/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLAmpSimulator.hpp"

CAWLAmpSimulator::CAWLAmpSimulator():
mVolume(0.5),
mGain(0.5),
mDistortion(0.5),
mMixLevel(0.5)
{
    
}

CAWLAmpSimulator::~CAWLAmpSimulator()
{
    
}

void CAWLAmpSimulator::processBuffer(float * buf, const unsigned int numOfSamples)
{
    float xCurrSample = 0.0;
    float qLevel = 0.0;
    float qWorkPoint = 0.0;
    float yCurrOutput = 0.0;
    float zFactor = 0.0;
    float maxCurrSample = 0.0;
    float absMaxCurrSample = 0.0;
    
    maxCurrSample = buf[0];
    for(unsigned i = 1; i < numOfSamples; i++)
    {
        if(buf[i] > maxCurrSample)
            maxCurrSample = buf[i];
    }
    
    absMaxCurrSample = fabs(maxCurrSample);
    
    //Step through numOfSamples sample
    for(unsigned i = 0; i < numOfSamples; i++)
    {
        //Copy the sample over
        xCurrSample = buf[i];
        
        //Calculate the qLevel
        qLevel = xCurrSample * (mGain/absMaxCurrSample);
        
        
        if(qWorkPoint == 0.0)
        {
            if(qLevel == qWorkPoint)
                zFactor = 1.0/mDistortion;
            else
                zFactor = qLevel / (1 - exp(-(mDistortion) * qLevel));
        }
        else
        {
            float a = (qLevel - qWorkPoint)/(1-exp(-(mDistortion) * (qLevel - qWorkPoint)));
            float b = qWorkPoint/(1-exp(mDistortion*mDistortion));
            zFactor = a + b;
            
        }
        
        yCurrOutput = mMixLevel * zFactor * absMaxCurrSample/fabs(zFactor) + (1-mMixLevel) * xCurrSample;
        yCurrOutput = yCurrOutput * absMaxCurrSample/fabs(yCurrOutput);
        
        //Fill it back in the buffer
        buf[i] = yCurrOutput;
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






