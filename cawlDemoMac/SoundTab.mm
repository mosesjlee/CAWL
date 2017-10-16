//
//  SoundTab.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#import "SoundTab.h"
#import "AmpUI.h"
#import "DelayUI.h"
#import "EqualizerUI.h"


NSArray * ampList = @[@"Off",
                      @"Phender BassWoman",
                      @"Box DC30",
                      @"Phender Princesston"];

NSArray * effectsList = @[@"Off",
                          @"Digital Delay",
                          @"Reverb",
                          @"Wah-Wah",
                          @"Chorus",
                          @"Overdrive",
                          @"Fuzz",
                          @"Compressor",
                          @"Equalizer"];

@implementation SoundTab {
    NSString * currAmp;
    NSString * currEffect1, * currEffect2, * currEffect3, * currEffect4;
    AmpUI * ampUI;
    DelayUI * delayUI;
    EqualizerUI * equalizerUI;
}

- (instancetype)initWithIdentifier:(id)identifier
{
    self = [super initWithIdentifier:identifier];
    [self setupAmpSelector];
    [self setupEffectSelector1];
    [self setupEffectSelector2];
    [self setupEffectSelector3];
    [self setupEffectSelector4];
    currAmp = [_ampSelector selectedItem].title;
    
    [self createAmpUI];
    [self createDelayUI];
    _soundBoard = new CAWLSoundBoard();
    __block CAWLSoundBoard * weak = _soundBoard;
    _buffer = ^(float * buf, const unsigned int numSamples) {
        weak->processBuffer(buf, numSamples);
    };
    
    return self;
}

- (void)drawLabel:(BOOL)shouldTruncateLabel
           inRect:(NSRect)labelRect
{
    [super drawLabel:shouldTruncateLabel inRect:labelRect];
}

- (cawlBuffers) getSoundBoardRef {
    return _buffer;
}

- (void)setupAmpSelector {
    _ampSelector = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(10, 350, 250, 50) pullsDown:NO];
    [_ampSelector addItemsWithTitles:ampList];
    [self.view addSubview:_ampSelector];
    [_ampSelector setNeedsDisplay:YES];
    [_ampSelector setAction:@selector(updateAmpSelection:)];
    [_ampSelector setTarget:self];
}

- (void) updateAmpSelection:(id)sender {
    currAmp =  [_ampSelector selectedItem].title;
    NSLog(@"Amp selection %@ for %@", currAmp, self.label);
    [self drawAmpUI];
}
     
- (void)setupEffectSelector1 {
    _effectSelector1 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(300, 350, 175, 50) pullsDown:NO];
    [_effectSelector1 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector1];
    [_effectSelector1 setNeedsDisplay:YES];
    [_effectSelector1 setAction:@selector(updateEffect1Selection:)];
    [_effectSelector1 setTarget:self];
}

- (void) updateEffect1Selection:(id)sender {
    //See if the selectd effect is used
    if(([currEffect2 isEqualToString:[_effectSelector1 selectedItem].title] ||
       [currEffect3 isEqualToString:[_effectSelector1 selectedItem].title] ||
       [currEffect4 isEqualToString:[_effectSelector1 selectedItem].title]) &&
       ![[_effectSelector1 selectedItem].title isEqualToString:effectsList[0]]) {
        NSAlert *alert = [[NSAlert alloc] init];
        [alert addButtonWithTitle:@"OK"];
        [alert setInformativeText:@"Effect already being used."];
        [alert setAlertStyle:NSWarningAlertStyle];
        if ([alert runModal] == NSAlertFirstButtonReturn) {
            return;
        }
    }
    
    currEffect1 =  [_effectSelector1 selectedItem].title;
    NSLog(@"Effect 1 selection %@ for %@", currEffect1, self.label);
    
    if([currEffect1 isEqualToString:effectsList[1]]) {
        [self drawDelayUI:NSMakePoint(300, 0)];
        _soundBoard->setDelayOnOff(true);
    }
}

- (void)setupEffectSelector2 {
    _effectSelector2 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(530, 350, 175, 50) pullsDown:NO];
    [_effectSelector2 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector2];
    [_effectSelector2 setNeedsDisplay:YES];
    [_effectSelector2 setAction:@selector(updateEffect2Selection:)];
    [_effectSelector2 setTarget:self];
}

- (void) updateEffect2Selection:(id)sender {
    if([currEffect1 isEqualToString:[_effectSelector1 selectedItem].title] ||
       [currEffect3 isEqualToString:[_effectSelector1 selectedItem].title] ||
       [currEffect4 isEqualToString:[_effectSelector1 selectedItem].title]) {
        NSAlert *alert = [[NSAlert alloc] init];
        [alert addButtonWithTitle:@"OK"];
        [alert setInformativeText:@"Effect already being used."];
        [alert setAlertStyle:NSWarningAlertStyle];
        if ([alert runModal] == NSAlertFirstButtonReturn) {
            return;
        }
    }
    
    currEffect2 =  [_effectSelector2 selectedItem].title;
    NSLog(@"Effect 2 selection %@ for %@", currEffect2, self.label);
    
    if([currEffect2 isEqualToString:effectsList[1]]) {
        [self drawDelayUI:NSMakePoint(530, 0)];
        _soundBoard->setDelayOnOff(true);
    }
}

- (void)setupEffectSelector3 {
    _effectSelector3 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(750, 350, 175, 50) pullsDown:NO];
    [_effectSelector3 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector3];
    [_effectSelector3 setNeedsDisplay:YES];
    [_effectSelector3 setAction:@selector(updateEffect3Selection:)];
    [_effectSelector3 setTarget:self];
    
}

- (void) updateEffect3Selection:(id)sender {
    if([currEffect1 isEqualToString:[_effectSelector1 selectedItem].title] ||
       [currEffect2 isEqualToString:[_effectSelector1 selectedItem].title] ||
       [currEffect4 isEqualToString:[_effectSelector1 selectedItem].title]) {
        NSAlert *alert = [[NSAlert alloc] init];
        [alert addButtonWithTitle:@"OK"];
        [alert setInformativeText:@"Effect already being used."];
        [alert setAlertStyle:NSWarningAlertStyle];
        if ([alert runModal] == NSAlertFirstButtonReturn) {
            return;
        }
    }
    currEffect3 =  [_effectSelector3 selectedItem].title;
    NSLog(@"Effect 3 selection %@ for %@", currEffect3, self.label);
    if([currEffect3 isEqualToString:effectsList[1]]) {
        [self drawDelayUI:NSMakePoint(750, 0)];
        _soundBoard->setDelayOnOff(true);
    }
}

- (void)setupEffectSelector4 {
    _effectSelector4 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(970, 350, 175, 50) pullsDown:NO];
    [_effectSelector4 addItemsWithTitles:effectsList];
    [self.view addSubview:_effectSelector4];
    [_effectSelector4 setNeedsDisplay:YES];
    [_effectSelector4 setAction:@selector(updateEffect4Selection:)];
    [_effectSelector4 setTarget:self];
}

- (void) updateEffect4Selection:(id)sender {
    if([currEffect1 isEqualToString:[_effectSelector1 selectedItem].title] ||
       [currEffect2 isEqualToString:[_effectSelector1 selectedItem].title] ||
       [currEffect3 isEqualToString:[_effectSelector1 selectedItem].title]) {
        NSAlert *alert = [[NSAlert alloc] init];
        [alert addButtonWithTitle:@"OK"];
        [alert setInformativeText:@"Effect already being used."];
        [alert setAlertStyle:NSWarningAlertStyle];
        if ([alert runModal] == NSAlertFirstButtonReturn) {
            return;
        }
    }
    currEffect4 =  [_effectSelector4 selectedItem].title;
    NSLog(@"Effect 4 selection %@ for %@", currEffect4, self.label);
    if([currEffect4 isEqualToString:effectsList[1]]) {
        [self drawDelayUI:NSMakePoint(970, 0)];
        _soundBoard->setDelayOnOff(true);
    }
}

#pragma mark UI_Creation
- (void) createAmpUI {
    ampUI = [[AmpUI alloc] initWithFrame:NSMakeRect(0, 0, 300, 600)];
    [ampUI setFrameOrigin:NSMakePoint(0, 0)];
    [self.view addSubview:ampUI];
    [ampUI setHidden:YES];
    [ampUI setNeedsLayout:YES];
    ampUI.soundTabRef = self;
}

- (void)createDelayUI {
    delayUI = [[DelayUI alloc] initWithFrame:NSMakeRect(0, 0, 300, 600)];
    [self.view addSubview:delayUI];
    [delayUI setHidden:YES];
    [delayUI setNeedsLayout:YES];
    delayUI.soundTabRef = self;
}

- (void)createReverbUI {
    
}

- (void)createWahUI {
    
}

- (void)createChorusUI {
    
}

- (void)createOverdriveUI {
    
}

- (void)createFuzzUI {
    
}

- (void)createCompressorUI {
    
}

#pragma mark UI_drawing
- (void)drawAmpUI {
    [ampUI setHidden:NO];
}

- (void)drawDelayUI:(NSPoint) newPoint{
    [delayUI setFrameOrigin:newPoint];
    [delayUI setHidden:NO];
}

- (void)drawReverbUI {
    
}

- (void)drawWahUI {
    
}

- (void)drawChorusUI {
    
}

- (void)drawOverdriveUI {
    
}

- (void)drawFuzzUI {
    
}

- (void)drawCompressorUI {
    
}

#pragma mark Hide_UI

- (void)hideAmpUI {
    [ampUI setHidden:YES];
}

- (void)hideDelayUI{
    [delayUI setHidden:YES];
}

- (void)hideReverbUI {
    
}

- (void)hideWahUI {
    
}

- (void)hideChorusUI {
    
}

- (void)hideOverdriveUI {
    
}

- (void)hideFuzzUI {
    
}

- (void)hideCompressorUI {
    
}
@end
