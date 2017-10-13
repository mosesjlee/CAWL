//
//  SoundTab.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "SoundTab.h"
NSArray * ampList = @[@"Phender BassWoman", @"Box DC30", @"Phender Princesston"];
NSArray * effectsList = @[@"Digital Delay", @"Reverb", @"Wah-Wah", @"Chorus", @"Overdrive", @"Fuzz", @"Compressor"];
@implementation SoundTab {
}
- (instancetype)initWithIdentifier:(id)identifier
{
    self = [super initWithIdentifier:identifier];
    
    _ampSelector = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(10, 350, 175, 50) pullsDown:NO];
    [_ampSelector addItemsWithTitles:ampList];
    [self.view addSubview:_ampSelector];
    [_ampSelector setNeedsDisplay:YES];
    
    
    _effectSelector1 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(250, 350, 175, 50) pullsDown:NO];
    [_effectSelector1 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector1];
    [_effectSelector1 setNeedsDisplay:YES];
    
    _effectSelector2 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(460, 350, 175, 50) pullsDown:NO];
    [_effectSelector2 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector2];
    [_effectSelector2 setNeedsDisplay:YES];
    
    _effectSelector3 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(670, 350, 175, 50) pullsDown:NO];
    [_effectSelector3 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector3];
    [_effectSelector3 setNeedsDisplay:YES];
    
    _effectSelector4 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(880, 350, 175, 50) pullsDown:NO];
    [_effectSelector4 addItemsWithTitles:effectsList];
    [self.view addSubview:_effectSelector4];
    [_effectSelector4 setNeedsDisplay:YES];
    
    return self;
}

- (void)drawLabel:(BOOL)shouldTruncateLabel
           inRect:(NSRect)labelRect
{
    [super drawLabel:shouldTruncateLabel inRect:labelRect];

}
@end
