//
//  DelayUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/13/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "DelayUI.h"

@implementation DelayUI {
	//Sliders
    NSSlider    *feedbackSlider;
    NSSlider    *wetMixSlider;
	NSSlider 	*dryMixSlider;
    NSSlider    *delayTimeSlider;
	
	//Labels
    NSTextField *feedbackLabel;
    NSTextField *wetMixLabel;
	NSTextField *delayTimeLabel;
	NSTextField *dryMixLabel;
	
	//Titles
    NSTextField *feedbackTitle;
    NSTextField *wetMixTitle;
    NSTextField *delayTimeTitle;
	NSTextField *dryMixTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupFeedbackUI];
    [self setupWetMixUI];
    [self setupDelayTimeUI];
	[self setupDryGainUI];
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    [self drawBorder:dirtyRect];
    // Drawing code here.
}


#pragma mark DELAY_UI_SETUP
- (void)setupFeedbackUI {
    //The title
    feedbackTitle = [self drawLabelTextFieldWithRect:NSMakeRect(15, 250, 50, 30)
                                           WithTitle:@"FB Gain"
                                              toView:self];
    
    //The value label
	feedbackLabel = [self drawValueTextFieldWithRect:NSMakeRect(15, 280, 30, 20)
                                              toView:self];

    //The slider
	feedbackSlider = [self drawCircularSliderWithRect:NSMakeRect(15, 320, 30, 30)
										   WithMaxVal:1.0
										AndWithMinVal:0.0
                                         atDefaultVal:0.5
                                               toView:self
                                         withSelector:@selector(updateFeedbackGainLevel:)];
}



- (void)setupWetMixUI {
    wetMixTitle = [self drawLabelTextFieldWithRect:NSMakeRect(60, 250, 30, 30)
                                         WithTitle:@"Wet Mix"
                                            toView:self];
	
    
    wetMixLabel = [self drawValueTextFieldWithRect:NSMakeRect(60, 280, 30, 20)
                                            toView:self];
    
	wetMixSlider = [self drawCircularSliderWithRect:NSMakeRect(60, 320, 30, 30)
										 WithMaxVal:1.0
									  AndWithMinVal:0.0
                                       atDefaultVal:0.5
                                             toView:self
                                       withSelector:@selector(updateWetMixLevel:)];
}

- (void)updateWetMixLevel:(id)sender {
    wetMixLabel.stringValue = [NSString stringWithFormat:@"%f", wetMixSlider.doubleValue];
    self.soundTabRef.soundBoard->setDelayWetMixLevel(wetMixSlider.doubleValue);
}

- (void)setupDelayTimeUI {
    delayTimeTitle = [self drawLabelTextFieldWithRect:NSMakeRect(100, 250, 70, 30)
                                            WithTitle:@"Delay Time"
                                               toView:self];
    
    delayTimeLabel = [self drawValueTextFieldWithRect:NSMakeRect(100, 280, 50, 20)
                                               toView:self];
    
    delayTimeSlider = [self drawCircularSliderWithRect:NSMakeRect(100, 320, 30, 30)
                                            WithMaxVal:1500
                                         AndWithMinVal:400
                                          atDefaultVal:300
                                                toView:self
                                          withSelector:@selector(updateDelayTime:)];
}



- (void)setupDryGainUI {
	//The title
	dryMixTitle = [self drawLabelTextFieldWithRect:NSMakeRect(165, 250, 50, 30)
                                         WithTitle:@"Dry Mix"
                                            toView:self];
	
	//The value label
	dryMixLabel = [self drawValueTextFieldWithRect:NSMakeRect(165, 280, 30, 20)
                                            toView:self];
	
	//The slider
	dryMixSlider = [self drawCircularSliderWithRect:NSMakeRect(165, 320, 30, 30)
										   WithMaxVal:1.0
										AndWithMinVal:0.0
                                       atDefaultVal:0.5
                                             toView:self
                                       withSelector:@selector(updatDryGainLevel:)];
}

#pragma mark DELAY_ACTIONS
- (IBAction)updateFeedbackGainLevel:(id)sender {
    feedbackLabel.stringValue = [NSString stringWithFormat:@"%f", feedbackSlider.doubleValue];
    self.soundTabRef.soundBoard->setDelayFeedbackGain(feedbackSlider.doubleValue);
}

- (IBAction)updateDelayTime:(id)sender {
    delayTimeLabel.stringValue = [NSString stringWithFormat:@"%d", delayTimeSlider.intValue];
    self.soundTabRef.soundBoard->setNewDelayTime(delayTimeSlider.intValue);
}

- (IBAction)updatDryGainLevel:(NSSlider *)sender {
	dryMixLabel.stringValue = [NSString stringWithFormat:@"%f", dryMixSlider.floatValue];
	self.soundTabRef.soundBoard->setDelayDryMixGain(dryMixSlider.floatValue);
}

@end
