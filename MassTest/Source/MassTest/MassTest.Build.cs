// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MassTest : ModuleRules
{
	public MassTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore",
			"MassAIBehavior", "MassEntity", "MassCommon","MassNavigation", "MassMovement",
			"StateTreeModule", "MassSignals", "NavigationSystem", "MassRepresentation", "MassLOD", "StructUtils" });
	}
}
