# OculusPlatformBP Plugin

A library of UE4 Blueprint nodes for Oculus Platform functions.

#### What this is:
+ ...the [*Oculus Platform SDK (v19)*](https://developer.oculus.com/reference/platform/v19/) exposed from C++ to Blueprints as directly as possible.
+ ...or at least some of it. There's a still a lot of work to do.

#### What this isn't:
+ ...an attempt to integrate the Oculus Platform SDK into existing UE4 systems.
+ ...an expansion of the existing SDK.
+ ...a simplification or explanation of the existing SDK.
+ ...completed. Most of the modules have **not** been implemented yet.

This means you'll find blueprint nodes for the functions included in the [*Oculus Platform SDK*](https://developer.oculus.com/reference/platform/v19/).
But that's pretty much it. No direct support is offered, but I'll try my best to answer questions.
Please refer to the [*Oculus Platform SDK*](https://developer.oculus.com/reference/platform/v19/) and [*Oculus Platform Solutions*](https://developer.oculus.com/documentation/unreal/ps-platform-intro/) pages for documentation and example usage.
Please refer to the [*Unreal Engine 4*](https://github.com/EpicGames/UnrealEngine) GitHub for links and resources related to UE4.

*(Note: OculusVR plugin and OnlineSubsystemOculus plugin are required for OculusPlatformBP to function)*

## Support
*(Much of this has not been fully tested. So, please tell me if something is broken.)*
* **Unreal Engine** - [4.25.3-Oculus](https://github.com/Oculus-VR/UnrealEngine/tree/4.25)
* **Platforms** - Win64, Android *(note: not yet tested on Android) (todo: test on Android)*
* **Oculus Platform SDK** - [v19](https://developer.oculus.com/downloads/package/oculus-platform-sdk/19.0.0/)<br>
*(UE4.23+ includes Oculus Platform SDK 1.40 by default. It is recommended to update to v19 to access all features and bug fixes.)*<br>
*(This plugin has only been tested for UE4.25.3-Oculus, however it may also work on other engine branches. No promises.)*

## Installation
*(Optional)* - Update [*Oculus Platform SDK*](https://developer.oculus.com/downloads/package/oculus-platform-sdk/) to latest version (v19).
1) Place the *'OculusPlatformBP'* folder in *'Engine/Plugins/Marketplace'* or your project's *'Plugins'* folder<br>
2) Regenerate project files<br>
3) Compile engine<br>
4) Enable the *OculusVR*, *OnlineSubsystemOculus*, and *OculusPlatformBP* plugins in your project
5) Check Oculus Entitlement
6) Use *OculusPlatformBP* to do cool stuff

## Modules
+ [Rich Presence/Destinations](https://developer.oculus.com/documentation/unreal/ps-rich-presence/)
+ [Leaderboards](https://developer.oculus.com/documentation/unreal/ps-leaderboards/)

## Legal
*OculusPlatformBP Plugin* by ItsNotMeTrustMe *(Brian Edward Hicks)* of InnerLoop LLC, 2020<br>
This plugin was not created by, or in partnership with, Oculus or Epic Games.<br>
No guarantees are made about anything. Use at your own risk.<br>
Please drink responsibly.
