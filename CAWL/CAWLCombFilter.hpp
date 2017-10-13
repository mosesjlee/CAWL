//
//  CAWLFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 9/30/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLFilter_hpp
#define CAWLFilter_hpp
#include <stdio.h>
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
    CAWLDelayLine delayLine;
    unsigned int delay;
    double lastSampleOfBlock;
    double mFeedbackGain;
    double mFeedForwardGain;
    double mMixLevel;
};
#endif /* CAWLFilter_hpp */
