/*
 CAWLAmpSimulator.hpp
 cawlTester

 Created by Moses Lee on 9/24/17.
 Copyright © 2017 Moses Lee. All rights reserved.
*/

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

#include "CAWLValveTubeSimulator.hpp"
#include "CAWLHighPassFilter.hpp"
#include "CAWLLowShelfFilter.hpp"

class CAWLAmpSimulator : public CAWLSoundModule
{
public:
    CAWLAmpSimulator();
    CAWLAmpSimulator(int model);
    ~CAWLAmpSimulator();
	virtual void processBuffer(float * buf, const unsigned int numOfSamples);
    void setGain(float gain);
	void setAmpBass(double newBass);
	void setAmpMid(double newMid);
	void setAmpTreble(double newTreble);
	void setAmpModel(int model);
  
private:
    CAWLValveTubeSimulator valveTube;
    CAWLHighPassFilter hp1;
    CAWLLowShelfFilter lsf;
	double cAmpBass;
	double cAmpMid;
	double cAmpTreble;
};
#endif /* CAWLAmpSimulator_hpp */
