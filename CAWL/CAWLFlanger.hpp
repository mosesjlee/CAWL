/*
  CAWLFlanger.hpp
  CAWL

  Created by Moses Lee on 10/15/17.
  Copyright © 2017 Moses Lee. All rights reserved.
*/

#ifndef CAWLFlanger_hpp
#define CAWLFlanger_hpp

#include "CAWLModDelayEffect.hpp"


class CAWLFlanger : public CAWLModDelayEffect
{
public:
	CAWLFlanger();
	~CAWLFlanger();
    double modulatedTime();
};

#endif /* CAWLFlanger_hpp */
