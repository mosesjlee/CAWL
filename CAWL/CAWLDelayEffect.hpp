/*
 CAWLDelayEffect.hpp
 CAWL

 Created by Moses Lee on 10/12/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 CAWLDelayEffect is a basic delay effect
 that produces echo.
*/

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
    double getWetMixLevel();
    double getFeedbackLevel();
    double getDryMix();
    double getDelayTime();
    
private:
    CAWLUniversalCombFilter * cUcf;
    double cWetMix;
    double cDryMix;
    double cFeedbackMix;
    double cDelayTime;
    double cLastSampleOfBlock;
};

#endif /* CAWLDelayEffect_hpp */
