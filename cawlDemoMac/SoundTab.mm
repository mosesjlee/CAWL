//
//  SoundTab.m
//  cawlDemoMac
//
//  Created by Moses Lee on 10/12/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#ifdef DEBUG
#include "DebugUtilities.hpp"
#endif

#import "SoundTab.h"
#import "AmpUI.h"
#import "DelayUI.h"
#import "EqualizerUI.h"
#import "ReverbUI.h"
#import "ChorusUI.h"
#import "WahUI.h"
#import "OverdriveUI.h"
#import "FuzzUI.h"
#import "CompressorUI.h"
#import "PhaserUI.h"
#import "FlangerUI.h"


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
                          @"Equalizer",
                          @"Phaser",
                          @"Flanger"];

@implementation SoundTab {
    NSString * currAmp;
    NSString * currEffect1, * currEffect2, * currEffect3, * currEffect4;
    NSMutableArray<NSString *> * currentEffectsList;
    AmpUI           *ampUI;
    DelayUI         *delayUI;
    EqualizerUI     *equalizerUI;
    ReverbUI        *reverbUI;
    ChorusUI        *chorusUI;
    WahUI           *wahUI;
    OverdriveUI     *overdriveUI;
    FuzzUI          *fuzzUI;
    CompressorUI    *compressorUI;
    PhaserUI        *phaserUI;
    FlangerUI       *flangerUI;
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
    currentEffectsList = [[NSMutableArray alloc] init];
    
    //Create the UI Elements
    [self createAmpUI];
    [self createDelayUI];
    [self createEqualizerUI];
    [self createReverbUI];
    [self createChorusUI];
    [self createWahUI];
    [self createFlangerUI];
    [self createOverdriveUI];
    [self createFuzzUI];
    [self createCompressorUI];
    [self createPhaserUI];
    
    //Create soundboard object
    _soundBoard = new CAWLSoundBoard();
    
    //fillGuitarStream();
    
    //Register the block
    __block CAWLSoundBoard * weak = _soundBoard;
    _buffer = ^(float * buf, const unsigned int numSamples) {
        //testBuffer(buf, numSamples);
        weak->processBuffer(buf, numSamples);
    };
    return self;
}

- (void)drawLabel:(BOOL)shouldTruncateLabel
           inRect:(NSRect)labelRect
{
    [super drawLabel:shouldTruncateLabel inRect:labelRect];
}

- (cawlBuffer) getSoundBoardRef {
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
    if([currAmp isEqualToString:ampList[0]]) {
        _soundBoard->setTurnOnAmp(false);
        [self hideAmpUI];
    } else if ([currAmp isEqualToString:ampList[1]]) {
        _soundBoard->setTurnOnAmp(true);
		_soundBoard->selectAmpType(1);
		[self drawAmpUI:1];
	} else if ([currAmp isEqualToString:ampList[2]]) {
		_soundBoard->setTurnOnAmp(true);
		_soundBoard->selectAmpType(2);
		[self drawAmpUI:2];
	} else if ([currAmp isEqualToString:ampList[3]]) {
		_soundBoard->setTurnOnAmp(true);
		_soundBoard->selectAmpType(3);
		[self drawAmpUI:3];
	}
}

#pragma mark SETUP_EFFECT_MENU
- (void)setupEffectSelector1 {
    _effectSelector1 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(320, 350, 175, 50) pullsDown:NO];
    [_effectSelector1 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector1];
    [_effectSelector1 setNeedsDisplay:YES];
    [_effectSelector1 setAction:@selector(updateEffect1Selection:)];
    [_effectSelector1 setTarget:self];
}

- (void)setupEffectSelector2 {
    _effectSelector2 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(590, 350, 175, 50) pullsDown:NO];
    [_effectSelector2 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector2];
    [_effectSelector2 setNeedsDisplay:YES];
    [_effectSelector2 setAction:@selector(updateEffect2Selection:)];
    [_effectSelector2 setTarget:self];
}

- (void)setupEffectSelector3 {
    _effectSelector3 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(850, 350, 175, 50) pullsDown:NO];
    [_effectSelector3 addItemsWithTitles:effectsList];;
    [self.view addSubview:_effectSelector3];
    [_effectSelector3 setNeedsDisplay:YES];
    [_effectSelector3 setAction:@selector(updateEffect3Selection:)];
    [_effectSelector3 setTarget:self];
}

- (void)setupEffectSelector4 {
    _effectSelector4 = [[NSPopUpButton alloc] initWithFrame:NSMakeRect(1115, 350, 175, 50) pullsDown:NO];
    [_effectSelector4 addItemsWithTitles:effectsList];
    [self.view addSubview:_effectSelector4];
    [_effectSelector4 setNeedsDisplay:YES];
    [_effectSelector4 setAction:@selector(updateEffect4Selection:)];
    [_effectSelector4 setTarget:self];
}

#pragma mark UPDATE_EFFECT_MENU
- (void) updateEffect1Selection:(id)sender {
    //See if the selectd effect is used
    if([currentEffectsList containsObject:[_effectSelector1 selectedItem].title] &&
       ![[_effectSelector1 selectedItem].title isEqualToString:effectsList[0]]) {
        NSAlert *alert = [[NSAlert alloc] init];
        [alert addButtonWithTitle:@"OK"];
        [alert setInformativeText:@"Effect already being used."];
        [alert setAlertStyle:NSWarningAlertStyle];
        if ([alert runModal] == NSAlertFirstButtonReturn) {
            return;
        }
    }
    
    //Turn off previous effect and disable previous UI
    [self turnOffSelectedEffect:currEffect1];
    
    //Update the new currEffect
    currEffect1 =  [_effectSelector1 selectedItem].title;
    NSLog(@"Effect 1 selection %@ for %@", currEffect1, self.label);
    
    //Turn on new effect and draw new UI
    [self turnOnSelectedEffect:currEffect1 with:NSMakePoint(285, 0)];
}

- (void) updateEffect2Selection:(id)sender {
    if([currentEffectsList containsObject:[_effectSelector2 selectedItem].title] &&
       ![[_effectSelector2 selectedItem].title isEqualToString:effectsList[0]]) {
        NSAlert *alert = [[NSAlert alloc] init];
        [alert addButtonWithTitle:@"OK"];
        [alert setInformativeText:@"Effect already being used."];
        [alert setAlertStyle:NSWarningAlertStyle];
        if ([alert runModal] == NSAlertFirstButtonReturn) {
            return;
        }
    }
    
    //Turn off previous effect and disable previous UI
    [self turnOffSelectedEffect:currEffect2];
    
    //Update the new currEffect
    currEffect2 =  [_effectSelector2 selectedItem].title;
    NSLog(@"Effect 2 selection %@ for %@", currEffect2, self.label);
    
    //Turn on new effect and draw new UI
    [self turnOnSelectedEffect:currEffect2 with:NSMakePoint(550, 0)];
    NSLog(@"Effect 2 selection %@ for %@", currEffect2, self.label);
}

- (void) updateEffect3Selection:(id)sender {
    if([currentEffectsList containsObject:[_effectSelector3 selectedItem].title] &&
       ![[_effectSelector3 selectedItem].title isEqualToString:effectsList[0]]) {
        NSAlert *alert = [[NSAlert alloc] init];
        [alert addButtonWithTitle:@"OK"];
        [alert setInformativeText:@"Effect already being used."];
        [alert setAlertStyle:NSWarningAlertStyle];
        if ([alert runModal] == NSAlertFirstButtonReturn) {
            return;
        }
    }
    
    //Turn off previous effect and disable previous UI
    [self turnOffSelectedEffect:currEffect3];
    
    //Update the new currEffect
    currEffect3 =  [_effectSelector3 selectedItem].title;
    NSLog(@"Effect 1 selection %@ for %@", currEffect2, self.label);
    
    //Turn on new effect and draw new UI
    [self turnOnSelectedEffect:currEffect3 with:NSMakePoint(815, 0)];
    NSLog(@"Effect 2 selection %@ for %@", currEffect3, self.label);
}

- (void) updateEffect4Selection:(id)sender {
    if([currentEffectsList containsObject:[_effectSelector4 selectedItem].title] &&
       ![[_effectSelector4 selectedItem].title isEqualToString:effectsList[0]]) {
        NSAlert *alert = [[NSAlert alloc] init];
        [alert addButtonWithTitle:@"OK"];
        [alert setInformativeText:@"Effect already being used."];
        [alert setAlertStyle:NSWarningAlertStyle];
        if ([alert runModal] == NSAlertFirstButtonReturn) {
            return;
        }
    }
    
    //Turn off previous effect and disable previous UI
    [self turnOffSelectedEffect:currEffect4];
    
    //Update the new currEffect
    currEffect4 =  [_effectSelector4 selectedItem].title;
    NSLog(@"Effect 4 selection %@ for %@", currEffect4, self.label);
    
    //Turn on new effect and draw new UI
    [self turnOnSelectedEffect:currEffect4 with:NSMakePoint(1080, 0)];
}

#pragma mark UI_Utilities
- (BOOL) isEffectExist:(NSString *) currEffect AtSlot:(int) slot {
    BOOL retval = NO;
    
    switch (slot) {
        case 1: {
            
        }
            break;
        case 2: {
            
        }
            break;
        case 3: {
            
        }
            break;
        case 4: {
            
        }
            break;
        //default:
            
    }
    
    NSAlert *alert = [[NSAlert alloc] init];
    [alert addButtonWithTitle:@"OK"];
    [alert setInformativeText:@"Effect already being used."];
    [alert setAlertStyle:NSWarningAlertStyle];
    if ([alert runModal] == NSAlertFirstButtonReturn) {
        return retval;
    }
    
    return retval;
}

- (void)turnOffSelectedEffect:(NSString *) effect
{
    [currentEffectsList removeObject:effect];
    if([effect isEqualToString:effectsList[0]]) {
        return;
    }
    else if([effect isEqualToString:effectsList[1]]) {
        _soundBoard->turnOnDelay(false);
        [self hideEffectUI:delayUI];
    }
    else if([effect isEqualToString:effectsList[2]]) {
        _soundBoard->turnOnReverb(false);
        [self hideEffectUI:reverbUI];
    }
    else if([effect isEqualToString:effectsList[3]]) {
        _soundBoard->turnOnWah(false);
        [self hideEffectUI:wahUI];
    }
    else if([effect isEqualToString:effectsList[4]]) {
        _soundBoard->turnOnChorus(false);
        [self hideEffectUI:chorusUI];
    }
    else if([effect isEqualToString:effectsList[5]]) {
        _soundBoard->turnOnOverdrive(false);
        [self hideEffectUI:overdriveUI];
    }
    else if([effect isEqualToString:effectsList[6]]) {
        _soundBoard->turnOnFuzz(false);
        [self hideEffectUI:fuzzUI];
    }
    else if([effect isEqualToString:effectsList[7]]) {
        _soundBoard->turnOnCompressor(false);
        [self hideEffectUI:compressorUI];
    }
    else if([effect isEqualToString:effectsList[8]]) {
        _soundBoard->turnOnEqualizer(false);
        [self hideEffectUI:equalizerUI];
    }
    else if([effect isEqualToString:effectsList[9]]) {
        _soundBoard->turnOnPhaser(false);
        [self hideEffectUI:phaserUI];
    }
    else if([effect isEqualToString:effectsList[10]]) {
        _soundBoard->turnOnFlanger(false);
        [self hideEffectUI:flangerUI];
    }
}

- (void)turnOnSelectedEffect:(NSString *) effect
                        with:(NSPoint) coordinate
{
    if([effect isEqualToString:effectsList[0]]) {
        return;
    }
    else if([effect isEqualToString:effectsList[1]]) {
        _soundBoard->turnOnDelay(true);
        [self drawEffectUI:delayUI with:coordinate];
    }
    else if([effect isEqualToString:effectsList[2]]) {
        _soundBoard->turnOnReverb(true);
        [self drawEffectUI:reverbUI with:coordinate];
    }
    else if([effect isEqualToString:effectsList[3]]) {
        _soundBoard->turnOnWah(true);
        [self drawEffectUI:wahUI with:coordinate];
    }
    else if([effect isEqualToString:effectsList[4]]) {
        _soundBoard->turnOnChorus(true);
        [self drawEffectUI:chorusUI with:coordinate];
    }
    else if([effect isEqualToString:effectsList[5]]) {
        _soundBoard->turnOnOverdrive(true);
        [self drawEffectUI:overdriveUI with:coordinate];
    }
    else if([effect isEqualToString:effectsList[6]]) {
        _soundBoard->turnOnFuzz(true);
        [self drawEffectUI:fuzzUI with:coordinate];
        
    }
    else if([effect isEqualToString:effectsList[7]]) {
        _soundBoard->turnOnCompressor(true);
        [self drawEffectUI:compressorUI with:coordinate];
        
    }
    else if([effect isEqualToString:effectsList[8]]) {
        _soundBoard->turnOnEqualizer(true);
        [self drawEffectUI:equalizerUI with:coordinate];
        
    }
    else if([effect isEqualToString:effectsList[9]]) {
        _soundBoard->turnOnPhaser(true);
        [self drawEffectUI:phaserUI with:coordinate];
    }
    else if([effect isEqualToString:effectsList[10]]) {
        _soundBoard->turnOnFlanger(true);
        [self drawEffectUI:flangerUI with:coordinate];
    }
    
    //Add it to the list
    [currentEffectsList addObject:effect];
}

#pragma mark UI_Creation
- (void) createAmpUI {
    ampUI = [[AmpUI alloc] initWithFrame:NSMakeRect(0, 0, 265, MAX_HEIGHT)];
    [ampUI setFrameOrigin:NSMakePoint(0, 0)];
    [self.view addSubview:ampUI];
    [ampUI setHidden:YES];
    [ampUI setNeedsLayout:YES];
    ampUI.soundTabRef = self;
}

- (void)createDelayUI {
    delayUI = [[DelayUI alloc] initWithFrame:NSMakeRect(0, 0, MAX_WIDTH, MAX_HEIGHT)];
    [self.view addSubview:delayUI];
    [delayUI setHidden:YES];
    [delayUI setNeedsLayout:YES];
    delayUI.soundTabRef = self;
}

- (void)createEqualizerUI {
    equalizerUI = [[EqualizerUI alloc] initWithFrame:NSMakeRect(0, 0, MAX_WIDTH, MAX_HEIGHT)];
    [self.view addSubview:equalizerUI];
    [equalizerUI setHidden:YES];
    [equalizerUI setNeedsLayout:YES];
    equalizerUI.soundTabRef = self;
}

- (void)createReverbUI {
    reverbUI = [[ReverbUI alloc] initWithFrame:NSMakeRect(0, 0, MAX_WIDTH, MAX_HEIGHT)];
    [self.view addSubview:reverbUI];
    [reverbUI setHidden:YES];
    [reverbUI setNeedsLayout:YES];
    reverbUI.soundTabRef = self;
}

- (void)createWahUI {
    wahUI = [[WahUI alloc] initWithFrame:NSMakeRect(0, 0, MAX_WIDTH, MAX_HEIGHT)];
    [self.view addSubview:wahUI];
    [wahUI setHidden:YES];
    [wahUI setNeedsLayout:YES];
    wahUI.soundTabRef = self;
}

- (void)createChorusUI {
    chorusUI = [[ChorusUI alloc] initWithFrame:NSMakeRect(0, 0, MAX_WIDTH, MAX_HEIGHT)];
    [self.view addSubview:chorusUI];
    [chorusUI setHidden:YES];
    [chorusUI setNeedsLayout:YES];
    chorusUI.soundTabRef = self;
}

- (void)createOverdriveUI {
    overdriveUI = [[OverdriveUI alloc] initWithFrame:NSMakeRect(0, 0, MAX_WIDTH, MAX_HEIGHT)];
    [self.view addSubview:overdriveUI];
    [overdriveUI setHidden:YES];
    [overdriveUI setNeedsLayout:YES];
    overdriveUI.soundTabRef = self;
}

- (void)createFuzzUI {
    fuzzUI = [[FuzzUI alloc] initWithFrame:NSMakeRect(0, 0, MAX_WIDTH, MAX_HEIGHT)];
    [self.view addSubview:fuzzUI];
    [fuzzUI setHidden:YES];
    [fuzzUI setNeedsLayout:YES];
    fuzzUI.soundTabRef = self;
}

- (void)createCompressorUI {
    compressorUI = [[CompressorUI alloc] initWithFrame:NSMakeRect(0, 0, MAX_WIDTH, MAX_HEIGHT)];
    [self.view addSubview:compressorUI];
    [compressorUI setHidden:YES];
    [compressorUI setNeedsLayout:YES];
    compressorUI.soundTabRef = self;
}

- (void)createFlangerUI {
    flangerUI = [[FlangerUI alloc] initWithFrame:NSMakeRect(0, 0, MAX_WIDTH, MAX_HEIGHT)];
    [self.view addSubview:flangerUI];
    [flangerUI setHidden:YES];
    [flangerUI setNeedsLayout:YES];
    flangerUI.soundTabRef = self;
}

- (void)createPhaserUI {
    phaserUI = [[PhaserUI alloc] initWithFrame:NSMakeRect(0, 0, MAX_WIDTH, MAX_HEIGHT)];
    [self.view addSubview:phaserUI];
    [phaserUI setHidden:YES];
    [phaserUI setNeedsLayout:YES];
    phaserUI.soundTabRef = self;
}

- (void)createUI:(EffectUI *) ui{
    
}

#pragma mark UI_drawing
- (void)drawAmpUI:(int) model {
    [ampUI setHidden:NO];
	[ampUI setAmpTitle:ampList[model]];
}

- (void)drawEffectUI:(EffectUI *) ui with:(NSPoint) newPoint{
    [ui setFrameOrigin:newPoint];
    [ui setHidden:NO];
}

#pragma mark Hide_UI

- (void)hideAmpUI {
    [ampUI setHidden:YES];
}

- (void)hideEffectUI:(EffectUI *) ui{
    [ui setHidden:YES];
}
@end
