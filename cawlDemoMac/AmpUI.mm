//
//  AmpUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/13/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "AmpUI.h"

@implementation AmpUI {
    NSSlider * gainSlider;
    NSSlider * volumeSlider;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupGainSlider];
    [self setupVolumeSlider];
    return self;
}

- (void)setupGainSlider {
    gainSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(10, 300, 30, 30)];
    [self addSubview:gainSlider];
    [gainSlider setSliderType:NSSliderTypeCircular];
    [gainSlider setNeedsDisplay:YES];
}

- (void)setupVolumeSlider {
    volumeSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(60, 300, 30, 30)];
    [self addSubview:volumeSlider];
    [volumeSlider setSliderType:NSSliderTypeCircular];
    [volumeSlider setNeedsDisplay:YES];
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

@end
