//
//  ACSFeatures.h
//  AzureCommunicationCalling
//
//

#ifndef ACSFeatures_h
#define ACSFeatures_h

#import <Foundation/Foundation.h>
#import "AzureCommunicationCalling.h"

NS_SWIFT_NAME(Features)
@interface ACSFeatures : NSObject

@property (class, readonly) Class recording NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class transcription NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class dominantSpeakers NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class localUserDiagnostics NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class raisedHands NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class localVideoEffects NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class captions NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class spotlight NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class mediaStatistics NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class dataChannel NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class capabilities NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class survey NS_REFINED_FOR_SWIFT;
@property (class, readonly) Class realTimeText NS_REFINED_FOR_SWIFT;

@end

#endif /* ACSFeatures_h */
