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
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

- (void)setupFeedbackUI {
    //The title
    feedbackTitle = [[NSTextField alloc] initWithFrame:NSMakeRect(5, 250, 50, 30)];
    [self addSubview:feedbackTitle];
    feedbackTitle.stringValue = @"FB Gain";
    [feedbackTitle setEditable:NO];
    [feedbackTitle setBordered:NO];
    [feedbackTitle setDrawsBackground:NO];
    [feedbackTitle setNeedsDisplay:YES];
    
    //The value label
    feedbackLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(5, 280, 30, 20)];
    [self addSubview:feedbackLabel];
    [feedbackLabel setNeedsDisplay:YES];
    
    //The slider
    feedbackSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(5, 320, 30, 30)];
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
    wetMixTitle = [[NSTextField alloc] initWithFrame:NSMakeRect(50, 250, 30, 30)];
    wetMixTitle.stringValue = @"Wet Mix";
    [wetMixTitle setEditable:NO];
    [wetMixTitle setBordered:NO];
    [wetMixTitle setDrawsBackground:NO];
    [self addSubview:wetMixTitle];
    [wetMixTitle setNeedsDisplay:YES];
    
    wetMixLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(50, 280, 30, 20)];
    [self addSubview:wetMixLabel];
    [wetMixLabel setNeedsDisplay:YES];

    
    wetMixSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(50, 320, 30, 30)];
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
    delayTimeTitle = [[NSTextField alloc] initWithFrame:NSMakeRect(90, 250, 70, 30)];
    delayTimeTitle.stringValue = @"Delay Time";
    [delayTimeTitle setEditable:NO];
    [delayTimeTitle setBordered:NO];
    [delayTimeTitle setDrawsBackground:NO];
    [self addSubview:delayTimeTitle];
    [delayTimeTitle setNeedsDisplay:YES];
    
    delayTimeLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(90, 280, 50, 20)];
    [self addSubview:delayTimeLabel];
    [delayTimeLabel setNeedsDisplay:YES];
    
    delayTimeSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(90, 320, 30, 30)];
    [delayTimeSlider setSliderType:NSSliderTypeCircular];
    [delayTimeSlider setNeedsDisplay:YES];
    [delayTimeSlider setMaxValue:1500];
    [delayTimeSlider setMinValue:5];
    [delayTimeSlider setAction:@selector(updateDelayTime)];
    [self addSubview:delayTimeSlider];
}

- (void)updateDelayTime {
    delayTimeLabel.stringValue = [NSString stringWithFormat:@"%d", delayTimeSlider.intValue];
    self.soundTabRef.soundBoard->setNewDelayTime(delayTimeSlider.intValue);
}

@end
