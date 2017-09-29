//
//  CAWLAmpSimulator.hpp
//  cawlTester
//
//  Created by Moses Lee on 9/24/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

/*
 The signal processing algorithms and constants in this class is taken directly from
 http://quitte.de/dsp/caps.html source code. The 2 major authors in this set
 of source code are Tim Goetze and David Yeh. In particular I took the portions
 of the ToneStack model created and implemented by David Yeh from Stanford University's
 CCRMA to fit my design. None of the algorithms and constant is my own and
 I give full credit to the names mentioned above. I will explicitly denote all the components
 that I ported over from the original source code.
 */
#ifndef CAWLAmpSimulator_hpp
#define CAWLAmpSimulator_hpp

#include <stdio.h>
#include "CAWLSoundModule.hpp"
#include "CAWLValveTubeSimulator.hpp"
#include "HighPassFilter.hpp"
class ToneStack;
class HP1;
class DCBlocker;
class CAWLAmpSimulator : public CAWLSoundModule
{
public:
    CAWLAmpSimulator();
    CAWLAmpSimulator(int model);
    ~CAWLAmpSimulator();
	virtual void processBuffer(float * buf, const unsigned int numOfSamples);
  
private:
    CAWLValveTubeSimulator valveTube;
	ToneStack * stack;
    HP1 * dc;
    HighPassFilter hp1;
	DCBlocker * dcBlocker, * dcBlocker2;
};
#endif /* CAWLAmpSimulator_hpp */
