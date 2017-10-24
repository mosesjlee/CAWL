//
//  EffectUI.h
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SoundTab.h"

@interface EffectUI : NSView
@property SoundTab *soundTabRef;
- (NSSlider *)drawCircularSliderWithRect:(NSRect) rect
                              WithMaxVal:(float) max
                           AndWithMinVal:(float) min;
- (NSSlider *)drawRegularSliderWithRect:(NSRect) rect
                             WithMaxVal:(float) max
                          AndWithMinVal:(float) min;;
- (NSTextField *)drawLabelTextFieldWithRect:(NSRect) rect
                                  WithTitle:(NSString *)title;
- (NSTextField *)drawValueTextFieldWithRect:(NSRect) rect;

-(void)drawBorder:(NSRect)rect;
@end

