//
//  CAWLOverdrive.hpp
//  CAWL
//
//  Created by Moses Lee on 10/21/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLOverdrive_hpp
#define CAWLOverdrive_hpp

class CAWLOverdrive
{
public:
    CAWLOverdrive();
    ~CAWLOverdrive();
    void processBuffer(float * buf, const unsigned int numSamples);
};
#endif /* CAWLOverdrive_hpp */
