//
//  CAWLDelayLine.cpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLDelayLine.hpp"

CAWLDelayLine::CAWLDelayLine():
maxDelayInSamples(8192), //About 18.5 seconds of delay
currReadPos(0),
currWritePos(0),
currDelayInSamples(0)
{
    delayLine = new float[maxDelayInSamples];
    
    //0 out the buffer
    for(int i = 0; i < maxDelayInSamples; i++)
        delayLine[i] = 0.0;
    
}


CAWLDelayLine::~CAWLDelayLine()
{
    delete [] delayLine;
}

void CAWLDelayLine::setDelayTime(unsigned int delayTime)
{
    //Input is in milliseconds so convert that to samples
    currDelayInSamples = delayTime * sampleRate/MILLISECONDS;
    
    //Update the read and write index
}

void CAWLDelayLine::processBuffers(float * buf, const unsigned int numOfSamples)
{
    float yCurrOutput = 0.0;
    for(int i = 0; i < numOfSamples; i++)
    {
        delayLine[currWritePos] = buf[i];
        yCurrOutput = delayLine[currReadPos];
        
        
        
        currReadPos = (++currReadPos) % maxDelayInSamples;
        currWritePos = (++currWritePos) % maxDelayInSamples;
        
        buf[i] = yCurrOutput;
    }
}



