//
//  CAWLSoundModule.hpp
//  CAWL
//
//  Created by Moses Lee on 9/17/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLSoundModule_hpp
#define CAWLSoundModule_hpp
#define DEFAULT_SR 44100.0
#define MILLISECONDS 1000.0
#include <stdio.h>
#include <cmath>

class CAWLSoundModule
{
public:
    virtual void processBuffer(float * buf, const unsigned int numOfSamples) = 0;
    virtual void setSampleRate(float newSampleRate) { sampleRate = newSampleRate; }
    
protected:
    float sampleRate = DEFAULT_SR;
};
#endif /* CAWLSoundModules_hpp */
