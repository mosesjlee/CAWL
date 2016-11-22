//
//  ViewController.m
//  cawlDemoPhone
//
//  Created by Moses Lee on 11/21/16.
//  Copyright © 2016 Moses Lee. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
	_instance = CAWL::Instance();
	_instance->startPlaying();
}


- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
	// Dispose of any resources that can be recreated.
}


@end
