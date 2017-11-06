//
//  CAWLReverb.hpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLReverb_hpp
#define CAWLReverb_hpp

class CAWLReverb
{
public:
    CAWLReverb();
    ~CAWLReverb();
    void processBuffer(float * buf, const unsigned int numSamples);
    
private:
};

#endif /* CAWLReverb_hpp */
