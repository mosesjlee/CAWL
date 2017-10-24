//
//  CAWLOscillator.hpp
//  CAWL
//
//  Created by Moses Lee on 10/23/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLOscillator_hpp
#define CAWLOscillator_hpp
#define MAX_TABLE_SIZE 16384.0

class CAWLOscillator
{
public:
    double getNextSample();
    void setFreq(double newFreq);
    void setSampleRate(double newSampleRate);
protected:
    double *table;
    double sampleRate;
    double freq;
    double counter;
    double cycleLength;
};
#endif /* CAWLOscillator_hpp */
