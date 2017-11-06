//
//  CAWLWahWah.hpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLWahWah_hpp
#define CAWLWahWah_hpp

#include "CAWLTriangleWaveOsc.hpp"
#include "CAWLBandPassFilter.hpp"

class CAWLWahWah
{
public:
    CAWLWahWah();
    ~CAWLWahWah();
    void processBuffer(float * buf, const unsigned int numSamples);
    
private:
    CAWLTriangleWaveOsc * triangeWave;
    CAWLBandPassFilter * bandPass;
    double centerFreq;
    double qFactor;
};
#endif /* CAWLWahWah_hpp */
