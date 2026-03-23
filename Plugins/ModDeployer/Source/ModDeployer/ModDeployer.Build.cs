using UnrealBuildTool;
using System;
using System.IO;

public class ModDeployer : ModuleRules
{
	public ModDeployer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Cpp17;
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Projects",
				"InputCore",
				"UnrealEd",
				"ToolMenus",
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Http",
				"Json",
				"JsonUtilities",
				"LevelEditor",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			string NEW_LIBCPP_PATH = "$HOME/.llvm-libcpp-11.0.1";

			NEW_LIBCPP_PATH = NEW_LIBCPP_PATH.Replace("$HOME", Environment.GetFolderPath(Environment.SpecialFolder.UserProfile));
			NEW_LIBCPP_PATH = NEW_LIBCPP_PATH.Replace("~", Environment.GetFolderPath(Environment.SpecialFolder.UserProfile));
			
			PublicAdditionalLibraries.Add(Path.Combine(NEW_LIBCPP_PATH, "libc++.a"));
			PublicAdditionalLibraries.Add(Path.Combine(NEW_LIBCPP_PATH, "libc++abi.a"));
		}
	}
}
