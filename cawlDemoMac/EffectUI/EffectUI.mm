//
//  EffectUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "EffectUI.h"

@implementation EffectUI
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

- (NSSlider *)drawCircularSliderWithRect:(NSRect) rect
                              WithMaxVal:(float) max
                           AndWithMinVal:(float) min
{
    NSSlider * retval = [[NSSlider alloc] initWithFrame:rect];
    [retval setSliderType:NSSliderTypeCircular];
    [retval setMaxValue:max];
    [retval setMinValue:min];
    [retval setNeedsDisplay:YES];
    return retval;
}

- (NSSlider *)drawRegularSliderWithRect:(NSRect) rect
                             WithMaxVal:(float) max
                          AndWithMinVal:(float) min
{
    NSSlider * retval = [[NSSlider alloc] initWithFrame:rect];
    [retval setMaxValue:max];
    [retval setMinValue:min];
    [retval setNeedsDisplay:YES];
    return retval;
}

- (NSTextField *)drawLabelTextFieldWithRect:(NSRect) rect
                                  WithTitle:(NSString *)title
{
    NSTextField * retval = [[NSTextField alloc] initWithFrame:rect];
    retval.stringValue = title;
    [retval setEditable:NO];
    [retval setBordered:NO];
    [retval setDrawsBackground:NO];
    [retval setNeedsDisplay:YES];
    return retval;
}

- (NSTextField *)drawValueTextFieldWithRect:(NSRect) rect {
    NSTextField * retval = [[NSTextField alloc] initWithFrame:rect];
    [retval setNeedsDisplay:YES];
    return retval;
}

//From question:
//https://stackoverflow.com/questions/5004960/adding-border-and-rounded-rect-in-the-nsview
-(void)drawBorder:(NSRect)rect{
    NSRect frameRect = [self bounds];
    
    if(rect.size.height < frameRect.size.height)
        return;
    NSRect newRect = NSMakeRect(rect.origin.x+2, rect.origin.y+2, rect.size.width-3, rect.size.height-3);
    
    NSBezierPath *textViewSurround = [NSBezierPath bezierPathWithRoundedRect:newRect xRadius:10 yRadius:10];
    [textViewSurround setLineWidth:10];
    //[pBorderColor set];
    [textViewSurround stroke];
    [self setWantsLayer: YES];
    [self.layer setBorderWidth: 2];
    [self.layer setCornerRadius: 10];
}

@end
