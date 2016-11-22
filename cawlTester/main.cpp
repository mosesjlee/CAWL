//
//  main.cpp
//  cawlTester
//
//  Created by Moses Lee on 11/22/16.
//  Copyright © 2016 Moses Lee. All rights reserved.
//

#include <iostream>
#include "CAWL.hpp"

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	CAWL * instance = CAWL::Instance();
	instance->startPlaying();
	
	printf("recording shiz");
	getchar();
    return 0;
}
