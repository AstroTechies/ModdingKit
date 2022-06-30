using UnrealBuildTool;

public class AstroTarget : TargetRules {
	public AstroTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Game;
		// DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new string[] {
			"Astro",
			"MessageOfTheDay",
			"Terrain2"
		});
	}
}
