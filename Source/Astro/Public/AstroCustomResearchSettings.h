#pragma once
#include "CoreMinimal.h"
#include "AstroCustomResearchSettings.generated.h"

USTRUCT(BlueprintType)
struct FAstroCustomResearchSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 StartingBytes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float ResearchRewardScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float ResearchSpeedScalar;
    
    ASTRO_API FAstroCustomResearchSettings();
};

