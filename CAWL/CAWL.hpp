/*
 *  CAWL.hpp
 *  CAWL
 *
 *  Created by Moses Lee on 10/31/16.
 *  Copyright © 2016 Moses Lee. All rights reserved.
 *
 */

#ifndef CAWL_
#define CAWL_

#include <CoreAudio/CoreAudio.h>

class CAWL
{
public:
	CAWL();
	~CAWL();
    void HelloWorld(const char *);
	float * getBufferAtChannel(unsigned int channel);
	static CAWL * Instance();
	
private:
	static CAWL * cawlInstance;
};

#endif
