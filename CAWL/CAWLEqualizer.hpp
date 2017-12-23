/*
 CAWLEqualizer.hpp
 CAWL

 Created by Moses Lee on 10/12/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLEqualizer. This is my equalizer class that
 took 2 shelving filter and 2 peaking filter
 and put them in serial to get a parametric EQ
*/

#ifndef CAWLEqualizer_hpp
#define CAWLEqualizer_hpp
#include "CAWLLowShelfFilter.hpp"
#include "CAWLHighShelfFilter.hpp"
#include "CAWLPeakFilter.hpp"

#include <stdio.h>
class CAWLEqualizer
{
public:
    CAWLEqualizer();
    ~CAWLEqualizer();
    
    //Setters
    void setLowShelfCenterFreq(double centerFreq);
    void setHighShelfCenterFreq(double centerFreq);
    void setlowMidCenterFreq(double centerFreq);
    void setHighMidCenterFreq(double centerFreq);
    void setLowShelfGain(double newGain);
    void setHighShelfGain(double newGain);
    void setlowMidGain(double newGain);
    void setHighMidGain(double newGain);
    void setLowMidQFactor(double newQFactor);
    void setHighMidQFactor(double newQFactor);
    
    //Getters
    double getLowShelfCenterFreq();
    double getHighShelfCenterFreq();
    double getlowMidCenterFreq();
    double getHighMidCenterFreq();
    double getLowShelfGain();
    double getHighShelfGain();
    double getlowMidGain();
    double getHighMidGain();
    double getLowMidQFactor();
    double getHighMidQFactor();
    void processBuffer(float * buf, const unsigned int numSamples);
    
private:
    CAWLLowShelfFilter cLowShelf;       //For low end shelving
    CAWLHighShelfFilter cHighShelf;     //For high end shelving
    CAWLPeakFilter cLowMid;             //Peak for low mid
    CAWLPeakFilter cHighMid;            //Peak for high mid
    
    double cLowShelfCenterFreq;         //Low shelf center frequency
    double cHighShelfCenterFreq;        //High shelf center frequency
    double cLowMidCenterFreq;           //Low mid center frequency
    double cHighMidCenterFreq;          //High mid center frequency

    double cLowShelfGain;               //Low shelf center gain
    double cHighShelfGain;              //High shelf center gain
    double cLowMidGain;                 //Low mid center gain
    double cHighMidGain;                //High mid center gain
    
    double cLowMidQFactor;              //Low mid Peak filter Q value
    double cHighMidQFactor;             //High mid Peak filter Q value
};

#endif /* CAWLEqualizer_hpp */
