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
#include "CAWLBiQuadFilter.hpp"

class CAWLTimeVariableFilter : public CAWLBiQuadFilter
{
public:
	void setTimeRate(double newRate);
	void setMixLevel(double newMixLevel);
	virtual void processBuffer(float * buf, const unsigned int numSamples);
	void calculateCoefficients();
	
protected:
	CAWLTriangleWaveOsc * triangeWave;
	double qFactor;
	double rate;
	double mixLevel;
	
	//copied
	float freq;
	float startphase;
	float  depth;
	float  freqofs;
	float res;
	
	float b0;
	float b1;
	float b2;
	float a0;
	float a1;
	float a2;
	float mCurRate;
	float lfoskip;
	int skipcount = 0;
	float phase;
	float xn1;
	float xn2;
	float yn1;
	float yn2;
};

#endif /* CAWLTimeVariableFilter_hpp */
