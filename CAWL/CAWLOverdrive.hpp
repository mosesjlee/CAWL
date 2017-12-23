/*
 CAWLOverdrive.hpp
 CAWL

 Created by Moses Lee on 10/21/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 CAWLOverdrive the 
*/

#ifndef CAWLOverdrive_hpp
#define CAWLOverdrive_hpp
#include "CAWLHighShelfFilter.hpp"

class CAWLOverdrive
{
public:
    CAWLOverdrive();
    ~CAWLOverdrive();
    void processBuffer(float * audioStreamBuf, const unsigned int numSamples);
	void adjustOverdriveTone(double newToneLevel);
    void adjustOverdriveGain(double newGainLevel);
private:
	double cGain;
	CAWLHighShelfFilter cToneControl;
};
#endif /* CAWLOverdrive_hpp */
