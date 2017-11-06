//
//  CAWLTimeVariableFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 11/6/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLTimeVariableFilter_hpp
#define CAWLTimeVariableFilter_hpp

#include "CAWLTriangleWaveOsc.hpp"

class CAWLTimeVariableFilter
{
public:
	void setTimeRate(double newRate);
	void setMixLevel(double newMixLevel);
	void processBuffer(float * buf, const unsigned int numSamples);
	
protected:
	CAWLTriangleWaveOsc * triangeWave;
	double centerFreq;
	double qFactor;
	double rate;
	double mixLevel;
};

#endif /* CAWLTimeVariableFilter_hpp */
