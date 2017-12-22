/*
 CAWLSoundModule.hpp
 CAWL

 Created by Moses Lee on 9/17/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLSoundModule
 This is the parent class that majority of sound modules inherit from
*/

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

    /*
     This the main processing callback function that all sound module must implement
     */
    virtual void processBuffer(float * audioStreambuf, const unsigned int numOfSamples) = 0;
    
    /*
     Function to set the sample rate. The default sample rate of the project
     is 44100 kHz
     */
    virtual void setSampleRate(float newSampleRate) { cSampleRate = newSampleRate; }
protected:
    float cSampleRate = DEFAULT_SR;
};
#endif /* CAWLSoundModules_hpp */
