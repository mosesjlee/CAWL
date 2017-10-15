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
    NSTextField * volumeLabel;
    NSTextField * gainLabel;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupGainUI];
    [self setupVolumeUI];
    return self;
}

- (void)setupGainUI {
    gainSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(10, 300, 30, 30)];
    [self addSubview:gainSlider];
    [gainSlider setSliderType:NSSliderTypeCircular];
    [gainSlider setNeedsDisplay:YES];
    [gainSlider setMaxValue:1.0];
    [gainSlider setMinValue:0.0];
    [gainSlider setAction:@selector(updateGain)];
    
    //Set up label
    gainLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(10, 270, 30, 20)];
    [self addSubview:gainLabel];
    [gainLabel setNeedsDisplay:YES];
}

- (void) updateGain {
    gainLabel.stringValue = [NSString stringWithFormat:@"%f", gainSlider.doubleValue * 10.0];
    _soundTabRef.soundBoard->setNewAmpGain(gainSlider.doubleValue);
    NSLog(@"New Gain: %f", gainSlider.doubleValue);
}

- (void)setupVolumeUI {
    volumeSlider = [[NSSlider alloc] initWithFrame:NSMakeRect(60, 300, 30, 30)];
    [self addSubview:volumeSlider];
    [volumeSlider setSliderType:NSSliderTypeCircular];
    [volumeSlider setNeedsDisplay:YES];
    [volumeSlider setMaxValue:1.0];
    [volumeSlider setMinValue:0.0];
    [volumeSlider setAction:@selector(updateVolume)];
    
    volumeLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(60, 270, 30, 20)];
    [self addSubview:volumeLabel];
    [volumeLabel setNeedsDisplay:YES];
}

- (void) updateVolume {
    volumeLabel.stringValue = [NSString stringWithFormat:@"%f", volumeSlider.doubleValue * 10.0];
}


- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

@end
