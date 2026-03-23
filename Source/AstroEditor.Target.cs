using UnrealBuildTool;

public class AstroEditorTarget : TargetRules {
	public AstroEditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		// DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new string[] {
			"Astro",
			"MessageOfTheDay",
			"Terrain2"
		});

		if (Target.Platform == UnrealTargetPlatform.Linux)
		{
			// uncomment to disable ModDeployer

			//DisablePlugins.Add("ModDeployer");
		}
	}
}
