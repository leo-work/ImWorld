//
//  QMacTools.cpp
//  IMWorld
//
//  Created by Leo on 2018/9/11.
//

#include "QMacTools.h"

#include <Cocoa/Cocoa.h>
#include <Qdebug>


namespace QMacTools {
    
    void windowDidEnterFullScreen(NSNotification * notification){
        NSLog(@"324234");
  
        //  [self windowResizeAction: true];
    }
    
//    (void)windowDidExitFullScreen:(NSNotification *)notification{
//
//        //  [self windowResizeAction: false];
//        g_fill = false;
//        NSLog(@"000000");
//    }
//
//    (void)windowDidResize:(NSNotification *)notification{
//        if(!g_fill){
//            //     [self windowResizeAction: false];
//            NSLog(@"8989");
//        }
//
//    }
    void InitWindow(WId w)
    {
        NSWindow* nw = [w window];
        nw.titleVisibility = NSWindowTitleHidden;
        nw.styleMask |= NSFullSizeContentViewWindowMask;
        nw.titlebarAppearsTransparent = YES;
    }
    
    void InitLoginWindow(WId w){
        NSWindow* nw = [w window];
        nw.titleVisibility = NSWindowTitleHidden;
        nw.styleMask |= NSFullSizeContentViewWindowMask;
        nw.titlebarAppearsTransparent = YES;
        NSButton *zoomButton = [nw standardWindowButton:NSWindowZoomButton];
        NSButton *minitButton = [nw standardWindowButton:NSWindowMiniaturizeButton];
        zoomButton.hidden = YES;
        minitButton.hidden = YES;
    }
    void CreateCocoaContianerForWindow(WId w, bool fullScreen)
    {
        NSWindow* nw = [w window];
        CGFloat kTitlebarHeight = 54.0;
        CGFloat kFullScreenButtonYOrigin = 3.0;
        CGFloat buttonX = 10.0;
        NSButton *closeButton = [nw standardWindowButton:NSWindowCloseButton];
        NSButton *minitButton = [nw standardWindowButton:NSWindowMiniaturizeButton];
        NSButton *zoomButton = [nw standardWindowButton:NSWindowZoomButton];
        zoomButton.enabled = NO;
        NSView * msTitleBar = closeButton.superview.superview;
        NSRect msTitleBarFrame = msTitleBar.frame;
        NSRect nwFrame = nw.frame;
        msTitleBarFrame.origin.y = nwFrame.size.height - kTitlebarHeight;
        msTitleBarFrame.size.height = CGFloat(kTitlebarHeight);
        msTitleBar.frame = msTitleBarFrame;
        msTitleBar.wantsLayer = YES; //需要先设置这个，再设置颜色，否则颜色无效
       
       // NSColor * nsColor = [NSColor colorWithCalibratedRed:242.0/255.0 green:242.0/255.0 blue:242.0/255.0 alpha:0.5];
       // msTitleBar.layer.backgroundColor = nsColor.CGColor;
        
        NSArray *array = [NSArray arrayWithObjects: closeButton, minitButton, zoomButton, nil];
        for (NSView * buttonView in array) {
            NSRect buttonFrame = buttonView.frame;
            buttonFrame.origin.y = fullScreen ? kFullScreenButtonYOrigin : round((kTitlebarHeight - (buttonFrame.size.height))/2.0);
            buttonFrame.origin.x = CGFloat(buttonX);
            buttonX = (buttonFrame.size.width) + 6 + buttonX;
            buttonView.frame = buttonFrame;
        }
    }
    
    void windowDidResize(NSNotification *aNotification)
    {
        // 调整NSWindow上NSView的frame
    }
};

