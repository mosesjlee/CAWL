//
//  CAWLFuzz.hpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLFuzz_hpp
#define CAWLFuzz_hpp

class CAWLFuzz
{
public:
    CAWLFuzz();
    ~CAWLFuzz();
    void processBuffer(float * buf, const unsigned int numSamples);
    void setGain(double newGain);
    void setMix(double newMix);
private:
    double mGain;
    double mMixLevel;
};
#endif /* CAWLFuzz_hpp */
