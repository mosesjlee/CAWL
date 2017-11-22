//
//  CAWLWahWah.cpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLWahWah.hpp"
#include <math.h>

#define lfoskipsamples 30

#define MAX_WAH_CENTER_FREQ 2000
#define MIN_WAH_CENTER_FREQ 800
#define MAX_WAH_DEPTH_FREQ 500
#define MAX_WAH_MOD_RATE 2
#define MIN_WAH_MOD_RATE 0.75

#define epsilon 0.00000000001
CAWLWahWah::CAWLWahWah()
{
    triangeWave = new CAWLTriangleWaveOsc();
    triangeWave->setFreq(0.75);
	centerFrequency = 800;
    anchorFrequency = centerFrequency;
	freq = float(1.5);
	startphase = 0;
	depth = (float)0.7;
	freqofs = (float)0.3;
	res = float(2.5);
	mCurRate = 44100.0;
	lfoskip = freq * 2 * M_PI / mCurRate;
	phase = 0;
	
    //State Variable
    y_h = 0;
    y_b = 0;
    y_l = 0;
    y_b_n1 = 0;
    y_l_n1 = 0;
    max_y_b = 0.1;
    
    //Universal variables
    mixLevel = 1.0;
    modDepth = 400;
}

CAWLWahWah::~CAWLWahWah()
{
    delete triangeWave;
}

//https://searchcode.com/codesearch/view/20121801/ look at that
void CAWLWahWah::processBuffer(float * buf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double yCurrOutput = 0.0;
    double damp = 0.05;
    float frequency, omega, sn, cs, alpha;
    float in, out;
    
    for(int i = 0; i < numSamples; i++)
    {
#if 0
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
#else
        //F_1 = 2 * sin(M_PI * f_c/f_s)
        //Q_1 = 1/Q
        //y_h = x(n) - y_l(n-1) - Q_1 * y_b(n-1)
        //y_b = F_1 * y_h(n) + y_b(n-1)
        //y_l = F_1 * y_b(n) + y_l(n-1)
        xCurrSample = buf[i];
        double Q_1 = 2 * damp;
        double F_1 = 2 * sin(M_PI * (anchorFrequency)/sampleRate);
        
        y_h = xCurrSample - y_l_n1 - Q_1 * y_b_n1;
        y_b = F_1 * y_h + y_b_n1;
        y_l = F_1 * y_b + y_l_n1;
        y_b_n1 = y_b;
        y_l_n1 = y_l;
        if(max_y_b < fabs(y_b)) max_y_b = fabs(y_b);
        if(fabs(max_y_b) < epsilon) max_y_b = 1.0;
        
        buf[i] = (y_b/max_y_b * mixLevel) + (xCurrSample * (1.0f-mixLevel));
        anchorFrequency = (triangeWave->getNextSample() * modDepth) + centerFrequency;
#endif
    }
    
}

void CAWLWahWah::setCenterFreq(double newCenterFreq)
{
    if(newCenterFreq > MAX_WAH_CENTER_FREQ)
        centerFrequency = MAX_WAH_CENTER_FREQ;
    else if(newCenterFreq < MIN_WAH_CENTER_FREQ)
        centerFrequency = MIN_WAH_CENTER_FREQ;
    else
        centerFrequency = newCenterFreq;
}

void CAWLWahWah::setModulationDepth(double newModDepth)
{
    if(newModDepth > MAX_WAH_DEPTH_FREQ)
        modDepth = MAX_WAH_DEPTH_FREQ;
    else
        modDepth = newModDepth;
}

void CAWLWahWah::setMixLevel(double newMixLevel)
{
    if(newMixLevel > 1.0)
        mixLevel = 1.0;
    else if(newMixLevel < 0.0)
        mixLevel = 0.0;
    else
        mixLevel = newMixLevel;
}

void CAWLWahWah::setModulationRate(double newModLevel)
{
    if(newModLevel > MAX_WAH_MOD_RATE)
        triangeWave->setFreq(MAX_WAH_MOD_RATE);
    else if(newModLevel < MIN_WAH_MOD_RATE)
        triangeWave->setFreq(MIN_WAH_MOD_RATE);
    else
        triangeWave->setFreq(newModLevel);
}








