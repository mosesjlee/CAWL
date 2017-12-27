//
//  CompressorUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "CompressorUI.h"

@implementation CompressorUI {
	NSSlider *thresholdSlider;
	NSSlider *kneeSlider;
	NSSlider *ratioSlider;
	NSSlider *gainSlider;
	
	NSTextField *thresholdTitle;
	NSTextField *kneeTitle;
	NSTextField *ratioTitle;
	NSTextField *gainTitle;
	
	NSTextField *thresholdLabel;
	NSTextField *kneeLabel;
	NSTextField *ratioLabel;
	NSTextField *gainLabel;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupThresholdUI];
    [self setupGainUI];
    [self setupKneeUI];
    [self setupRatioUI];
    return self;
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI
-(void) setupThresholdUI {
    thresholdTitle = [self drawLabelTextFieldWithRect:NSMakeRect(10, 320, 65, MAX_TEXTFIELD_HEIGHT)
                                            WithTitle:@"Threshold"
                                               toView:self];
    
    thresholdSlider = [self drawCircularSliderWithRect:NSMakeRect(25, 290, 30, 30)
                                            WithMaxVal:0
                                         AndWithMinVal:-60
                                          atDefaultVal:40
                                                toView:self
                                          withSelector:@selector(updateThresholdLevel:)];
    
    thresholdLabel = [self drawValueTextFieldWithRect:NSMakeRect(15, 260, 50, MAX_TEXTFIELD_HEIGHT)
                                               toView:self];
}

-(void) setupKneeUI {
    kneeTitle = [self drawLabelTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-50, 320, 40, MAX_TEXTFIELD_HEIGHT)
                                       WithTitle:@"Knee"
                                          toView:self];
    
    kneeSlider = [self drawCircularSliderWithRect:NSMakeRect(MAX_WIDTH/2-45, 290, 30, 30)
                                       WithMaxVal:20
                                    AndWithMinVal:0
                                     atDefaultVal:0.5
                                           toView:self
                                     withSelector:@selector(updateKneeLevel:)];
    
    kneeLabel = [self drawValueTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-55, 260, 50, MAX_TEXTFIELD_HEIGHT)
                                          toView:self];
}

-(void) setupRatioUI {
    ratioTitle = [self drawLabelTextFieldWithRect:NSMakeRect(MAX_WIDTH/2+5, 320, 40, MAX_TEXTFIELD_HEIGHT)
                                        WithTitle:@"Ratio"
                                           toView:self];
    
    ratioSlider = [self drawCircularSliderWithRect:NSMakeRect(MAX_WIDTH/2, 290, 40, 30)
                                        WithMaxVal:8
                                     AndWithMinVal:1
                                      atDefaultVal:1
                                            toView:self
                                      withSelector:@selector(updateRatio:)];
    
    ratioLabel = [self drawValueTextFieldWithRect:NSMakeRect(MAX_WIDTH/2, 260, 50, MAX_TEXTFIELD_HEIGHT)
                                           toView:self];
}

-(void) setupGainUI {
    gainTitle = [self drawLabelTextFieldWithRect:NSMakeRect(185, 320, 35, MAX_TEXTFIELD_HEIGHT)
                                       WithTitle:@"Gain"
                                          toView:self];
    
    gainSlider = [self drawCircularSliderWithRect:NSMakeRect(180, 290, 35, 30)
                                       WithMaxVal:12
                                    AndWithMinVal:0
                                     atDefaultVal:0
                                           toView:self
                                     withSelector:@selector(gainLevel:)];
    
    gainLabel = [self drawValueTextFieldWithRect:NSMakeRect(180, 260, 50, MAX_TEXTFIELD_HEIGHT)
                                          toView:self];
}

#pragma mark IBACTION_COMPRESSOR

-(IBAction) updateThresholdLevel:(id)sender {
    thresholdLabel.stringValue = [NSString stringWithFormat:@"%02d dB", thresholdSlider.intValue];
    self.soundTabRef.soundBoard->setCompressorThreshold(thresholdSlider.intValue);
}

-(IBAction) updateKneeLevel:(id)sender {
    kneeLabel.stringValue = [NSString stringWithFormat:@"%.02f", kneeSlider.floatValue];
    self.soundTabRef.soundBoard->setCompressorKnee(kneeSlider.intValue);
}

-(IBAction) updateRatio:(id)sender {
    ratioLabel.stringValue = [NSString stringWithFormat:@"%.01f : 1", ratioSlider.floatValue];
    self.soundTabRef.soundBoard->setCompressorRatio(ratioSlider.intValue);
}

-(IBAction) gainLevel:(id)sender {
    gainLabel.stringValue = [NSString stringWithFormat:@"%.01f", gainSlider.floatValue];
    self.soundTabRef.soundBoard->setCompressorGain(gainSlider.intValue);
}

@end





