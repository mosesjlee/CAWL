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
	NSSlider * bassSlider;
	NSSlider * midSlider;
	NSSlider * trebleSlider;
	
	
    NSTextField * volumeLabel;
    NSTextField * gainLabel;
	NSTextField * bassValueLabel;
	NSTextField * midValueLabel;
	NSTextField * trebleValueLabel;
	
    NSTextField * volumeTitle;
    NSTextField * gainTitle;
	NSTextField * bassTitle;
	NSTextField * midTitle;
	NSTextField * trebleTitle;
	
	NSTextField *ampTitle;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupGainUI];
    [self setupVolumeUI];
	[self setupBassUI];
	[self setupMidUI];
	[self setupTrebelUI];
	ampTitle = [self drawLabelTextFieldWithRect:NSMakeRect(60, 140, 150, 25)
									  	WithTitle:@""
										 	toView:self];
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
									 withSelector:@selector(updateGain:)];
    
    //Set up label
    gainLabel = [self drawValueTextFieldWithRect:NSMakeRect(10, 270, 30, 20)
                                          toView:self];
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
									   withSelector:@selector(updateVolume:)];
    
    volumeLabel = [self drawValueTextFieldWithRect:NSMakeRect(60, 270, 30, 20)
                                            toView:self];
}

- (void)setupBassUI {
	bassTitle = [self drawLabelTextFieldWithRect:NSMakeRect(105, 240, 50, 20)
									   WithTitle:@"Bass"
										  toView:self];
	bassSlider = [self drawCircularSliderWithRect:NSMakeRect(105, 300, 30, 30)
									   WithMaxVal:1.0
									AndWithMinVal:0.0
									atDefaultVal:0.5
										   toView:self
									 withSelector:@selector(updateBass:)];
	bassValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(105, 270, 30, 20)
											   toView:self];
}

- (void)setupMidUI {
	midTitle = [self drawLabelTextFieldWithRect:NSMakeRect(160, 240, 50, 20)
									   WithTitle:@"Mid"
										  toView:self];
	midSlider = [self drawCircularSliderWithRect:NSMakeRect(160, 300, 30, 30)
									   WithMaxVal:1.0
									AndWithMinVal:0.0
									 atDefaultVal:0.5
										   toView:self
									 withSelector:@selector(updateMids:)];
	midValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(160, 270, 30, 20)
											   toView:self];
}

- (void)setupTrebelUI {
	trebleTitle = [self drawLabelTextFieldWithRect:NSMakeRect(210, 240, 50, 20)
										 WithTitle:@"Treble"
										  	toView:self];
	trebleSlider = [self drawCircularSliderWithRect:NSMakeRect(210, 300, 30, 30)
										 WithMaxVal:1.0
									  AndWithMinVal:0.0
									   atDefaultVal:0.5
											 toView:self
									   withSelector:@selector(updateTreble:)];
	trebleValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(210, 270, 30, 20)
												 toView:self];
	
}

- (void) setAmpTitle:(NSString *)title
{
	ampTitle.stringValue = title;
}

- (IBAction) updateVolume:(id) sender {
    volumeLabel.stringValue = [NSString stringWithFormat:@"%f", volumeSlider.doubleValue * 10.0];
	self.soundTabRef.soundBoard->setNewAmpGain(gainSlider.doubleValue);
}

- (IBAction)updateGain:(id) sender {
	gainLabel.stringValue = [NSString stringWithFormat:@"%f", gainSlider.doubleValue * 10.0];
	self.soundTabRef.soundBoard->setNewAmpGain(gainSlider.doubleValue);
}

- (IBAction)updateBass:(id) sender {
	bassValueLabel.stringValue = [NSString stringWithFormat:@"%f", bassSlider.doubleValue * 10];
	self.soundTabRef.soundBoard->setAmpBass(bassSlider.doubleValue);
}

- (IBAction)updateMids:(id) sender {
	midValueLabel.stringValue = [NSString stringWithFormat:@"%f", midSlider.doubleValue * 10];
	self.soundTabRef.soundBoard->setAmpMids(midSlider.doubleValue);
}

- (IBAction)updateTreble:(id) sender {
	trebleValueLabel.stringValue = [NSString stringWithFormat:@"%f", trebleSlider.doubleValue * 10];
	self.soundTabRef.soundBoard->setAmpTreble(trebleSlider.doubleValue);
}


- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

@end
