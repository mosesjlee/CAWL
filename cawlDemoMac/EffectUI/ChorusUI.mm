//
//  ChorusUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/15/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "ChorusUI.h"

@implementation ChorusUI
- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    [self drawBorder:dirtyRect];
}

@end
