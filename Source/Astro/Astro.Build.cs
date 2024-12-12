using UnrealBuildTool;

public class Astro : ModuleRules {
    public Astro(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "Core",
            "CoreUObject",
            "Engine",
            "GameplayTags",
            "GameplayTasks",
            "InputCore",
            "LevelSequence",
            "MessageOfTheDay",
            "ReplicationGraph",
            "SlateCore",
            "Terrain2",
            "UMG",
        });
    }
}
