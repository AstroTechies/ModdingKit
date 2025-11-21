using UnrealBuildTool;

public class Astro : ModuleRules {
    public Astro(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "GameplayTags",
            "GameplayTasks",
            "InputCore",
            "LevelSequence",
            "MessageOfTheDay",
            "PhysicsCore",
            "ReplicationGraph",
            "SlateCore",
            "Terrain2",
            "UMG",
        });
    }
}
