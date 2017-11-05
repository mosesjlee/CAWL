//
//  CAWLSoundModule.hpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLSoundModule_hpp
#define CAWLSoundModule_hpp
#define DEFAULT_SR 44100.0f
#define MILLISECONDS 1000.0f
#include <stdio.h>
#include <iostream>
#include <cmath>

class CAWLSoundModule
{
public:
    virtual ~CAWLSoundModule(){};
    CAWLSoundModule(){};

    virtual void processBuffer(float * buf, const unsigned int numOfSamples) = 0;
    virtual void setSampleRate(float newSampleRate) { sampleRate = newSampleRate; }
protected:
    float sampleRate = DEFAULT_SR;
};
#endif /* CAWLSoundModules_hpp */
