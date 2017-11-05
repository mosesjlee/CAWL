//
//  WahUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "WahUI.h"

@implementation WahUI {
	NSSlider *gainSlider;
	NSSlider *qFactorSlider;
	
	NSTextField *gainTitle;
	NSTextField *qFactorTitle;
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
-(void) setupGainUI {
	
}

-(void) setupQFactorUI {
	
}

#pragma mark IBACTION_WAH

-(IBAction) updateGainLevel:(id)sender {
	
}

-(IBAction) updateQLevel:(id)sender {
	
}


@end




