# OculusPlatformBP

An Unreal Engine 4 plugin featuring a library of **300+ Blueprint nodes** for Oculus Platform functions.

*If you enjoy this plugin and want to see it improve, please consider helping me buy some caffeine. [Donate via PayPal](https://paypal.me/bhicks85).<br>
Or you could buy the full version on the [Unreal Marketplace](https://www.unrealengine.com/marketplace/en-US/product/3dd4be07fc1e47e88987713958ab5933).*

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
+ ...the [*Oculus Platform SDK (v28)*](https://developer.oculus.com/reference/platform/v28/) exposed from C++ to Blueprints as directly as possible.
+ ...or at least most of it.
+ ...client-side stuff **only**.

#### What this isn't:
+ ...an attempt to integrate the Oculus Platform SDK into existing UE4 systems. *(e.g. Sessions)*
+ ...an expansion, simplification, or explanation of the existing SDK.
+ ...complete. Some features have **not** been implemented.

This means you'll find blueprint nodes for the functions included in the [*Oculus Platform SDK*](https://developer.oculus.com/reference/platform/latest/), but that's pretty much it. Please refer to the [*Oculus Platform documentation*](https://developer.oculus.com/documentation/unreal/ps-platform-intro/) for explanations of usage. Please refer to the [*Unreal Engine 4*](https://github.com/EpicGames/UnrealEngine) GitHub for links and resources related to UE4. Oculus App Lab is supported for Oculus Quest.

## Updates
*6/14/21* - Surprise update! Since most of the questions that I field about this plugin are related to the setup process, I've streamlined it a bit. **There is now a Settings menu in `Project Settings` which helps configure your Oculus Platform ini settings!** Your config files will be checked on load to ensure they're properly setup. If the config sections/keys do not exist, they'll be created. You'll see warnings in your `Output Log` if the values are not set properly. This should make setting up your project to use the Oculus Platform a lot less confusing. There's also a new node, `GetOculusPlatformSettings()`, which exposes the AppIds to Blueprints. <br><br>
*5/24/21* - Updated to support Oculus Platform SDK v28. Finished exposing blueprint arrays for request nodes. Also, added a FAQ to this README to clear up some common questions. Next: a basic demo project which provides examples of how to use common features.

## Requirements
* **Recommended Unreal Engine Version** - [4.26-Oculus](https://github.com/Oculus-VR/UnrealEngine/tree/4.26)
* **Supported Unreal Engine Versions** - 4.26, 4.25, 4.24, 4.23, 4.22, 4.21, 4.20 *(limited support)*
* **Platforms** - Win64, Android
* **Recommended Oculus Platform SDK** - [v28](https://developer.oculus.com/downloads/package/oculus-platform-sdk/28.0.0/)<br>
* **Minimum Oculus Platform SDK** - [v1.24](https://developer.oculus.com/downloads/package/oculus-platform-sdk/1.24.0/)<br>
* **Plugins** - OculusVR, OnlineSubsystemOculus<br>

## Installation
*(Optional)* - Update [*Oculus Platform SDK*](https://developer.oculus.com/downloads/package/oculus-platform-sdk/) to latest version.
1) Place the `OculusPlatformBP` folder in `Engine\Plugins\Marketplace` or your project's `Plugins` folder
2) Regenerate project files
3) Compile engine
4) Enable the `OculusVR`, `OnlineSubsystemOculus`, and `OculusPlatformBP` plugins in your project
5) Set the AppIDs via `Project Settings->OculusPlatformBP` or by manually editing the config files. [*(instructions)*](https://developer.oculus.com/documentation/unreal/ps-setup/)
6) Check Oculus Entitlement
7) Use *OculusPlatformBP* to do cool stuff<br>

## Updating the Oculus Platform SDK
*(This is optional, but highly recommended in order to access all Oculus Platform SDK features and bugfixes.)*
1) Download the latest [*Oculus Platform SDK*](https://developer.oculus.com/downloads/package/oculus-platform-sdk/)
2) In that zip file, go to the `Windows` folder and copy `LibOVRPlatform32_1.lib` and `LibOVRPlatform64_1.lib` into the following folder within your engine directory: `Engine\Source\ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\lib` replacing the existing files.
3) If you're building for Quest, copy the two folders from the `Android\libs` directory of the zip file into that same engine directory.
4) Copy the entire `Include` folder from the zip file and replace the `Engine\Source\ThirdParty\Oculus\LibOVRPlatform\LibOVRPlatform\include` folder.
5) That's it! Regenerate project files. Then compile and you're good to go.<br>

## FAQ / Common Issues
> #### This plugin fails to compile for unmodified installations of the Oculus fork of UE4.25 or later.<br>
Oculus updated the include files for the Oculus Platform SDK, but the Win64 libraries are outdated. This tricks the plugin into thinking certain classes are available which are not. To solve this, please manually update the Oculus Platform SDK using the steps outlined above.
> #### My app fails to load on Oculus Quest with this plugin enabled.<br>
Most likely, this is due to a configuration issue. Please check your configuration settings in `Project Settings->OculusPlatformBP`. Additionally, please follow the Oculus documentation carefully. The most commonly missed step is to add the config file `Android/AndroidEngine.ini`. *(NOTE: As of OculusPlatformBP v28.1, the settings menu will create this file for you, if it does not already exist. Setting your `DefaultPlatformService` via this menu will update that value in both required config files.)*
> #### My app fails the entitlement check but some platform features work.<br>
I don't recommend placing the `Verify Entitlement` node in your Game Instance blueprint. The game instance can sometimes fire `Event Init` prior to `OnlineSubsystemOculus` loading. This would cause the check to always fail. Instead, I recommend executing the entitlement check on `Begin Play` in a blueprint actor.
> #### My app passes the entitlement check but some platform features do not work.<br>
In this case, please check that you have completed all requisite setup steps. A build must be uploaded to a release channel (the app doesn't need to function properly, it just has to exist). Then, you must add your Oculus email address to the authorized users of that release channel. You will also need to complete the Data Use Checkup on the Oculus Developers site, for each feature used in your app.
> #### In-App Purchases are returning error messages about user permissions.<br>
Currently, App Lab titles are only permitted to offer free IAP. This is not an issue with the plugin, but a limitation set by Oculus. Similarly, Subscriptions are not available for App Lab projects at this time. If your app has been approved for the Oculus Store and you still have this issue, please contact me.
> #### How can I access the UE4 logs for my Quest project?<br>
By default, UE4 does not generate logs in shipping configuration. In order to access logs (which are extremely helpful in isolating these issues), please build your app in development configuration while testing. Alternatively, you can follow the steps outlined in [this post](https://forums.unrealengine.com/t/how-to-add-buselogginginshipping-to-my-project/125651/2) to enable logs in shipping configuration. Please note that you should not include the line `bUseChecksInShipping` as it will cause issues uploading your build to an Oculus release channel. Run the app to generate logs, then pull the logs with the following adb command: `adb pull /storage/emulated/0/Android/data/com.[your_company].[your_project]/files/UE4Game/[your_project]/[your_project]/Saved/Logs`.
> #### Can my App Lab project share Leaderboards or other features with Rift store titles?<br>
No, this feature is not currently available to App Lab projects. If your app has been accepted as an official Oculus Store app, then you can do this with App Groupings.
> #### Can the same UE4 project be used to create builds for both Rift and Quest?<br>
Yes, it can! When configuring `DefaultEngine.ini` for an App Lab project, it is recommended to set `RiftAppID` and `MobileAppID` instead of only `OculusAppID`. This will allow you to create builds for the Rift store and SideQuest without adjusting your config file for each build.
> #### Do I have to update the Oculus Platform SDK?<br>
Short answer? No, not unless you are working on UE4.25 or later from the Oculus fork *(see above)* or require features which are more recent additions to the SDK. This plugin attempts to handle whichever Oculus Platform SDK is installed. v1.24 or later is required. Please consult the [Unreal Compatibility Matrix](https://developer.oculus.com/documentation/unreal/unreal-compatibility-matrix/) to determine which version of the Platform SDK is included with your version of Unreal Engine 4.

## Support
For technical support, questions, comments, etc, please reach out on our [Discord Server](https://discord.gg/k6KxJvq).<br>
Find out more about InnerLoop LLC at [https://www.innerloopllc.com](https://www.innerloopllc.com).

## Legal
*OculusPlatformBP Plugin* by [ItsNotMeTrustMe *(Brian Edward Hicks)*](mailto:brian@superhockeyball.com) of InnerLoop LLC, 2021<br>
This plugin was not created by, or in partnership with, Oculus or Epic Games *(which are trademarks of their respective entities)*.<br>
No guarantees are made about anything. Use at your own risk. But please let me know if something breaks, so I can fix it.<br>
Please drink responsibly.
