//
//  CAWLWahWah.cpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLWahWah.hpp"
#include <math.h>

#define MAX_WAH_CENTER_FREQ 1400
#define MIN_WAH_CENTER_FREQ 800
#define MAX_WAH_DEPTH_FREQ 500
#define MAX_WAH_MOD_RATE 2
#define MIN_WAH_MOD_RATE 0.75

#define epsilon 0.00000000001

/*
 Default constructor
 */
CAWLWahWah::CAWLWahWah()
{
    //Initialize the Triangle Wave Oscillator
    triangeWave = new CAWLTriangleWaveOsc();
    triangeWave->setWaveTableFreq(0.75);
	centerFrequency = 800;
    anchorFrequency = centerFrequency;
	
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

/*
 Default destructor
 */
CAWLWahWah::~CAWLWahWah()
{
    delete triangeWave;
}

/*
 Main processing block. The State variable filter is adapted from
 Udo Zölzer's DAFX pg. 50
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLWahWah::processBuffer(float * audioStreamBuf, const unsigned int numSamples)
{
    double xCurrSample = 0.0;
    double damp = 0.05;
    
    for(int i = 0; i < numSamples; i++)
    {
        //F_1 = 2 * sin(M_PI * f_c/f_s)
        //Q_1 = 1/Q
        //y_h = x(n) - y_l(n-1) - Q_1 * y_b(n-1)
        //y_b = F_1 * y_h(n) + y_b(n-1)
        //y_l = F_1 * y_b(n) + y_l(n-1)
        xCurrSample = audioStreamBuf[i];
        double Q_1 = 2 * damp;
        double F_1 = 2 * sin(M_PI * (anchorFrequency)/cSampleRate);
        
        y_h = xCurrSample - y_l_n1 - Q_1 * y_b_n1;
        y_b = F_1 * y_h + y_b_n1;
        y_l = F_1 * y_b + y_l_n1;
        y_b_n1 = y_b;
        y_l_n1 = y_l;
        if(max_y_b < fabs(y_b)) max_y_b = fabs(y_b);
        if(fabs(max_y_b) < epsilon) max_y_b = 1.0;
        
        audioStreamBuf[i] = (y_b/max_y_b * mixLevel) + (xCurrSample * (1.0f-mixLevel));
        anchorFrequency = (triangeWave->getNextSample() * modDepth) + centerFrequency;
    }
    
}

/*
 Set the center frequency of the Wah
 @param newCenterFreq -> the new center frequency
 */
void CAWLWahWah::setCenterFreq(double newCenterFreq)
{
    if(newCenterFreq > MAX_WAH_CENTER_FREQ)
        centerFrequency = MAX_WAH_CENTER_FREQ;
    else if(newCenterFreq < MIN_WAH_CENTER_FREQ)
        centerFrequency = MIN_WAH_CENTER_FREQ;
    else
        centerFrequency = newCenterFreq;
}

/*
 Set the new modulation depth
 @param newModDepth -> the new modulation depth
 */
void CAWLWahWah::setModulationDepth(double newModDepth)
{
    if(newModDepth > MAX_WAH_DEPTH_FREQ)
        modDepth = MAX_WAH_DEPTH_FREQ;
    else
        modDepth = newModDepth;
}

/*
 Set the new mix level
 @param newMixLevel -> the new mix level
 */
void CAWLWahWah::setMixLevel(double newMixLevel)
{
    if(newMixLevel > 1.0)
        mixLevel = 1.0;
    else if(newMixLevel < 0.0)
        mixLevel = 0.0;
    else
        mixLevel = newMixLevel;
}

/*
 Set modulation rate
 @param newModLevel -> the new modulation level
 */
void CAWLWahWah::setModulationRate(double newModLevel)
{
    if(newModLevel > MAX_WAH_MOD_RATE)
        triangeWave->setWaveTableFreq(MAX_WAH_MOD_RATE);
    else if(newModLevel < MIN_WAH_MOD_RATE)
        triangeWave->setWaveTableFreq(MIN_WAH_MOD_RATE);
    else
        triangeWave->setWaveTableFreq(newModLevel);
}








