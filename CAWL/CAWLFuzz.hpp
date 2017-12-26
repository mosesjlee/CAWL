/*
 CAWLFuzz.hpp
 CAWL

 Created by Moses Lee on 10/21/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLFuzz class emulates a harder distortion sound
 that sounds like a Fuzz effect pedal
*/

#ifndef CAWLFuzz_hpp
#define CAWLFuzz_hpp
#include "CAWLHighShelfFilter.hpp"
class CAWLFuzz
{
public:
    CAWLFuzz();
    ~CAWLFuzz();
    void processBuffer(float * audioStreamBuf, const unsigned int numSamples);
    void setGain(double newGain);
    void setMixLevel(double newMix);
	void adjustFuzzTone(double newToneLevel);
    
private:
    double cGain;
    double cMixLevel;
	CAWLHighShelfFilter cToneControl;
};
#endif /* CAWLFuzz_hpp */
