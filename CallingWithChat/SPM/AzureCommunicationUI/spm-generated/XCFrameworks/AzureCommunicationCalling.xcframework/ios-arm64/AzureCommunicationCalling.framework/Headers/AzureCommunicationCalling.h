// ACSCallingShared
// This file was auto-generated from ACSCallingModelGA.cs.

#import <Foundation/Foundation.h>
#import <Corevideo/CoreVideo.h>

#import <CoreVideo/CoreVideo.h>
#import <AVFoundation/AVFoundation.h>
#import <AzureCommunicationCommon/AzureCommunicationCommon-Swift.h>
#import "ACSCallKit.h"
#import "ACSVideoStreamRenderer.h"
#import "ACSVideoStreamRendererView.h"
#import "ACSStreamSize.h"
#import "ACSFeatures.h"

// Enumerations.
/// Additional failed states for Azure Communication Services
typedef NS_OPTIONS(NSInteger, ACSCallingCommunicationErrors)
{
    /// No errors
    ACSCallingCommunicationErrorsNone = 0,
    /// No Audio permissions available.
    ACSCallingCommunicationErrorsNoAudioPermission = 1,
    /// No Video permissions available.
    ACSCallingCommunicationErrorsNoVideoPermission = 2,
    /// No Video and Audio permissions available.
    ACSCallingCommunicationErrorsNoAudioAndVideoPermission = 3,
    /// Failed to process push notification payload.
    ACSCallingCommunicationErrorsReceivedInvalidPushNotificationPayload = 4,
    /// Received empty/invalid notification payload.
    ACSCallingCommunicationErrorsFailedToProcessPushNotificationPayload = 8,
    /// Received invalid group Id.
    ACSCallingCommunicationErrorsInvalidGuidGroupId = 16,
    /// Push notification device registration token is invalid.
    ACSCallingCommunicationErrorsInvalidPushNotificationDeviceRegistrationToken = 32,
    /// Cannot create multiple renders for same device or stream.
    ACSCallingCommunicationErrorsMultipleRenderersNotSupported = 64,
    /// Renderer doesn't support creating multiple views.
    ACSCallingCommunicationErrorsMultipleViewsNotSupported = 128,
    /// The local video stream on the video options is invalid.
    ACSCallingCommunicationErrorsInvalidLocalVideoStreamForVideoOptions = 256,
    /// No multiple connections with same identity per app is allowed.
    ACSCallingCommunicationErrorsNoMultipleConnectionsWithSameIdentity = 512,
    /// Invalid server call Id because it's empty or has invalid values.
    ACSCallingCommunicationErrorsInvalidServerCallId = 1024,
    /// Failure while switch source on a local video stream.
    ACSCallingCommunicationErrorsLocalVideoStreamSwitchSourceFailure = 2048,
    /// Attempt to answer an incoming call that has been unplaced.
    ACSCallingCommunicationErrorsIncomingCallAlreadyUnplaced = 4096,
    /// Invalid meeting link provided.
    ACSCallingCommunicationErrorsInvalidMeetingLink = 16384,
    /// Attempt to add participant to a unconnected call.
    ACSCallingCommunicationErrorsParticipantAddedToUnconnectedCall = 32768,
    /// Participant already added to the call.
    ACSCallingCommunicationErrorsParticipantAlreadyAddedToCall = 65536,
    /// Call feature extension not found.
    ACSCallingCommunicationErrorsCallFeatureExtensionNotFound = 131072,
    /// User display name is longer than the supported length.
    ACSCallingCommunicationErrorsDisplayNameLengthLongerThanSupported = 8388608,
    /// Cannot hangup for everyone in a non-hostless call
    ACSCallingCommunicationErrorsFailedToHangupForEveryone = 16777216,
    /// No multiple connections with different cloud type per app is allowed.
    ACSCallingCommunicationErrorsNoMultipleConnectionsWithDifferentClouds = 33554432,
    /// Virtual tried to register an already registered device id.
    ACSCallingCommunicationErrorsDuplicateDeviceId = 262144,
    /// Virtual device is not started.
    ACSCallingCommunicationErrorsVirtualDeviceNotStarted = 1048576,
    /// Invalid video stream combination provided.
    ACSCallingCommunicationErrorsInvalidVideoStreamCombination = 4194304,
    /// Invalid video format set
    ACSCallingCommunicationErrorsInvalidVideoFormat = 257,
    /// The buffer does not match the video format set or does contain valid data
    ACSCallingCommunicationErrorsInvalidBuffer = 258,
    /// There was a problem while sending the video frame
    ACSCallingCommunicationErrorsRawVideoFrameNotSent = 259,
    /// The selected video resolution is not valid for the virtual video
    ACSCallingCommunicationErrorsUnsupportedVideoStreamResolution = 260,
    /// Feature extension not found.
    ACSCallingCommunicationErrorsFeatureExtensionNotFound = 67108864,
    /// Video effect not supported by device
    ACSCallingCommunicationErrorsVideoEffectNotSupported = 134217728,
    /// Sending Raw Audio Buffer Failed
    ACSCallingCommunicationErrorsFailedToSendRawAudioBuffer = 5,
    /// Cannot mute virtual audio stream
    ACSCallingCommunicationErrorsCannotMuteVirtualAudioStream = 6,
    /// Start captions failed
    ACSCallingCommunicationErrorsCaptionsFailedToStart = 261,
    /// Start captions failed, captions is disabled by configurations
    ACSCallingCommunicationErrorsCaptionsDisabledByConfigurations = 262,
    /// Start captions failed, captions policy is disabled
    ACSCallingCommunicationErrorsCaptionsPolicyDisabled = 263,
    /// Captions are not active
    ACSCallingCommunicationErrorsCaptionsNotActive = 264,
    /// The requested language is not supported
    ACSCallingCommunicationErrorsCaptionsRequestedLanguageNotSupported = 265,
    /// Set caption language failed
    ACSCallingCommunicationErrorsFailedToSetCaptionLanguage = 266,
    /// Set caption language is disabled
    ACSCallingCommunicationErrorsSetCaptionLanguageDisabled = 267,
    /// Set caption language failed, teams premium license needed
    ACSCallingCommunicationErrorsSetCaptionLanguageTeamsPremiumLicenseNeeded = 268,
    /// Failed to set spoken language
    ACSCallingCommunicationErrorsCaptionsFailedToSetSpokenLanguage = 269,
    /// Set spoken language is disabled
    ACSCallingCommunicationErrorsCaptionsSetSpokenLanguageDisabled = 270,
    /// Get captions failed, call should be connected
    ACSCallingCommunicationErrorsGetCaptionsFailedCallStateNotConnected = 271,
    /// Get captions failed
    ACSCallingCommunicationErrorsGetCaptionsFailed = 272,
    /// Spotlight failed, spotlight feature is disabled by configurations
    ACSCallingCommunicationErrorsSpotlightDisabledByConfigurations = 273,
    /// Max supported spotlight reached
    ACSCallingCommunicationErrorsMaxSpotlightReached = 274,
    /// Spotlight Input List empty
    ACSCallingCommunicationErrorsSpotlightParticipantEmptyList = 275,
    /// Signaling Service Status Code
    ACSCallingCommunicationErrorsSignalingOperationFailed = 276,
    /// Music mode not enabled
    ACSCallingCommunicationErrorsMusicModeNotEnabled = 277,
    /// Lobby is disabled by configurations
    ACSCallingCommunicationErrorsLobbyDisabledByConfigurations = 282,
    /// Current conversation type does not support Lobby
    ACSCallingCommunicationErrorsLobbyConversationTypeNotSupported = 283,
    /// Current meeting role does not have permission to admit/reject user from Lobby
    ACSCallingCommunicationErrorsLobbyMeetingRoleNotAllowed = 284,
    /// Participant is not exist in the Lobby
    ACSCallingCommunicationErrorsLobbyParticipantNotExist = 285,
    /// Remove participant operation failure
    ACSCallingCommunicationErrorsRemoveParticipantOperationFailure = 286,
    /// Admit/AdmitAll operation failure
    ACSCallingCommunicationErrorsLobbyAdmitOperationFailure = 287,
    /// Teams Interop is disabled while using proxy
    ACSCallingCommunicationErrorsProxyNotAvailableForTeams = 288,
    /// Set media proxy failed
    ACSCallingCommunicationErrorsFailedToSetMediaProxy = 289,
    /// Invalid report interval for Media Statistics Call Feature.
    ACSCallingCommunicationErrorsMediaStatisticsInvalidReportInterval = 290,
    /// Start Data Channel Call Feature failed
    ACSCallingCommunicationErrorsDataChannelFailedToStart = 291,
    /// Data Channel sender already closed
    ACSCallingCommunicationErrorsDataChannelSenderClosed = 292,
    /// Random data channel id not available
    ACSCallingCommunicationErrorsDataChannelRandomIdNotAvailable = 293,
    /// Data Channel message size over the limit
    ACSCallingCommunicationErrorsDataChannelMessageSizeOverLimit = 294,
    /// Data Channel message failed to send due to bandwidth
    ACSCallingCommunicationErrorsDataChannelMessageFailureForBandwidth = 295,
    /// Start Data Channel message failed to send due to traffic limit
    ACSCallingCommunicationErrorsDataChannelMessageFailureForTrafficLimit = 296,
    /// Attempted to added a participant with an invalid type to the call
    ACSCallingCommunicationErrorsInvalidParticipantAddedToCall = 536870912,
    /// Invalid token provider given.
    ACSCallingCommunicationErrorsInvalidTokenProvider = 297,
    /// Teams for life meeting join not supported
    ACSCallingCommunicationErrorsTeamsForLifeMeetingJoinNotSupported = 298,
    /// Stop captions failed
    ACSCallingCommunicationErrorsCaptionsFailedToStop = 301,
    /// Switch source blocked
    ACSCallingCommunicationErrorsSwitchSourceBlocked = 305,
    /// Survey Rating Scale Invalid Bounds
    ACSCallingCommunicationErrorsSurveyRatingScaleOutOfBounds = 306,
    /// Survey Rating Scale Invalid Threshold
    ACSCallingCommunicationErrorsSurveyRatingScaleInvalidThreshold = 307,
    /// Survey Score Out of Bounds
    ACSCallingCommunicationErrorsSurveyScoreOutOfBounds = 308,
    /// Survey Double Submission Not Allowed
    ACSCallingCommunicationErrorsSurveyDoubleSubmissionNotAllowed = 309,
    /// Forbidden to mute others
    ACSCallingCommunicationErrorsMuteOthersForbidden = 278,
    /// Internal server error occurred when muting others
    ACSCallingCommunicationErrorsMuteOthersInternalServerError = 279,
    /// Not found exception occurred when muting others
    ACSCallingCommunicationErrorsMuteOthersNotFound = 280,
    /// Cannot mute others because method not supported
    ACSCallingCommunicationErrorsMuteOthersNotSupported = 302,
    /// Real time text, content too long
    ACSCallingCommunicationErrorsRealTimeTextContentTooLong = 311
} NS_SWIFT_NAME(CallingCommunicationErrors);

/// Type of outgoing video stream is being used on the call
typedef NS_ENUM(NSInteger, ACSVideoStreamType)
{
    /// Remote
    ACSVideoStreamTypeRemoteIncoming = 1,
    /// Raw
    ACSVideoStreamTypeRawIncoming = 2,
    /// Local
    ACSVideoStreamTypeLocalOutgoing = 3,
    /// Video
    ACSVideoStreamTypeVirtualOutgoing = 4,
    /// Screen share
    ACSVideoStreamTypeScreenShareOutgoing = 5
} NS_SWIFT_NAME(VideoStreamType);

/// Local and Remote Video Stream types
typedef NS_ENUM(NSInteger, ACSVideoStreamSourceType)
{
    /// Video
    ACSVideoStreamSourceTypeVideo = 1,
    /// Screen share
    ACSVideoStreamSourceTypeScreenSharing = 2
} NS_SWIFT_NAME(VideoStreamSourceType);

/// Defines possible running states for a video stream
typedef NS_ENUM(NSInteger, ACSVideoStreamState)
{
    /// Available
    ACSVideoStreamStateAvailable = 0,
    /// Started
    ACSVideoStreamStateStarted = 1,
    /// Stopping
    ACSVideoStreamStateStopping = 2,
    /// Stopped
    ACSVideoStreamStateStopped = 3,
    /// NotAvailable
    ACSVideoStreamStateNotAvailable = 4
} NS_SWIFT_NAME(VideoStreamState);

/// Defines direction of the CallAudioStream or CallVideoStream
typedef NS_ENUM(NSInteger, ACSStreamDirection)
{
    /// Incoming
    ACSStreamDirectionIncoming = 0,
    /// Outgoing
    ACSStreamDirectionOutgoing = 1
} NS_SWIFT_NAME(StreamDirection);

/// Local and Remote Video Stream types
typedef NS_ENUM(NSInteger, ACSMediaStreamType)
{
    /// Video
    ACSMediaStreamTypeVideo = 1,
    /// Screen share
    ACSMediaStreamTypeScreenSharing = 2
} NS_SWIFT_NAME(MediaStreamType) DEPRECATED_MSG_ATTRIBUTE("Use VideoStreamSourceType instead");

/// State of a call
typedef NS_ENUM(NSInteger, ACSCallState)
{
    /// None - disposed or applicable very early in lifetime of a call
    ACSCallStateNone = 0,
    /// Early Media
    ACSCallStateEarlyMedia = 1,
    /// Call is being connected
    ACSCallStateConnecting = 3,
    /// Call is ringing
    ACSCallStateRinging = 4,
    /// Call is connected
    ACSCallStateConnected = 5,
    /// Call held by local participant
    ACSCallStateLocalHold = 6,
    /// Call is being disconnected
    ACSCallStateDisconnecting = 7,
    /// Call is disconnected
    ACSCallStateDisconnected = 8,
    /// In Lobby
    ACSCallStateInLobby = 9,
    /// Call held by a remote participant
    ACSCallStateRemoteHold = 10
} NS_SWIFT_NAME(CallState);

/// Direction of the camera
typedef NS_ENUM(NSInteger, ACSCameraFacing)
{
    /// Unknown
    ACSCameraFacingUnknown = 0,
    /// External device
    ACSCameraFacingExternal = 1,
    /// Front camera
    ACSCameraFacingFront = 2,
    /// Back camera
    ACSCameraFacingBack = 3,
    /// Panoramic camera
    ACSCameraFacingPanoramic = 4,
    /// Left front camera
    ACSCameraFacingLeftFront = 5,
    /// Right front camera
    ACSCameraFacingRightFront = 6
} NS_SWIFT_NAME(CameraFacing);

/// Describes the video device type
typedef NS_ENUM(NSInteger, ACSVideoDeviceType)
{
    /// Unknown type of video device
    ACSVideoDeviceTypeUnknown = 0,
    /// USB Camera Video Device
    ACSVideoDeviceTypeUsbCamera = 1,
    /// Capture Adapter Video Device
    ACSVideoDeviceTypeCaptureAdapter = 2,
    /// Virtual Video Device
    ACSVideoDeviceTypeVirtual = 3
} NS_SWIFT_NAME(VideoDeviceType);

/// Specifies the noise suppression modes supported by outgoing audio filters
typedef NS_ENUM(NSInteger, ACSNoiseSuppressionMode)
{
    ACSNoiseSuppressionModeOff = 0,
    ACSNoiseSuppressionModeAuto = 1,
    ACSNoiseSuppressionModeLow = 2,
    ACSNoiseSuppressionModeHigh = 3
} NS_SWIFT_NAME(NoiseSuppressionMode);

/// Describes different types of Push notifications supported
typedef NS_ENUM(NSInteger, ACSPushNotificationEventType)
{
    ACSPushNotificationEventTypeIncomingCall = 107,
    ACSPushNotificationEventTypeIncomingGroupCall = 109,
    ACSPushNotificationEventTypeIncomingPstnCall = 111,
    ACSPushNotificationEventTypeStopRinging = 110
} NS_SWIFT_NAME(PushNotificationEventType);

/// The role of an user in the Call.
typedef NS_ENUM(NSInteger, ACSCallParticipantRole)
{
    /// Uninitialized
    ACSCallParticipantRoleUninitialized = 0,
    /// Attendee
    ACSCallParticipantRoleAttendee = 1,
    /// Consumer
    ACSCallParticipantRoleConsumer = 2,
    /// Presenter
    ACSCallParticipantRolePresenter = 3,
    /// Organizer
    ACSCallParticipantRoleOrganizer = 4,
    /// CoOrganizer
    ACSCallParticipantRoleCoOrganizer = 5
} NS_SWIFT_NAME(CallParticipantRole);

/// State of a participant in the call
typedef NS_ENUM(NSInteger, ACSParticipantState)
{
    /// Idle
    ACSParticipantStateIdle = 0,
    /// Early Media
    ACSParticipantStateEarlyMedia = 1,
    /// Connecting
    ACSParticipantStateConnecting = 2,
    /// Connected
    ACSParticipantStateConnected = 3,
    /// On Hold
    ACSParticipantStateHold = 4,
    /// In Lobby
    ACSParticipantStateInLobby = 5,
    /// Disconnected
    ACSParticipantStateDisconnected = 6,
    /// Ringing
    ACSParticipantStateRinging = 7
} NS_SWIFT_NAME(ParticipantState);

/// Type of Communication
typedef NS_ENUM(NSInteger, ACSCommunicationCallType)
{
    /// Call
    ACSCommunicationCallTypeCall = 0,
    /// TeamsCall
    ACSCommunicationCallTypeTeamsCall = 1
} NS_SWIFT_NAME(CommunicationCallType);

/// Local and Remote Video scaling mode
typedef NS_ENUM(NSInteger, ACSScalingMode)
{
    /// Cropped
    ACSScalingModeCrop = 1,
    /// Fitted
    ACSScalingModeFit = 2
} NS_SWIFT_NAME(ScalingMode);

/// DTMF (Dual-Tone Multi-Frequency) tone for PSTN calls
typedef NS_ENUM(NSInteger, ACSDtmfTone)
{
    /// Zero
    ACSDtmfToneZero = 0,
    /// One
    ACSDtmfToneOne = 1,
    /// Two
    ACSDtmfToneTwo = 2,
    /// Three
    ACSDtmfToneThree = 3,
    /// Four
    ACSDtmfToneFour = 4,
    /// Five
    ACSDtmfToneFive = 5,
    /// Six
    ACSDtmfToneSix = 6,
    /// Seven
    ACSDtmfToneSeven = 7,
    /// Eight
    ACSDtmfToneEight = 8,
    /// Nine
    ACSDtmfToneNine = 9,
    /// Star
    ACSDtmfToneStar = 10,
    /// Pound
    ACSDtmfTonePound = 11,
    /// A
    ACSDtmfToneA = 12,
    /// B
    ACSDtmfToneB = 13,
    /// C
    ACSDtmfToneC = 14,
    /// D
    ACSDtmfToneD = 15,
    /// Flash
    ACSDtmfToneFlash = 16
} NS_SWIFT_NAME(DtmfTone);

/// Direction of a Call
typedef NS_ENUM(NSInteger, ACSCallDirection)
{
    /// Outgoing call
    ACSCallDirectionOutgoing = 1,
    /// Incoming call
    ACSCallDirectionIncoming = 2
} NS_SWIFT_NAME(CallDirection);

/// Specifies the result type of a real-time text message.
typedef NS_ENUM(NSInteger, ACSRealTimeTextResultType)
{
    /// Indicates that the text message is partial and may be updated.
    ACSRealTimeTextResultTypePartial = 0,
    /// Indicates that the text message is finalized and will not change.
    ACSRealTimeTextResultTypeFinal = 1
} NS_SWIFT_NAME(RealTimeTextResultType);

/// Indicates the captions result type
typedef NS_ENUM(NSInteger, ACSCaptionsResultType)
{
    /// Text contains partially spoken sentence.
    ACSCaptionsResultTypePartial = 0,
    /// Sentence has been completely transcribed.
    ACSCaptionsResultTypeFinal = 1
} NS_SWIFT_NAME(CaptionsResultType);

/// Indicates the active captions type
typedef NS_ENUM(NSInteger, ACSCaptionsType)
{
    /// Teams Captions.
    ACSCaptionsTypeTeamsCaptions = 0,
    /// Communication Captions.
    ACSCaptionsTypeCommunicationCaptions = 1
} NS_SWIFT_NAME(CaptionsType);

/// Informs how media frames will be available for encoding or decoding.
typedef NS_ENUM(NSInteger, ACSRawVideoFrameType)
{
    /// Use buffer for encoding or decoding
    ACSRawVideoFrameTypeBuffer = 0,
    /// Use texture for encoding or decoding
    ACSRawVideoFrameTypeTexture = 1
} NS_SWIFT_NAME(RawVideoFrameType);

/// Informs how the pixels of the video frame is encoded.
typedef NS_ENUM(NSInteger, ACSVideoStreamPixelFormat)
{
    /// Pixel format is encoded as single plane with 32 bits per pixels, 8 bits per channel, ordered as blue, followed by green, followed by red and discarding the last 8 bits.
    ACSVideoStreamPixelFormatBgrx = 0,
    /// Pixel format is encoded as single plane with 24 bits per pixels, 8 bits per channel, ordered as blue, followed by green, followed by red.
    ACSVideoStreamPixelFormatBgr24 = 1,
    /// Pixel format is encoded as single plane with 32 bits per pixels, 8 bits per channel, ordered as blue, followed by green, followed by red and discarding the last 8 bits.
    ACSVideoStreamPixelFormatRgbx = 2,
    /// Pixel format is encoded as single plane with 32 bits per pixels, 8 bits per channel, ordered as blue, followed by green, followed by red and alpha as 8 bits each. Alpha is discarded.
    ACSVideoStreamPixelFormatRgba = 3,
    /// Pixel format  is encoded as YUV 4:2:0 with a plane of 8 bit Y samples, followed by an interleaved U/V plane containing 8 bit 2x2 sub-sampled color difference samples.
    ACSVideoStreamPixelFormatNv12 = 4,
    /// Pixel format is encoded as YUV 4:2:0 with a plane of 8 bit ordered by Y, followed by a U plane, followed by a V plane.
    ACSVideoStreamPixelFormatI420 NS_SWIFT_NAME(i420) = 5
} NS_SWIFT_NAME(VideoStreamPixelFormat);

/// Represents the list of supported video resolution for VirtualOutgoingVideoStream
typedef NS_ENUM(NSInteger, ACSVideoStreamResolution)
{
    /// Represents unknown resolution
    ACSVideoStreamResolutionUnknown = 0,
    /// Represents 1920x1080 resolution
    ACSVideoStreamResolutionP1080 NS_SWIFT_NAME(p1080) = 1,
    /// Represents 1280x720 resolution
    ACSVideoStreamResolutionP720 NS_SWIFT_NAME(p720) = 2,
    /// Represents 960x540 resolution
    ACSVideoStreamResolutionP540 NS_SWIFT_NAME(p540) = 3,
    /// Represents 858x480 resolution
    ACSVideoStreamResolutionP480 NS_SWIFT_NAME(p480) = 4,
    /// Represents 640x360 resolution
    ACSVideoStreamResolutionP360 NS_SWIFT_NAME(p360) = 5,
    /// Represents 480x270 resolution
    ACSVideoStreamResolutionP270 NS_SWIFT_NAME(p270) = 6,
    /// Represents 352x240 resolution
    ACSVideoStreamResolutionP240 NS_SWIFT_NAME(p240) = 7,
    /// Represents 320x180 resolution
    ACSVideoStreamResolutionP180 NS_SWIFT_NAME(p108) = 8,
    /// Represents 1920x1080 resolution
    ACSVideoStreamResolutionFullHd = 9,
    /// Represents 1280x720 resolution
    ACSVideoStreamResolutionHd = 10,
    /// Represents 640x480 resolution
    ACSVideoStreamResolutionVga = 11,
    /// Represents 320x240 resolution
    ACSVideoStreamResolutionQvga = 12
} NS_SWIFT_NAME(VideoStreamResolution);

/// Defines possible running states for an audio stream
typedef NS_ENUM(NSInteger, ACSAudioStreamState)
{
    /// Started
    ACSAudioStreamStateStarted = 0,
    /// Stopped
    ACSAudioStreamStateStopped = 1
} NS_SWIFT_NAME(AudioStreamState);

/// Specifies the sample rates supported by the RawAudioStreams entities
typedef NS_ENUM(NSInteger, ACSAudioStreamSampleRate)
{
    /// 16000 Hz
    ACSAudioStreamSampleRateHz_16000 NS_SWIFT_NAME(hz16000) = 0,
    /// 22050 Hz
    ACSAudioStreamSampleRateHz_22050 NS_SWIFT_NAME(hz22050) = 1,
    /// 24000 Hz
    ACSAudioStreamSampleRateHz_24000 NS_SWIFT_NAME(hz24000) = 2,
    /// 32000 Hz
    ACSAudioStreamSampleRateHz_32000 NS_SWIFT_NAME(hz32000) = 3,
    /// 44100 Hz
    ACSAudioStreamSampleRateHz_44100 NS_SWIFT_NAME(hz44100) = 4,
    /// 48000 Hz
    ACSAudioStreamSampleRateHz_48000 NS_SWIFT_NAME(hz48000) = 5
} NS_SWIFT_NAME(AudioStreamSampleRate);

/// Specifies the channel modes supported by the RawAudioStreams entities
typedef NS_ENUM(NSInteger, ACSAudioStreamChannelMode)
{
    /// Mono Channel Audio
    ACSAudioStreamChannelModeMono = 0,
    /// Stereo Channel Audio
    ACSAudioStreamChannelModeStereo = 1
} NS_SWIFT_NAME(AudioStreamChannelMode);

/// Specifies the audio formats supported by the RawAudioStreams entities
typedef NS_ENUM(NSInteger, ACSAudioStreamFormat)
{
    /// 16 BIT PCM bit-depth
    ACSAudioStreamFormatPcm16Bit = 0
} NS_SWIFT_NAME(AudioStreamFormat);

/// Specifies the data per block in milliseconds for buffers supported by the RawOutgoingAudioStream entities
typedef NS_ENUM(NSInteger, ACSAudioStreamBufferDuration)
{
    /// 10 ms blocks
    ACSAudioStreamBufferDurationMs10 = 0,
    /// 20 ms blocks
    ACSAudioStreamBufferDurationMs20 = 1
} NS_SWIFT_NAME(AudioStreamBufferDuration);

/// Type of outgoing audio stream is being used on the call
typedef NS_ENUM(NSInteger, ACSAudioStreamType)
{
    /// Remote Incoming
    ACSAudioStreamTypeRemoteIncoming = 1,
    /// Raw Incoming
    ACSAudioStreamTypeRawIncoming = 2,
    /// Local Outgoing
    ACSAudioStreamTypeLocalOutgoing = 3,
    /// Virtual Outgoing
    ACSAudioStreamTypeVirtualOutgoing = 4
} NS_SWIFT_NAME(AudioStreamType);

/// Represents a diagnostic quality scale.
typedef NS_ENUM(NSInteger, ACSDiagnosticQuality)
{
    /// Unknown
    ACSDiagnosticQualityUnknown = 0,
    /// Good
    ACSDiagnosticQualityGood = 1,
    /// Poor
    ACSDiagnosticQualityPoor = 2,
    /// Bad
    ACSDiagnosticQualityBad = 3
} NS_SWIFT_NAME(DiagnosticQuality);

/// Priority options for data channel.
typedef NS_ENUM(NSInteger, ACSDataChannelPriority)
{
    ACSDataChannelPriorityNormal = 0,
    ACSDataChannelPriorityHigh = 1
} NS_SWIFT_NAME(DataChannelPriority);

/// Reliability options for data channel.
typedef NS_ENUM(NSInteger, ACSDataChannelReliability)
{
    ACSDataChannelReliabilityLossy = 0,
    ACSDataChannelReliabilityDurable = 1
} NS_SWIFT_NAME(DataChannelReliability);

/// Name of capabilities available
typedef NS_ENUM(NSInteger, ACSParticipantCapabilityType)
{
    /// Turn Video On
    ACSParticipantCapabilityTypeTurnVideoOn = 0,
    /// Unmute mic
    ACSParticipantCapabilityTypeUnmuteMicrophone = 1,
    /// Share Screen
    ACSParticipantCapabilityTypeShareScreen = 2,
    /// Remove Participant
    ACSParticipantCapabilityTypeRemoveParticipant = 3,
    /// Hang up for everyone
    ACSParticipantCapabilityTypeHangUpForEveryone = 4,
    /// Add Teams user
    ACSParticipantCapabilityTypeAddTeamsUser = 5,
    /// Add communications user
    ACSParticipantCapabilityTypeAddCommunicationUser = 6,
    /// Add phone number
    ACSParticipantCapabilityTypeAddPhoneNumber = 7,
    /// manage lobby
    ACSParticipantCapabilityTypeManageLobby = 8,
    /// Spotlight participant
    ACSParticipantCapabilityTypeSpotlightParticipant = 9,
    /// Remove participant spotlight
    ACSParticipantCapabilityTypeRemoveParticipantSpotlight = 10,
    /// Blur background
    ACSParticipantCapabilityTypeBlurBackground = 11,
    /// Custom background
    ACSParticipantCapabilityTypeCustomBackground = 12,
    /// Start live captions
    ACSParticipantCapabilityTypeStartLiveCaptions = 13,
    /// Raise hands
    ACSParticipantCapabilityTypeRaiseHand = 14,
    /// Soft mute others
    ACSParticipantCapabilityTypeMuteOthers = 15
} NS_SWIFT_NAME(ParticipantCapabilityType);

/// Reason for capabilities changed
typedef NS_ENUM(NSInteger, ACSCapabilitiesChangedReason)
{
    /// Role changed
    ACSCapabilitiesChangedReasonRoleChanged = 0,
    /// User policy changed
    ACSCapabilitiesChangedReasonUserPolicyChanged = 1,
    /// Meeting details changed
    ACSCapabilitiesChangedReasonMeetingDetailsChanged = 2
} NS_SWIFT_NAME(CapabilitiesChangedReason);

/// Capability Resolution Reason
typedef NS_ENUM(NSInteger, ACSCapabilityResolutionReason)
{
    /// Capable
    ACSCapabilityResolutionReasonCapable = 0,
    /// Call type restricted
    ACSCapabilityResolutionReasonCallTypeRestricted = 1,
    /// User policy restricted
    ACSCapabilityResolutionReasonUserPolicyRestricted = 2,
    /// Role restricted
    ACSCapabilityResolutionReasonRoleRestricted = 3,
    /// Meeting restricted
    ACSCapabilityResolutionReasonMeetingRestricted = 4,
    /// Feature not supported
    ACSCapabilityResolutionReasonFeatureNotSupported = 5,
    /// Not initialized
    ACSCapabilityResolutionReasonNotInitialized = 6,
    /// Not capable
    ACSCapabilityResolutionReasonNotCapable = 7
} NS_SWIFT_NAME(CapabilityResolutionReason);

/// Possible values for common call issues
typedef NS_OPTIONS(NSInteger, ACSCallIssues)
{
    ACSCallIssuesNone = 0,
    ACSCallIssuesCannotJoin = 1,
    ACSCallIssuesCannotInvite = 2,
    ACSCallIssuesHadToRejoin = 4,
    ACSCallIssuesEndedUnexpectedly = 8,
    ACSCallIssuesOtherIssues = 16
} NS_SWIFT_NAME(CallIssues);

/// Possible values for common audio issues
typedef NS_OPTIONS(NSInteger, ACSAudioIssues)
{
    ACSAudioIssuesNone = 0,
    ACSAudioIssuesNoLocalAudio = 1,
    ACSAudioIssuesNoRemoteAudio = 2,
    ACSAudioIssuesEcho = 4,
    ACSAudioIssuesAudioNoise = 8,
    ACSAudioIssuesLowVolume = 16,
    ACSAudioIssuesAudioStoppedUnexpectedly = 32,
    ACSAudioIssuesDistortedSpeech = 64,
    ACSAudioIssuesAudioInterruption = 128,
    ACSAudioIssuesOtherIssues = 256
} NS_SWIFT_NAME(AudioIssues);

/// Possible values for common video issues
typedef NS_OPTIONS(NSInteger, ACSVideoIssues)
{
    ACSVideoIssuesNone = 0,
    ACSVideoIssuesNoVideoReceived = 1,
    ACSVideoIssuesNoVideoSent = 2,
    ACSVideoIssuesLowQuality = 4,
    ACSVideoIssuesFreezes = 8,
    ACSVideoIssuesStoppedUnexpectedly = 16,
    ACSVideoIssuesDarkVideoReceived = 32,
    ACSVideoIssuesAudioVideoOutOfSync = 64,
    ACSVideoIssuesOtherIssues = 128
} NS_SWIFT_NAME(VideoIssues);

/// Possible values for common screen share issues
typedef NS_OPTIONS(NSInteger, ACSScreenShareIssues)
{
    ACSScreenShareIssuesNone = 0,
    ACSScreenShareIssuesNoContentLocal = 1,
    ACSScreenShareIssuesNoContentRemote = 2,
    ACSScreenShareIssuesCannotPresent = 4,
    ACSScreenShareIssuesLowQuality = 8,
    ACSScreenShareIssuesFreezes = 16,
    ACSScreenShareIssuesStoppedUnexpectedly = 32,
    ACSScreenShareIssuesLargeDelay = 64,
    ACSScreenShareIssuesOtherIssues = 128
} NS_SWIFT_NAME(ScreenShareIssues);

// MARK: Forward declarations.
@class ACSCallVideoStream;
@class ACSOutgoingVideoStream;
@class ACSIncomingVideoStream;
@class ACSOutgoingVideoOptions;
@class ACSOutgoingVideoConstraints;
@class ACSIncomingVideoOptions;
@class ACSVideoOptions;
@class ACSLocalVideoStream;
@class ACSVideoDeviceInfo;
@class ACSLocalVideoStreamFeature;
@class ACSVideoStreamStateChangedEventArgs;
@class ACSOutgoingAudioFilters;
@class ACSLiveOutgoingAudioFilters;
@class ACSAudioOptions;
@class ACSIncomingAudioOptions;
@class ACSIncomingAudioStream;
@class ACSOutgoingAudioOptions;
@class ACSOutgoingAudioStream;
@class ACSCallOptions;
@class ACSJoinTeamsCallOptions;
@class ACSJoinCallOptions;
@class ACSAcceptTeamsCallOptions;
@class ACSAcceptCallOptions;
@class ACSStartCallOptions;
@class ACSVideoConstraints;
@class ACSAddPhoneNumberOptions;
@class ACSJoinMeetingLocator;
@class ACSJoinTeamsMeetingLocator;
@class ACSGroupCallLocator;
@class ACSTeamsMeetingCoordinatesLocator;
@class ACSTeamsMeetingIdLocator;
@class ACSTeamsMeetingLinkLocator;
@class ACSCallerInfo;
@class ACSPushNotificationInfo;
@class ACSCallAgentOptions;
@class ACSEmergencyCallOptions;
@class ACSCallAgent;
@class ACSCall;
@class ACSPropertyChangedEventArgs;
@class ACSParticipantsUpdatedEventArgs;
@class ACSRemoteParticipant;
@class ACSCallEndReason;
@class ACSRemoteVideoStream;
@class ACSRemoteVideoStreamsEventArgs;
@class ACSLocalVideoStreamsUpdatedEventArgs;
@class ACSCallsUpdatedEventArgs;
@class ACSIncomingCall;
@class ACSCallDebugInfo;
@class ACSCallClient;
@class ACSCallClientOptions;
@class ACSCallDiagnosticsOptions;
@class ACSCallNetworkOptions;
@class ACSIceServer;
@class ACSTeamsCallAgentOptions;
@class ACSTeamsCallAgent;
@class ACSTeamsCall;
@class ACSTeamsCallInfo;
@class ACSStartTeamsCallOptions;
@class ACSTeamsCallsUpdatedEventArgs;
@class ACSTeamsIncomingCall;
@class ACSDeviceManager;
@class ACSVideoDevicesUpdatedEventArgs;
@class ACSHangUpOptions;
@class ACSCallLobby;
@class ACSAdmitParticipantsResult;
@class ACSAdmitAllParticipantsResult;
@class ACSCallFeature;
@class ACSRealTimeTextInfo;
@class ACSRealTimeTextCallFeature;
@class ACSRealTimeTextInfoReceivedEventArgs;
@class ACSRecordingCallFeature;
@class ACSTranscriptionCallFeature;
@class ACSStartCaptionsOptions;
@class ACSTeamsCaptionsReceivedEventArgs;
@class ACSCommunicationCaptionsReceivedEventArgs;
@class ACSCallCaptions;
@class ACSCommunicationCaptions;
@class ACSTeamsCaptions;
@class ACSCaptionsCallFeature;
@class ACSDominantSpeakersCallFeature;
@class ACSDominantSpeakersInfo;
@class ACSRaiseHandCallFeature;
@class ACSRaisedHand;
@class ACSRaisedHandChangedEventArgs;
@class ACSLoweredHandChangedEventArgs;
@class ACSSpotlightCallFeature;
@class ACSSpotlightedParticipant;
@class ACSSpotlightChangedEventArgs;
@class ACSCreateViewOptions;
@class ACSVideoStreamFormat;
@class ACSVideoStreamFormatChangedEventArgs;
@class ACSRawVideoFrame;
@class ACSRawVideoFrameBuffer;
@class ACSRawVideoFrameReceivedEventArgs;
@class ACSRawOutgoingVideoStreamOptions;
@class ACSRawOutgoingVideoStream;
@class ACSScreenShareOutgoingVideoStream;
@class ACSVirtualOutgoingVideoStream;
@class ACSRawIncomingVideoStream;
@class ACSIncomingMixedAudioEventArgs;
@class ACSRawIncomingAudioStreamProperties;
@class ACSRawAudioBuffer;
@class ACSRawAudioStreamProperties;
@class ACSAudioStreamStateChangedEventArgs;
@class ACSCallAudioStream;
@class ACSRawOutgoingAudioStreamProperties;
@class ACSRawAudioStreamOptions;
@class ACSRawOutgoingAudioStreamOptions;
@class ACSRawIncomingAudioStreamOptions;
@class ACSLocalOutgoingAudioStream;
@class ACSRemoteIncomingAudioStream;
@class ACSRawIncomingAudioStream;
@class ACSRawOutgoingAudioStream;
@class ACSRoomCallLocator;
@class ACSCommonCallAgentOptions;
@class ACSCommonCallAgent;
@class ACSCommonIncomingCall;
@class ACSCommonCall;
@class ACSVideoEffect;
@class ACSBackgroundBlurEffect;
@class ACSBackgroundReplacementEffect;
@class ACSLocalVideoEffectsFeature;
@class ACSVideoEffectEnabledEventArgs;
@class ACSVideoEffectDisabledEventArgs;
@class ACSVideoEffectErrorEventArgs;
@class ACSLocalUserDiagnosticsCallFeature;
@class ACSNetworkDiagnostics;
@class ACSNetworkDiagnosticValues;
@class ACSDiagnosticFlagChangedEventArgs;
@class ACSDiagnosticQualityChangedEventArgs;
@class ACSMediaDiagnostics;
@class ACSMediaDiagnosticValues;
@class ACSMediaStatisticsCallFeature;
@class ACSMediaStatisticsReportReceivedEventArgs;
@class ACSMediaStatisticsReport;
@class ACSOutgoingMediaStatistics;
@class ACSOutgoingAudioStatistics;
@class ACSOutgoingVideoStatistics;
@class ACSOutgoingScreenShareStatistics;
@class ACSOutgoingDataChannelStatistics;
@class ACSIncomingMediaStatistics;
@class ACSIncomingAudioStatistics;
@class ACSIncomingVideoStatistics;
@class ACSIncomingScreenShareStatistics;
@class ACSIncomingDataChannelStatistics;
@class ACSDataChannelReceiverCreatedEventArgs;
@class ACSDataChannelReceiver;
@class ACSDataChannelSenderOptions;
@class ACSDataChannelMessage;
@class ACSDataChannelSender;
@class ACSDataChannelCallFeature;
@class ACSParticipantCapability;
@class ACSCapabilitiesChangedEventArgs;
@class ACSCapabilitiesCallFeature;
@class ACSCallSurveyResult;
@class ACSSurveyCallFeature;
@class ACSCallSurvey;
@class ACSCallSurveyScore;
@class ACSCallSurveyRatingScale;
@protocol ACSLocalVideoStreamDelegate;
@class ACSLocalVideoStreamEvents;
@protocol ACSCallAgentDelegate;
@class ACSCallAgentEvents;
@protocol ACSCallDelegate;
@class ACSCallEvents;
@protocol ACSRemoteParticipantDelegate;
@class ACSRemoteParticipantEvents;
@protocol ACSRemoteVideoStreamDelegate;
@class ACSRemoteVideoStreamEvents;
@protocol ACSIncomingCallDelegate;
@class ACSIncomingCallEvents;
@protocol ACSTeamsCallAgentDelegate;
@class ACSTeamsCallAgentEvents;
@protocol ACSTeamsCallDelegate;
@class ACSTeamsCallEvents;
@protocol ACSTeamsIncomingCallDelegate;
@class ACSTeamsIncomingCallEvents;
@protocol ACSDeviceManagerDelegate;
@class ACSDeviceManagerEvents;
@protocol ACSCallLobbyDelegate;
@class ACSCallLobbyEvents;
@protocol ACSRealTimeTextCallFeatureDelegate;
@class ACSRealTimeTextCallFeatureEvents;
@protocol ACSRecordingCallFeatureDelegate;
@class ACSRecordingCallFeatureEvents;
@protocol ACSTranscriptionCallFeatureDelegate;
@class ACSTranscriptionCallFeatureEvents;
@protocol ACSCommunicationCaptionsDelegate;
@class ACSCommunicationCaptionsEvents;
@protocol ACSTeamsCaptionsDelegate;
@class ACSTeamsCaptionsEvents;
@protocol ACSCaptionsCallFeatureDelegate;
@class ACSCaptionsCallFeatureEvents;
@protocol ACSDominantSpeakersCallFeatureDelegate;
@class ACSDominantSpeakersCallFeatureEvents;
@protocol ACSRaiseHandCallFeatureDelegate;
@class ACSRaiseHandCallFeatureEvents;
@protocol ACSSpotlightCallFeatureDelegate;
@class ACSSpotlightCallFeatureEvents;
@protocol ACSScreenShareOutgoingVideoStreamDelegate;
@class ACSScreenShareOutgoingVideoStreamEvents;
@protocol ACSVirtualOutgoingVideoStreamDelegate;
@class ACSVirtualOutgoingVideoStreamEvents;
@protocol ACSRawIncomingVideoStreamDelegate;
@class ACSRawIncomingVideoStreamEvents;
@protocol ACSLocalOutgoingAudioStreamDelegate;
@class ACSLocalOutgoingAudioStreamEvents;
@protocol ACSRemoteIncomingAudioStreamDelegate;
@class ACSRemoteIncomingAudioStreamEvents;
@protocol ACSRawIncomingAudioStreamDelegate;
@class ACSRawIncomingAudioStreamEvents;
@protocol ACSRawOutgoingAudioStreamDelegate;
@class ACSRawOutgoingAudioStreamEvents;
@protocol ACSLocalVideoEffectsFeatureDelegate;
@class ACSLocalVideoEffectsFeatureEvents;
@protocol ACSNetworkDiagnosticsDelegate;
@class ACSNetworkDiagnosticsEvents;
@protocol ACSMediaDiagnosticsDelegate;
@class ACSMediaDiagnosticsEvents;
@protocol ACSMediaStatisticsCallFeatureDelegate;
@class ACSMediaStatisticsCallFeatureEvents;
@protocol ACSDataChannelReceiverDelegate;
@class ACSDataChannelReceiverEvents;
@protocol ACSDataChannelCallFeatureDelegate;
@class ACSDataChannelCallFeatureEvents;
@protocol ACSCapabilitiesCallFeatureDelegate;
@class ACSCapabilitiesCallFeatureEvents;

NS_SWIFT_NAME(LocalVideoStreamEvents)
@interface ACSLocalVideoStreamEvents : NSObject
@property (copy, nullable) void (^onStateChanged)(ACSVideoStreamStateChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(CallAgentEvents)
@interface ACSCallAgentEvents : NSObject
@property (copy, nullable) void (^onCallsUpdated)(ACSCallsUpdatedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIncomingCall)(ACSIncomingCall * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(CallEvents)
@interface ACSCallEvents : NSObject
@property (copy, nullable) void (^onIdChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onStartTimeUpdated)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onStateChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onRoleChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onRemoteParticipantsUpdated)(ACSParticipantsUpdatedEventArgs * _Nonnull);
@property (copy, nullable) void (^onLocalVideoStreamsUpdated)(ACSLocalVideoStreamsUpdatedEventArgs * _Nonnull) DEPRECATED_MSG_ATTRIBUTE("Use onStateChanged in VideoStream types instead");
@property (copy, nullable) void (^onIsMutedChanged)(ACSPropertyChangedEventArgs * _Nonnull) DEPRECATED_MSG_ATTRIBUTE("Use OnOutgoingAudioStateChanged instead");
@property (copy, nullable) void (^onOutgoingAudioStateChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onMutedByOthers)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIncomingAudioStateChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onTotalParticipantCountChanged)(ACSPropertyChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(RemoteParticipantEvents)
@interface ACSRemoteParticipantEvents : NSObject
@property (copy, nullable) void (^onStateChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsMutedChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsSpeakingChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onDisplayNameChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onRoleChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onVideoStreamsUpdated)(ACSRemoteVideoStreamsEventArgs * _Nonnull) DEPRECATED_MSG_ATTRIBUTE("Use remoteParticipant(_:didChangeVideoStreamState:)) instead");
@property (copy, nullable) void (^onVideoStreamStateChanged)(ACSVideoStreamStateChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(RemoteVideoStreamEvents)
@interface ACSRemoteVideoStreamEvents : NSObject
@property (copy, nullable) void (^onStateChanged)(ACSVideoStreamStateChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(IncomingCallEvents)
@interface ACSIncomingCallEvents : NSObject
@property (copy, nullable) void (^onCallEnded)(ACSPropertyChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(TeamsCallAgentEvents)
@interface ACSTeamsCallAgentEvents : NSObject
@property (copy, nullable) void (^onCallsUpdated)(ACSTeamsCallsUpdatedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIncomingCall)(ACSTeamsIncomingCall * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(TeamsCallEvents)
@interface ACSTeamsCallEvents : NSObject
@property (copy, nullable) void (^onIdChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onStartTimeUpdated)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onStateChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onRoleChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onRemoteParticipantsUpdated)(ACSParticipantsUpdatedEventArgs * _Nonnull);
@property (copy, nullable) void (^onOutgoingAudioStateChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onMutedByOthers)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIncomingAudioStateChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onTotalParticipantCountChanged)(ACSPropertyChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(TeamsIncomingCallEvents)
@interface ACSTeamsIncomingCallEvents : NSObject
@property (copy, nullable) void (^onCallEnded)(ACSPropertyChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(DeviceManagerEvents)
@interface ACSDeviceManagerEvents : NSObject
@property (copy, nullable) void (^onCamerasUpdated)(ACSVideoDevicesUpdatedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(CallLobbyEvents)
@interface ACSCallLobbyEvents : NSObject
@property (copy, nullable) void (^onLobbyParticipantsUpdated)(ACSParticipantsUpdatedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(RealTimeTextCallFeatureEvents)
@interface ACSRealTimeTextCallFeatureEvents : NSObject
@property (copy, nullable) void (^onInfoReceived)(ACSRealTimeTextInfoReceivedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(RecordingCallFeatureEvents)
@interface ACSRecordingCallFeatureEvents : NSObject
@property (copy, nullable) void (^onIsRecordingActiveChanged)(ACSPropertyChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(TranscriptionCallFeatureEvents)
@interface ACSTranscriptionCallFeatureEvents : NSObject
@property (copy, nullable) void (^onIsTranscriptionActiveChanged)(ACSPropertyChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(CommunicationCaptionsEvents)
@interface ACSCommunicationCaptionsEvents : NSObject
@property (copy, nullable) void (^onActiveSpokenLanguageChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onCaptionsEnabledChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onCaptionsReceived)(ACSCommunicationCaptionsReceivedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(TeamsCaptionsEvents)
@interface ACSTeamsCaptionsEvents : NSObject
@property (copy, nullable) void (^onCaptionsEnabledChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onActiveSpokenLanguageChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onActiveCaptionLanguageChanged)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onCaptionsReceived)(ACSTeamsCaptionsReceivedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(CaptionsCallFeatureEvents)
@interface ACSCaptionsCallFeatureEvents : NSObject
@property (copy, nullable) void (^onActiveCaptionsTypeChanged)(ACSPropertyChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(DominantSpeakersCallFeatureEvents)
@interface ACSDominantSpeakersCallFeatureEvents : NSObject
@property (copy, nullable) void (^onDominantSpeakersChanged)(ACSPropertyChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(RaiseHandCallFeatureEvents)
@interface ACSRaiseHandCallFeatureEvents : NSObject
@property (copy, nullable) void (^onHandRaised)(ACSRaisedHandChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onHandLowered)(ACSLoweredHandChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(SpotlightCallFeatureEvents)
@interface ACSSpotlightCallFeatureEvents : NSObject
@property (copy, nullable) void (^onSpotlightChanged)(ACSSpotlightChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(ScreenShareOutgoingVideoStreamEvents)
@interface ACSScreenShareOutgoingVideoStreamEvents : NSObject
@property (copy, nullable) void (^onStateChanged)(ACSVideoStreamStateChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onFormatChanged)(ACSVideoStreamFormatChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(VirtualOutgoingVideoStreamEvents)
@interface ACSVirtualOutgoingVideoStreamEvents : NSObject
@property (copy, nullable) void (^onStateChanged)(ACSVideoStreamStateChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onFormatChanged)(ACSVideoStreamFormatChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(RawIncomingVideoStreamEvents)
@interface ACSRawIncomingVideoStreamEvents : NSObject
@property (copy, nullable) void (^onRawVideoFrameReceived)(ACSRawVideoFrameReceivedEventArgs * _Nonnull);
@property (copy, nullable) void (^onStateChanged)(ACSVideoStreamStateChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(LocalOutgoingAudioStreamEvents)
@interface ACSLocalOutgoingAudioStreamEvents : NSObject
@property (copy, nullable) void (^onStateChanged)(ACSAudioStreamStateChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(RemoteIncomingAudioStreamEvents)
@interface ACSRemoteIncomingAudioStreamEvents : NSObject
@property (copy, nullable) void (^onStateChanged)(ACSAudioStreamStateChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(RawIncomingAudioStreamEvents)
@interface ACSRawIncomingAudioStreamEvents : NSObject
@property (copy, nullable) void (^onMixedAudioBufferReceived)(ACSIncomingMixedAudioEventArgs * _Nonnull);
@property (copy, nullable) void (^onStateChanged)(ACSAudioStreamStateChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(RawOutgoingAudioStreamEvents)
@interface ACSRawOutgoingAudioStreamEvents : NSObject
@property (copy, nullable) void (^onStateChanged)(ACSAudioStreamStateChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(LocalVideoEffectsFeatureEvents)
@interface ACSLocalVideoEffectsFeatureEvents : NSObject
@property (copy, nullable) void (^onVideoEffectEnabled)(ACSVideoEffectEnabledEventArgs * _Nonnull);
@property (copy, nullable) void (^onVideoEffectDisabled)(ACSVideoEffectDisabledEventArgs * _Nonnull);
@property (copy, nullable) void (^onVideoEffectError)(ACSVideoEffectErrorEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(NetworkDiagnosticsEvents)
@interface ACSNetworkDiagnosticsEvents : NSObject
@property (copy, nullable) void (^onIsNetworkUnavailableChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsNetworkRelaysUnreachableChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onNetworkReconnectionQualityChanged)(ACSDiagnosticQualityChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onNetworkReceiveQualityChanged)(ACSDiagnosticQualityChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onNetworkSendQualityChanged)(ACSDiagnosticQualityChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(MediaDiagnosticsEvents)
@interface ACSMediaDiagnosticsEvents : NSObject
@property (copy, nullable) void (^onIsSpeakerNotFunctioningChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsSpeakerBusyChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsSpeakerMutedChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsSpeakerVolumeZeroChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsNoSpeakerDevicesAvailableChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsSpeakingWhileMicrophoneIsMutedChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsNoMicrophoneDevicesAvailableChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsMicrophoneBusyChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsCameraFrozenChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsCameraStartFailedChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsCameraStartTimedOutChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsMicrophoneNotFunctioningChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsMicrophoneMutedUnexpectedlyChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onIsCameraPermissionDeniedChanged)(ACSDiagnosticFlagChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(MediaStatisticsCallFeatureEvents)
@interface ACSMediaStatisticsCallFeatureEvents : NSObject
@property (copy, nullable) void (^onReportReceived)(ACSMediaStatisticsReportReceivedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(DataChannelReceiverEvents)
@interface ACSDataChannelReceiverEvents : NSObject
@property (copy, nullable) void (^onMessageReceived)(ACSPropertyChangedEventArgs * _Nonnull);
@property (copy, nullable) void (^onClosed)(ACSPropertyChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(DataChannelCallFeatureEvents)
@interface ACSDataChannelCallFeatureEvents : NSObject
@property (copy, nullable) void (^onReceiverCreated)(ACSDataChannelReceiverCreatedEventArgs * _Nonnull);
- (void) removeAll;
@end

NS_SWIFT_NAME(CapabilitiesCallFeatureEvents)
@interface ACSCapabilitiesCallFeatureEvents : NSObject
@property (copy, nullable) void (^onCapabilitiesChanged)(ACSCapabilitiesChangedEventArgs * _Nonnull);
- (void) removeAll;
@end

/**
 * A set of methods that are called by ACSLocalVideoStream in response to important events.
 */
NS_SWIFT_NAME(LocalVideoStreamDelegate)
@protocol ACSLocalVideoStreamDelegate <NSObject>
@optional
- (void)onStateChanged:(ACSLocalVideoStream * _Nonnull)localVideoStream :(ACSVideoStreamStateChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( localVideoStream(_:didChangeState:));
@end

/**
 * A set of methods that are called by ACSCallAgent in response to important events.
 */
NS_SWIFT_NAME(CallAgentDelegate)
@protocol ACSCallAgentDelegate <NSObject>
@optional
- (void)onCallsUpdated:(ACSCallAgent * _Nonnull)callAgent :(ACSCallsUpdatedEventArgs * _Nonnull)args NS_SWIFT_NAME( callAgent(_:didUpdateCalls:));
- (void)onIncomingCall:(ACSCallAgent * _Nonnull)callAgent :(ACSIncomingCall * _Nonnull)incomingCall NS_SWIFT_NAME( callAgent(_:didRecieveIncomingCall:));
@end

/**
 * A set of methods that are called by ACSCall in response to important events.
 */
NS_SWIFT_NAME(CallDelegate)
@protocol ACSCallDelegate <NSObject>
@optional
- (void)onIdChanged:(ACSCall * _Nonnull)call :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didChangeId:));
- (void)onStartTimeUpdated:(ACSCall * _Nonnull)call :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didUpdateStartTime:));
- (void)onStateChanged:(ACSCall * _Nonnull)call :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didChangeState:));
- (void)onRoleChanged:(ACSCall * _Nonnull)call :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didChangeRole:));
- (void)onRemoteParticipantsUpdated:(ACSCall * _Nonnull)call :(ACSParticipantsUpdatedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didUpdateRemoteParticipant:));
- (void)onLocalVideoStreamsUpdated:(ACSCall * _Nonnull)call :(ACSLocalVideoStreamsUpdatedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didUpdateLocalVideoStreams:)) DEPRECATED_MSG_ATTRIBUTE("Use didChangeState on VideoStream types instead");
- (void)onIsMutedChanged:(ACSCall * _Nonnull)call :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didChangeMuteState:)) DEPRECATED_MSG_ATTRIBUTE("Use call(_:didUpdateOutgoingAudioState:) instead");
- (void)onOutgoingAudioStateChanged:(ACSCall * _Nonnull)call :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didUpdateOutgoingAudioState:));
- (void)onMutedByOthers:(ACSCall * _Nonnull)call :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didGetMutedByOthers:));
- (void)onIncomingAudioStateChanged:(ACSCall * _Nonnull)call :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didUpdateIncomingAudioState:));
- (void)onTotalParticipantCountChanged:(ACSCall * _Nonnull)call :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( call(_:didChangeTotalParticipantCount:));
@end

/**
 * A set of methods that are called by ACSRemoteParticipant in response to important events.
 */
NS_SWIFT_NAME(RemoteParticipantDelegate)
@protocol ACSRemoteParticipantDelegate <NSObject>
@optional
- (void)onStateChanged:(ACSRemoteParticipant * _Nonnull)remoteParticipant :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( remoteParticipant(_:didChangeState:));
- (void)onIsMutedChanged:(ACSRemoteParticipant * _Nonnull)remoteParticipant :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( remoteParticipant(_:didChangeMuteState:));
- (void)onIsSpeakingChanged:(ACSRemoteParticipant * _Nonnull)remoteParticipant :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( remoteParticipant(_:didChangeSpeakingState:));
- (void)onDisplayNameChanged:(ACSRemoteParticipant * _Nonnull)remoteParticipant :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( remoteParticipant(_:didChangeDisplayName:));
- (void)onRoleChanged:(ACSRemoteParticipant * _Nonnull)remoteParticipant :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( remoteParticipant(_:didChangeRole:));
- (void)onVideoStreamsUpdated:(ACSRemoteParticipant * _Nonnull)remoteParticipant :(ACSRemoteVideoStreamsEventArgs * _Nonnull)args NS_SWIFT_NAME( remoteParticipant(_:didUpdateVideoStreams:)) DEPRECATED_MSG_ATTRIBUTE("Use remoteParticipant(_:didChangeVideoStreamState:)) instead");
- (void)onVideoStreamStateChanged:(ACSRemoteParticipant * _Nonnull)remoteParticipant :(ACSVideoStreamStateChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( remoteParticipant(_:didChangeVideoStreamState:));
@end

/**
 * A set of methods that are called by ACSRemoteVideoStream in response to important events.
 */
NS_SWIFT_NAME(RemoteVideoStreamDelegate)
@protocol ACSRemoteVideoStreamDelegate <NSObject>
@optional
- (void)onStateChanged:(ACSRemoteVideoStream * _Nonnull)remoteVideoStream :(ACSVideoStreamStateChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( remoteVideoStream(_:didChangeState:));
@end

/**
 * A set of methods that are called by ACSIncomingCall in response to important events.
 */
NS_SWIFT_NAME(IncomingCallDelegate)
@protocol ACSIncomingCallDelegate <NSObject>
@optional
- (void)onCallEnded:(ACSIncomingCall * _Nonnull)incomingCall :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( incomingCall(_:didEnd:));
@end

/**
 * A set of methods that are called by ACSTeamsCallAgent in response to important events.
 */
NS_SWIFT_NAME(TeamsCallAgentDelegate)
@protocol ACSTeamsCallAgentDelegate <NSObject>
@optional
- (void)onCallsUpdated:(ACSTeamsCallAgent * _Nonnull)teamsCallAgent :(ACSTeamsCallsUpdatedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCallAgent(_:didUpdateCalls:));
- (void)onIncomingCall:(ACSTeamsCallAgent * _Nonnull)teamsCallAgent :(ACSTeamsIncomingCall * _Nonnull)incomingCall NS_SWIFT_NAME( teamsCallAgent(_:didRecieveIncomingCall:));
@end

/**
 * A set of methods that are called by ACSTeamsCall in response to important events.
 */
NS_SWIFT_NAME(TeamsCallDelegate)
@protocol ACSTeamsCallDelegate <NSObject>
@optional
- (void)onIdChanged:(ACSTeamsCall * _Nonnull)teamsCall :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCall(_:didChangeId:));
- (void)onStartTimeUpdated:(ACSTeamsCall * _Nonnull)teamsCall :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCall(_:didUpdateStartTime:));
- (void)onStateChanged:(ACSTeamsCall * _Nonnull)teamsCall :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCall(_:didChangeState:));
- (void)onRoleChanged:(ACSTeamsCall * _Nonnull)teamsCall :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCall(_:didChangeRole:));
- (void)onRemoteParticipantsUpdated:(ACSTeamsCall * _Nonnull)teamsCall :(ACSParticipantsUpdatedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCall(_:didUpdateRemoteParticipant:));
- (void)onOutgoingAudioStateChanged:(ACSTeamsCall * _Nonnull)teamsCall :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCall(_:didUpdateOutgoingAudioState:));
- (void)onMutedByOthers:(ACSTeamsCall * _Nonnull)teamsCall :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCall(_:didGetMutedByOthers:));
- (void)onIncomingAudioStateChanged:(ACSTeamsCall * _Nonnull)teamsCall :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCall(_:didUpdateIncomingAudioState:));
- (void)onTotalParticipantCountChanged:(ACSTeamsCall * _Nonnull)teamsCall :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCall(_:didChangeTotalParticipantCount:));
@end

/**
 * A set of methods that are called by ACSTeamsIncomingCall in response to important events.
 */
NS_SWIFT_NAME(TeamsIncomingCallDelegate)
@protocol ACSTeamsIncomingCallDelegate <NSObject>
@optional
- (void)onCallEnded:(ACSTeamsIncomingCall * _Nonnull)teamsIncomingCall :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsIncomingCall(_:didEnd:));
@end

/**
 * A set of methods that are called by ACSDeviceManager in response to important events.
 */
NS_SWIFT_NAME(DeviceManagerDelegate)
@protocol ACSDeviceManagerDelegate <NSObject>
@optional
- (void)onCamerasUpdated:(ACSDeviceManager * _Nonnull)deviceManager :(ACSVideoDevicesUpdatedEventArgs * _Nonnull)args NS_SWIFT_NAME( deviceManager(_:didUpdateCameras:));
@end

/**
 * A set of methods that are called by ACSCallLobby in response to important events.
 */
NS_SWIFT_NAME(CallLobbyDelegate)
@protocol ACSCallLobbyDelegate <NSObject>
@optional
- (void)onLobbyParticipantsUpdated:(ACSCallLobby * _Nonnull)callLobby :(ACSParticipantsUpdatedEventArgs * _Nonnull)args NS_SWIFT_NAME( callLobby(_:didUpdateLobbyParticipants:));
@end

/**
 * A set of methods that are called by ACSRealTimeTextCallFeature in response to important events.
 */
NS_SWIFT_NAME(RealTimeTextCallFeatureDelegate)
@protocol ACSRealTimeTextCallFeatureDelegate <NSObject>
@optional
- (void)onInfoReceived:(ACSRealTimeTextCallFeature * _Nonnull)realTimeTextCallFeature :(ACSRealTimeTextInfoReceivedEventArgs * _Nonnull)args NS_SWIFT_NAME( realTimeTextCallFeature(_:didReceiveInfo:));
@end

/**
 * A set of methods that are called by ACSRecordingCallFeature in response to important events.
 */
NS_SWIFT_NAME(RecordingCallFeatureDelegate)
@protocol ACSRecordingCallFeatureDelegate <NSObject>
@optional
- (void)onIsRecordingActiveChanged:(ACSRecordingCallFeature * _Nonnull)recordingCallFeature :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( recordingCallFeature(_:didChangeRecordingState:));
@end

/**
 * A set of methods that are called by ACSTranscriptionCallFeature in response to important events.
 */
NS_SWIFT_NAME(TranscriptionCallFeatureDelegate)
@protocol ACSTranscriptionCallFeatureDelegate <NSObject>
@optional
- (void)onIsTranscriptionActiveChanged:(ACSTranscriptionCallFeature * _Nonnull)transcriptionCallFeature :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( transcriptionCallFeature(_:didChangeTranscriptionState:));
@end

/**
 * A set of methods that are called by ACSCommunicationCaptions in response to important events.
 */
NS_SWIFT_NAME(CommunicationCaptionsDelegate)
@protocol ACSCommunicationCaptionsDelegate <NSObject>
@optional
- (void)onActiveSpokenLanguageChanged:(ACSCommunicationCaptions * _Nonnull)communicationCaptions :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( communicationCaptions(_:didChangeActiveSpokenLanguageState:));
- (void)onCaptionsEnabledChanged:(ACSCommunicationCaptions * _Nonnull)communicationCaptions :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( communicationCaptions(_:didChangeCaptionsEnabledState:));
- (void)onCaptionsReceived:(ACSCommunicationCaptions * _Nonnull)communicationCaptions :(ACSCommunicationCaptionsReceivedEventArgs * _Nonnull)args NS_SWIFT_NAME( communicationCaptions(_:didReceiveCaptions:));
@end

/**
 * A set of methods that are called by ACSTeamsCaptions in response to important events.
 */
NS_SWIFT_NAME(TeamsCaptionsDelegate)
@protocol ACSTeamsCaptionsDelegate <NSObject>
@optional
- (void)onCaptionsEnabledChanged:(ACSTeamsCaptions * _Nonnull)teamsCaptions :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCaptions(_:didChangeCaptionsEnabledState:));
- (void)onActiveSpokenLanguageChanged:(ACSTeamsCaptions * _Nonnull)teamsCaptions :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCaptions(_:didChangeActiveSpokenLanguageState:));
- (void)onActiveCaptionLanguageChanged:(ACSTeamsCaptions * _Nonnull)teamsCaptions :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCaptions(_:didChangeActiveCaptionLanguageState:));
- (void)onCaptionsReceived:(ACSTeamsCaptions * _Nonnull)teamsCaptions :(ACSTeamsCaptionsReceivedEventArgs * _Nonnull)args NS_SWIFT_NAME( teamsCaptions(_:didReceiveCaptions:));
@end

/**
 * A set of methods that are called by ACSCaptionsCallFeature in response to important events.
 */
NS_SWIFT_NAME(CaptionsCallFeatureDelegate)
@protocol ACSCaptionsCallFeatureDelegate <NSObject>
@optional
- (void)onActiveCaptionsTypeChanged:(ACSCaptionsCallFeature * _Nonnull)captionsCallFeature :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( captionsCallFeature(_:didChangeActiveCaptionsType:));
@end

/**
 * A set of methods that are called by ACSDominantSpeakersCallFeature in response to important events.
 */
NS_SWIFT_NAME(DominantSpeakersCallFeatureDelegate)
@protocol ACSDominantSpeakersCallFeatureDelegate <NSObject>
@optional
- (void)onDominantSpeakersChanged:(ACSDominantSpeakersCallFeature * _Nonnull)dominantSpeakersCallFeature :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( dominantSpeakersCallFeature(_:didChangeDominantSpeakers:));
@end

/**
 * A set of methods that are called by ACSRaiseHandCallFeature in response to important events.
 */
NS_SWIFT_NAME(RaiseHandCallFeatureDelegate)
@protocol ACSRaiseHandCallFeatureDelegate <NSObject>
@optional
- (void)onHandRaised:(ACSRaiseHandCallFeature * _Nonnull)raiseHandCallFeature :(ACSRaisedHandChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( raiseHandCallFeature(_:didRaiseHand:));
- (void)onHandLowered:(ACSRaiseHandCallFeature * _Nonnull)raiseHandCallFeature :(ACSLoweredHandChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( raiseHandCallFeature(_:didLowerHand:));
@end

/**
 * A set of methods that are called by ACSSpotlightCallFeature in response to important events.
 */
NS_SWIFT_NAME(SpotlightCallFeatureDelegate)
@protocol ACSSpotlightCallFeatureDelegate <NSObject>
@optional
- (void)onSpotlightChanged:(ACSSpotlightCallFeature * _Nonnull)spotlightCallFeature :(ACSSpotlightChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(spotlightCallFeature(_:didChangeSpotlight:));
@end

/**
 * A set of methods that are called by ACSScreenShareOutgoingVideoStream in response to important events.
 */
NS_SWIFT_NAME(ScreenShareOutgoingVideoStreamDelegate)
@protocol ACSScreenShareOutgoingVideoStreamDelegate <NSObject>
@optional
- (void)onStateChanged:(ACSScreenShareOutgoingVideoStream * _Nonnull)screenShareOutgoingVideoStream :(ACSVideoStreamStateChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( screenShareOutgoingVideoStream(_:didChangeState:));
- (void)onFormatChanged:(ACSScreenShareOutgoingVideoStream * _Nonnull)screenShareOutgoingVideoStream :(ACSVideoStreamFormatChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(screenShareOutgoingVideoStream(_:didChangeFormat:));
@end

/**
 * A set of methods that are called by ACSVirtualOutgoingVideoStream in response to important events.
 */
NS_SWIFT_NAME(VirtualOutgoingVideoStreamDelegate)
@protocol ACSVirtualOutgoingVideoStreamDelegate <NSObject>
@optional
- (void)onStateChanged:(ACSVirtualOutgoingVideoStream * _Nonnull)virtualOutgoingVideoStream :(ACSVideoStreamStateChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(virtualOutgoingVideoStream(_:didChangeState:));
- (void)onFormatChanged:(ACSVirtualOutgoingVideoStream * _Nonnull)virtualOutgoingVideoStream :(ACSVideoStreamFormatChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(virtualOutgoingVideoStream(_:didChangeFormat:));
@end

/**
 * A set of methods that are called by ACSRawIncomingVideoStream in response to important events.
 */
NS_SWIFT_NAME(RawIncomingVideoStreamDelegate)
@protocol ACSRawIncomingVideoStreamDelegate <NSObject>
@optional
- (void)onRawVideoFrameReceived:(ACSRawIncomingVideoStream * _Nonnull)rawIncomingVideoStream :(ACSRawVideoFrameReceivedEventArgs * _Nonnull)args NS_SWIFT_NAME( rawIncomingVideoStream(_:didReceiveRawVideoFrame:));
- (void)onStateChanged:(ACSRawIncomingVideoStream * _Nonnull)rawIncomingVideoStream :(ACSVideoStreamStateChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( rawIncomingVideoStream(_:didChangeState:));
@end

/**
 * A set of methods that are called by ACSLocalOutgoingAudioStream in response to important events.
 */
NS_SWIFT_NAME(LocalOutgoingAudioStreamDelegate)
@protocol ACSLocalOutgoingAudioStreamDelegate <NSObject>
@optional
- (void)onStateChanged:(ACSLocalOutgoingAudioStream * _Nonnull)localOutgoingAudioStream :(ACSAudioStreamStateChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(localAudioStream(_:didChangeState:));
@end

/**
 * A set of methods that are called by ACSRemoteIncomingAudioStream in response to important events.
 */
NS_SWIFT_NAME(RemoteIncomingAudioStreamDelegate)
@protocol ACSRemoteIncomingAudioStreamDelegate <NSObject>
@optional
- (void)onStateChanged:(ACSRemoteIncomingAudioStream * _Nonnull)remoteIncomingAudioStream :(ACSAudioStreamStateChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(remoteAudioStream(_:didChangeState:));
@end

/**
 * A set of methods that are called by ACSRawIncomingAudioStream in response to important events.
 */
NS_SWIFT_NAME(RawIncomingAudioStreamDelegate)
@protocol ACSRawIncomingAudioStreamDelegate <NSObject>
@optional
- (void)onMixedAudioBufferReceived:(ACSRawIncomingAudioStream * _Nonnull)rawIncomingAudioStream :(ACSIncomingMixedAudioEventArgs * _Nonnull)args NS_SWIFT_NAME(rawIncomingAudioStream(_:didReceiveMixedAudioBuffer:));
- (void)onStateChanged:(ACSRawIncomingAudioStream * _Nonnull)rawIncomingAudioStream :(ACSAudioStreamStateChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(rawIncomingAudioStream(_:didChangeState:));
@end

/**
 * A set of methods that are called by ACSRawOutgoingAudioStream in response to important events.
 */
NS_SWIFT_NAME(RawOutgoingAudioStreamDelegate)
@protocol ACSRawOutgoingAudioStreamDelegate <NSObject>
@optional
- (void)onStateChanged:(ACSRawOutgoingAudioStream * _Nonnull)rawOutgoingAudioStream :(ACSAudioStreamStateChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(rawOutgoingAudioStream(_:didChangeState:));
@end

/**
 * A set of methods that are called by ACSLocalVideoEffectsFeature in response to important events.
 */
NS_SWIFT_NAME(LocalVideoEffectsFeatureDelegate)
@protocol ACSLocalVideoEffectsFeatureDelegate <NSObject>
@optional
- (void)onVideoEffectEnabled:(ACSLocalVideoEffectsFeature * _Nonnull)localVideoEffectsFeature :(ACSVideoEffectEnabledEventArgs * _Nonnull)args NS_SWIFT_NAME(localVideoEffectsFeature(_:didEnableVideoEffect:));
- (void)onVideoEffectDisabled:(ACSLocalVideoEffectsFeature * _Nonnull)localVideoEffectsFeature :(ACSVideoEffectDisabledEventArgs * _Nonnull)args NS_SWIFT_NAME(localVideoEffectsFeature(_:didDisableVideoEffect:));
- (void)onVideoEffectError:(ACSLocalVideoEffectsFeature * _Nonnull)localVideoEffectsFeature :(ACSVideoEffectErrorEventArgs * _Nonnull)args NS_SWIFT_NAME(localVideoEffectsFeature(_:didReceiveVideoEffectError:));
@end

/**
 * A set of methods that are called by ACSNetworkDiagnostics in response to important events.
 */
NS_SWIFT_NAME(NetworkDiagnosticsDelegate)
@protocol ACSNetworkDiagnosticsDelegate <NSObject>
@optional
- (void)onIsNetworkUnavailableChanged:(ACSNetworkDiagnostics * _Nonnull)networkDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(networkDiagnostics(_:didChangeIsNetworkUnavailable:));
- (void)onIsNetworkRelaysUnreachableChanged:(ACSNetworkDiagnostics * _Nonnull)networkDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(networkDiagnostics(_:didChangeIsNetworkRelaysUnreachable:));
- (void)onNetworkReconnectionQualityChanged:(ACSNetworkDiagnostics * _Nonnull)networkDiagnostics :(ACSDiagnosticQualityChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(networkDiagnostics(_:didChangeNetworkReconnectionQuality:));
- (void)onNetworkReceiveQualityChanged:(ACSNetworkDiagnostics * _Nonnull)networkDiagnostics :(ACSDiagnosticQualityChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(networkDiagnostics(_:didChangeNetworkReceiveQuality:));
- (void)onNetworkSendQualityChanged:(ACSNetworkDiagnostics * _Nonnull)networkDiagnostics :(ACSDiagnosticQualityChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(networkDiagnostics(_:didChangeNetworkSendQuality:));
@end

/**
 * A set of methods that are called by ACSMediaDiagnostics in response to important events.
 */
NS_SWIFT_NAME(MediaDiagnosticsDelegate)
@protocol ACSMediaDiagnosticsDelegate <NSObject>
@optional
- (void)onIsSpeakerNotFunctioningChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsSpeakerNotFunctioning:));
- (void)onIsSpeakerBusyChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsSpeakerBusy:));
- (void)onIsSpeakerMutedChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsSpeakerMuted:));
- (void)onIsSpeakerVolumeZeroChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsSpeakerVolumeZero:));
- (void)onIsNoSpeakerDevicesAvailableChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsNoSpeakerDevicesAvailable:));
- (void)onIsSpeakingWhileMicrophoneIsMutedChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsSpeakingWhileMicrophoneIsMuted:));
- (void)onIsNoMicrophoneDevicesAvailableChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsNoMicrophoneDevicesAvailable:));
- (void)onIsMicrophoneBusyChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsMicrophoneBusy:));
- (void)onIsCameraFrozenChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsCameraFrozen:));
- (void)onIsCameraStartFailedChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsCameraStartFailed:));
- (void)onIsCameraStartTimedOutChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsCameraStartTimedOut:));
- (void)onIsMicrophoneNotFunctioningChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsMicrophoneNotFunctioning:));
- (void)onIsMicrophoneMutedUnexpectedlyChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsMicrophoneMutedUnexpectedly:));
- (void)onIsCameraPermissionDeniedChanged:(ACSMediaDiagnostics * _Nonnull)mediaDiagnostics :(ACSDiagnosticFlagChangedEventArgs * _Nonnull)args NS_SWIFT_NAME(mediaDiagnostics(_:didChangeIsCameraPermissionDenied:));
@end

/**
 * A set of methods that are called by ACSMediaStatisticsCallFeature in response to important events.
 */
NS_SWIFT_NAME(MediaStatisticsCallFeatureDelegate)
@protocol ACSMediaStatisticsCallFeatureDelegate <NSObject>
@optional
- (void)onReportReceived:(ACSMediaStatisticsCallFeature * _Nonnull)mediaStatisticsCallFeature :(ACSMediaStatisticsReportReceivedEventArgs * _Nonnull)args NS_SWIFT_NAME( mediaStatisticsCallFeature(_:didReceiveReport:));
@end

/**
 * A set of methods that are called by ACSDataChannelReceiver in response to important events.
 */
NS_SWIFT_NAME(DataChannelReceiverDelegate)
@protocol ACSDataChannelReceiverDelegate <NSObject>
@optional
- (void)onMessageReceived:(ACSDataChannelReceiver * _Nonnull)dataChannelReceiver :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( dataChannelReceiver(_:didReceiveMessage:));
- (void)onClosed:(ACSDataChannelReceiver * _Nonnull)dataChannelReceiver :(ACSPropertyChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( dataChannelReceiver(_:didClose:));
@end

/**
 * A set of methods that are called by ACSDataChannelCallFeature in response to important events.
 */
NS_SWIFT_NAME(DataChannelCallFeatureDelegate)
@protocol ACSDataChannelCallFeatureDelegate <NSObject>
@optional
- (void)onReceiverCreated:(ACSDataChannelCallFeature * _Nonnull)dataChannelCallFeature :(ACSDataChannelReceiverCreatedEventArgs * _Nonnull)args NS_SWIFT_NAME( dataChannelCallFeature(_:didCreateReceiver:));
@end

/**
 * A set of methods that are called by ACSCapabilitiesCallFeature in response to important events.
 */
NS_SWIFT_NAME(CapabilitiesCallFeatureDelegate)
@protocol ACSCapabilitiesCallFeatureDelegate <NSObject>
@optional
- (void)onCapabilitiesChanged:(ACSCapabilitiesCallFeature * _Nonnull)capabilitiesCallFeature :(ACSCapabilitiesChangedEventArgs * _Nonnull)args NS_SWIFT_NAME( capabilitiesCallFeature(_:didChangeCapabilities:));
@end

/// Base class for all Video streams which contains logic for rendering a Video and/or provide video frames
NS_SWIFT_NAME(CallVideoStream)
@interface ACSCallVideoStream : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Get the type of the derived class
@property (readonly) ACSVideoStreamType type;

/// Get VideoStreamSourceType of the current CallVideoStream
@property (readonly) ACSVideoStreamSourceType sourceType;

/// Informs the current running state of this CallVideoStream. It might change during the call due network conditions or other events.
@property (readonly) ACSVideoStreamState state;

/// Informs if the video is Incoming or Outgoing
@property (readonly) ACSStreamDirection direction;

/// MediaStream type of the current remote video stream (Video or ScreenShare).
@property (readonly) ACSMediaStreamType mediaStreamType DEPRECATED_MSG_ATTRIBUTE("Use sourceType instead");

/// Unique Identifier of the current remote video stream.
@property (readonly) int id;

@end

/// Contains information about common properties between different types of outgoing video streams
NS_SWIFT_NAME(OutgoingVideoStream)
@interface ACSOutgoingVideoStream : ACSCallVideoStream
-(nonnull instancetype)init NS_UNAVAILABLE;
@end

/// Contains information about common properties between the different types of incoming video streams
NS_SWIFT_NAME(IncomingVideoStream)
@interface ACSIncomingVideoStream : ACSCallVideoStream
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Return the remote participant endpoint id that owns this incoming video streams Same user logged in from different devices will have different ParticipantSourceId Note: This field is not the same as CommunicationIdentifier.
@property (retain, nonnull, readonly) NSString * participantSourceId;

@end

/// Hold properties that configure OutgoingVideoStreams
NS_SWIFT_NAME(OutgoingVideoOptions)
@interface ACSOutgoingVideoOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Get or set the OutgoingVideoStreams should start once the call start
@property (copy, nonnull) NSArray<ACSOutgoingVideoStream *> * streams;

/// Get or set the OutgoingVideoConstraints
@property (retain, nullable) ACSOutgoingVideoConstraints * constraints;

@end

/// Hold properties that configure OutgoingVideoConstraints
NS_SWIFT_NAME(OutgoingVideoConstraints)
@interface ACSOutgoingVideoConstraints : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Set a constraint on height
@property int maxHeight;

/// Set a constraint on width
@property int maxWidth;

/// Set a constriant on frame rate
@property int maxFrameRate;

/// Set a constraint on bit rate
@property int maxBitRate;

@end

/// Hold properties that configure incoming video streams
NS_SWIFT_NAME(IncomingVideoOptions)
@interface ACSIncomingVideoOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Get or set the Incoming Video Stream that should be provided
@property ACSVideoStreamType streamType;

@end

/// Property bag class for Video Options. Use this class to set video options required during a call (start/accept/join)
DEPRECATED_MSG_ATTRIBUTE("Use incomingVideoOptions and outgoingVideoOptions instead")
NS_SWIFT_NAME(VideoOptions)
@interface ACSVideoOptions : NSObject
-(nonnull instancetype)init:(NSArray<ACSLocalVideoStream *> * _Nonnull )localVideoStreams NS_SWIFT_NAME( init(localVideoStreams:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The video stream that is used to render the video on the UI surface
@property (copy, nonnull, readonly) NSArray<ACSLocalVideoStream *> * localVideoStreams;

@end

/// Local video stream information
NS_SWIFT_NAME(LocalVideoStream)
@interface ACSLocalVideoStream : ACSOutgoingVideoStream
-(nonnull instancetype)init:(ACSVideoDeviceInfo * _Nonnull )camera NS_SWIFT_NAME( init(camera:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/// Video device to use as source for local video.
@property (retain, nonnull, readonly) ACSVideoDeviceInfo * source;

/// Sets to True when the local video stream is being sent on a call.
@property (readonly) BOOL isSending DEPRECATED_MSG_ATTRIBUTE("Use state property instead");

/**
 * The delegate that will handle events from the ACSLocalVideoStream.
 */
@property(nonatomic, weak, nullable) id<ACSLocalVideoStreamDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSLocalVideoStream.
 */
@property(nonatomic, strong, nonnull, readonly) ACSLocalVideoStreamEvents *events;

// Class extension begins for LocalVideoStream.
-(void)switchSource:(ACSVideoDeviceInfo* _Nonnull)camera withCompletionHandler:(void (^ _Nonnull)(NSError* _Nullable error))completionHandler NS_SWIFT_NAME( switchSource(camera:completionHandler:));

-(id _Nonnull)feature: (Class _Nonnull)featureClass NS_REFINED_FOR_SWIFT;
// Class extension ends for LocalVideoStream.

@end

/// Information about a video device
NS_SWIFT_NAME(VideoDeviceInfo)
@interface ACSVideoDeviceInfo : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Get the name of this video device.
@property (retain, nonnull, readonly) NSString * name;

/// Get Name of this audio device.
@property (retain, nonnull, readonly) NSString * id;

/// Direction of the camera
@property (readonly) ACSCameraFacing cameraFacing;

/// Get the Device Type of this video device.
@property (readonly) ACSVideoDeviceType deviceType;

@end

/// LocalVideoStreamFeature base type, features extensions for local video stream.
NS_SWIFT_NAME(LocalVideoStreamFeature)
@interface ACSLocalVideoStreamFeature : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Name of the extended LocalVideoStreamFeature.
@property (retain, nonnull, readonly) NSString * name;

@end

/// Contains Information about the CallVideoStream that it;s state has changed
NS_SWIFT_NAME(VideoStreamStateChangedEventArgs)
@interface ACSVideoStreamStateChangedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// CallVideoStream that it's state changed
@property (retain, nonnull, readonly) ACSCallVideoStream * stream;

/// Contains an important message about the functioning of the CallVideoStream.
@property (retain, nonnull, readonly) NSString * message;

@end

/// Holds properties that configure outgoing audio preprocessing before call start
NS_SWIFT_NAME(OutgoingAudioFilters)
@interface ACSOutgoingAudioFilters : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Enables Analog Automatic Gain Control
@property BOOL analogAutomaticGainControlEnabled;

/// Enables Digital Automatic Gain Control
@property BOOL digitalAutomaticGainControlEnabled;

/// Changes mode/type of Noise Suppression
@property ACSNoiseSuppressionMode noiseSuppressionMode;

/// Toggles Music Mode
@property BOOL musicModeEnabled;

/// Toggles Echo Cancellation. Requires Music Mode to be on.
@property BOOL acousticEchoCancellationEnabled;

@end

/// Holds properties that configure outgoing audio preprocessing during call
NS_SWIFT_NAME(LiveOutgoingAudioFilters)
@interface ACSLiveOutgoingAudioFilters : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Changes mode/type of Noise Suppression
@property ACSNoiseSuppressionMode noiseSuppressionMode;

/// Toggles Music Mode
@property BOOL musicModeEnabled;

/// Toggles Echo Cancellation. Requires Music Mode to be on.
@property BOOL acousticEchoCancellationEnabled;

@end

/// Property bag class for Audio Options. Use this class to set audio settings required during a call (start/join)
DEPRECATED_MSG_ATTRIBUTE("Use IncomingAudioOptions and OutgoingAudioOptions instead")
NS_SWIFT_NAME(AudioOptions)
@interface ACSAudioOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Start an outgoing or accept incoming call muted (true) or un-muted(false)
@property BOOL muted DEPRECATED_MSG_ATTRIBUTE("Deprecated use muted property in OutgoingAudioOptions instead");

@end

/// Property bag class for Incoming Audio Options. Use this class to set audio settings required during a call (start/join)
NS_SWIFT_NAME(IncomingAudioOptions)
@interface ACSIncomingAudioOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Start an outgoing or accept incoming call with speaker muted (true) or un-muted(false).
@property BOOL muted;

/// Incoming Audio Stream that will be started when the call connects.
@property (retain, nullable) ACSIncomingAudioStream * stream;

@end

/// Base class for all Audio Stream objects
NS_SWIFT_NAME(CallAudioStream)
@interface ACSCallAudioStream : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Informs the kind of the Audio Stream.
@property (readonly) ACSAudioStreamType type;

/// Informs the state of the Audio Stream.
@property (readonly) ACSAudioStreamState state;

/// Informs if the audio is Incoming or Outgoing
@property (readonly) ACSStreamDirection direction;

@end

/// Base Class for all Incoming Audio Stream objects
NS_SWIFT_NAME(IncomingAudioStream)
@interface ACSIncomingAudioStream : ACSCallAudioStream
-(nonnull instancetype)init NS_UNAVAILABLE;
@end

/// Property bag class for Outgoing Audio Options. Use this class to set audio settings required during a call (start/join)
NS_SWIFT_NAME(OutgoingAudioOptions)
@interface ACSOutgoingAudioOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Start an outgoing or accept incoming call with microphone muted (true) or un-muted(false)
@property BOOL muted;

/// Start an outgoing or accept incoming call with outgoing audio filter features
@property (retain, nullable) ACSOutgoingAudioFilters * filters;

/// Outgoing Audio Stream that will be started when the call connects.
@property (retain, nullable) ACSOutgoingAudioStream * stream;

@end

/// Base Class for all Outgoing Audio Stream objects
NS_SWIFT_NAME(OutgoingAudioStream)
@interface ACSOutgoingAudioStream : ACSCallAudioStream
-(nonnull instancetype)init NS_UNAVAILABLE;
@end

/// Holds options for video and audio
NS_SWIFT_NAME(CallOptions)
@interface ACSCallOptions : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Set or set the IncomingVideoOptions that should be taken in count once the call start
@property (retain, nullable) ACSIncomingVideoOptions * incomingVideoOptions;

/// Set or set the OutgoingVideoOptions that should be taken in count once the call start
@property (retain, nullable) ACSOutgoingVideoOptions * outgoingVideoOptions;

/// Incoming Audio options when joining or accepting a call
@property (retain, nullable) ACSIncomingAudioOptions * incomingAudioOptions;

/// Outgoing Audio options when joining or accepting a call
@property (retain, nullable) ACSOutgoingAudioOptions * outgoingAudioOptions;

// Class extension begins for CallOptions.
@property(nullable) ACSCallKitRemoteInfo* callKitRemoteInfo;
// Class extension ends for CallOptions.

@end

/// Options to be passed when joining a Teams call
NS_SWIFT_NAME(JoinTeamsCallOptions)
@interface ACSJoinTeamsCallOptions : ACSCallOptions
-(nonnull instancetype)init;

@end

/// Options to be passed when joining a call
NS_SWIFT_NAME(JoinCallOptions)
@interface ACSJoinCallOptions : ACSCallOptions
-(nonnull instancetype)init;

/// Video options. When both OutgoingVideoOptions and VideoOptions are specified both options will be merged.
@property (retain, nullable) ACSVideoOptions * videoOptions DEPRECATED_MSG_ATTRIBUTE("Use incomingVideoOptions and outgoingVideoOptions instead");

/// Audio options when joining a call
@property (retain, nullable) ACSAudioOptions * audioOptions DEPRECATED_MSG_ATTRIBUTE("Use incomingAudioOptions and outgoingAudioOptions instead.");

@end

/// Options to be passed when accepting a Teams call
NS_SWIFT_NAME(AcceptTeamsCallOptions)
@interface ACSAcceptTeamsCallOptions : ACSCallOptions
-(nonnull instancetype)init;

@end

/// Options to be passed when accepting a call
NS_SWIFT_NAME(AcceptCallOptions)
@interface ACSAcceptCallOptions : ACSCallOptions
-(nonnull instancetype)init;

/// Video options. When both OutgoingVideoOptions and VideoOptions are specified both options will be merged.
@property (retain, nullable) ACSVideoOptions * videoOptions DEPRECATED_MSG_ATTRIBUTE("Use incomingVideoOptions and outgoingVideoOptions instead");

@end

/// Options to be passed when starting a call
NS_SWIFT_NAME(StartCallOptions)
@interface ACSStartCallOptions : ACSCallOptions
-(nonnull instancetype)init;

/// Video options. When both OutgoingVideoOptions and VideoOptions are specified both options will be merged.
@property (retain, nullable) ACSVideoOptions * videoOptions DEPRECATED_MSG_ATTRIBUTE("Use incomingVideoOptions and outgoingVideoOptions instead");

/// Audio options when joining a call
@property (retain, nullable) ACSAudioOptions * audioOptions DEPRECATED_MSG_ATTRIBUTE("Use incomingAudioOptions and outgoingAudioOptions instead.");

// Class extension begins for StartCallOptions.
@property(nonatomic, nonnull) PhoneNumberIdentifier* alternateCallerId;
// Class extension ends for StartCallOptions.

@end

/// Hold properties that configure VideoConstraints
NS_SWIFT_NAME(VideoConstraints)
@interface ACSVideoConstraints : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Constraints for outgoing video
@property (retain, nullable) ACSOutgoingVideoConstraints * outgoingVideoConstraints;

@end

/// Options when making an outgoing PSTN call
NS_SWIFT_NAME(AddPhoneNumberOptions)
@interface ACSAddPhoneNumberOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

// Class extension begins for AddPhoneNumberOptions.
@property(nonatomic, nonnull) PhoneNumberIdentifier* alternateCallerId;
// Class extension ends for AddPhoneNumberOptions.

@end

/// JoinMeetingLocator super type, locator for joining meetings
NS_SWIFT_NAME(JoinMeetingLocator)
@interface ACSJoinMeetingLocator : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

@end

/// JoinTeamsMeetingLocator super type, locator for joining meetings
NS_SWIFT_NAME(JoinTeamsMeetingLocator)
@interface ACSJoinTeamsMeetingLocator : ACSJoinMeetingLocator
-(nonnull instancetype)init NS_UNAVAILABLE;
@end

/// Options for joining a group call
NS_SWIFT_NAME(GroupCallLocator)
@interface ACSGroupCallLocator : ACSJoinMeetingLocator
-(nonnull instancetype)init:(NSUUID * _Nonnull )groupId NS_SWIFT_NAME( init(groupId:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/// The unique identifier for the group conversation
@property (retain, nonnull, readonly) NSUUID *groupId;

@end

/// Options for joining a Teams meeting using Coordinates locator
NS_SWIFT_NAME(TeamsMeetingCoordinatesLocator)
@interface ACSTeamsMeetingCoordinatesLocator : ACSJoinTeamsMeetingLocator
-(nonnull instancetype)initWithThreadId:(NSString * _Nonnull )threadId organizerId:(NSUUID * _Nonnull )organizerId tenantId:(NSUUID * _Nonnull )tenantId messageId:(NSString * _Nonnull )messageId NS_SWIFT_NAME( init(withThreadId:organizerId:tenantId:messageId:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/// The thread identifier of meeting
@property (retain, nonnull, readonly) NSString * threadId;

/// The organizer identifier of meeting
@property (retain, nonnull, readonly) NSUUID *organizerId;

/// The tenant identifier of meeting
@property (retain, nonnull, readonly) NSUUID *tenantId;

/// The message identifier of meeting
@property (retain, nonnull, readonly) NSString * messageId;

@end

/// Options for joining a Teams meeting using Meeting ID and Passcode
NS_SWIFT_NAME(TeamsMeetingIdLocator)
@interface ACSTeamsMeetingIdLocator : ACSJoinTeamsMeetingLocator
-(nonnull instancetype)initWithMeetingId:(NSString * _Nonnull )meetingId passcode:(NSString * _Nonnull )passcode NS_SWIFT_NAME( init(with:passcode:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/// The Meeting ID of the meeting
@property (retain, nonnull, readonly) NSString * meetingId;

/// The Passcode of the meeting
@property (retain, nonnull, readonly) NSString * passcode;

@end

/// Options for joining a Teams meeting using Link locator
NS_SWIFT_NAME(TeamsMeetingLinkLocator)
@interface ACSTeamsMeetingLinkLocator : ACSJoinTeamsMeetingLocator
-(nonnull instancetype)init:(NSString * _Nonnull )meetingLink NS_SWIFT_NAME( init(meetingLink:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/// The URI of the meeting
@property (retain, nonnull, readonly) NSString * meetingLink;

@end

/// Describes the Caller Information
NS_SWIFT_NAME(CallerInfo)
@interface ACSCallerInfo : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The display name of the caller
@property (retain, nonnull, readonly) NSString * displayName;

// Class extension begins for CallerInfo.
@property(nonatomic, readonly, nonnull) id<CommunicationIdentifier> identifier;
// Class extension ends for CallerInfo.

@end

/// Describes an incoming call
NS_SWIFT_NAME(PushNotificationInfo)
@interface ACSPushNotificationInfo : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The display name of the caller
@property (retain, nonnull, readonly) NSString * fromDisplayName;

/// Indicates whether the incoming call has a video or not
@property (readonly) BOOL incomingWithVideo;

/// Type of Push Notification Event
@property (readonly) ACSPushNotificationEventType eventType;

// Class extension begins for PushNotificationInfo.
@property (retain, readonly, nonnull) id<CommunicationIdentifier> from;
@property (retain, readonly, nonnull) id<CommunicationIdentifier> to;
@property (nonatomic, readonly, nonnull) NSUUID* callId;
+(ACSPushNotificationInfo* _Nonnull) fromDictionary:(NSDictionary* _Nonnull)payload;
// Class extension ends for PushNotificationInfo.

@end

/// Common Options for creating CallAgent
NS_SWIFT_NAME(CommonCallAgentOptions)
@interface ACSCommonCallAgentOptions : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Determines whether to disable the internal push mechanism for delivering the push payload of an incoming call. There are two ways that a push payload of an incoming call can be delivered to the callee: 1. By using Firebase Cloud Messaging (FCM) and registering the device token with the API `registerPushNotification` method on `CallAgent` or `TeamsCallAgent`. 2. When a `CallAgent` or `TeamsCallAgent` is created, the SDK also internally registers with our internal push service to receive the push payload. By default, the internal push is enabled. To exclusively use FCM and disable the internal push, set this parameter to `true`.
@property BOOL disableInternalPushForIncomingCall;

// Class extension begins for CommonCallAgentOptions.
@property(retain, nullable) ACSCallKitOptions* callKitOptions;
// Class extension ends for CommonCallAgentOptions.

@end

/// Options for creating CallAgent
NS_SWIFT_NAME(CallAgentOptions)
@interface ACSCallAgentOptions : ACSCommonCallAgentOptions
-(nonnull instancetype)init;

/// Specify the display name of the local participant for all new calls
@property (retain, nonnull) NSString * displayName;

/// Emergency call options when creating a call agent
@property (retain, nullable) ACSEmergencyCallOptions * emergencyCallOptions;

// Class extension begins for CallAgentOptions.
@property(retain, nullable) ACSCallKitOptions* callKitOptions;
/// Specify the time-to-live duration for push notifications
@property NSTimeInterval pushNotificationTtl;
// Class extension ends for CallAgentOptions.

@end

/// Options for emergency call of call agent
NS_SWIFT_NAME(EmergencyCallOptions)
@interface ACSEmergencyCallOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Specify the ISO 3166-1 alpha-2 emergency country code of the local participant for emergency calls
@property (retain, nonnull) NSString * countryCode;

@end

/// Common call agent base class to represent extended call agent classes created by the CallClient factory method createCallAgent It bears the responsibility of managing calls on behalf of the authenticated user
NS_SWIFT_NAME(CommonCallAgent)
@interface ACSCommonCallAgent : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Informs how video frames will be available for encoding or decoding.
@property (readonly) ACSCommunicationCallType type;

/// Releases all the resources held by Base CallAgent. Base CallAgent should be destroyed/nullified after dispose. Closes this resource. This gets projected to java.lang.AutoCloseable.close() in Java projection.
-(void)dispose;

/// Unregister all previously registered devices from receiving incoming calls push notifications.
-(void)unregisterPushNotificationWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( unregisterPushNotification(completionHandler:));

// Class extension begins for CommonCallAgent.
-(void)registerPushNotifications: (NSData* _Nonnull)deviceToken withCompletionHandler:(void (^ _Nonnull)(NSError* _Nullable error))completionHandler NS_SWIFT_NAME( registerPushNotifications(deviceToken:completionHandler:));
-(void)handlePushNotification:(ACSPushNotificationInfo* _Nonnull)notification withCompletionHandler:(void (^_Nonnull)(NSError* _Nullable error))completionHandler NS_SWIFT_NAME( handlePush(notification:completionHandler:));
// Class extension ends for CommonCallAgent.

@end

/// Call agent created by the CallClient factory method createCallAgent It bears the responsibility of managing calls on behalf of the authenticated user
NS_SWIFT_NAME(CallAgent)
@interface ACSCallAgent : ACSCommonCallAgent
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Returns the list of all active calls.
@property (copy, nonnull, readonly) NSArray<ACSCall *> * calls;

/**
 * The delegate that will handle events from the ACSCallAgent.
 */
@property(nonatomic, weak, nullable) id<ACSCallAgentDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSCallAgent.
 */
@property(nonatomic, strong, nonnull, readonly) ACSCallAgentEvents *events;

// Class extension begins for CallAgent.
-(void)startCall:(NSArray<id<CommunicationIdentifier>>* _Nonnull)participants
withCompletionHandler:(void (^ _Nonnull)(ACSCall* _Nullable call, NSError* _Nullable error))completionHandler NS_SWIFT_NAME( startCall(participants:completionHandler:));
-(void)startCallWithOptions:(NSArray<id<CommunicationIdentifier>>* _Nonnull)participants
                    options:(ACSStartCallOptions* _Nullable)options
      withCompletionHandler:(void (^ _Nonnull)(ACSCall* _Nullable call, NSError* _Nullable error))completionHandler NS_SWIFT_NAME( startCall(participants:options:completionHandler:));
-(void)joinWithMeetingLocator:(ACSJoinMeetingLocator* _Nonnull)meetingLocator
        withCompletionHandler:(void (^ _Nonnull)(ACSCall* _Nullable call, NSError* _Nullable error))completionHandler NS_SWIFT_NAME( join(with:completionHandler:));
-(void)joinWithMeetingLocatorWithOptions:(ACSJoinMeetingLocator* _Nonnull)meetingLocator
                         joinCallOptions:(ACSJoinCallOptions* _Nullable)joinCallOptions
                   withCompletionHandler:(void (^ _Nonnull)(ACSCall* _Nullable call, NSError* _Nullable error))completionHandler NS_SWIFT_NAME( join(with:joinCallOptions:completionHandler:));
// Class extension ends for CallAgent.

@end

/// Describes a common call
NS_SWIFT_NAME(CommonCall)
@interface ACSCommonCall : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Informs how video frames will be available for encoding or decoding.
@property (readonly) ACSCommunicationCallType type;

/// Get a list of remote participants in the current call. In case of calls with participants of hundred or more, only media active participants are present in this collection.
@property (copy, nonnull, readonly) NSArray<ACSRemoteParticipant *> * remoteParticipants;

/// Id of the call
@property (retain, nonnull, readonly) NSString * id;

/// Time the call was bootstrapped
@property (retain, nonnull, readonly) NSDate * startTime;

/// Current state of the call
@property (readonly) ACSCallState state;

/// Containing code/subcode indicating how a call has ended
@property (retain, nonnull, readonly) ACSCallEndReason * callEndReason;

/// Outgoing or Incoming depending on the Call Direction
@property (readonly) ACSCallDirection direction;

/// Whether the local microphone is muted or not.
@property (readonly) BOOL isOutgoingAudioMuted;

/// Whether the local speaker is muted or not.
@property (readonly) BOOL isIncomingAudioMuted;

/// The identity of the caller
@property (retain, nonnull, readonly) ACSCallerInfo * callerInfo;

/// Get the Teams meeting lobby.
@property (retain, nonnull, readonly) ACSCallLobby * callLobby;

/// Currently active incoming audio stream in the call
@property (retain, nonnull, readonly) ACSIncomingAudioStream * activeIncomingAudioStream;

/// Currently active outgoing audio stream in the call
@property (retain, nonnull, readonly) ACSOutgoingAudioStream * activeOutgoingAudioStream;

/// Participant role in the call
@property (readonly) ACSCallParticipantRole callParticipantRole;

/// Get a list of outgoing streams in the current call.
@property (copy, nonnull, readonly) NSArray<ACSOutgoingVideoStream *> * outgoingVideoStreams;

/// Total number of participants active in the current call
@property (readonly) int totalParticipantCount;

/// Get the current configurable outgoing audio filters
@property (retain, nonnull, readonly) ACSLiveOutgoingAudioFilters * liveOutgoingAudioFilters;

/// Get the server call ID
-(void)getServerCallIdWithCompletionHandler:(void (^ _Nonnull )(NSString * _Nullable  value, NSError * _Nullable error))completionHandler NS_SWIFT_NAME( getServerCallId(completionHandler:));

/// Start audio stream
-(void)startAudio:(ACSCallAudioStream * _Nonnull )stream withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( startAudio(stream:completionHandler:));

/// Stop audio stream
-(void)stopAudio:(ACSCallAudioStream * _Nonnull )stream withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( stopAudio(stream:completionHandler:));

/// Mute all remote participants audio
-(void)muteAllRemoteParticipantsWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( muteAllRemoteParticipants(completionHandler:));

/// Mute speaker.
-(void)muteIncomingAudioWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( muteIncomingAudio(completionHandler:));

/// UnMute speaker.
-(void)unmuteIncomingAudioWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( unmuteIncomingAudio(completionHandler:));

/// UnMute microphone.
-(void)unmuteOutgoingAudioWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( unmuteOutgoingAudio(completionHandler:));

/// Mute microphone.
-(void)muteOutgoingAudioWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( muteOutgoingAudio(completionHandler:));

/// Send DTMF tone
-(void)sendDtmf:(ACSDtmfTone)tone withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( sendDtmf(tone:completionHandler:));

/// Start sharing video stream to the call
-(void)startVideo:(ACSOutgoingVideoStream * _Nonnull )stream withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( startVideo(stream:completionHandler:));

/// Stop sharing video stream to the call
-(void)stopVideo:(ACSOutgoingVideoStream * _Nonnull )stream withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( stopVideo(stream:completionHandler:));

/// HangUp a call
-(void)hangUp:(ACSHangUpOptions * _Nullable )options withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( hangUp(options:completionHandler:));

/// Remove a participant from a call
-(void)removeParticipant:(ACSRemoteParticipant * _Nonnull )participant withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( remove(participant:completionHandler:));

/// Hold this call
-(void)holdWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( hold(completionHandler:));

/// Resume this call
-(void)resumeWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( resume(completionHandler:));

/// Set the constraints for outgoing and incoming video streams
-(void)setVideoConstraints:(ACSVideoConstraints * _Nonnull )constraints NS_SWIFT_NAME(set(videoConstraints:));

// Class extension begins for CommonCall.
-(id _Nonnull)feature: (Class _Nonnull)featureClass NS_REFINED_FOR_SWIFT;
// Class extension ends for CommonCall.

@end

/// Describes a call
NS_SWIFT_NAME(Call)
@interface ACSCall : ACSCommonCall
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Whether the local microphone is muted or not.
@property (readonly) BOOL isMuted DEPRECATED_MSG_ATTRIBUTE("Use isOutgoingAudioMuted instead.");

/// Get a list of local video streams in the current call.
@property (copy, nonnull, readonly) NSArray<ACSLocalVideoStream *> * localVideoStreams DEPRECATED_MSG_ATTRIBUTE("Use outgoingVideoStreams instead");

/**
 * The delegate that will handle events from the ACSCall.
 */
@property(nonatomic, weak, nullable) id<ACSCallDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSCall.
 */
@property(nonatomic, strong, nonnull, readonly) ACSCallEvents *events;

/// Mute local microphone.
-(void)muteWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( mute(completionHandler:)) DEPRECATED_MSG_ATTRIBUTE("Use muteOutgoingAudio instead.");

/// Unmute local microphone.
-(void)unmuteWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( unmute(completionHandler:)) DEPRECATED_MSG_ATTRIBUTE("Use unmuteOutgoingAudio instead.");

// Class extension begins for Call.
-(ACSRemoteParticipant* _Nullable)addParticipant:(id<CommunicationIdentifier> _Nonnull)participant withError:(NSError*_Nullable*_Nonnull) error __attribute__((swift_error(nonnull_error))) NS_SWIFT_NAME( add(participant:));
-(ACSRemoteParticipant* _Nullable)addParticipant:(PhoneNumberIdentifier* _Nonnull) participant options:(ACSAddPhoneNumberOptions* _Nullable)options withError:(NSError*_Nullable*_Nonnull) error __attribute__((swift_error(nonnull_error))) NS_SWIFT_NAME( add(participant:options:));
// Class extension ends for Call.

@end

/// Describes a PropertyChanged event data
NS_SWIFT_NAME(PropertyChangedEventArgs)
@interface ACSPropertyChangedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

@end

/// Describes a ParticipantsUpdated event data
NS_SWIFT_NAME(ParticipantsUpdatedEventArgs)
@interface ACSParticipantsUpdatedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// List of Participants that were added
@property (copy, nonnull, readonly) NSArray<ACSRemoteParticipant *> * addedParticipants;

/// List of Participants that were removed
@property (copy, nonnull, readonly) NSArray<ACSRemoteParticipant *> * removedParticipants;

@end

/// Describes a remote participant on a call
NS_SWIFT_NAME(RemoteParticipant)
@interface ACSRemoteParticipant : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Role of the remote participant
@property (readonly) ACSCallParticipantRole callParticipantRole;

/// Private Preview Only: Display Name of the remote participant
@property (retain, nonnull, readonly) NSString * displayName;

/// True if the remote participant is muted
@property (readonly) BOOL isMuted;

/// True if the remote participant is speaking. Only applicable to multi-party calls
@property (readonly) BOOL isSpeaking;

/// Reason why participant left the call, contains code/subcode.
@property (retain, nonnull, readonly) ACSCallEndReason * callEndReason;

/// Current state of the remote participant
@property (readonly) ACSParticipantState state;

/// Remote Video streams part of the current call
@property (copy, nonnull, readonly) NSArray<ACSRemoteVideoStream *> * videoStreams DEPRECATED_MSG_ATTRIBUTE("Use incomingVideoStreams instead");

/// Get a list of incoming streams in the current call.
@property (copy, nonnull, readonly) NSArray<ACSIncomingVideoStream *> * incomingVideoStreams;

/**
 * The delegate that will handle events from the ACSRemoteParticipant.
 */
@property(nonatomic, weak, nullable) id<ACSRemoteParticipantDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSRemoteParticipant.
 */
@property(nonatomic, strong, nonnull, readonly) ACSRemoteParticipantEvents *events;

/// Mute remote participant audio
-(void)muteWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( mute(completionHandler:));

// Class extension begins for RemoteParticipant.
@property(nonatomic, readonly, nonnull) id<CommunicationIdentifier> identifier;
// Class extension ends for RemoteParticipant.

@end

/// Describes the reason for a call to end
NS_SWIFT_NAME(CallEndReason)
@interface ACSCallEndReason : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The code
@property (readonly) int code;

/// The subcode
@property (readonly) int subcode;

@end

/// Video stream on remote participant
NS_SWIFT_NAME(RemoteVideoStream)
@interface ACSRemoteVideoStream : ACSIncomingVideoStream
-(nonnull instancetype)init NS_UNAVAILABLE;
/// True when remote video stream is available.
@property (readonly) BOOL isAvailable DEPRECATED_MSG_ATTRIBUTE("Use state property instead");

/**
 * The delegate that will handle events from the ACSRemoteVideoStream.
 */
@property(nonatomic, weak, nullable) id<ACSRemoteVideoStreamDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSRemoteVideoStream.
 */
@property(nonatomic, strong, nonnull, readonly) ACSRemoteVideoStreamEvents *events;

@end

/// Information about remote video streams added or removed
DEPRECATED_MSG_ATTRIBUTE("Use VideoStreamStateChangedEventArgs instead")
NS_SWIFT_NAME(RemoteVideoStreamsEventArgs)
@interface ACSRemoteVideoStreamsEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Remote video streams that have been added to the current call
@property (copy, nonnull, readonly) NSArray<ACSRemoteVideoStream *> * addedRemoteVideoStreams;

/// Remote video streams that are no longer part of the current call
@property (copy, nonnull, readonly) NSArray<ACSRemoteVideoStream *> * removedRemoteVideoStreams;

@end

/// Describes a LocalVideoStreamsUpdated event data
DEPRECATED_MSG_ATTRIBUTE("Use VideoStreamStateChangedEventArgs instead")
NS_SWIFT_NAME(LocalVideoStreamsUpdatedEventArgs)
@interface ACSLocalVideoStreamsUpdatedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// List of LocalVideoStream that were added
@property (copy, nonnull, readonly) NSArray<ACSLocalVideoStream *> * addedStreams;

/// List of LocalVideoStream that were removed
@property (copy, nonnull, readonly) NSArray<ACSLocalVideoStream *> * removedStreams;

@end

/// Describes a CallsUpdated event
NS_SWIFT_NAME(CallsUpdatedEventArgs)
@interface ACSCallsUpdatedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// New calls being tracked by the library
@property (copy, nonnull, readonly) NSArray<ACSCall *> * addedCalls;

/// Calls that are no longer tracked by the library
@property (copy, nonnull, readonly) NSArray<ACSCall *> * removedCalls;

@end

/// Describes a common incoming call
NS_SWIFT_NAME(CommonIncomingCall)
@interface ACSCommonIncomingCall : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Informs how video frames will be available for encoding or decoding.
@property (readonly) ACSCommunicationCallType type;

/// Describe the reason why a call has ended
@property (retain, nullable, readonly) ACSCallEndReason * callEndReason;

/// Information about the caller
@property (retain, nonnull, readonly) ACSCallerInfo * callerInfo;

/// Id of the call
@property (retain, nonnull, readonly) NSString * id;

/// Is incoming video enabled
@property (readonly) BOOL isVideoEnabled;

/// Reject this incoming call
-(void)rejectWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( reject(completionHandler:));

@end

/// Describes an incoming call
NS_SWIFT_NAME(IncomingCall)
@interface ACSIncomingCall : ACSCommonIncomingCall
-(nonnull instancetype)init NS_UNAVAILABLE;
/**
 * The delegate that will handle events from the ACSIncomingCall.
 */
@property(nonatomic, weak, nullable) id<ACSIncomingCallDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSIncomingCall.
 */
@property(nonatomic, strong, nonnull, readonly) ACSIncomingCallEvents *events;

/// Accept an incoming call
-(void)accept:(ACSAcceptCallOptions * _Nonnull )options withCompletionHandler:(void (^ _Nonnull )(ACSCall * _Nullable  value, NSError * _Nullable error))completionHandler NS_SWIFT_NAME( accept(options:completionHandler:));

@end

/// DebugInfo such as Blog file locations
NS_SWIFT_NAME(CallDebugInfo)
@interface ACSCallDebugInfo : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

// Class extension begins for CallDebugInfo.
@property (nonatomic, strong, readonly, nonnull) NSArray<NSURL *> *supportFiles;
// Class extension ends for CallDebugInfo.

@end

/// This is the main class representing the entrypoint for the Calling SDK.
NS_SWIFT_NAME(CallClient)
@interface ACSCallClient : NSObject
-(nonnull instancetype)init;

-(nonnull instancetype)init:(ACSCallClientOptions * _Nonnull )options NS_SWIFT_NAME( init(options:));

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Retrieves the DebugInfo class, which is an interface to Debugging/Support helpers such as retrieving files for support
@property (retain, nonnull, readonly) ACSCallDebugInfo * debugInfo;

/// Releases all the resources held by CallClient. CallClient should be destroyed/nullified after dispose.
-(void)dispose;

// Class extension begins for CallClient.
-(void)createCallAgent:(CommunicationTokenCredential* _Nonnull) userCredential
 withCompletionHandler:(void (^ _Nonnull)(ACSCallAgent* _Nullable clientAgent,
                                          NSError * _Nullable error))completionHandler NS_SWIFT_NAME( createCallAgent(userCredential:completionHandler:));

-(void)createCallAgentWithOptions:(CommunicationTokenCredential* _Nonnull) userCredential
                 callAgentOptions:(ACSCallAgentOptions* _Nullable) callAgentOptions
            withCompletionHandler:(void (^ _Nonnull)(ACSCallAgent* _Nullable clientAgent,
                                                     NSError* _Nullable error))completionHandler NS_SWIFT_NAME( createCallAgent(userCredential:options:completionHandler:));

 -(void)createTeamsCallAgent:(CommunicationTokenCredential* _Nonnull) userCredential
       withCompletionHandler:(void (^ _Nonnull)(ACSTeamsCallAgent* _Nullable clientAgent,
                                          NSError * _Nullable error))completionHandler NS_SWIFT_NAME( createTeamsCallAgent(userCredential:completionHandler:));

-(void)createTeamsCallAgentWithOptions:(CommunicationTokenCredential* _Nonnull) userCredential
      teamsCallAgentOptions:(ACSTeamsCallAgentOptions* _Nonnull)options
 withCompletionHandler:(void (^ _Nonnull)(ACSTeamsCallAgent* _Nullable clientAgent,
                                          NSError * _Nullable error))completionHandler NS_SWIFT_NAME( createTeamsCallAgent(userCredential:options:completionHandler:));

+(void)reportIncomingCall:(ACSPushNotificationInfo* _Nonnull)payload
                    callKitOptions:(ACSCallKitOptions* _Nonnull) callKitOptions
             withCompletionHandler:(void (^ _Nonnull)(NSError* _Nullable error))completionHandler NS_SWIFT_NAME( reportIncomingCall(with:callKitOptions:completionHandler:));

-(void)getDeviceManagerWithCompletionHandler:(void (^ _Nonnull)(ACSDeviceManager* _Nullable value,
                                                                NSError* _Nullable error))completionHandler NS_SWIFT_NAME( getDeviceManager(completionHandler:));

@property (retain, nonnull) CommunicationTokenCredential* communicationCredential;
// Class extension ends for CallClient.

@end

/// Options to be passed when creating a call client
NS_SWIFT_NAME(CallClientOptions)
@interface ACSCallClientOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Call Diagnostics options when creating a call client
@property (retain, nullable) ACSCallDiagnosticsOptions * diagnostics;

/// Call network options when creating a call client
@property (retain, nullable) ACSCallNetworkOptions * network;

@end

/// Options for diagnostics of call client
NS_SWIFT_NAME(CallDiagnosticsOptions)
@interface ACSCallDiagnosticsOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// An Identifier to group together multiple appIds into small bundle, invariant of version.
@property (retain, nonnull) NSString * appName;

/// The application version.
@property (retain, nonnull) NSString * appVersion;

/// Tags - additonal information.
@property (copy, nonnull) NSArray<NSString *> * tags;

@end

/// Network options for call client
NS_SWIFT_NAME(CallNetworkOptions)
@interface ACSCallNetworkOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Url to be used for proxy.
@property (retain, nonnull) NSString * proxyUrl;

@property (copy, nonnull) NSArray<ACSIceServer *> * iceServers;

@end

/// Describes an ICE Server
NS_SWIFT_NAME(IceServer)
@interface ACSIceServer : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Urls for the ICE servers
@property (copy, nonnull) NSArray<NSString *> * urls;

/// Realm for the ICE servers
@property (retain, nonnull) NSString * realm;

/// TCP port for the ICE servers
@property int tcpPort;

/// UDP port for the ICE servers
@property int udpPort;

/// Username for the ICE servers if credential infomation is needed for the server
@property (retain, nonnull) NSString * username;

/// Password for the ICE servers if credential infomation is needed for the server
@property (retain, nonnull) NSString * password;

@end

/// Options for creating TeamsCallAgent
NS_SWIFT_NAME(TeamsCallAgentOptions)
@interface ACSTeamsCallAgentOptions : ACSCommonCallAgentOptions
-(nonnull instancetype)init;

// Class extension begins for TeamsCallAgentOptions.
@property(retain, nullable) ACSCallKitOptions* callKitOptions;
// Class extension ends for TeamsCallAgentOptions.

@end

/// Teams Call agent created by the CallClient factory method createTeamsCallAgent. It bears the responsibility of managing calls on behalf of the authenticated user.
NS_SWIFT_NAME(TeamsCallAgent)
@interface ACSTeamsCallAgent : ACSCommonCallAgent
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Returns the list of all active calls.
@property (copy, nonnull, readonly) NSArray<ACSTeamsCall *> * calls;

/**
 * The delegate that will handle events from the ACSTeamsCallAgent.
 */
@property(nonatomic, weak, nullable) id<ACSTeamsCallAgentDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSTeamsCallAgent.
 */
@property(nonatomic, strong, nonnull, readonly) ACSTeamsCallAgentEvents *events;

// Class extension begins for TeamsCallAgent.
-(void)startCallWithParticipantWithOptions:(id<CommunicationIdentifier> _Nonnull)participant
                                   options:(ACSStartTeamsCallOptions* _Nonnull)options
                     withCompletionHandler:(void (^ _Nonnull)(ACSTeamsCall* _Nullable call, NSError* _Nullable error))completionHandler NS_SWIFT_NAME( startCall(participant:options:completionHandler:));

-(void)startCallWithParticipant:(id<CommunicationIdentifier> _Nonnull)participant
          withCompletionHandler:(void (^ _Nonnull)(ACSTeamsCall* _Nullable call, NSError* _Nullable error))completionHandler NS_SWIFT_NAME( startCall(participant:completionHandler:));

-(void)joinWithTeamsMeetingLocatorWithOptions:(ACSJoinTeamsMeetingLocator* _Nonnull)meetingLocator
                         joinTeamsCallOptions:(ACSJoinTeamsCallOptions* _Nonnull)joinCallOptions
                        withCompletionHandler:(void (^ _Nonnull)(ACSTeamsCall* _Nullable call, NSError* _Nullable error))completionHandler NS_SWIFT_NAME( join(with:joinTeamsCallOptions:completionHandler:));

-(void)joinWithTeamsMeetingLocator:(ACSJoinTeamsMeetingLocator* _Nonnull)meetingLocator
             withCompletionHandler:(void (^ _Nonnull)(ACSTeamsCall* _Nullable call, NSError* _Nullable error))completionHandler NS_SWIFT_NAME( join(with:completionHandler:));
// Class extension ends for TeamsCallAgent.

@end

/// Describes a teams call
NS_SWIFT_NAME(TeamsCall)
@interface ACSTeamsCall : ACSCommonCall
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Information about the teams call
@property (retain, nonnull, readonly) ACSTeamsCallInfo * callInfo;

/**
 * The delegate that will handle events from the ACSTeamsCall.
 */
@property(nonatomic, weak, nullable) id<ACSTeamsCallDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSTeamsCall.
 */
@property(nonatomic, strong, nonnull, readonly) ACSTeamsCallEvents *events;

@end

/// Describes a teamscall's information
NS_SWIFT_NAME(TeamsCallInfo)
@interface ACSTeamsCallInfo : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Get meeting thread ID
@property (retain, nonnull, readonly) NSString * meetingThreadId;

@end

/// Options to be passed when starting a teams call
NS_SWIFT_NAME(StartTeamsCallOptions)
@interface ACSStartTeamsCallOptions : ACSCallOptions
-(nonnull instancetype)init;

@end

/// Describes a TeamsCallsUpdated event
NS_SWIFT_NAME(TeamsCallsUpdatedEventArgs)
@interface ACSTeamsCallsUpdatedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// New calls being tracked by the library
@property (copy, nonnull, readonly) NSArray<ACSTeamsCall *> * addedCalls;

/// Calls that are no longer tracked by the library
@property (copy, nonnull, readonly) NSArray<ACSTeamsCall *> * removedCalls;

@end

/// Describes an teams incoming call
NS_SWIFT_NAME(TeamsIncomingCall)
@interface ACSTeamsIncomingCall : ACSCommonIncomingCall
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Information about the call
@property (retain, nonnull, readonly) ACSTeamsCallInfo * callInfo;

/**
 * The delegate that will handle events from the ACSTeamsIncomingCall.
 */
@property(nonatomic, weak, nullable) id<ACSTeamsIncomingCallDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSTeamsIncomingCall.
 */
@property(nonatomic, strong, nonnull, readonly) ACSTeamsIncomingCallEvents *events;

/// Accept a teams incoming call
-(void)accept:(ACSAcceptTeamsCallOptions * _Nonnull )options withCompletionHandler:(void (^ _Nonnull )(ACSTeamsCall * _Nullable  value, NSError * _Nullable error))completionHandler NS_SWIFT_NAME( accept(options:completionHandler:));

@end

/// Device manager
NS_SWIFT_NAME(DeviceManager)
@interface ACSDeviceManager : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Get the list of currently connected video devices
@property (copy, nonnull, readonly) NSArray<ACSVideoDeviceInfo *> * cameras;

/**
 * The delegate that will handle events from the ACSDeviceManager.
 */
@property(nonatomic, weak, nullable) id<ACSDeviceManagerDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSDeviceManager.
 */
@property(nonatomic, strong, nonnull, readonly) ACSDeviceManagerEvents *events;

@end

/// Describes a VideoDevicesUpdated event data
NS_SWIFT_NAME(VideoDevicesUpdatedEventArgs)
@interface ACSVideoDevicesUpdatedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Video devicesRemote video streams that have been added to the current call
@property (copy, nonnull, readonly) NSArray<ACSVideoDeviceInfo *> * addedVideoDevices;

/// Remote video streams that have been added to the current call
@property (copy, nonnull, readonly) NSArray<ACSVideoDeviceInfo *> * removedVideoDevices;

@end

/// Property bag class for hanging up a call
NS_SWIFT_NAME(HangUpOptions)
@interface ACSHangUpOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Use to determine whether the current call should be terminated for all participant on the call or not
@property BOOL forEveryone;

@end

/// Describes a Teams Meeting Lobby's information
NS_SWIFT_NAME(CallLobby)
@interface ACSCallLobby : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Get a list of remote participants in the current Teams meeting lobby.
@property (copy, nonnull, readonly) NSArray<ACSRemoteParticipant *> * participants;

/**
 * The delegate that will handle events from the ACSCallLobby.
 */
@property(nonatomic, weak, nullable) id<ACSCallLobbyDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSCallLobby.
 */
@property(nonatomic, strong, nonnull, readonly) ACSCallLobbyEvents *events;

/// Admit all participants from the Teams meeting lobby
-(void)admitAllWithCompletionHandler:(void (^ _Nonnull )(ACSAdmitAllParticipantsResult * _Nullable  value, NSError * _Nullable error))completionHandler NS_SWIFT_NAME( admitAll(completionHandler:));

// Class extension begins for CallLobby.
-(void)admit:(NSArray<id<CommunicationIdentifier>>* _Nonnull)identifiers
withCompletionHandler:(void (^ _Nonnull)(ACSAdmitParticipantsResult* _Nullable result, NSError* _Nullable error))completionHandler NS_SWIFT_NAME( admit(identifiers:completionHandler:));
-(void)reject:(id<CommunicationIdentifier> _Nonnull)identifier
withCompletionHandler:(void (^ _Nonnull)(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( reject(identifier:completionHandler:));
// Class extension ends for CallLobby.

@end

/// Result for Lobby admit operation
NS_SWIFT_NAME(AdmitParticipantsResult)
@interface ACSAdmitParticipantsResult : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The number of successfully admitted participants
@property (readonly) int successCount;

/// Get a list of remote participants that are failed during admit operation
@property (copy, nonnull, readonly) NSArray<ACSRemoteParticipant *> * failedParticipants;

@end

/// Result for Lobby admitAll operation
NS_SWIFT_NAME(AdmitAllParticipantsResult)
@interface ACSAdmitAllParticipantsResult : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The number of successfully admitted participants
@property (readonly) int successCount;

/// The number of participants that are failed during admitAll operation
@property (readonly) int failureCount;

@end

/// CallFeature super type, features extensions for call.
NS_SWIFT_NAME(CallFeature)
@interface ACSCallFeature : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Name of the extended CallFeature.
@property (retain, nonnull, readonly) NSString * name;

@end

/// Represents a real-time text message entry.
NS_SWIFT_NAME(RealTimeTextInfo)
@interface ACSRealTimeTextInfo : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Gets information about the sender of the real-time text message.
@property (retain, nonnull, readonly) ACSCallerInfo * sender;

/// Gets the sequence identifier of the real-time text message.
@property (readonly) int sequenceId;

/// Gets the text content of the real-time text message.
@property (retain, nonnull, readonly) NSString * text;

/// Gets the result type indicating whether the message is partial or final. Final messages are no longer editable.
@property (readonly) ACSRealTimeTextResultType resultType;

/// Gets the local timestamp when the real-time text message was received.
@property (retain, nonnull, readonly) NSDate * receivedTime;

/// Gets the local timestamp when the real-time text message was last updated.
@property (retain, nonnull, readonly) NSDate * updatedTime;

/// Determines if the real-time text message is locally produced (I.e. from the user)
@property (readonly) BOOL isLocal;

@end

/// Provides functionality to send and receive real-time text messages during a call.
NS_SWIFT_NAME(RealTimeTextCallFeature)
@interface ACSRealTimeTextCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/**
 * The delegate that will handle events from the ACSRealTimeTextCallFeature.
 */
@property(nonatomic, weak, nullable) id<ACSRealTimeTextCallFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSRealTimeTextCallFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSRealTimeTextCallFeatureEvents *events;

/// Sends a real-time text message.
-(void)sendStringText:(NSString * _Nonnull )text withError: (NSError*_Nullable*_Nullable) error __attribute__((swift_error(nonnull_error))) NS_SWIFT_NAME( send(text:));

/// Sends a real-time text message with an option to finalize it.
-(void)sendStringTextBooleanFinalizedWithText:(NSString * _Nonnull )text finalized:(BOOL)finalized withError: (NSError*_Nullable*_Nullable) error __attribute__((swift_error(nonnull_error))) NS_SWIFT_NAME( send(text:finalized:));

@end

/// Provides data for the RealTimeTextCallFeature.InfoReceived and Azure.Communication.Calling.RealTimeTextCallFeature.OnInfoReceived events.
NS_SWIFT_NAME(RealTimeTextInfoReceivedEventArgs)
@interface ACSRealTimeTextInfoReceivedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Gets the real-time text info associated with the event.
@property (retain, nonnull, readonly) ACSRealTimeTextInfo * info;

@end

/// Call Feature for managing call recording
NS_SWIFT_NAME(RecordingCallFeature)
@interface ACSRecordingCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Indicates if recording is active in current call
@property (readonly) BOOL isRecordingActive;

/**
 * The delegate that will handle events from the ACSRecordingCallFeature.
 */
@property(nonatomic, weak, nullable) id<ACSRecordingCallFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSRecordingCallFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSRecordingCallFeatureEvents *events;

@end

/// Call Feature for managing call transcription
NS_SWIFT_NAME(TranscriptionCallFeature)
@interface ACSTranscriptionCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Indicates if transcription is active in current call
@property (readonly) BOOL isTranscriptionActive;

/**
 * The delegate that will handle events from the ACSTranscriptionCallFeature.
 */
@property(nonatomic, weak, nullable) id<ACSTranscriptionCallFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSTranscriptionCallFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSTranscriptionCallFeatureEvents *events;

@end

/// Options to request language before starting captions
NS_SWIFT_NAME(StartCaptionsOptions)
@interface ACSStartCaptionsOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// language in which the speaker is speaking.
@property (retain, nonnull) NSString * spokenLanguage;

@end

/// Describes an CaptionsReceived event for when new captions data comes in
NS_SWIFT_NAME(TeamsCaptionsReceivedEventArgs)
@interface ACSTeamsCaptionsReceivedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Information about the speaker.
@property (retain, nonnull, readonly) ACSCallerInfo * speaker;

/// The original text with no transcribed.
@property (retain, nonnull, readonly) NSString * spokenText;

/// language identifier for the speaker.
@property (retain, nonnull, readonly) NSString * spokenLanguage;

/// The transcribed text.
@property (retain, nonnull, readonly) NSString * captionText;

/// language identifier for the captions text.
@property (retain, nonnull, readonly) NSString * captionLanguage;

/// CaptionsResultType is Partial if text contains partially spoken sentence. It is set to Final once the sentence has been completely transcribed.
@property (readonly) ACSCaptionsResultType resultType;

/// Timestamp denoting the time when the corresponding speech was made. timestamp is received from call recorder in C# ticks since 1/1/1900 (NTP Epoch) timestamp is converted to ms since 1/1/1970 (UNIX Epoch) 10000 C# ticks / 1 ms
@property (retain, nonnull, readonly) NSDate * timestamp;

@end

/// Describes an CaptionsReceived event for when new captions data comes in
NS_SWIFT_NAME(CommunicationCaptionsReceivedEventArgs)
@interface ACSCommunicationCaptionsReceivedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Information about the speaker in this caption.
@property (retain, nonnull, readonly) ACSCallerInfo * speaker;

/// CaptionsResultType is Partial if text contains partially spoken sentence. It is set to Final once the sentence has been completely transcribed.
@property (readonly) ACSCaptionsResultType resultType;

/// Timestamp denoting the time when the corresponding speech was made. timestamp is received from call recorder in C# ticks since 1/1/1900 (NTP Epoch) timestamp is converted to ms since 1/1/1970 (UNIX Epoch) 10000 C# ticks / 1 ms
@property (retain, nonnull, readonly) NSDate * timestamp;

/// The transcribed text.
@property (retain, nonnull, readonly) NSString * spokenText;

/// language identifier for the speaker. Ex: en-US.
@property (retain, nonnull, readonly) NSString * spokenLanguage;

@end

/// Call captions for managing common captions functionality.
NS_SWIFT_NAME(CallCaptions)
@interface ACSCallCaptions : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// List of supported spoken languages for Captions.
@property (copy, nonnull, readonly) NSArray<NSString *> * supportedSpokenLanguages;

/// Indicates if captions is enabled in current call.
@property (readonly) BOOL isEnabled;

/// Get captions type.
@property (readonly) ACSCaptionsType type;

/// Get active spoken language.
@property (retain, nonnull, readonly) NSString * activeSpokenLanguage;

/// Starts the captions.
-(void)startCaptions:(ACSStartCaptionsOptions * _Nullable )options withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( startCaptions(options:completionHandler:));

/// Stop the captions.
-(void)stopCaptionsWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( stopCaptions(completionHandler:));

/// Set the spoken language.
-(void)setSpokenLanguage:(NSString * _Nonnull )language withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( set(spokenLanguage:completionHandler:));

@end

/// Captions for managing captions for a group call.
NS_SWIFT_NAME(CommunicationCaptions)
@interface ACSCommunicationCaptions : ACSCallCaptions
-(nonnull instancetype)init NS_UNAVAILABLE;
/**
 * The delegate that will handle events from the ACSCommunicationCaptions.
 */
@property(nonatomic, weak, nullable) id<ACSCommunicationCaptionsDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSCommunicationCaptions.
 */
@property(nonatomic, strong, nonnull, readonly) ACSCommunicationCaptionsEvents *events;

@end

/// Teams captions for managing captions for a Teams Interop call.
NS_SWIFT_NAME(TeamsCaptions)
@interface ACSTeamsCaptions : ACSCallCaptions
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Get active caption language.
@property (retain, nonnull, readonly) NSString * activeCaptionLanguage;

/// List of supported captions languages for Captions.
@property (copy, nonnull, readonly) NSArray<NSString *> * supportedCaptionLanguages;

/**
 * The delegate that will handle events from the ACSTeamsCaptions.
 */
@property(nonatomic, weak, nullable) id<ACSTeamsCaptionsDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSTeamsCaptions.
 */
@property(nonatomic, strong, nonnull, readonly) ACSTeamsCaptionsEvents *events;

/// Set the captions language.
-(void)setCaptionLanguage:(NSString * _Nonnull )language withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( set(captionLanguage:completionHandler:));

@end

/// Call Feature for managing captions for a call.
NS_SWIFT_NAME(CaptionsCallFeature)
@interface ACSCaptionsCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/**
 * The delegate that will handle events from the ACSCaptionsCallFeature.
 */
@property(nonatomic, weak, nullable) id<ACSCaptionsCallFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSCaptionsCallFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSCaptionsCallFeatureEvents *events;

/// Get captions for a connected call.
-(void)getCaptionsWithCompletionHandler:(void (^ _Nonnull )(ACSCallCaptions * _Nullable  value, NSError * _Nullable error))completionHandler NS_SWIFT_NAME( getCaptions(completionHandler:));

@end

/// Call Feature for managing the dominant speakers of a call
NS_SWIFT_NAME(DominantSpeakersCallFeature)
@interface ACSDominantSpeakersCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Information about the dominant speakers of the call
@property (retain, nonnull, readonly) ACSDominantSpeakersInfo * dominantSpeakersInfo;

/**
 * The delegate that will handle events from the ACSDominantSpeakersCallFeature.
 */
@property(nonatomic, weak, nullable) id<ACSDominantSpeakersCallFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSDominantSpeakersCallFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSDominantSpeakersCallFeatureEvents *events;

@end

/// Information about the dominant speakers of a call
NS_SWIFT_NAME(DominantSpeakersInfo)
@interface ACSDominantSpeakersInfo : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Last updated time of the current dominant speakers list
@property (retain, nonnull, readonly) NSDate * lastUpdatedAt NS_SWIFT_NAME(lastUpdated);

// Class extension begins for DominantSpeakersInfo.
/// List of the current dominant speakers
@property(nonatomic, readonly, nonnull) NSArray<id<CommunicationIdentifier>> * speakers;
// Class extension ends for DominantSpeakersInfo.

@end

/// Call Feature for managing raise hand states for participants on the call.
NS_SWIFT_NAME(RaiseHandCallFeature)
@interface ACSRaiseHandCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Get all active raised hands. Sorted by order of raise hand events.
@property (copy, nonnull, readonly) NSArray<ACSRaisedHand *> * raisedHands;

/**
 * The delegate that will handle events from the ACSRaiseHandCallFeature.
 */
@property(nonatomic, weak, nullable) id<ACSRaiseHandCallFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSRaiseHandCallFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSRaiseHandCallFeatureEvents *events;

/// Send request to raise hand for local user.
-(void)raiseHandWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( raiseHand(completionHandler:));

/// Send request to lower hand for local user.
-(void)lowerHandWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( lowerHand(completionHandler:));

/// Send request to lower raised hands for every user on the call.
-(void)lowerAllHandsWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( lowerAllHands(completionHandler:));

// Class extension begins for RaiseHandCallFeature.
-(void)lowerHands:(NSArray<id<CommunicationIdentifier>>* _Nonnull)participants
withCompletionHandler:(void (^ _Nonnull)(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( lowerHands(participants:completionHandler:));
// Class extension ends for RaiseHandCallFeature.

@end

/// Raise hand details.
NS_SWIFT_NAME(RaisedHand)
@interface ACSRaisedHand : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Order of raise hand events.
@property (readonly) int order;

// Class extension begins for RaisedHand.
@property(nonatomic, readonly, nonnull) id<CommunicationIdentifier> identifier;
// Class extension ends for RaisedHand.

@end

/// Raised hand event information.
NS_SWIFT_NAME(RaisedHandChangedEventArgs)
@interface ACSRaisedHandChangedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

// Class extension begins for RaisedHandChangedEventArgs.
@property(nonatomic, readonly, nonnull) id<CommunicationIdentifier> identifier;
// Class extension ends for RaisedHandChangedEventArgs.

@end

/// Lowered hand event information.
NS_SWIFT_NAME(LoweredHandChangedEventArgs)
@interface ACSLoweredHandChangedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

// Class extension begins for LoweredHandChangedEventArgs.
@property(nonatomic, readonly, nonnull) id<CommunicationIdentifier> identifier;
// Class extension ends for LoweredHandChangedEventArgs.

@end

/// Call Feature for managing spotlight states in a call.
NS_SWIFT_NAME(SpotlightCallFeature)
@interface ACSSpotlightCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Send request to return the maximum number of participants that can be spotlighted
@property (readonly) int maxSpotlightedParticipants;

/// Send request to get a list of all spotlighted participants
@property (copy, nonnull, readonly) NSArray<ACSSpotlightedParticipant *> * spotlightedParticipants;

/**
 * The delegate that will handle events from the ACSSpotlightCallFeature.
 */
@property(nonatomic, weak, nullable) id<ACSSpotlightCallFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSSpotlightCallFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSSpotlightCallFeatureEvents *events;

/// Send request to stop spotlight for all spotlighted participants
-(void)cancelAllSpotlightsWithCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( cancelAllSpotlights(completionHandler:));

// Class extension begins for SpotlightCallFeature.
-(void)spotlight:(NSArray<id<CommunicationIdentifier>>* _Nonnull)identifiers
withCompletionHandler:(void (^ _Nonnull)(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( spotlight(identifiers:completionHandler:));
-(void)cancelSpotlights:(NSArray<id<CommunicationIdentifier>>* _Nonnull)identifiers
withCompletionHandler:(void (^ _Nonnull)(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( cancelSpotlights(identifiers:completionHandler:));
// Class extension ends for SpotlightCallFeature.

@end

/// Spotlighted participant details
NS_SWIFT_NAME(SpotlightedParticipant)
@interface ACSSpotlightedParticipant : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

// Class extension begins for SpotlightedParticipant.
@property(nonatomic, readonly, nonnull) id<CommunicationIdentifier> identifier;
// Class extension ends for SpotlightedParticipant.

@end

/// Spotlight event information.
NS_SWIFT_NAME(SpotlightChangedEventArgs)
@interface ACSSpotlightChangedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// List of spotlighted participants identifiers that were added
@property (copy, nonnull, readonly) NSArray<ACSSpotlightedParticipant *> * added;

/// List of Participants identifiers whose spotlight state were removed
@property (copy, nonnull, readonly) NSArray<ACSSpotlightedParticipant *> * removed;

@end

/// Options to be passed when rendering a Video
NS_SWIFT_NAME(CreateViewOptions)
@interface ACSCreateViewOptions : NSObject
-(nonnull instancetype)init:(ACSScalingMode)scalingMode NS_SWIFT_NAME( init(scalingMode:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Scaling mode for rendering the video.
@property ACSScalingMode scalingMode;

@end

/// Describes details of the video frame content that the application is capable of generating. ACS Calling SDK will dynamically select the VideoStreamFormat best matching with network conditions at runtime.
NS_SWIFT_NAME(VideoStreamFormat)
@interface ACSVideoStreamFormat : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Total width-wise count of pixels of the video frame. It must be greater or equal to 240 and less or equal to 1920. Values greater than 1280 and aspect ratios other than 16:9 or 4:3 might be adjusted by the SDK consuming extra resources.
@property int width;

/// Total height-wise count of pixels of the video frame. It must be greater or equal to 180 and less or equal to 1080. Values greater than 720 and aspect ratios other than 16:9 or 4:3 might be adjusted by the SDK consuming extra resources.
@property int height;

/// Width and height to be used from a known video resolution standard
@property ACSVideoStreamResolution resolution;

/// Informs how the content of the video frame is encoded.
@property ACSVideoStreamPixelFormat pixelFormat;

/// Informs how many frames per second the virtual video device will be sending to remote participants. It must be greater or equal to 1 and lower or equal to 30. The following values are preferable 7.5, 15 or 30.
@property float framesPerSecond;

/// Informs the stride in bytes for the first plane of the video frame content when RawVideoFrameType is VideoSoftware. It must be greater or equal to the count of bytes required for the first plane of the selected VideoStreamPixelFormat.
@property int stride1;

/// For VideoFormats with more than one plane, informs the stride in bytes for the second plane of the video frame content when RawVideoFrameType is VideoSoftware. It must be greater or equal to the count of bytes required for the second plane of the selected VideoStreamPixelFormat.
@property int stride2;

/// For VideoFormats with more than two planes, informs the stride in bytes for the third plane of the video frame content when RawVideoFrameType is VideoSoftware. It must be greater or equal to the count of bytes required for the third plane of the selected VideoStreamPixelFormat.
@property int stride3;

@end

/// Contains information about changes to the flow control of a video or audio virtual device.
NS_SWIFT_NAME(VideoStreamFormatChangedEventArgs)
@interface ACSVideoStreamFormatChangedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// New VideoStreamFormat
@property (retain, nonnull, readonly) ACSVideoStreamFormat * format;

@end

/// Information about the video frame
NS_SWIFT_NAME(RawVideoFrame)
@interface ACSRawVideoFrame : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Informs how video frames will be available for encoding or decoding.
@property (readonly) ACSRawVideoFrameType type;

/// Information about the 4CC used on this video frame
@property (retain, nonnull) ACSVideoStreamFormat * streamFormat;

/// time when the video frame was created
@property int64_t timestampInTicks;

/// Dispose heavy resources
-(void)dispose;

@end

/// Hold's video frame data as a buffer
NS_SWIFT_NAME(RawVideoFrameBuffer)
@interface ACSRawVideoFrameBuffer : ACSRawVideoFrame
-(nonnull instancetype)init;

// Class extension begins for RawVideoFrameBuffer.
@property CVPixelBufferRef _Nonnull buffer;
// Class extension ends for RawVideoFrameBuffer.

@end

/// Contains information about the newest video frame
NS_SWIFT_NAME(RawVideoFrameReceivedEventArgs)
@interface ACSRawVideoFrameReceivedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Information about the new video frame
@property (retain, nonnull, readonly) ACSRawVideoFrame * frame;

/// VideoStreamId that own this video frame
@property (readonly) int videoStreamId;

@end

/// Defines the options required for creating a virtual video device. Changes to RawOutgoingVideoStreamOptions do not affect previously created virtual video devices.
NS_SWIFT_NAME(RawOutgoingVideoStreamOptions)
@interface ACSRawOutgoingVideoStreamOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Returns an array of the video formats supported by the virtual video stream
@property (copy, nonnull) NSArray<ACSVideoStreamFormat *> * formats;

@end

/// Contains information about common properties between different types of outgoing virtual video streams
NS_SWIFT_NAME(RawOutgoingVideoStream)
@interface ACSRawOutgoingVideoStream : ACSOutgoingVideoStream
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Get VideoStreamFormat used to send VideoFrames
@property (retain, nonnull, readonly) ACSVideoStreamFormat * format;

/// Timestamp with the time of the current outgoing stream
@property (readonly) int64_t timestampInTicks;

/// Send Raw Video Frame
-(void)sendRawVideoFrame:(ACSRawVideoFrame * _Nonnull )rawVideoFrame withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( send(frame:completionHandler:));

@end

/// Screen Share stream information
NS_SWIFT_NAME(ScreenShareOutgoingVideoStream)
@interface ACSScreenShareOutgoingVideoStream : ACSRawOutgoingVideoStream
-(nonnull instancetype)init:(ACSRawOutgoingVideoStreamOptions * _Nonnull )videoStreamOptions NS_SWIFT_NAME( init(videoStreamOptions:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/**
 * The delegate that will handle events from the ACSScreenShareOutgoingVideoStream.
 */
@property(nonatomic, weak, nullable) id<ACSScreenShareOutgoingVideoStreamDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSScreenShareOutgoingVideoStream.
 */
@property(nonatomic, strong, nonnull, readonly) ACSScreenShareOutgoingVideoStreamEvents *events;

@end

/// Virtual stream information
NS_SWIFT_NAME(VirtualOutgoingVideoStream)
@interface ACSVirtualOutgoingVideoStream : ACSRawOutgoingVideoStream
-(nonnull instancetype)init:(ACSRawOutgoingVideoStreamOptions * _Nonnull )videoStreamOptions NS_SWIFT_NAME( init(videoStreamOptions:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/**
 * The delegate that will handle events from the ACSVirtualOutgoingVideoStream.
 */
@property(nonatomic, weak, nullable) id<ACSVirtualOutgoingVideoStreamDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSVirtualOutgoingVideoStream.
 */
@property(nonatomic, strong, nonnull, readonly) ACSVirtualOutgoingVideoStreamEvents *events;

@end

/// Representation of a remote CallVideoStream using raw data (bytes)
NS_SWIFT_NAME(RawIncomingVideoStream)
@interface ACSRawIncomingVideoStream : ACSIncomingVideoStream
-(nonnull instancetype)init NS_UNAVAILABLE;
/**
 * The delegate that will handle events from the ACSRawIncomingVideoStream.
 */
@property(nonatomic, weak, nullable) id<ACSRawIncomingVideoStreamDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSRawIncomingVideoStream.
 */
@property(nonatomic, strong, nonnull, readonly) ACSRawIncomingVideoStreamEvents *events;

/// Start receiving frames
-(void)start;

/// Stop receiving frames
-(void)stop;

@end

/// Describes an IncomingMixedAudio event for when new audio data comes in
NS_SWIFT_NAME(IncomingMixedAudioEventArgs)
@interface ACSIncomingMixedAudioEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Properties of the Raw Incoming Audio Buffer
@property (retain, nonnull, readonly) ACSRawIncomingAudioStreamProperties * streamProperties;

/// Audio Buffer that was received
@property (retain, nonnull, readonly) ACSRawAudioBuffer * audioBuffer;

@end

/// Base Class for All Raw Audio Properties needed to describe RawAudioStreams
NS_SWIFT_NAME(RawAudioStreamProperties)
@interface ACSRawAudioStreamProperties : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Sample Rate of Audio Stream
@property ACSAudioStreamSampleRate sampleRate;

/// Channel Mode of Audio Stream
@property ACSAudioStreamChannelMode channelMode;

/// Audio Format of Audio Stream in the Call
@property ACSAudioStreamFormat format;

@end

/// Audio Properties For RawIncomingAudioStreams
NS_SWIFT_NAME(RawIncomingAudioStreamProperties)
@interface ACSRawIncomingAudioStreamProperties : ACSRawAudioStreamProperties
-(nonnull instancetype)init;

@end

/// An entity that represents an audio buffer that provides a wrapper native buffers and additional information
NS_SWIFT_NAME(RawAudioBuffer)
@interface ACSRawAudioBuffer : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Timestamp of Buffer to set/get depending on outgoing/incoming
@property int64_t timestampInTicks;

/// Dispose method for cleaning up resources
-(void)dispose;

// Class extension begins for RawAudioBuffer.
@property (retain, nullable) AVAudioBuffer * buffer;
// Class extension ends for RawAudioBuffer.

@end

/// Describes an AudioStreamStateChanged event when audio stream state has updated for an CallAudioStream
NS_SWIFT_NAME(AudioStreamStateChangedEventArgs)
@interface ACSAudioStreamStateChangedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Audio Stream that has its state changed
@property (retain, nonnull, readonly) ACSCallAudioStream * stream;

/// Contains message about Audio Stream
@property (retain, nonnull, readonly) NSString * message;

@end

/// Audio Properties For RawOutgoingAudioStreams
NS_SWIFT_NAME(RawOutgoingAudioStreamProperties)
@interface ACSRawOutgoingAudioStreamProperties : ACSRawAudioStreamProperties
-(nonnull instancetype)init;

/// Specifies the size of sample data block expected to be sent through a given outgoing audio stream.
@property ACSAudioStreamBufferDuration bufferDuration;

@end

/// Base Class for All Raw Audio Options needed to be defined for RawAudioStreams
NS_SWIFT_NAME(RawAudioStreamOptions)
@interface ACSRawAudioStreamOptions : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

@end

/// Options required for initializing a RawOutgoingAudioStream
NS_SWIFT_NAME(RawOutgoingAudioStreamOptions)
@interface ACSRawOutgoingAudioStreamOptions : ACSRawAudioStreamOptions
-(nonnull instancetype)init;

/// Raw Outgoing Audio Properties needed for initializing a RawOutgoingAudioStream
@property (retain, nonnull) ACSRawOutgoingAudioStreamProperties * properties;

@end

/// Options required for initializing a RawIncomingAudioStream
NS_SWIFT_NAME(RawIncomingAudioStreamOptions)
@interface ACSRawIncomingAudioStreamOptions : ACSRawAudioStreamOptions
-(nonnull instancetype)init;

/// Raw Incoming Audio Properties needed for initializing a RawIncomingAudioStream
@property (retain, nonnull) ACSRawIncomingAudioStreamProperties * properties;

@end

/// Local (Physical device) Audio Stream
NS_SWIFT_NAME(LocalOutgoingAudioStream)
@interface ACSLocalOutgoingAudioStream : ACSOutgoingAudioStream
-(nonnull instancetype)init;

/**
 * The delegate that will handle events from the ACSLocalOutgoingAudioStream.
 */
@property(nonatomic, weak, nullable) id<ACSLocalOutgoingAudioStreamDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSLocalOutgoingAudioStream.
 */
@property(nonatomic, strong, nonnull, readonly) ACSLocalOutgoingAudioStreamEvents *events;

@end

/// An audio stream that utilizes physical device for playback
NS_SWIFT_NAME(RemoteIncomingAudioStream)
@interface ACSRemoteIncomingAudioStream : ACSIncomingAudioStream
-(nonnull instancetype)init;

/**
 * The delegate that will handle events from the ACSRemoteIncomingAudioStream.
 */
@property(nonatomic, weak, nullable) id<ACSRemoteIncomingAudioStreamDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSRemoteIncomingAudioStream.
 */
@property(nonatomic, strong, nonnull, readonly) ACSRemoteIncomingAudioStreamEvents *events;

@end

/// An audio stream that utilizes a virtual device for receiving audio
NS_SWIFT_NAME(RawIncomingAudioStream)
@interface ACSRawIncomingAudioStream : ACSIncomingAudioStream
-(nonnull instancetype)init:(ACSRawIncomingAudioStreamOptions * _Nonnull )options NS_SWIFT_NAME( init(options:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/**
 * The delegate that will handle events from the ACSRawIncomingAudioStream.
 */
@property(nonatomic, weak, nullable) id<ACSRawIncomingAudioStreamDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSRawIncomingAudioStream.
 */
@property(nonatomic, strong, nonnull, readonly) ACSRawIncomingAudioStreamEvents *events;

@end

/// An audio stream that utilizes a virtual device for sending audio
NS_SWIFT_NAME(RawOutgoingAudioStream)
@interface ACSRawOutgoingAudioStream : ACSOutgoingAudioStream
-(nonnull instancetype)init:(ACSRawOutgoingAudioStreamOptions * _Nonnull )options NS_SWIFT_NAME( init(options:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/// Expected buffer size of Audio Buffer
@property (readonly) int64_t expectedBufferSizeInBytes;

/// RawOutgoingAudioStreamProperties that this CallAudioStream is set to
@property (retain, nonnull, readonly) ACSRawOutgoingAudioStreamProperties * properties;

/**
 * The delegate that will handle events from the ACSRawOutgoingAudioStream.
 */
@property(nonatomic, weak, nullable) id<ACSRawOutgoingAudioStreamDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSRawOutgoingAudioStream.
 */
@property(nonatomic, strong, nonnull, readonly) ACSRawOutgoingAudioStreamEvents *events;

/// Method for sending audio buffer. The buffer should match the format, sample rate and channel mode specified in the stream properties. For data per block property, we recommend sending data in the specified size, but additionally, we support sending larger buffers limited to 100ms as long as it can be evenly divided by the specified data per block.
-(void)sendRawAudioBuffer:(ACSRawAudioBuffer * _Nonnull )rawAudioBuffer withCompletionHandler:(void (^ _Nonnull )(NSError * _Nullable error))completionHandler NS_SWIFT_NAME( send(buffer:completionHandler:));

@end

/// Options for joining a call using Room ID locator
NS_SWIFT_NAME(RoomCallLocator)
@interface ACSRoomCallLocator : ACSJoinMeetingLocator
-(nonnull instancetype)init:(NSString * _Nonnull )roomId NS_SWIFT_NAME( init(roomId:));

-(nonnull instancetype)init NS_UNAVAILABLE;
/// The Room identifier of the meeting
@property (retain, nonnull, readonly) NSString * roomId;

@end

/// Video Effect base type.
NS_SWIFT_NAME(VideoEffect)
@interface ACSVideoEffect : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Name of the video effect.
@property (retain, nonnull, readonly) NSString * name;

@end

/// Video Effect for Background Blur
NS_SWIFT_NAME(BackgroundBlurEffect)
@interface ACSBackgroundBlurEffect : ACSVideoEffect
-(nonnull instancetype)init;

@end

/// Video Effect for Background Replacement
NS_SWIFT_NAME(BackgroundReplacementEffect)
@interface ACSBackgroundReplacementEffect : ACSVideoEffect
-(nonnull instancetype)init;

/// Image Buffer to Fill for Background Replacement
@property (retain, nonnull) NSData * buffer;

@end

/// LocalVideoStream Feature for managing video effects.
NS_SWIFT_NAME(LocalVideoEffectsFeature)
@interface ACSLocalVideoEffectsFeature : ACSLocalVideoStreamFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/**
 * The delegate that will handle events from the ACSLocalVideoEffectsFeature.
 */
@property(nonatomic, weak, nullable) id<ACSLocalVideoEffectsFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSLocalVideoEffectsFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSLocalVideoEffectsFeatureEvents *events;

/// Checks if a video effect is supported on the device. Video effect to check if supported
-(BOOL)isEffectSupported:(ACSVideoEffect * _Nonnull )effect NS_SWIFT_NAME( isSupported(effect:));

/// Enables a video effect. Video effect to start
-(void)enableEffect:(ACSVideoEffect * _Nonnull )effect NS_SWIFT_NAME( enable(effect:));

/// Disable an enabled video effect.
-(void)disableEffect:(ACSVideoEffect * _Nonnull )effect NS_SWIFT_NAME( disable(effect:));

@end

/// Information about video effect enabled status
NS_SWIFT_NAME(VideoEffectEnabledEventArgs)
@interface ACSVideoEffectEnabledEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Name of the video effect.
@property (retain, nonnull, readonly) NSString * videoEffectName;

@end

/// Information about video effect disabled status
NS_SWIFT_NAME(VideoEffectDisabledEventArgs)
@interface ACSVideoEffectDisabledEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Name of the video effect.
@property (retain, nonnull, readonly) NSString * videoEffectName;

@end

/// Information about remote Effects changing state
NS_SWIFT_NAME(VideoEffectErrorEventArgs)
@interface ACSVideoEffectErrorEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Name of the video effect.
@property (retain, nonnull, readonly) NSString * videoEffectName;

/// Error code.
@property (retain, nonnull, readonly) NSString * code;

/// Error message.
@property (retain, nonnull, readonly) NSString * message;

@end

/// Wraps the user facing diagnostics feature in the call context.
NS_SWIFT_NAME(LocalUserDiagnosticsCallFeature)
@interface ACSLocalUserDiagnosticsCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Source for all network diagnostics.
@property (retain, nonnull, readonly) ACSNetworkDiagnostics * networkDiagnostics;

/// Source for all media diagnostics.
@property (retain, nonnull, readonly) ACSMediaDiagnostics * mediaDiagnostics;

@end

/// Represents an object where network diagnostics are accessed.
NS_SWIFT_NAME(NetworkDiagnostics)
@interface ACSNetworkDiagnostics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Get latest values for all known network diagnostics.
@property (retain, nonnull, readonly) ACSNetworkDiagnosticValues * latest;

/**
 * The delegate that will handle events from the ACSNetworkDiagnostics.
 */
@property(nonatomic, weak, nullable) id<ACSNetworkDiagnosticsDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSNetworkDiagnostics.
 */
@property(nonatomic, strong, nonnull, readonly) ACSNetworkDiagnosticsEvents *events;

@end

/// Represents an object where all the latest diagnostics values for network diagnostic.
NS_SWIFT_NAME(NetworkDiagnosticValues)
@interface ACSNetworkDiagnosticValues : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Last updated time of any diagnostic property.
@property (retain, nonnull, readonly) NSDate * lastUpdatedAt NS_SWIFT_NAME(lastUpdated);

// Class extension begins for NetworkDiagnosticValues.
-(BOOL)valueForNoNetwork:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForNetworkRelaysNotReachable:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;

-(ACSDiagnosticQuality)valueForNetworkReconnect NS_REFINED_FOR_SWIFT;
-(ACSDiagnosticQuality)valueForNetworkReceiveQuality NS_REFINED_FOR_SWIFT;
-(ACSDiagnosticQuality)valueForNetworkSendQuality NS_REFINED_FOR_SWIFT;
// Class extension ends for NetworkDiagnosticValues.

@end

/// Event payload containing information of a boolean diagnostic change event.
NS_SWIFT_NAME(DiagnosticFlagChangedEventArgs)
@interface ACSDiagnosticFlagChangedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The new diagnostic value.
@property (readonly) BOOL value;

/// The name of the diagnostic that changed.
@property (retain, nonnull, readonly) NSString * name;

@end

/// Event payload containing information of a quality diagnostic change event.
NS_SWIFT_NAME(DiagnosticQualityChangedEventArgs)
@interface ACSDiagnosticQualityChangedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The new diagnostic quality value.
@property (readonly) ACSDiagnosticQuality value;

/// The name of the diagnostic that changed.
@property (retain, nonnull, readonly) NSString * name;

@end

/// Represents an object where media diagnostics are accessed.
NS_SWIFT_NAME(MediaDiagnostics)
@interface ACSMediaDiagnostics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Stored latest values for all known media diagnostics.
@property (retain, nonnull, readonly) ACSMediaDiagnosticValues * latest;

/**
 * The delegate that will handle events from the ACSMediaDiagnostics.
 */
@property(nonatomic, weak, nullable) id<ACSMediaDiagnosticsDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSMediaDiagnostics.
 */
@property(nonatomic, strong, nonnull, readonly) ACSMediaDiagnosticsEvents *events;

@end

/// Represents an object where all the latest diagnostics values for media diagnostic.
NS_SWIFT_NAME(MediaDiagnosticValues)
@interface ACSMediaDiagnosticValues : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Last updated time of any diagnostic property.
@property (retain, nonnull, readonly) NSDate * lastUpdatedAt NS_SWIFT_NAME(lastUpdated);

// Class extension begins for MediaDiagnosticValues.
-(BOOL)valueForSpeakerNotFunctioning:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForSpeakerNotFunctioningDeviceInUse:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForSpeakerMuted:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForSpeakerVolumeIsZero:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForNoSpeakerDevicesEnumerated:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForSpeakingWhileMicrophoneIsMuted:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForNoMicrophoneDevicesEnumerated:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForMicrophoneNotFunctioningDeviceInUse:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForCameraFreeze:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForCameraStartFailed:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForCameraStartTimedOut:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForMicrophoneNotFunctioning:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForMicrophoneMutedUnexpectedly:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
-(BOOL)valueForCameraPermissionDenied:(NSError *_Nullable *_Nullable)error __attribute__((swift_error(nonnull_error))) NS_REFINED_FOR_SWIFT;
// Class extension ends for MediaDiagnosticValues.

@end

/// Media Statistics Call Feature. Track Media information for a call.
NS_SWIFT_NAME(MediaStatisticsCallFeature)
@interface ACSMediaStatisticsCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Define how often Media Statistics information reports are informed to the callback (min 10 seconds and max 3600 seconds)
@property (readonly) int reportIntervalInSeconds;

/**
 * The delegate that will handle events from the ACSMediaStatisticsCallFeature.
 */
@property(nonatomic, weak, nullable) id<ACSMediaStatisticsCallFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSMediaStatisticsCallFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSMediaStatisticsCallFeatureEvents *events;

// Class extension begins for MediaStatisticsCallFeature.
-(void)updateReportIntervalInSeconds:(int)reportInterval withError:(NSError*_Nullable*_Nonnull) error __attribute__((swift_error(nonnull_error))) NS_SWIFT_NAME(updateReportInterval(inSeconds:));
// Class extension ends for MediaStatisticsCallFeature.

@end

/// Describes a Media Statistics Report Received event.
NS_SWIFT_NAME(MediaStatisticsReportReceivedEventArgs)
@interface ACSMediaStatisticsReportReceivedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Report with the Media Statistics information.
@property (retain, nonnull, readonly) ACSMediaStatisticsReport * report;

@end

/// Report for all Media Statistics available in a given instant.
NS_SWIFT_NAME(MediaStatisticsReport)
@interface ACSMediaStatisticsReport : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Outgoing Media Statistics from the local participant
@property (retain, nonnull, readonly) ACSOutgoingMediaStatistics * outgoingStatistics;

/// Incoming Media Statistics from the remote participants
@property (retain, nonnull, readonly) ACSIncomingMediaStatistics * incomingStatistics;

/// Timestamp in unix epoch for when the report was generated.
@property (retain, nonnull, readonly) NSDate * lastUpdatedAt NS_SWIFT_NAME(lastUpdated);

@end

/// Aggregate for all outgoing Media Statistics information.
NS_SWIFT_NAME(OutgoingMediaStatistics)
@interface ACSOutgoingMediaStatistics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The list of the audio statistics for the call.
@property (copy, nonnull, readonly) NSArray<ACSOutgoingAudioStatistics *> * audio;

/// The list of the video statistics for the call.
@property (copy, nonnull, readonly) NSArray<ACSOutgoingVideoStatistics *> * video;

/// The list of the screen share statistics for the call.
@property (copy, nonnull, readonly) NSArray<ACSOutgoingScreenShareStatistics *> * screenShare;

/// The list of the data channel statistics for the call.
@property (copy, nonnull, readonly) NSArray<ACSOutgoingDataChannelStatistics *> * dataChannel;

@end

/// Represents the outgoing audio Media Statistics for a call.
NS_SWIFT_NAME(OutgoingAudioStatistics)
@interface ACSOutgoingAudioStatistics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Codec Name
@property (retain, nonnull, readonly) NSString * codecName;

/// Bitrate in bits per second.
@property (nullable, readonly) NSNumber * bitrateInBps NS_REFINED_FOR_SWIFT;

/// Average packet jitter in milliseconds.
@property (nullable, readonly) NSNumber * jitterInMs NS_REFINED_FOR_SWIFT;

/// The total number of packets sent.
@property (nullable, readonly) NSNumber * packetCount NS_REFINED_FOR_SWIFT;

/// Identifier used to distinguish when there are multiple streams with same media type/direction.
@property (nullable, readonly) NSNumber * streamId NS_REFINED_FOR_SWIFT;

@end

/// Represents the outgoing video Media Statistics for a call.
NS_SWIFT_NAME(OutgoingVideoStatistics)
@interface ACSOutgoingVideoStatistics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Codec Name.
@property (retain, nonnull, readonly) NSString * codecName;

/// Bitrate in bits per second.
@property (nullable, readonly) NSNumber * bitrateInBps NS_REFINED_FOR_SWIFT;

/// The total number of packets sent.
@property (nullable, readonly) NSNumber * packetCount NS_REFINED_FOR_SWIFT;

/// Identifier used to distinguish when there are multiple streams with same media type/direction.
@property (nullable, readonly) NSNumber * streamId NS_REFINED_FOR_SWIFT;

/// Frame rate sent on the RTP stream (frames/sec).
@property (nullable, readonly) NSNumber * frameRate NS_REFINED_FOR_SWIFT;

/// Frame width of the encoded frame (pixel).
@property (nullable, readonly) NSNumber * frameWidth NS_REFINED_FOR_SWIFT;

/// Frame height of the encoded frame (pixel).
@property (nullable, readonly) NSNumber * frameHeight NS_REFINED_FOR_SWIFT;

@end

/// Represents the outgoing screen share Media Statistics for a call.
NS_SWIFT_NAME(OutgoingScreenShareStatistics)
@interface ACSOutgoingScreenShareStatistics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Codec Name.
@property (retain, nonnull, readonly) NSString * codecName;

/// Bitrate in bits per second.
@property (nullable, readonly) NSNumber * bitrateInBps NS_REFINED_FOR_SWIFT;

/// The total number of packets sent.
@property (nullable, readonly) NSNumber * packetCount NS_REFINED_FOR_SWIFT;

/// Identifier used to distinguish when there are multiple streams with same media type/direction.
@property (nullable, readonly) NSNumber * streamId NS_REFINED_FOR_SWIFT;

/// Frame rate sent on the RTP stream (frames/sec).
@property (nullable, readonly) NSNumber * frameRate NS_REFINED_FOR_SWIFT;

/// Frame width of the encoded frame (pixel).
@property (nullable, readonly) NSNumber * frameWidth NS_REFINED_FOR_SWIFT;

/// Frame height of the encoded frame (pixel).
@property (nullable, readonly) NSNumber * frameHeight NS_REFINED_FOR_SWIFT;

@end

/// Represents the outgoing data channel Media Statistics for a call.
NS_SWIFT_NAME(OutgoingDataChannelStatistics)
@interface ACSOutgoingDataChannelStatistics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The total number of packets sent.
@property (nullable, readonly) NSNumber * packetCount NS_REFINED_FOR_SWIFT;

@end

/// Aggregate for all incoming Media Statistics information.
NS_SWIFT_NAME(IncomingMediaStatistics)
@interface ACSIncomingMediaStatistics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The list of the audio statistics for the call.
@property (copy, nonnull, readonly) NSArray<ACSIncomingAudioStatistics *> * audio;

/// The list of the video statistics for the call.
@property (copy, nonnull, readonly) NSArray<ACSIncomingVideoStatistics *> * video;

/// The list of the screen share statistics for the call.
@property (copy, nonnull, readonly) NSArray<ACSIncomingScreenShareStatistics *> * screenShare;

/// The list of the data channel statistics for the call.
@property (copy, nonnull, readonly) NSArray<ACSIncomingDataChannelStatistics *> * dataChannel;

@end

/// Represents the incoming audio Media Statistics for a call.
NS_SWIFT_NAME(IncomingAudioStatistics)
@interface ACSIncomingAudioStatistics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Codec Name.
@property (retain, nonnull, readonly) NSString * codecName;

/// Average packet jitter in milliseconds.
@property (nullable, readonly) NSNumber * jitterInMs NS_REFINED_FOR_SWIFT;

/// The total number of packets received.
@property (nullable, readonly) NSNumber * packetCount NS_REFINED_FOR_SWIFT;

/// Packet Loss Rate (packets/second).
@property (nullable, readonly) NSNumber * packetsLostPerSecond NS_REFINED_FOR_SWIFT;

/// Identifier used to distinguish when there are multiple streams with same media type/direction.
@property (nullable, readonly) NSNumber * streamId NS_REFINED_FOR_SWIFT;

@end

/// Represents the incoming video Media Statistics for a call.
NS_SWIFT_NAME(IncomingVideoStatistics)
@interface ACSIncomingVideoStatistics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Codec Name.
@property (retain, nonnull, readonly) NSString * codecName;

/// Bitrate in bits per second.
@property (nullable, readonly) NSNumber * bitrateInBps NS_REFINED_FOR_SWIFT;

/// Average packet jitter in milliseconds.
@property (nullable, readonly) NSNumber * jitterInMs NS_REFINED_FOR_SWIFT;

/// The total number of packets received.
@property (nullable, readonly) NSNumber * packetCount NS_REFINED_FOR_SWIFT;

/// Packet Loss Rate (packets/second).
@property (nullable, readonly) NSNumber * packetsLostPerSecond NS_REFINED_FOR_SWIFT;

/// Identifier used to distinguish when there are multiple streams with same media type/direction.
@property (nullable, readonly) NSNumber * streamId NS_REFINED_FOR_SWIFT;

/// Frame rate received on the RTP stream (frames/sec).
@property (nullable, readonly) NSNumber * frameRate NS_REFINED_FOR_SWIFT;

/// Frame width of the decoded frame (pixels).
@property (nullable, readonly) NSNumber * frameWidth NS_REFINED_FOR_SWIFT;

/// Frame height of the decoded frame (pixels).
@property (nullable, readonly) NSNumber * frameHeight NS_REFINED_FOR_SWIFT;

/// Total freeze duration (milliseconds).
@property (nullable, readonly) NSNumber * totalFreezeDurationInMs NS_REFINED_FOR_SWIFT;

// Class extension begins for IncomingVideoStatistics.
@property(nonatomic, readonly, nonnull) id<CommunicationIdentifier> participantIdentifier;
// Class extension ends for IncomingVideoStatistics.

@end

/// Represents the incoming screen share Media Statistics for a call.
NS_SWIFT_NAME(IncomingScreenShareStatistics)
@interface ACSIncomingScreenShareStatistics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Codec Name.
@property (retain, nonnull, readonly) NSString * codecName;

/// Bitrate in bits per second.
@property (nullable, readonly) NSNumber * bitrateInBps NS_REFINED_FOR_SWIFT;

/// Average packet jitter in milliseconds.
@property (nullable, readonly) NSNumber * jitterInMs NS_REFINED_FOR_SWIFT;

/// The total number of packets received.
@property (nullable, readonly) NSNumber * packetCount NS_REFINED_FOR_SWIFT;

/// Packet Loss Rate (packets/second).
@property (nullable, readonly) NSNumber * packetsLostPerSecond NS_REFINED_FOR_SWIFT;

/// Identifier used to distinguish when there are multiple streams with same media type/direction
@property (nullable, readonly) NSNumber * streamId NS_REFINED_FOR_SWIFT;

/// Frame rate received on the RTP stream (frames/sec).
@property (nullable, readonly) NSNumber * frameRate NS_REFINED_FOR_SWIFT;

/// Frame width of the decoded frame (pixels).
@property (nullable, readonly) NSNumber * frameWidth NS_REFINED_FOR_SWIFT;

/// Frame height of the decoded frame (pixels).
@property (nullable, readonly) NSNumber * frameHeight NS_REFINED_FOR_SWIFT;

/// Total freeze duration (milliseconds).
@property (nullable, readonly) NSNumber * totalFreezeDurationInMs NS_REFINED_FOR_SWIFT;

// Class extension begins for IncomingScreenShareStatistics.
@property(nonatomic, readonly, nonnull) id<CommunicationIdentifier> participantIdentifier;
// Class extension ends for IncomingScreenShareStatistics.

@end

/// Represents the incoming data channel Media Statistics for a call.
NS_SWIFT_NAME(IncomingDataChannelStatistics)
@interface ACSIncomingDataChannelStatistics : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Average packet jitter in milliseconds.
@property (nullable, readonly) NSNumber * jitterInMs NS_REFINED_FOR_SWIFT;

/// The total number of packets received.
@property (nullable, readonly) NSNumber * packetCount NS_REFINED_FOR_SWIFT;

@end

/// Describes a data channel receiver created event data
NS_SWIFT_NAME(DataChannelReceiverCreatedEventArgs)
@interface ACSDataChannelReceiverCreatedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// The receiver created with the event
@property (retain, nonnull, readonly) ACSDataChannelReceiver * receiver;

@end

/// Describes the data channel as a receiver to process the incoming data messages
NS_SWIFT_NAME(DataChannelReceiver)
@interface ACSDataChannelReceiver : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Data channel id
@property (readonly) int channelId;

/**
 * The delegate that will handle events from the ACSDataChannelReceiver.
 */
@property(nonatomic, weak, nullable) id<ACSDataChannelReceiverDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSDataChannelReceiver.
 */
@property(nonatomic, strong, nonnull, readonly) ACSDataChannelReceiverEvents *events;

// Class extension begins for DataChannelReceiver.
@property(nonatomic, readonly, nonnull) id<CommunicationIdentifier> senderIdentifier;

// Fetch data message from the data channel
-(nullable ACSDataChannelMessage *)receiveMessage;
// Class extension ends for DataChannelReceiver.

@end

/// Describes the options used to create a data channel sender
NS_SWIFT_NAME(DataChannelSenderOptions)
@interface ACSDataChannelSenderOptions : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Data channel id
@property int channelId;

/// Data channel bitrate in kbps
@property int bitrateInKbps;

/// Data channel priority
@property ACSDataChannelPriority priority;

/// Data channel reliability
@property ACSDataChannelReliability reliability;

// Class extension begins for DataChannelSenderOptions.
@property(nonatomic, readonly, nonnull) NSArray<id<CommunicationIdentifier>> * participants;
// Class extension ends for DataChannelSenderOptions.

@end

/// Describes the message received including a sequence number and user-provided data
NS_SWIFT_NAME(DataChannelMessage)
@interface ACSDataChannelMessage : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Sequence number indicating the order of the message
@property (readonly) int64_t sequenceNumber;

/// Byte array holding the data received
@property (copy, nonnull, readonly) NSData * data;

@end

/// Describes a data channel as the sender to send messages to one or more participants
NS_SWIFT_NAME(DataChannelSender)
@interface ACSDataChannelSender : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Data channel id
@property (readonly) int channelId;

/// Gets the max size allowed for a message
@property (readonly) int maxMessageSizeInBytes;

/// Sends data message
-(void)sendMessage:(NSData * _Nonnull )data NS_SWIFT_NAME( sendMessage(data:));

/// Close the data channel
-(void)closeSender;

// Class extension begins for DataChannelSender.
-(void)setParticipants:(NSArray<id<CommunicationIdentifier>>* _Nonnull) participants NS_SWIFT_NAME( setParticipants(participants:));
// Class extension ends for DataChannelSender.

@end

/// A call feature to use data channel
NS_SWIFT_NAME(DataChannelCallFeature)
@interface ACSDataChannelCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/**
 * The delegate that will handle events from the ACSDataChannelCallFeature.
 */
@property(nonatomic, weak, nullable) id<ACSDataChannelCallFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSDataChannelCallFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSDataChannelCallFeatureEvents *events;

/// Creates a new data channel sender with user-specified options
-(nonnull ACSDataChannelSender *)getDataChannelSender:(ACSDataChannelSenderOptions * _Nonnull )options NS_SWIFT_NAME( getDataChannelSender(options:));

@end

/// Single participant capability
NS_SWIFT_NAME(ParticipantCapability)
@interface ACSParticipantCapability : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Capability name
@property (readonly) ACSParticipantCapabilityType type;

/// Tells whether capability is capable or not
@property (readonly) BOOL isAllowed;

/// Capability resolution reason
@property (readonly) ACSCapabilityResolutionReason reason;

@end

/// Capability Changed Event
NS_SWIFT_NAME(CapabilitiesChangedEventArgs)
@interface ACSCapabilitiesChangedEventArgs : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// List of capabilites changed
@property (copy, nonnull, readonly) NSArray<ACSParticipantCapability *> * changedCapabilities;

/// Capability changed reason
@property (readonly) ACSCapabilitiesChangedReason reason;

@end

/// Capability call feature
NS_SWIFT_NAME(CapabilitiesCallFeature)
@interface ACSCapabilitiesCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/// List of all capabilites
@property (copy, nonnull, readonly) NSArray<ACSParticipantCapability *> * capabilities;

/**
 * The delegate that will handle events from the ACSCapabilitiesCallFeature.
 */
@property(nonatomic, weak, nullable) id<ACSCapabilitiesCallFeatureDelegate> delegate;

/**
 * The events will register blocks to handle events from the ACSCapabilitiesCallFeature.
 */
@property(nonatomic, strong, nonnull, readonly) ACSCapabilitiesCallFeatureEvents *events;

@end

/// Submit Survey Result
NS_SWIFT_NAME(CallSurveyResult)
@interface ACSCallSurveyResult : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Uniquely identify the call survey
@property (retain, nonnull, readonly) NSString * surveyId;

/// Uniquely identify the call being served
@property (retain, nonnull, readonly) NSString * callId;

/// An anonymized guid (for privacy reasons) that represents the participant submitting the survey This is not an End User Identifiable Information since this id is different for every survey/call.
@property (retain, nonnull, readonly) NSString * anonymizedParticipantId;

@end

/// Feature to allow submit call quality survey feedback after the end of the call.
NS_SWIFT_NAME(SurveyCallFeature)
@interface ACSSurveyCallFeature : ACSCallFeature
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Start Survey Process, returns an object that allow to configure votes. Either submit or ignore the return object after setup.
-(void)startSurveyWithCompletionHandler:(void (^ _Nonnull )(ACSCallSurvey * _Nullable  value, NSError * _Nullable error))completionHandler NS_SWIFT_NAME( startSurvey(completionHandler:));

/// Submit survey data
-(void)submitSurvey:(ACSCallSurvey * _Nonnull )survey withCompletionHandler:(void (^ _Nonnull )(ACSCallSurveyResult * _Nullable  value, NSError * _Nullable error))completionHandler NS_SWIFT_NAME( submit(survey:completionHandler:));

@end

/// Call Survey Information to be submitted
NS_SWIFT_NAME(CallSurvey)
@interface ACSCallSurvey : NSObject
-(nonnull instancetype)init NS_UNAVAILABLE;
/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Overall Score
@property (retain, nonnull) ACSCallSurveyScore * overallScore;

/// Audio score
@property (retain, nonnull) ACSCallSurveyScore * audioScore;

/// Video Score
@property (retain, nonnull) ACSCallSurveyScore * videoScore;

/// Screen Share score
@property (retain, nonnull) ACSCallSurveyScore * screenShareScore;

/// Set of call issues
@property ACSCallIssues overallIssues;

/// Set of audio issues
@property ACSAudioIssues audioIssues;

/// Set of video issues
@property ACSVideoIssues videoIssues;

/// Set of screen share issues
@property ACSScreenShareIssues screenShareIssues;

@end

/// Survey Score
NS_SWIFT_NAME(CallSurveyScore)
@interface ACSCallSurveyScore : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Score Value
@property int score;

/// Rating Scale for the score, default is 5 star rating (1-5)
@property (retain, nonnull) ACSCallSurveyRatingScale * scale;

@end

/// Rate scale for Call Survey scores.
NS_SWIFT_NAME(CallSurveyRatingScale)
@interface ACSCallSurveyRatingScale : NSObject
-(nonnull instancetype)init;

/// Deallocates the memory occupied by this object.
-(void)dealloc;

/// Inclusive lower bound of the rating value 0 to 100 (default 1)
@property int lowerBound;

/// Inclusive upper bound of the rating value 0 to 100 (default 5)
@property int upperBound;

/// The threshold value when the score is lower or equals (inclusive) than will be considered a bad experience (default 3)
@property int lowScoreThreshold;

@end

