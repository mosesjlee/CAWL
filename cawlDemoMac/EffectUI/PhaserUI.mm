//
//  PhaserUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "PhaserUI.h"

@implementation PhaserUI {
	NSSlider *speedSlider;
	NSSlider *rateSlider;
	NSSlider *mixLevelSlider;
	
	NSTextField *speedTitle;
	NSTextField *rateTitle;
	NSTextField *mixLevelTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    
    return self;
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI
- (void)setupSpeedUI {
	
}

- (void)setupRateUI {
	
}


- (void)setupMixLevelUI {
	
}

#pragma mark PHASER_IBACTION
- (IBAction)updateSpeed:(id) sender {
	
}

- (IBAction)updateRate:(id)sender {
	
}

- (IBAction)updateMixLevel:(id)sender {
	
}
@end


