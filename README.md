# Calling with Chat using UI Libraries Sample for iOS

The sample is a native iOS application that uses the Azure Communication Services iOS [Calling UI library](https://docs.microsoft.com/en-us/azure/communication-services/quickstarts/ui-library/get-started-composites?tabs=kotlin&pivots=platform-iOS) and [Chat UI library](https://learn.microsoft.com/en-us/azure/communication-services/quickstarts/ui-library/get-started-chat-ui-library?tabs=kotlin&pivots=platform-iOS) to build a calling with chat experience that features both voice and video calling and chat. The application uses a server-side component to provision access tokens that are then used to initialize the Azure Communication Services client library. To configure this server-side component, feel free to follow the [Trusted Service with Azure Functions](https://docs.microsoft.com/azure/communication-services/tutorials/trusted-service-tutorial) tutorial.

Additional documentation for this sample can be found on [Microsoft Docs](https://docs.microsoft.com/en-us/azure/communication-services/samples/calling-hero-sample?pivots=platform-iOS). See this sample's wiki to see updated information on [known issues](https://github.com/Azure-Samples/communication-services-calling-ui-with-chat-ios/issues)

<p>
<img width="30%" alt="image" src="iOS.gif">
</p>

## Features

This project framework provides the following features:

* Join a Teams meeting call and it's chat 
* Join a Group Call and a chat thread

## Getting Started

### Prerequisites

- Xcode 13 or greater
- An Azure account with an active subscription. [Create an account for free](https://azure.microsoft.com/free/?WT.mc_id=A261C142F).
- A Mac running [Xcode](https://go.microsoft.com/fwLink/p/?LinkID=266532), along with a valid developer certificate installed into your Keychain. [CocoaPods](https://cocoapods.org/) must also be installed to fetch dependencies.
- A deployed Communication Services resource. [Create a Communication Services resource](https://docs.microsoft.com/azure/communication-services/quickstarts/create-communication-resource).
- An Authentication Endpoint that will return the Azure Communication Services Token. See [example](https://docs.microsoft.com/azure/communication-services/tutorials/trusted-service-tutorial) or clone the [code](https://github.com/Azure-Samples/communication-services-javascript-quickstarts/tree/main/trusted-authentication-service).


### Quickstart

1. git clone this repository
1. Run `pod install` on the CallingWithChat directory
1. Open `CallingWithChat.xcworkspace` in XCode
1. Go to `GroupCallWithChatViewController` and `TeamsMeetingViewController` and update following:
    - Replace `TEAM_MEETING_LINK` with the Teams meeting link.
    - Replace `GROUP_ID` with the Teams meeting link.
    - Replace `ACS_ENDPOINT` with your ACS resource's endpoint.
    - Replace `DISPLAY_NAME` with your name.
    - Replace `USER_ID` with ACS user ID.
    - Replace `USER_ACCESS_TOKEN` with your token.
1. Run the application


## Resources

- [Calling UI library](https://docs.microsoft.com/en-us/azure/communication-services/quickstarts/ui-library/get-started-composites?tabs=kotlin&pivots=platform-iOS) 
- [Chat UI library](https://learn.microsoft.com/en-us/azure/communication-services/quickstarts/ui-library/get-started-chat-ui-library?tabs=kotlin&pivots=platform-iOS)
