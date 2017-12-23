/*
 CAWLChorus.hpp
 CAWL

 Created by Moses Lee on 10/12/17.
 Copyright © 2017 Moses Lee. All rights reserved.
 CAWLChorus inherits from CAWLModDelayEffect class.
 
*/

#ifndef CAWLChorus_hpp
#define CAWLChorus_hpp
#include "CAWLModDelayEffect.hpp"

class CAWLChorus : public CAWLModDelayEffect
{
public:
	CAWLChorus();
	~CAWLChorus();
    double modulatedTime();
};
#endif /* CAWLChorus_hpp */
