/*
 CAWLFilter.hpp
 CAWL

 Created by Moses Lee on 9/30/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLCombFilter. Base class for all comb filters
*/

#ifndef CAWLFilter_hpp
#define CAWLFilter_hpp

#include "CAWLSoundModule.hpp"
#include "CAWLDelayLine.hpp"
class CAWLCombFilter : public CAWLSoundModule
{
public:
    virtual void setDelay(float delay);
    virtual void setFeedForwardGain(float newGain);
    virtual void setFeedbackGain(float newGain);
    virtual void setMixLevel(float newMixLevel);
    
protected:
    CAWLDelayLine   *cDelayLine;
    unsigned int    cDelay;
    double          cLastSampleOfBlock;
    double          cFeedbackGain;
    double          cFeedForwardGain;
    double          cMixLevel;
};
#endif /* CAWLFilter_hpp */
