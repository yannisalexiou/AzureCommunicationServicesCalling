# Azure Communication UI Library - Swift Package Manager

This package provides Swift Package Manager support for the Azure Communication UI Library for iOS.

## Generated Information
- **Git Tag**: AzureCommunicationUICalling_1.14.2
- **Generated On**: Tue Jul 22 13:05:18 EEST 2025
- **Generator**: Azure Communication UI Library SPM Package Generator

## Features

### Available Products
- **AzureCommunicationCalling** - Azure Communication Services Calling SDK
- **AzureCommunicationUICalling** - Calling UI Library with full functionality
- **AzureCommunicationUIChat** - Chat UI Library with full functionality  
- **AzureCommunicationUICommon** - Common utilities and components

### Architecture Support
- **iOS Device**: arm64 (iPhone/iPad)
- **iOS Simulator**: arm64 + x86_64 (Apple Silicon + Intel Macs)

## Installation

### Swift Package Manager

Add this package to your `Package.swift`:

```swift
dependencies: [
    .package(path: "path/to/this/package")
]
```

Or add it to your Xcode project:
1. File → Add Package Dependencies
2. Add Local Package
3. Select this folder

## Usage

```swift
import AzureCommunicationCalling      // Calling SDK
import AzureCommunicationUICalling    // Calling UI Library
import AzureCommunicationUIChat       // Chat UI Library
import AzureCommunicationUICommon     // Common utilities
```

## What's Included

This package includes:
- All necessary XCFrameworks with proper iOS device + simulator support
- Source code for common utilities
- Complete dependency resolution
- Localization resources
- Assets and resources

## Platform Requirements

- iOS 16.0+
- Xcode 14.0+
- Swift 5.7+

## License

Same as the original Azure Communication UI Library - MIT License

## Generated Package

This is an automatically generated SPM package from the Azure Communication UI Library repository.
- Original Repository: https://github.com/Azure/communication-ui-library-ios
- Git Tag: AzureCommunicationUICalling_1.14.2
