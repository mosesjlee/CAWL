//
//  DebugUtilities.hpp
//  cawlDemoMac
//
//  Created by Moses Lee on 12/24/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifndef DebugUtilities_hpp
#define DebugUtilities_hpp
#include "CAWL.hpp"
#include <stdio.h>
void getRawGuitarStream(float * stream);
void getWhiteNoiseStream(float * stream);
void fillWhiteNoiseStream();
void fillGuitarStream();
extern cawlBuffer testBuffer;
#endif /* DebugUtilities_hpp */
