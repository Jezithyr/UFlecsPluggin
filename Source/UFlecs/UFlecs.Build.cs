// Copyright Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

public class UFlecs : ModuleRules
{
	public UFlecs(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		//The path for the header files
		PublicIncludePaths.AddRange(new string[] {
			Path.Combine(ModuleDirectory, "Public")
			});
		//PublicIncludePaths.AddRange(new string[] {"Public"});
		//The path for the source files
		PrivateIncludePaths.AddRange(new string[] {
			Path.Combine(ModuleDirectory, "Private"),
		});
		///PrivateIncludePaths.AddRange(new string[] {"Private"});	
		
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"FlecsLib"
		});
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
			//Important part because UBT has no idea what 'flecs_EXPORTS' is
		AppendStringToPublicDefinition("flecs_EXPORTS", "0");
	}
}
