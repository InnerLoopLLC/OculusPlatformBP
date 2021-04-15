// OculusPlatformBP plugin by InnerLoop LLC 2020

using System.IO;
using UnrealBuildTool;

public class OculusPlatformBP : ModuleRules
{
    public OculusPlatformBP(ReadOnlyTargetRules Target) : base(Target)
    {
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
				"LibOVRPlatform",
				"OnlineSubsystemUtils",
				"Projects"
            }
            );

        PrivateDependencyModuleNames.AddRange(
			new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
				"OculusHMD",
				"OnlineSubsystem",
				"OnlineSubsystemOculus",
				"Projects"
            }
			);
	}
}
