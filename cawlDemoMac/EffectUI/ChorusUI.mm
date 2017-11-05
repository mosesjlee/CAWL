//
//  ChorusUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "ChorusUI.h"

@implementation ChorusUI {
	NSSlider *chorusRateSlider;
	NSSlider *chorusDepthSlider;
	NSSlider *chorusMixLevel;
	
	NSTextField *chorusRateTitle;
	NSTextField *chorusDepthTitle;
	NSTextField *chorusMixTitle;
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

-(void) setupChorusRateUI {
	
}

-(void) setupChorusDepthUI {
	
}

-(void) setupMixLevelUI {
	
}

#pragma mark IBACTION_CHORUS

-(IBAction) updateChorusRate:(id)sender {
	
}

-(IBAction) updateChorusDepthLevel:(id)sender {
	
}

-(IBAction) updateMixLevel:(id)sender {
	
}

@end








