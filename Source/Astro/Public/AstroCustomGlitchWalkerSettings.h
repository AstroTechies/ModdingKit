#pragma once
#include "CoreMinimal.h"
#include "AstroCustomGlitchWalkerSettings.generated.h"

USTRUCT(BlueprintType)
struct FAstroCustomGlitchWalkerSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 StartingVirusProtectionAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 StartingVirusProtectionDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 StartingVirusProtectionZeta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool StormsDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool FirewallsDisabled;
    
    ASTRO_API FAstroCustomGlitchWalkerSettings();
};

