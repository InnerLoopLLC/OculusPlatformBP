# OculusPlatformBP Plugin

An Unreal Engine 4 plugin featuring a library of **300+ Blueprint nodes** for Oculus Platform functions.

*If you enjoy this plugin and want to see it improve, please consider helping me buy some caffeine.<br>
[**Donate via Patreon**](https://www.patreon.com/innerloopllc) or [**Donate via PayPal**](https://paypal.me/bhicks85)*

## Features
+ [Achievements](https://developer.oculus.com/documentation/unreal/ps-achievements)
+ [Asset Files](https://developer.oculus.com/documentation/unreal/ps-assets/)
+ [Challenges](https://developer.oculus.com/documentation/unreal/ps-challenges/)
+ [Cloud Storage](https://developer.oculus.com/documentation/unreal/ps-cloud-storage/)
+ [Deep Linking](https://developer.oculus.com/documentation/unreal/ps-deep-linking/)
+ [In-App Purchases](https://developer.oculus.com/documentation/unreal/ps-iap/)
+ [Language Packs](https://developer.oculus.com/documentation/unreal/ps-language-packs/)
+ [Leaderboards](https://developer.oculus.com/documentation/unreal/ps-leaderboards/)
+ [Livestreaming and Content Sharing](https://developer.oculus.com/documentation/unreal/ps-sharing/)
+ [Parties and Party Chat](https://developer.oculus.com/documentation/unreal/ps-parties/)
+ [Rich Presence/Destinations](https://developer.oculus.com/documentation/unreal/ps-rich-presence/)
+ [Rooms](https://developer.oculus.com/documentation/unreal/ps-rooms/) *(partial)*
+ [User/Identity](https://developer.oculus.com/documentation/unreal/ps-presence/)

#### What this is:
+ ...the [*Oculus Platform SDK (v23)*](https://developer.oculus.com/reference/platform/v23/) exposed from C++ to Blueprints as directly as possible.
+ ...or at least most of it.
+ ...client-side stuff **only**.

#### What this isn't:
+ ...an attempt to integrate the Oculus Platform SDK into existing UE4 systems. *(e.g. Sessions)*
+ ...an expansion, simplification, or explanation of the existing SDK.
+ ...complete. Some features have **not** been implemented.

This means you'll find blueprint nodes for the functions included in the [*Oculus Platform SDK*](https://developer.oculus.com/reference/platform/v23/), but that's pretty much it. Please refer to the [*Oculus Platform SDK*](https://developer.oculus.com/reference/platform/v23/) and [*Oculus Platform Solutions*](https://developer.oculus.com/documentation/unreal/ps-platform-intro/) pages for documentation and example usage. Please refer to the [*Unreal Engine 4*](https://github.com/EpicGames/UnrealEngine) GitHub for links and resources related to UE4. Usage examples are included in the *Examples* folder.

## Progress
[**View Current Progress on Trello**](https://trello.com/b/TNGt3Yer/oculusplatformbp)<br>

*2/17/21* - Changed accessor functions to be pure nodes. (So, 'Get' nodes don't have execution pins.) This should make the plugin easier to use.

*2/13/21* - Fixed crash when multiple OnlineSubsystems were in use and OSS-Oculus was not the default. Removed deprecated functions.

*2/11/21* - This plugin is now confirmed to function as expected on Oculus Quest via App Lab! Coming up next, an update will be available soon which should prevent crashes if multiple online subsystems are in use concurrently. If you're experiencing unexplained crashes while using request nodes, this will likely fix those issues for you! Additionally, deprecated nodes will be completely removed in the next update. Please make sure you're no longer using deprecated nodes in your projects. Finally, project templates are in progress which will provide functional examples of various features.

*2/4/21* - Oculus has launched [App Lab](https://developer.oculus.com/blog/introducing-app-lab-a-new-way-to-distribute-oculus-quest-apps/), which should now allow use of the Oculus Platform for Quest apps that aren't published on the official store. This plugin hasn't been tested for this yet, but I'll provide an update in the next couple of weeks once I've tested the features. In the meantime, please report any issues you run across. Thanks!

## Requirements
* **Recommended Unreal Engine Version** - [4.25.4-Oculus](https://github.com/Oculus-VR/UnrealEngine/tree/4.25)
* **Supported Unreal Engine Versions** - 4.26, 4.25, 4.24, 4.23, 4.22, 4.21, 4.20 *(limited support)*
* **Platforms** - Win64, Android *(note: Android testing is ongoing)*
* **Oculus Platform SDK** - [v23](https://developer.oculus.com/downloads/package/oculus-platform-sdk/23.0.0/)<br>
* **Plugins** - OculusVR, OnlineSubsystemOculus<br>
*(**It is highly recommended to update to Oculus Platform SDK v23 to access all features and bug fixes.**)*<br>
*(This plugin attempts to handle whichever Oculus Platform SDK is installed. Though 1.24+ is required.)*<br>

## Installation
*(Optional)* - Update [*Oculus Platform SDK*](https://developer.oculus.com/downloads/package/oculus-platform-sdk/) to latest version (v23).
1) Place the *'OculusPlatformBP'* folder in *'Engine\Plugins\Marketplace'* or your project's *'Plugins'* folder
2) Regenerate project files
3) Compile engine *(**4.25.4-Oculus sometimes has compilation errors, these are solved by updating the Oculus Platform SDK to v23.**)*
4) Configure *DefaultEngine.ini [(instructions)](https://developer.oculus.com/documentation/unreal/ps-setup/)*
5) Enable the *OculusVR*, *OnlineSubsystemOculus*, and *OculusPlatformBP* plugins in your project
6) Check Oculus Entitlement
7) Use *OculusPlatformBP* to do cool stuff<br>
*(Note: when configuring DefaultEngine.ini for an App Lab project, it is recommended to set RiftAppID and MobileAppID instead of only OculusAppID. This will allow you to deploy builds for the Rift store and SideQuest without adjusting your config file for each build. Keep in mind that it is currently not possible to share leaderboards etc between App Lab projects and official store releases. Official Quest store apps will be able to do this with App Groupings.)*<br>

## Updating the Oculus Platform SDK
*(This is optional, but highly recommended in order to access all Oculus Platform SDK features and bugfixes.)*
1) Download the latest [*Oculus Platform SDK*](https://developer.oculus.com/downloads/package/oculus-platform-sdk/)
2) In that zip file, go to the *'Windows'* folder and copy *'LibOVRPlatform32_1.lib'* and *'LibOVRPlatform64_1.lib'* into the following folder within your engine directory: *'Engine\Source\ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\lib'* replacing the existing files.
3) If you're building for Quest, copy the two folders from the *'Android\libs'* directory of the zip file into that same engine directory.
4) Copy the entire *'Include'* folder from the zip file and replace the *'Engine\Source\ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\include'* folder.
5) That's it! Regenerate project files. Then compile and you're good to go.<br>
*(**It is highly recommended to update to Oculus Platform SDK v23 to access all features and bug fixes.**)*<br>
## Support
For technical support, questions, comments, etc, please reach out on our [Discord Server](https://discord.gg/k6KxJvq).<br>
Find out more about InnerLoop LLC at [https://www.innerloopllc.com](https://www.innerloopllc.com).

## Legal
*OculusPlatformBP Plugin* by ItsNotMeTrustMe *(Brian Edward Hicks)* of InnerLoop LLC, 2020<br>
This plugin was not created by, or in partnership with, Oculus or Epic Games *(which are trademarks of their respective entities)*.<br>
No guarantees are made about anything. Use at your own risk.<br>
Please drink responsibly.
