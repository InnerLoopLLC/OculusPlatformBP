# OculusPlatformBP Plugin

A UE4 plugin library of Blueprint nodes for Oculus Platform functions.

*If you enjoy this plugin and want to see it improve, please consider helping me buy some caffeine.<br>
[**Donate via Patreon**](https://www.patreon.com/innerloopllc)*

#### What this is:
+ ...the [*Oculus Platform SDK (v19)*](https://developer.oculus.com/reference/platform/v19/) exposed from C++ to Blueprints as directly as possible.
+ ...or at least some of it. There's a still a lot of work to do.
+ ...client-side stuff **only**. For now. Server-side will be implemented eventually.

#### What this isn't:
+ ...an attempt to integrate the Oculus Platform SDK into existing UE4 systems. *(e.g. OnlineSubsystem)*
+ ...an expansion of the existing SDK.
+ ...a simplification or explanation of the existing SDK.
+ ...completed. Most of the features have **not** been implemented yet.

This means you'll find blueprint nodes for the functions included in the [*Oculus Platform SDK*](https://developer.oculus.com/reference/platform/v19/).
But that's pretty much it. No direct support is offered at this time, but I'll try my best to answer questions.
Please refer to the [*Oculus Platform SDK*](https://developer.oculus.com/reference/platform/v19/) and [*Oculus Platform Solutions*](https://developer.oculus.com/documentation/unreal/ps-platform-intro/) pages for documentation and example usage.
Please refer to the [*Unreal Engine 4*](https://github.com/EpicGames/UnrealEngine) GitHub for links and resources related to UE4.
Usage examples are included in the *Examples* folder.

*(Note: OculusVR plugin and OnlineSubsystemOculus plugin are required for OculusPlatformBP to function)*

Find out more about InnerLoop LLC at [https://www.innerloopllc.com](https://www.innerloopllc.com).

## Support
*(Much of this has not been fully tested. So, please tell me if something is broken.)*
* **Unreal Engine** - [4.25.3-Oculus](https://github.com/Oculus-VR/UnrealEngine/tree/4.25)
* **Platforms** - Win64, Android *(note: not yet tested on Android) (todo: test on Android)*
* **Oculus Platform SDK** - [v19](https://developer.oculus.com/downloads/package/oculus-platform-sdk/19.0.0/)<br>
*(**~It is highly recommended to update to v19 to access all features and bug fixes.~** or rather it will be. At the moment, the plugin is only tested against 1.40 and not all newer functions will compile properly.)*<br>
*(This plugin attempts to handle whichever Oculus Platform SDK is installed. Though 1.24+ is required.)*<br>
*(Launcher distributions of UE4 are not currently supported. You'll have to compile the engine from source.)*<br><br>
*(The following branches have not been tested for functionality, only to make sure it compiles)*
* **Unreal Engine** - 4.24, 4.23, 4.22, 4.21

## Installation
*(Optional)* - Update [*Oculus Platform SDK*](https://developer.oculus.com/downloads/package/oculus-platform-sdk/) to latest version (v19).
1) Place the *'OculusPlatformBP'* folder in *'Engine/Plugins/Marketplace'* or your project's *'Plugins'* folder
2) Regenerate project files
3) Compile engine
4) Enable the *OculusVR*, *OnlineSubsystemOculus*, and *OculusPlatformBP* plugins in your project
5) Check Oculus Entitlement
6) Use *OculusPlatformBP* to do cool stuff

## Updating the Oculus Platform SDK
*(This is optional, but highly recommended in order to access all Oculus Platform SDK features and bugfixes)*
1) Download the latest [*Oculus Platform SDK*](https://developer.oculus.com/downloads/package/oculus-platform-sdk/)
2) In that zip file, go to the *'Windows'* folder and copy *'LibOVRPlatform32_1.lib'* and *'LibOVRPlatform64_1.lib'* into the following folder within your engine directory: *'Engine\Source\ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\lib'* replacing the existing files.
3) If you're building for Quest, copy the two folders from the *'Android/libs'* directory of the zip file into that same engine directory.
4) Copy the entire *'Include'* folder from the zip file and overwrite the files within *'Engine\Source\ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\include'*.
5) That's it. Regenerate project files to be safe, then compile and you're good to go.

## Features
+ [Achievements](https://developer.oculus.com/documentation/unreal/ps-achievements)
+ [Leaderboards](https://developer.oculus.com/documentation/unreal/ps-leaderboards/)
+ [Rich Presence/Destinations](https://developer.oculus.com/documentation/unreal/ps-rich-presence/)
+ [User/Identity](https://developer.oculus.com/documentation/unreal/ps-presence/)

## Legal
*OculusPlatformBP Plugin* by ItsNotMeTrustMe *(Brian Edward Hicks)* of InnerLoop LLC, 2020<br>
This plugin was not created by, or in partnership with, Oculus or Epic Games *(which are trademarks of their respective entities)*.<br>
No guarantees are made about anything. Use at your own risk.<br>
Please drink responsibly.
