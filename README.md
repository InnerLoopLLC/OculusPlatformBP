# OculusPlatformBP Plugin

A UE4 plugin featuring a library of Blueprint nodes for Oculus Platform functions.

*If you enjoy this plugin and want to see it improve, please consider helping me buy some caffeine.<br>
[**Donate via Patreon**](https://www.patreon.com/innerloopllc)*

## Features
+ [Achievements](https://developer.oculus.com/documentation/unreal/ps-achievements)
+ [Cloud Storage](https://developer.oculus.com/documentation/unreal/ps-cloud-storage/)
+ [In-App Purchases](https://developer.oculus.com/documentation/unreal/ps-iap/)
+ [Leaderboards](https://developer.oculus.com/documentation/unreal/ps-leaderboards/)
+ [Rich Presence/Destinations](https://developer.oculus.com/documentation/unreal/ps-rich-presence/)
+ [User/Identity](https://developer.oculus.com/documentation/unreal/ps-presence/)

#### What this is:
+ ...the [*Oculus Platform SDK (v19)*](https://developer.oculus.com/reference/platform/v19/) exposed from C++ to Blueprints as directly as possible.
+ ...or at least some of it. There's a still a lot of work to do.
+ ...client-side stuff **only**. For now. Server-side may be implemented eventually.

#### What this isn't:
+ ...an attempt to integrate the Oculus Platform SDK into existing UE4 systems. *(e.g. OnlineSubsystem)*
+ ...an expansion of the existing SDK.
+ ...a simplification or explanation of the existing SDK.
+ ...completed. Most of the features have **not** been implemented yet.

This means you'll find blueprint nodes for the functions included in the [*Oculus Platform SDK*](https://developer.oculus.com/reference/platform/v19/), but that's pretty much it. Please refer to the [*Oculus Platform SDK*](https://developer.oculus.com/reference/platform/v19/) and [*Oculus Platform Solutions*](https://developer.oculus.com/documentation/unreal/ps-platform-intro/) pages for documentation and example usage. Please refer to the [*Unreal Engine 4*](https://github.com/EpicGames/UnrealEngine) GitHub for links and resources related to UE4. Usage examples are included in the *Examples* folder.

## Progress
*10/26/20* - The plugin now compiles properly for all engine versions back to launcher builds of 4.20! It's still best to use a source build (preferably the Oculus fork) and to update the Platform SDK to the latest version. The plugin also now handles OnlineSubsystemOculus not being properly configured. Additionally, In-App Purchases and Cloud Storage have now been implemented. This bring us to the point where the majority of the remaining features focus on multiplayer support (rooms, matchmaking, etc).

So, with most of the major features in place, it's time to take a step back and refactor some things. Specifically, the file structure is going to change to reflect the Oculus Platform SDK structure. Currently, I'm stacking way too many classes in single files. This is going to cause some problems later on, when the SDK is updated again. So, it might be a little while before the next update. Hopefully soon, though. In the meantime, please report any bugs or issues so I can stay on top of them.

## Requirements
* **Recommended Unreal Engine Version** - [4.25.3-Oculus](https://github.com/Oculus-VR/UnrealEngine/tree/4.25)
* **Supported Unreal Engine Versions** - 4.25, 4.24, 4.23, 4.22, 4.21, 4.20 *(limited support)*
* **Platforms** - Win64, Android *(note: not tested on Android)*
* **Oculus Platform SDK** - [v19](https://developer.oculus.com/downloads/package/oculus-platform-sdk/19.0.0/)<br>
* **Plugins** - OculusVR, OnlineSubsystemOculus<br>
*(**It is highly recommended to update to Oculus Platform SDK v19 to access all features and bug fixes.** )*<br>
*(This plugin attempts to handle whichever Oculus Platform SDK is installed. Though 1.24+ is required.)*<br>

## Installation
*(Optional)* - Update [*Oculus Platform SDK*](https://developer.oculus.com/downloads/package/oculus-platform-sdk/) to latest version (v19).
1) Place the *'OculusPlatformBP'* folder in *'Engine\Plugins\Marketplace'* or your project's *'Plugins'* folder
2) Regenerate project files
3) Compile engine
4) Configure *DefaultEngine.ini [(instructions)](https://developer.oculus.com/documentation/unreal/ps-setup/)*
5) Enable the *OculusVR*, *OnlineSubsystemOculus*, and *OculusPlatformBP* plugins in your project
6) Check Oculus Entitlement
7) Use *OculusPlatformBP* to do cool stuff

## Updating the Oculus Platform SDK
*(This is optional, but highly recommended in order to access all Oculus Platform SDK features and bugfixes)*
1) Download the latest [*Oculus Platform SDK*](https://developer.oculus.com/downloads/package/oculus-platform-sdk/)
2) In that zip file, go to the *'Windows'* folder and copy *'LibOVRPlatform32_1.lib'* and *'LibOVRPlatform64_1.lib'* into the following folder within your engine directory: *'Engine\Source\ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\lib'* replacing the existing files.
3) If you're building for Quest, copy the two folders from the *'Android\libs'* directory of the zip file into that same engine directory.
4) Copy the entire *'Include'* folder from the zip file and overwrite the files within *'Engine\Source\ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\include'*.
5) That's it. Regenerate project files to be safe, then compile and you're good to go.

## Support
For technical support, questions, comments, etc, please reach out on our [Discord Server](https://discord.gg/k6KxJvq).<br>
Find out more about InnerLoop LLC at [https://www.innerloopllc.com](https://www.innerloopllc.com).

## Legal
*OculusPlatformBP Plugin* by ItsNotMeTrustMe *(Brian Edward Hicks)* of InnerLoop LLC, 2020<br>
This plugin was not created by, or in partnership with, Oculus or Epic Games *(which are trademarks of their respective entities)*.<br>
No guarantees are made about anything. Use at your own risk.<br>
Please drink responsibly.
