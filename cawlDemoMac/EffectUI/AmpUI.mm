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
    NSTextField * volumeTitle;
    NSTextField * gainTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupGainUI];
    [self setupVolumeUI];
    return self;
}

- (void)setupGainUI {
    //Adding title
    gainTitle = [self drawLabelTextFieldWithRect:NSMakeRect(10, 240, 40, 20)
                                       WithTitle:@"Gain"
                                          toView:self];
    
    //The slider
    gainSlider = [self drawCircularSliderWithRect:NSMakeRect(10, 300, 30, 30)
                                       WithMaxVal:1.0
                                    AndWithMinVal:0.0
                                     atDefaultVal:0.5
                                           toView:self
                                     withSelector:@selector(updateGain)];
    
    //Set up label
    gainLabel = [self drawValueTextFieldWithRect:NSMakeRect(10, 270, 30, 20)
                                          toView:self];
}

- (void) updateGain {
    gainLabel.stringValue = [NSString stringWithFormat:@"%f", gainSlider.doubleValue * 10.0];
    self.soundTabRef.soundBoard->setNewAmpGain(gainSlider.doubleValue);
    
}

- (void)setupVolumeUI {
    volumeTitle = [self drawLabelTextFieldWithRect:NSMakeRect(55, 240, 50, 20)
                                         WithTitle:@"Volume"
                                            toView:self];
    
    volumeSlider = [self drawCircularSliderWithRect:NSMakeRect(60, 300, 30, 30)
                                         WithMaxVal:1.0
                                      AndWithMinVal:0.0
                                       atDefaultVal:0.5
                                             toView:self
                                       withSelector:@selector(updateVolume)];
    
    volumeLabel = [self drawValueTextFieldWithRect:NSMakeRect(60, 270, 30, 20)
                                            toView:self];
}

- (void) updateVolume {
    volumeLabel.stringValue = [NSString stringWithFormat:@"%f", volumeSlider.doubleValue * 10.0];
}


- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

@end
