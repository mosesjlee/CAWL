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
    NSTabViewItem * tab1, * tab2, *tab3;
    tab1 = [[NSTabViewItem alloc] init];
    tab2 = [[NSTabViewItem alloc] init];
    tab3 = [[NSTabViewItem alloc] init];
    [_tabbedView insertTabViewItem:tab1 atIndex:0];
    [_tabbedView insertTabViewItem:tab2 atIndex:1];
    [_tabbedView insertTabViewItem:tab3 atIndex:2];
}


- (void)setRepresentedObject:(id)representedObject {
	[super setRepresentedObject:representedObject];

	// Update the view, if already loaded.
}


@end
