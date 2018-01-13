//
//  CAWLEqualizer.cpp
//  CAWL
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLEqualizer.hpp"
#define MAX_LOW_SHELF_FREQ  200
#define MAX_LOW_MID_FREQ    1000
#define MAX_HIGH_MID_FREQ   10000
#define MAX_HIGH_SHELF_FREQ 20000

#define MIN_LOW_SHELF_FREQ 0
#define MIN_LOW_MID_FREQ   200
#define MIN_HIGH_MID_FREQ  1000
#define MIN_HIGH_SHELF_FREQ 10000

/*
 Default constructor
 */
CAWLEqualizer::CAWLEqualizer()
{
    cLowShelfCenterFreq = 100.0;
    cLowMidCenterFreq   = 500.0;
    cHighMidCenterFreq  = 5000.0;
    cHighShelfCenterFreq = 15000.0;
    cLowShelf.setCenterFreq(cLowShelfCenterFreq);
    cLowMid.setCenterFreq(cLowMidCenterFreq);
    cHighMid.setCenterFreq(cHighMidCenterFreq);
    cHighShelf.setCenterFreq(cHighShelfCenterFreq);
    cLowShelf.setGain(0.0);
    cLowMid.setGain(0.0);
    cHighMid.setGain(0.0);
    cHighShelf.setGain(0.0);
	cLowMid.setQFactor(0.707);
	cHighMid.setQFactor(0.707);
}

/*
 Default destructor
 */
CAWLEqualizer::~CAWLEqualizer()
{
}

/*
 Main processing block
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLEqualizer::processBuffer(float * audioStreamBuf, const unsigned int numSamples)
{
    cLowShelf.processBuffer(audioStreamBuf, numSamples);
    cLowMid.processBuffer(audioStreamBuf, numSamples);
    cHighMid.processBuffer(audioStreamBuf, numSamples);
    cHighShelf.processBuffer(audioStreamBuf, numSamples);
}

#pragma mark EQ_SETTERS
/*
 Sets the center frequency of the low shelving filter
 @param centerFreq -> the new center freq for the low shelf filter
 */
void CAWLEqualizer::setLowShelfCenterFreq(double centerFreq)
{
    if(centerFreq < MIN_LOW_SHELF_FREQ)
        cLowShelf.setCenterFreq(MIN_LOW_SHELF_FREQ);
    else if (centerFreq > MAX_LOW_SHELF_FREQ)
        cLowShelf.setCenterFreq(MIN_LOW_SHELF_FREQ);
    else
        cLowShelf.setCenterFreq(centerFreq);
}

/*
 Sets the center frequency of the high shelving filter
 @param centerFreq -> the new center freq for the high shelf filter
 */
void CAWLEqualizer::setHighShelfCenterFreq(double centerFreq)
{
    if(centerFreq < MIN_HIGH_SHELF_FREQ)
        cHighShelf.setCenterFreq(MIN_HIGH_SHELF_FREQ);
    if(centerFreq > MAX_HIGH_SHELF_FREQ)
        cHighShelf.setCenterFreq(MAX_HIGH_SHELF_FREQ);
    else
        cHighShelf.setCenterFreq(centerFreq);
}

/*
 Sets the center frequency of the peak filter that handles
 low mid range freq. In our case anywhere from 200Hz to 1000Hz
 @param centerFreq -> the new center freq for the peak filter
 */
void CAWLEqualizer::setlowMidCenterFreq(double centerFreq)
{
    if(centerFreq < MIN_LOW_MID_FREQ)
        cLowMid.setCenterFreq(MIN_LOW_MID_FREQ);
    else if(centerFreq > MAX_LOW_MID_FREQ)
        cLowMid.setCenterFreq(MAX_LOW_MID_FREQ);
    else
        cLowMid.setCenterFreq(centerFreq);
}

/*
 Sets the center frequency of the peak filter that handles
 high mid range freq. In our case anywhere from 1KHz to 10KHz
 @param centerFreq -> the new center freq for the peak filter
 */
void CAWLEqualizer::setHighMidCenterFreq(double centerFreq)
{
    if(centerFreq < MIN_HIGH_MID_FREQ)
        cHighMid.setCenterFreq(MIN_HIGH_MID_FREQ);
    else if (centerFreq > MAX_HIGH_MID_FREQ)
        cHighMid.setCenterFreq(MAX_HIGH_MID_FREQ);
    else
        cHighMid.setCenterFreq(centerFreq);
}

/*
 Sets the gain for the low shelf filter
 @param newGain -> the new gain for the filter.
 */
void CAWLEqualizer::setLowShelfGain(double newGain)
{
    cLowShelf.setGain(newGain);
}

/*
 Sets the gain for the high shelf filter
 @param newGain -> the new gain for the filter.
 */
void CAWLEqualizer::setHighShelfGain(double newGain)
{
    cHighShelf.setGain(newGain);
}

/*
 Sets the gain for the low mid peak filter
 @param newGain -> the new gain for the filter.
 */
void CAWLEqualizer::setlowMidGain(double newGain)
{
    cLowMid.setGain(newGain);
}

/*
 Sets the gain for the high mid peak filter
 @param newGain -> the new gain for the filter.
 */
void CAWLEqualizer::setHighMidGain(double newGain)
{
    cHighMid.setGain(newGain);
}

/*
 Sets the Q Factor for the low mid peak filter
 @param newQFactor -> the new q factor
 */
void CAWLEqualizer::setLowMidQFactor(double newQFactor)
{
    cLowMid.setQFactor(newQFactor);
}

/*
 Sets the Q Factor for the low mid peak filter
 @param newQFactor -> the new q factor
 */
void CAWLEqualizer::setHighMidQFactor(double newQFactor)
{
    cHighMid.setQFactor(newQFactor);
}

#pragma mark EQ_GETTERS
/*
 Returns the center frequency of low shelf
 @return the center frequency
 */
double CAWLEqualizer::getLowShelfCenterFreq()
{
    return cLowShelfCenterFreq;
}

/*
 Returns the center frequency of high shelf
 @return the center frequency
 */
double CAWLEqualizer::getHighShelfCenterFreq()
{
    return cHighShelfCenterFreq;
}

/*
 Returns the center frequency of low mid peak filter shelf
 @return the center frequency
 */
double CAWLEqualizer::getlowMidCenterFreq()
{
    return cLowMidCenterFreq;
}

/*
 Returns the center frequency of high mid peak filter shelf
 @return the center frequency
 */
double CAWLEqualizer::getHighMidCenterFreq()
{
    return cHighMidCenterFreq;
}

/*
 Returns the gain of low shelf
 @return the gain
 */
double CAWLEqualizer::getLowShelfGain()
{
    return cLowShelfGain;
}

/*
 Returns the gain of high shelf
 @return the gain
 */
double CAWLEqualizer::getHighShelfGain()
{
    return cHighShelfGain;
}

/*
 Returns the gain of low mid peak filter
 @return the gain
 */
double CAWLEqualizer::getlowMidGain()
{
    return cLowMidGain;
}

/*
 Returns the gain of high mid peak filter
 @return the gain
 */
double CAWLEqualizer::getHighMidGain()
{
    return cHighMidGain;
}

/*
 Returns the Q Factor of low mid peak filter
 @return Q Factor
 */
double CAWLEqualizer::getLowMidQFactor()
{
    return cLowMidQFactor;
}

/*
 Returns the Q Factor of high mid peak filter
 @return Q Factor
 */
double CAWLEqualizer::getHighMidQFactor()
{
    return cHighMidQFactor;
}

