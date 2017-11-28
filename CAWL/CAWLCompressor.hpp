//
//  CAWLCompressor.hpp
//  CAWL
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLCompressor_hpp
#define CAWLCompressor_hpp

class CAWLCompressor
{
public:
    CAWLCompressor();
    ~CAWLCompressor();
    void processBuffer(float * buf, const unsigned int numSamples);
    
private:
    double attackTime;
    double releaseTime;
    double compressorThreshold;
    double compressorRatio;
    double compressorSlope;
    
};

#endif /* CAWLCompressor_hpp */
