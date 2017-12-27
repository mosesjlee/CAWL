//
//  PhaserUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "PhaserUI.h"

@implementation PhaserUI {
	NSSlider *depthSlider;
	NSSlider *rateSlider;
	NSSlider *mixLevelSlider;
	
	NSTextField *depthTitle;
	NSTextField *rateTitle;
	NSTextField *mixLevelTitle;
    
    NSTextField *depthValueLabel;
    NSTextField *rateValueLabel;
    NSTextField *mixLevelValueLabel;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupDepthUI];
    [self setupRateUI];
    [self setupMixLevelUI];
    return self;
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI
- (void)setupDepthUI {
    depthTitle = [self drawLabelTextFieldWithRect:NSMakeRect(15, 320, 70, MAX_TEXTFIELD_HEIGHT)
                                        WithTitle:@"Depth"
                                           toView:self];
    
    depthSlider = [self drawCircularSliderWithRect:NSMakeRect(30, 290, 30, 30)
                                        WithMaxVal:1.0
                                     AndWithMinVal:0.0
                                      atDefaultVal:0.5
                                            toView:self
                                      withSelector:@selector(updateDepth:)];
    
    depthValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(20, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                toView:self];
}

- (void)setupRateUI {
    rateTitle = [self drawLabelTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-35, 320, 70, MAX_TEXTFIELD_HEIGHT)
                                       WithTitle:@"Rate"
                                          toView:self];
    
    rateSlider = [self drawCircularSliderWithRect:NSMakeRect(MAX_WIDTH/2-15, 290, 30, 30)
                                       WithMaxVal:1.0
                                    AndWithMinVal:0.0
                                     atDefaultVal:0.5
                                           toView:self
                                     withSelector:@selector(updateRate:)];
    
    rateValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(MAX_WIDTH/2-30, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                             toView:self];
}

- (void)setupMixLevelUI {
    mixLevelTitle = [self drawLabelTextFieldWithRect:NSMakeRect(165, 320, 70, MAX_TEXTFIELD_HEIGHT)
                                           WithTitle:@"Mix Level"
                                              toView:self];
    
    mixLevelSlider = [self drawCircularSliderWithRect:NSMakeRect(185, 290, 30, 30)
                                           WithMaxVal:1.0
                                        AndWithMinVal:0.0
                                         atDefaultVal:0.5
                                               toView:self
                                         withSelector:@selector(updateMixLevel:)];
    
    mixLevelValueLabel = [self drawValueTextFieldWithRect:NSMakeRect(170, 260, 60, MAX_TEXTFIELD_HEIGHT)
                                                   toView:self];
}

#pragma mark PHASER_IBACTION
- (IBAction)updateDepth:(id) sender {
    depthValueLabel.stringValue = [NSString stringWithFormat:@"%f", depthSlider.floatValue];
    self.soundTabRef.soundBoard->setPhaserDepth(depthSlider.floatValue);
}

- (IBAction)updateRate:(id)sender {
	rateValueLabel.stringValue = [NSString stringWithFormat:@"%f", rateSlider.floatValue];
    self.soundTabRef.soundBoard->setPhaserRate(rateSlider.floatValue);
}

- (IBAction)updateMixLevel:(id)sender {
	mixLevelValueLabel.stringValue = [NSString stringWithFormat:@"%.02f %%", mixLevelSlider.floatValue * 100];
    self.soundTabRef.soundBoard->setPhaserMixLevel(mixLevelSlider.floatValue);
}
@end


