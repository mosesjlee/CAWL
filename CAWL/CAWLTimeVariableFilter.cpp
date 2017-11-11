//
//  CAWLTimeVariableFilter.cpp
//  CAWL
//
//  Created by Moses Lee on 11/6/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLTimeVariableFilter.hpp"
#define lfoskipsamples 30

void CAWLTimeVariableFilter::setTimeRate(double newRate)
{
	triangeWave->setFreq(newRate);
	
}

void CAWLTimeVariableFilter::setMixLevel(double newMixLevel)
{
	mixLevel = newMixLevel;
}

//https://searchcode.com/codesearch/view/20121801/ look at that
void CAWLTimeVariableFilter::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yCurrOutput = 0.0;
	float frequency, omega, sn, cs, alpha;
	float in, out;
	centerFrequency = 5000;
	for(int i = 0; i < numSamples; i++)
	{
//		xCurrSample = buf[i];
//		x_a_0 = xCurrSample * a_0;
//		yCurrOutput = (x_a_0 + delayedSample1);
//		x_a_1 = xCurrSample * a_1;
//		x_a_2 = xCurrSample * a_2;
//		x_b_1 = yCurrOutput * (b_1 * -1);
//		x_b_2 = yCurrOutput * (b_2 * -1);
//		
//		delayedSample1 = x_a_1 + delayedSample2 + x_b_1;
//		delayedSample2 = x_a_2 + x_b_2;
//		buf[i] = yCurrOutput * c_0 + xCurrSample * d_0;
//		centerFrequency = triangeWave->getNextSample() * 3000 + 5000;
//		calculateCoefficients();

			in = buf[i];
			
			if ((skipcount++) % lfoskipsamples == 0) {
				frequency = (1 + cos(skipcount * lfoskip + phase)) / 2;
				frequency = frequency * depth * (1 - freqofs) + freqofs;
				frequency = exp((frequency - 1) * 6);
				omega = M_PI * frequency;
				sn = sin(omega);
				cs = cos(omega);
				alpha = sn / (2 * res);
				b0 = (1 - cs) / 2;
				b1 = 1 - cs;
				b2 = (1 - cs) / 2;
				a0 = 1 + alpha;
				a1 = -2 * cs;
				a2 = 1 - alpha;
			};
			out = (b0 * in + b1 * xn1 + b2 * xn2 - a1 * yn1 - a2 * yn2) / a0;
			xn2 = xn1;
			xn1 = in;
			yn2 = yn1;
			yn1 = out;
			
			// Prevents clipping
			if (out < -1.0)
				out = float(-1.0);
			else if (out > 1.0)
				out = float(1.0);
			
			buf[i] = (float) out;
	}

}

void CAWLTimeVariableFilter::calculateCoefficients()
{
	double K = tan(M_PI * centerFrequency/sampleRate);
	qFactor = .707;//centerFrequency/sampleRate;
	a_0 = K/(K*K*qFactor + K + qFactor);
	a_1 = 0.0;
	a_2 = -a_0;
	b_1 = (2 * qFactor * (K*K -1))/(K*K*qFactor + K + qFactor);
	b_2 = (K*K*qFactor-K+qFactor)/(K*K*qFactor + K + qFactor);
	c_0 = 1;
	d_0 = 0.0;
}
