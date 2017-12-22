/*
 CAWLOscillator.hpp
 CAWL

 Created by Moses Lee on 10/23/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 
 CAWLOscillator. This is the parent class for all wave table based
 oscillator
*/

#ifndef CAWLOscillator_hpp
#define CAWLOscillator_hpp
#define MAX_TABLE_SIZE 16384.0

class CAWLOscillator
{
public:
    double getNextSample();
    void setWaveTableFreq(double newFreq);
    void setSampleRate(double newSampleRate);
protected:
    double *cWaveTable;     //The Wave table
    double cSampleRate;     //The sampel rate. Default is 44100
    double cFreq;           //The Hz of the wave oscillator
    double cCounter;        //The counter
    double cCycleLength;    //Length of the stride
};
#endif /* CAWLOscillator_hpp */
