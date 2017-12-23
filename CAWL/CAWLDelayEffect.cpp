//
//  CAWLDelayEffect.cpp
//  CAWL
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLDelayEffect.hpp"
/*
 Default constructor
 */
CAWLDelayEffect::CAWLDelayEffect()
{
    cFeedbackMix = 0.5;
    cWetMix = 0.5;
    cDryMix = 1.0;
    cUcf = new CAWLUniversalCombFilter();
    cUcf->setDryMix(cDryMix);
    cUcf->setFeedForwardGain(cWetMix);
    cUcf->setFeedbackGain(cFeedbackMix);
    cUcf->setMixLevel(0);
    
}

/*
 Default destructor
 */
CAWLDelayEffect::~CAWLDelayEffect()
{
    delete cUcf;
}

/*
 Main processing block
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLDelayEffect::processBuffer(float * audioStreamBuf, const unsigned int numSamples)
{
    cUcf->processBuffer(audioStreamBuf, numSamples);
}

#pragma mark DELAY_SETTERS
/*
 Sets the wet mix level of the delay
 @param newWetMix -> the new wet mix level
 */
void CAWLDelayEffect::setWetMixLevel(double newWetMix)
{
    if(newWetMix > 1.0)
        cWetMix = 1.0;
    else if(newWetMix < 0.0)
        cWetMix = 0.0;
    else
        cWetMix = newWetMix;
    
    cUcf->setFeedForwardGain(cWetMix);
}

/*
 Sets the feedback level of the delay
 @param newFeedbackMix -> the new feedback level
 */
void CAWLDelayEffect::setFeedbackLevel(double newFeedbackMix)
{
    if(newFeedbackMix > 1.0)
        cFeedbackMix = 1.0;
    else if(newFeedbackMix < 0.0)
        cFeedbackMix = 0.0;
    else
        cFeedbackMix = newFeedbackMix;
    cUcf->setFeedbackGain(cFeedbackMix);
}

/*
 Sets the dry mix level of the delay
 @param newDryMix -> the dry wet mix level
 */
void CAWLDelayEffect::setDryMix(double newDryMix)
{
    if(newDryMix > 1.0)
        cDryMix = 1.0;
    else if(newDryMix < 0.0)
        cDryMix = 0.0;
    else
        cDryMix = newDryMix;
    
    cUcf->setDryMix(cDryMix);
}

/*
 Sets the delay time of the delay
 @param newDelayTime -> the new delay time
 */
void CAWLDelayEffect::setDelayTime(double newDelayTime)
{
    cDelayTime = newDelayTime;
    cUcf->setDelay(cDelayTime);
}

#pragma mark DELAY_GETTERS
/*
 Gets the wet mix level of the delay
 @return wet mix level
 */
double CAWLDelayEffect::getWetMixLevel()
{
    return cWetMix;
}

/*
 Gets the feedback mix level of the delay
 @return feedback mix level
 */
double CAWLDelayEffect::getFeedbackLevel()
{
    return cFeedbackMix;
}

/*
 Gets the dry mix level of the delay
 @return dry mix level
 */
double CAWLDelayEffect::getDryMix()
{
    return cDryMix;
}

/*
 Gets the delay time of the delay
 @return delay time
 */
double CAWLDelayEffect::getDelayTime()
{
    return cDelayTime;
}
