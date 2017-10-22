//
//  PhaserUI.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/22/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "PhaserUI.h"

@implementation PhaserUI
- (instancetype)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    [self drawBorder:frameRect];
    return self;
}
- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

@end
