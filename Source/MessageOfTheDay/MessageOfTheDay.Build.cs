using UnrealBuildTool;

public class MessageOfTheDay : ModuleRules {
    public MessageOfTheDay(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Astro",
            "Core",
            "CoreUObject",
            "Engine",
        });
    }
}
