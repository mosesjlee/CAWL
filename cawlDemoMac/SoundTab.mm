//
//  SoundTab.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "SoundTab.h"
NSArray * ampList = @[@"Phender BassWoman",
                      @"Box DC30",
                      @"Phender Princesston"];
NSArray * effectsList = @[@"Off",
                          @"Digital Delay",
                          @"Reverb",
                          @"Wah-Wah",
                          @"Chorus",
                          @"Overdrive",
                          @"Fuzz",
                          @"Compressor"];
@implementation SoundTab {
}
- (instancetype)initWithIdentifier:(id)identifier
{
    self = [super initWithIdentifier:identifier];
    [self setupAmpSelector];
    [self setupEffectSelector1];
    [self setupEffectSelector2];
    [self setupEffectSelector3];
    [self setupEffectSelector4];
    return self;
}

- (void)setupAmpSelector {
    _ampSelector = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(10, 350, 250, 50) pullsDown:NO];
    [_ampSelector addItemsWithTitles:ampList];
    [self.view addSubview:_ampSelector];
    [_ampSelector setNeedsDisplay:YES];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(updateAmpSelection)
                                                 name:NSPopUpButtonCellWillPopUpNotification
                                               object:nil];
}

- (void) updateAmpSelection {
    NSLog(@"Amp selection %@", self.label);
}
     
- (void)setupEffectSelector1 {
    _effectSelector1 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(300, 350, 175, 50) pullsDown:NO];
    [_effectSelector1 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector1];
    [_effectSelector1 setNeedsDisplay:YES];
}

- (void)setupEffectSelector2 {
    _effectSelector2 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(510, 350, 175, 50) pullsDown:NO];
    [_effectSelector2 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector2];
    [_effectSelector2 setNeedsDisplay:YES];
}

- (void)setupEffectSelector3 {
    _effectSelector3 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(720, 350, 175, 50) pullsDown:NO];
    [_effectSelector3 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector3];
    [_effectSelector3 setNeedsDisplay:YES];
    
}

- (void)setupEffectSelector4 {
    _effectSelector4 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(930, 350, 175, 50) pullsDown:NO];
    [_effectSelector4 addItemsWithTitles:effectsList];
    [self.view addSubview:_effectSelector4];
    [_effectSelector4 setNeedsDisplay:YES];
}

- (void)drawLabel:(BOOL)shouldTruncateLabel
           inRect:(NSRect)labelRect
{
    [super drawLabel:shouldTruncateLabel inRect:labelRect];

}
@end
