//
//  ViewController.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/31/16.
//  Copyright © 2016 Moses Lee. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];

	// Do any additional setup after loading the view.
	_instance = CAWL::Instance();
	_instance->startPlaying();
}


- (void)setRepresentedObject:(id)representedObject {
	[super setRepresentedObject:representedObject];

	// Update the view, if already loaded.
}


@end
