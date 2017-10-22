//
//  DelayUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/13/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "DelayUI.h"

@implementation DelayUI {
    NSSlider    *feedbackSlider;
    NSSlider    *wetMixSlider;
    NSSlider    *delayTimeSlider;
    NSTextField *feedbackLabel;
    NSTextField *wetMixLabel;
    NSTextField *delayTimeLabel;
    NSTextField *feedbackTitle;
    NSTextField *wetMixTitle;
    NSTextField *delayTimeTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupFeedbackUI];
    [self setupWetMixUI];
    [self setupDelayTimeUI];
    [self drawBorder:frameRect];
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

- (void)setupFeedbackUI {
    //The title
    feedbackTitle = [[NSTextField alloc] initWithFrame:NSMakeRect(15, 250, 50, 30)];
    [self addSubview:feedbackTitle];
    feedbackTitle.stringValue = @"FB Gain";
    [feedbackTitle setEditable:NO];
    [feedbackTitle setBordered:NO];
    [feedbackTitle setDrawsBackground:NO];
    [feedbackTitle setNeedsDisplay:YES];
    
    //The value label
    feedbackLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(15, 280, 30, 20)];
    [self addSubview:feedbackLabel];
    [feedbackLabel setNeedsDisplay:YES];
    
    //The slider
    feedbackSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(15, 320, 30, 30)];
    [feedbackSlider setSliderType:NSSliderTypeCircular];
    [feedbackSlider setNeedsDisplay:YES];
    [feedbackSlider setMaxValue:1.0];
    [feedbackSlider setMinValue:0.0];
    [feedbackSlider setAction:@selector(updateFeedbackGainLevel)];
    [self addSubview:feedbackSlider];
}

- (void)updateFeedbackGainLevel {
    feedbackLabel.stringValue = [NSString stringWithFormat:@"%f", feedbackSlider.doubleValue];
    self.soundTabRef.soundBoard->setDelayFeedbackGain(feedbackSlider.doubleValue);
}

- (void)setupWetMixUI {
    wetMixTitle = [[NSTextField alloc] initWithFrame:NSMakeRect(60, 250, 30, 30)];
    wetMixTitle.stringValue = @"Wet Mix";
    [wetMixTitle setEditable:NO];
    [wetMixTitle setBordered:NO];
    [wetMixTitle setDrawsBackground:NO];
    [self addSubview:wetMixTitle];
    [wetMixTitle setNeedsDisplay:YES];
    
    wetMixLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(60, 280, 30, 20)];
    [self addSubview:wetMixLabel];
    [wetMixLabel setNeedsDisplay:YES];

    
    wetMixSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(60, 320, 30, 30)];
    [wetMixSlider setSliderType:NSSliderTypeCircular];
    [wetMixSlider setNeedsDisplay:YES];
    [wetMixSlider setMaxValue:1.0];
    [wetMixSlider setMinValue:0.0];
    [wetMixSlider setAction:@selector(updateWetMixLevel)];
    [self addSubview:wetMixSlider];
}

- (void)updateWetMixLevel {
    wetMixLabel.stringValue = [NSString stringWithFormat:@"%f", wetMixSlider.doubleValue];
    self.soundTabRef.soundBoard->setDelayWetMixLevel(wetMixSlider.doubleValue);
}

- (void)setupDelayTimeUI {
    delayTimeTitle = [self drawLabelTextFieldWithRect:NSMakeRect(100, 250, 70, 30) WithTitle:@"Delay Time"];
    [self addSubview:delayTimeTitle];
    
    
    delayTimeLabel = [self drawValueTextFieldWithRect:NSMakeRect(100, 280, 50, 20)];
    [self addSubview:delayTimeLabel];
    
    delayTimeSlider = [self drawCircularSliderWithRect:NSMakeRect(100, 320, 30, 30)
                                            WithMaxVal:1500
                                         AndWithMinVal:5];
    [delayTimeSlider setAction:@selector(updateDelayTime)];
    [self addSubview:delayTimeSlider];
}

- (void)updateDelayTime {
    delayTimeLabel.stringValue = [NSString stringWithFormat:@"%d", delayTimeSlider.intValue];
    self.soundTabRef.soundBoard->setNewDelayTime(delayTimeSlider.intValue);
}

@end
