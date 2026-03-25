// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using UnrealBuildTool.Rules;

public class SupportalCombat : ModuleRules
{
	public SupportalCombat(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
        });

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTasks", "GameplayTags" });

		PublicIncludePaths.AddRange(new string[] {
			"SupportalCombat",
			"SupportalCombat/Variant_Platforming",
			"SupportalCombat/Variant_Platforming/Animation",
			"SupportalCombat/Variant_Combat",
			"SupportalCombat/Variant_Combat/AI",
			"SupportalCombat/Variant_Combat/Animation",
			"SupportalCombat/Variant_Combat/Gameplay",
			"SupportalCombat/Variant_Combat/Interfaces",
			"SupportalCombat/Variant_Combat/UI",
			"SupportalCombat/Variant_SideScrolling",
			"SupportalCombat/Variant_SideScrolling/AI",
			"SupportalCombat/Variant_SideScrolling/Gameplay",
			"SupportalCombat/Variant_SideScrolling/Interfaces",
			"SupportalCombat/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
