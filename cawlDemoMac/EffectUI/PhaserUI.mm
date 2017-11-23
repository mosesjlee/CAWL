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
    
    NSTextField *speedValueLabel;
    NSTextField *rateValueLabel;
    NSTextField *mixLevelValueLabel;
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
    speedTitle = [self drawLabelTextFieldWithRect:NSMakeRect(15, 320, 70, 30)
                                        WithTitle:@"Speed"
                                           toView:self];
    
    speedSlider = [self drawCircularSliderWithRect:NSMakeRect(20, 290, 30, 30)
                                        WithMaxVal:1.0
                                     AndWithMinVal:0.0
                                      atDefaultVal:0.5
                                            toView:self
                                      withSelector:@selector(updateSpeed:)];
    
    speedValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(20, 260, 30, 30)
                                                toView:self];
}

- (void)setupRateUI {
    rateTitle;
    rateSlider;
    rateValueLabel;
}

- (void)setupMixLevelUI {
    mixLevelTitle;
    mixLevelSlider;
    mixLevelValueLabel;
}

#pragma mark PHASER_IBACTION
- (IBAction)updateSpeed:(id) sender {
	
}

- (IBAction)updateRate:(id)sender {
	
}

- (IBAction)updateMixLevel:(id)sender {
	
}
@end


