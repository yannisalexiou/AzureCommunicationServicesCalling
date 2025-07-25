//
//  ACSCallAgent+CallKit.h
//  AzureCommunicationCalling
//
//  Created by Sanath Rao on 2/13/22.
//

#import <Foundation/Foundation.h>
#import <CallKit/CallKit.h>

@class ACSCallerInfo;
/*
CXHandle and Display Name for the Remote participant.
*/
NS_SWIFT_NAME(CallKitRemoteInfo)
@interface ACSCallKitRemoteInfo : NSObject

/*
Passed to CallKit for incoming and outgoing call.
*/
@property (retain, nullable) CXHandle* handle;

/*
The display name to be shown in call history while using CallKit.
*/
@property (retain, nullable) NSString* displayName;

@end

NS_SWIFT_NAME(CallKitOptions)
@interface ACSCallKitOptions : NSObject

- (nonnull instancetype)init NS_UNAVAILABLE;

- (nonnull instancetype)init: (CXProviderConfiguration* _Nonnull) providerConfiguration NS_SWIFT_NAME( init(with:));

@property (retain, nonnull, readonly) CXProviderConfiguration* providerConfiguration;

@property (nonatomic, copy, nullable) ACSCallKitRemoteInfo* _Nullable (^provideRemoteInfo)(ACSCallerInfo* _Nonnull);

@property (nonatomic, copy, nullable) NSError* _Nullable (^configureAudioSession)(void);

@property BOOL isCallHoldSupported;

@end


