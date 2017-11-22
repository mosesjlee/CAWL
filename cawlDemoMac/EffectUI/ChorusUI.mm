//
//  ChorusUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "ChorusUI.h"

@implementation ChorusUI {
	NSSlider *chorusRateSlider;
	NSSlider *chorusDepthSlider;
	NSSlider *chorusMixLevel;
	
	NSTextField *chorusRateTitle;
	NSTextField *chorusDepthTitle;
	NSTextField *chorusMixTitle;
    
    NSTextField *chorusRateValue;
    NSTextField *chorusDepthValue;
    NSTextField *chorusMixValue;
}

- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self setupChorusRateUI];
    [self setupChorusDepthUI];
    [self setupMixLevelUI];
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

#pragma mark SETUP_UI

-(void) setupChorusRateUI {
    chorusRateTitle = [self drawLabelTextFieldWithRect:NSMakeRect(20, 320, 40, 25)
                                             WithTitle:@"Rate"
                                                toView:self];
    
    chorusRateSlider = [self drawCircularSliderWithRect:NSMakeRect(20, 290, 30, 30)
                                             WithMaxVal:2.0
                                          AndWithMinVal:0.25
                                           atDefaultVal:1.0
                                                 toView:self
                                           withSelector:@selector(updateChorusRate:)];
    
    chorusRateValue = [self drawValueTextFieldWithRect:NSMakeRect(20, 260, 30, 25)
                                                toView:self];
}

-(void) setupChorusDepthUI {
	chorusDepthTitle = [self drawLabelTextFieldWithRect:NSMakeRect(85, 320, 45, 25)
                                              WithTitle:@"Depth"
                                                 toView:self];
    
    chorusDepthSlider = [self drawCircularSliderWithRect:NSMakeRect(90, 290, 30, 30)
                                              WithMaxVal:40
                                           AndWithMinVal:20
                                            atDefaultVal:30
                                                  toView:self
                                            withSelector:@selector(updateChorusDepthLevel:)];
    
    chorusDepthValue = [self drawValueTextFieldWithRect:NSMakeRect(90, 260, 30, 25)
                                                 toView:self];
}

-(void) setupMixLevelUI {
	chorusMixTitle = [self drawLabelTextFieldWithRect:NSMakeRect(160, 320, 30, 25)
                                            WithTitle:@"Mix"
                                               toView:self];
    
    chorusMixLevel = [self drawCircularSliderWithRect:NSMakeRect(160, 290, 30, 30)
                                           WithMaxVal:1.0
                                        AndWithMinVal:0.0
                                         atDefaultVal:1.0
                                               toView:self
                                         withSelector:@selector(updateMixLevel:)];
    
    chorusMixValue = [self drawValueTextFieldWithRect:NSMakeRect(160, 260, 30, 25)
                                               toView:self];
}

#pragma mark IBACTION_CHORUS

-(IBAction) updateChorusRate:(id)sender {
    chorusRateValue.stringValue = [NSString stringWithFormat:@"%f", chorusRateSlider.floatValue];
}

-(IBAction) updateChorusDepthLevel:(id)sender {
    chorusDepthValue.stringValue = [NSString stringWithFormat:@"%f", chorusDepthSlider.floatValue];
}

-(IBAction) updateMixLevel:(id)sender {
    chorusMixValue.stringValue = [NSString stringWithFormat:@"%f", chorusMixLevel.floatValue];
}

@end








