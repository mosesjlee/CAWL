//
//  CAWLDelayEffect.hpp
//  CAWL
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLDelayEffect_hpp
#define CAWLDelayEffect_hpp

#include "CAWLUniversalCombFilter.hpp"

class CAWLDelayEffect
{
public:
    CAWLDelayEffect();
    ~CAWLDelayEffect();
    void processBuffer(float * buf, const unsigned int numSamples);
    void setWetMixLevel(double wetMix);
    void setFeedbackLevel(double feedbackMix);
    void setDryMix(double dryMix);
    void setDelayTime(double newdelayTime);
private:
    CAWLUniversalCombFilter * ucf;
    double wetMix;
    double dryMix;
    double feedbackMix;
    double delayTime;
    double lastSampleOfBlock;
};

#endif /* CAWLDelayEffect_hpp */
