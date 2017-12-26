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
    feedbackTitle = [self drawLabelTextFieldWithRect:NSMakeRect(2, 250, 80, MAX_TEXTFIELD_HEIGHT)
                                           WithTitle:@"Feedback"
                                              toView:self];
    
    //The value label
	feedbackLabel = [self drawValueTextFieldWithRect:NSMakeRect(15, 280, 60, MAX_TEXTFIELD_HEIGHT)
                                              toView:self];

    //The slider
	feedbackSlider = [self drawCircularSliderWithRect:NSMakeRect(25, 310, 30, 30)
										   WithMaxVal:1.0
										AndWithMinVal:0.0
                                         atDefaultVal:0.5
                                               toView:self
                                         withSelector:@selector(updateFeedbackGainLevel:)];
}



- (void)setupWetMixUI {
    wetMixTitle = [self drawLabelTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-30, 250, 60, MAX_TEXTFIELD_HEIGHT)
                                         WithTitle:@"Wet Mix"
                                            toView:self];
	
    
    wetMixLabel = [self drawValueTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-30, 280, 60, MAX_TEXTFIELD_HEIGHT)
                                            toView:self];
    
	wetMixSlider = [self drawCircularSliderWithRect:NSMakeRect(MAX_WIDTH/2-15, 310, 30, 30)
										 WithMaxVal:1.0
									  AndWithMinVal:0.0
                                       atDefaultVal:0.5
                                             toView:self
                                       withSelector:@selector(updateWetMixLevel:)];
}

- (void)setupDryGainUI {
	//The title
	dryMixTitle = [self drawLabelTextFieldWithRect:NSMakeRect(175, 250, 60, MAX_TEXTFIELD_HEIGHT)
                                         WithTitle:@"Dry Mix"
                                            toView:self];
	
	//The value label
	dryMixLabel = [self drawValueTextFieldWithRect:NSMakeRect(175, 280, 60, MAX_TEXTFIELD_HEIGHT)
                                            toView:self];
	
	//The slider
	dryMixSlider = [self drawCircularSliderWithRect:NSMakeRect(185, 310, 30, 30)
										   WithMaxVal:1.0
										AndWithMinVal:0.0
                                       atDefaultVal:0.5
                                             toView:self
                                       withSelector:@selector(updatDryGainLevel:)];
}

- (void)setupDelayTimeUI {
    delayTimeTitle = [self drawLabelTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-45, 160, 90, MAX_TEXTFIELD_HEIGHT)
                                            WithTitle:@"Delay Time"
                                               toView:self];
    
    delayTimeLabel = [self drawValueTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-30, 190, 60, MAX_TEXTFIELD_HEIGHT)
                                               toView:self];
    
    delayTimeSlider = [self drawCircularSliderWithRect:NSMakeRect(MAX_WIDTH/2-15, 215, 30, 30)
                                            WithMaxVal:1500
                                         AndWithMinVal:400
                                          atDefaultVal:300
                                                toView:self
                                          withSelector:@selector(updateDelayTime:)];
}


#pragma mark DELAY_ACTIONS
- (IBAction)updateFeedbackGainLevel:(id)sender {
    feedbackLabel.stringValue = [NSString stringWithFormat:@"%.02f %%", feedbackSlider.doubleValue * 100];
    self.soundTabRef.soundBoard->setDelayFeedbackGain(feedbackSlider.doubleValue);
}

- (IBAction)updateDelayTime:(id)sender {
    delayTimeLabel.stringValue = [NSString stringWithFormat:@"%d ms", delayTimeSlider.intValue];
    self.soundTabRef.soundBoard->setNewDelayTime(delayTimeSlider.intValue);
}

- (IBAction)updatDryGainLevel:(NSSlider *)sender {
	dryMixLabel.stringValue = [NSString stringWithFormat:@"%.02f %%", dryMixSlider.floatValue * 100];
	self.soundTabRef.soundBoard->setDelayDryMixGain(dryMixSlider.floatValue);
}

- (IBAction)updateWetMixLevel:(id)sender {
    wetMixLabel.stringValue = [NSString stringWithFormat:@"%.02f %%", wetMixSlider.doubleValue * 100];
    self.soundTabRef.soundBoard->setDelayWetMixLevel(wetMixSlider.doubleValue);
}

@end
