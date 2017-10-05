//
//  CAWLLowShelfFilter.hpp
//  CAWL
//
//  Created by Moses Lee on 10/5/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef CAWLLowShelfFilter_hpp
#define CAWLLowShelfFilter_hpp

#include <stdio.h>
#include "CAWLBiQuadFilter.hpp"

class CAWLLowShelfFilter : public CAWLBiQuadFilter
{
	double theta;
	double gamma;
};

#endif /* CAWLLowShelfFilter_hpp */
