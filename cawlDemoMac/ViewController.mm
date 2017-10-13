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
//    NSTabViewItem * tab1, * tab2, *tab3;
//    tab1 = [[NSTabViewItem alloc] init];
//    tab2 = [[NSTabViewItem alloc] init];
//    tab3 = [[NSTabViewItem alloc] init];
//    [_tabbedView insertTabViewItem:tab1 atIndex:0];
//    [_tabbedView insertTabViewItem:tab2 atIndex:1];
//    [_tabbedView insertTabViewItem:tab3 atIndex:2];
    _cawlInstance = CAWL::Instance();
    _numChannels = _cawlInstance->getNumChannels();
    _soundPageArray = [[NSMutableArray alloc] init];
    for(unsigned i = 0; i < _numChannels; i++) {
        [_soundPageArray addObject:[[SoundTab alloc] init]];
        [_soundPageArray objectAtIndex:i].label = [NSString stringWithFormat:@"Channel %d", i+1];
        [_tabbedView insertTabViewItem:[_soundPageArray objectAtIndex:i] atIndex:i];
    }
}


- (void)setRepresentedObject:(id)representedObject {
	[super setRepresentedObject:representedObject];

	// Update the view, if already loaded.
}

- (void)registerInputChannel {
    //_cawlInstance->registerInputBlockAtInputChannel(<#^(float *buffer, const unsigned int numSamples)buffer#>, <#const unsigned int channel#>);
}

@end
