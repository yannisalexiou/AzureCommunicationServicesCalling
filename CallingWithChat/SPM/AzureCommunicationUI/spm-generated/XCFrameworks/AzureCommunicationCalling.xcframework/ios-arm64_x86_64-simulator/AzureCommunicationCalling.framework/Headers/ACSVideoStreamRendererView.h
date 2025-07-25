//+-----------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// Module name : ACSVideoStreamRendererView.h
//
//------------------------------------------------------------------------------

#ifndef VideoStreamRendererView_h
#define VideoStreamRendererView_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ACSCreateViewOptions;

typedef NS_ENUM(NSInteger, ACSScalingMode);

NS_SWIFT_NAME(RendererView)

@interface ACSVideoStreamRendererView : UIView

-(nonnull instancetype) init NS_UNAVAILABLE;

-(void) updateScalingMode: (ACSScalingMode) scalingMode NS_SWIFT_NAME( update(scalingMode:));

-(void) dispose;

-(bool) isRendering;

-(struct ACSStreamSize) videoFrameSize;

@end

#endif /* VideoStreamRendererView_h */
