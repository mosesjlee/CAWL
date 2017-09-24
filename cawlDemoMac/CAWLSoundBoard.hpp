//
//  CAWLSoundBoard.hpp
//  CAWL
//
//  Created by Moses Lee on 9/16/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLSoundBoard_hpp
#define CAWLSoundBoard_hpp

#include <stdio.h>
#include "CAWL.hpp"
#include "CAWLValveTubeSimulator.hpp"

class CAWLSoundBoard
{
public:
    CAWLSoundBoard();
    ~CAWLSoundBoard();
private:
    CAWL * cawlInstance;
    CAWLValveTubeSimulator * ampArray;
    
};

#endif /* CAWLSoundBoard_hpp */
