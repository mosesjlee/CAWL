//
//  CompressorUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "CompressorUI.h"

@implementation CompressorUI {
	NSSlider *thresholdSlider;
	NSSlider *kneeSlider;
	NSSlider *ratioSlider;
	NSSlider *gainSlider;
	
	NSTextField *thresholdTitle;
	NSTextField *kneeTitle;
	NSTextField *ratioTitle;
	NSTextField *gainTitle;
	
	NSTextField *thresholdLabel;
	NSTextField *kneeLabel;
	NSTextField *ratioLabel;
	NSTextField *gainLabel;
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
-(void) setupThresholdUI {
	
}

-(void) setupKneeUI {
	
}

-(void) setupRatioUI {
	
}

-(void) setupGainUI {
	
}

#pragma mark IBACTION_COMPRESSOR

-(IBAction) updateThresholdLevel:(id)sender {
	
}

-(IBAction) updateKneeLevel:(id)sender {
	
}

-(IBAction) updateRatio:(id)sender {
	
}

-(IBAction) gainLevel:(id)sender {
	
}

@end





