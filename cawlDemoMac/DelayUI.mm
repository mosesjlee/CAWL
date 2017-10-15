//
//  DelayUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/13/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "DelayUI.h"

@implementation DelayUI {
    NSSlider * feedbackSlider;
    NSSlider * wetMixSlider;
    NSSlider * delayTimeSlider;
    NSTextField * feedbackLabel;
    NSTextField * wetMixLabel;
    NSTextField * delayTimeLabel;
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
    feedbackSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(10, 300, 30, 30)];
    [feedbackSlider setSliderType:NSSliderTypeCircular];
    [feedbackSlider setNeedsDisplay:YES];
    [feedbackSlider setMaxValue:1.0];
    [feedbackSlider setMinValue:0.0];
    [feedbackSlider setAction:@selector(updateFeedbackGainLevel)];
    [self addSubview:feedbackSlider];
    
    
    feedbackLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(10, 270, 30, 20)];
    [self addSubview:feedbackLabel];
    [feedbackLabel setNeedsDisplay:YES];
}

- (void)updateFeedbackGainLevel {
    NSLog(@"Update Feedback gain");
}

- (void)setupWetMixUI {
    wetMixSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(50, 300, 30, 30)];
    [wetMixSlider setSliderType:NSSliderTypeCircular];
    [wetMixSlider setNeedsDisplay:YES];
    [wetMixSlider setMaxValue:1.0];
    [wetMixSlider setMinValue:0.0];
    [wetMixSlider setAction:@selector(updateWetMixLevel)];
    [self addSubview:wetMixSlider];
    
    wetMixLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(50, 270, 30, 20)];
    [self addSubview:wetMixLabel];
    [wetMixLabel setNeedsDisplay:YES];
}

- (void)updateWetMixLevel {
    NSLog(@"Update WetMix gain");
}

- (void)setupDelayTimeUI {
    delayTimeSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(90, 300, 30, 30)];
    [delayTimeSlider setSliderType:NSSliderTypeCircular];
    [delayTimeSlider setNeedsDisplay:YES];
    [delayTimeSlider setMaxValue:1500];
    [delayTimeSlider setMinValue:5];
    [delayTimeSlider setAction:@selector(updateDelayTime)];
    [self addSubview:delayTimeSlider];
    
    delayTimeLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(90, 270, 50, 20)];
    [self addSubview:delayTimeLabel];
    [delayTimeLabel setNeedsDisplay:YES];
}

- (void)updateDelayTime {
    delayTimeLabel.stringValue = [NSString stringWithFormat:@"%d", delayTimeSlider.intValue];
    NSLog(@"New delay %@", delayTimeLabel.stringValue);
    _soundTabRef.soundBoard->setNewDelayTime(delayTimeSlider.intValue);
}

@end
