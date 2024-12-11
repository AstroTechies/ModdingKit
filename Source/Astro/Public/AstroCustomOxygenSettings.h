#pragma once
#include "CoreMinimal.h"
#include "AstroCustomOxygenSettings.generated.h"

USTRUCT(BlueprintType)
struct FAstroCustomOxygenSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float GlobalOxygenConsumptionScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool FreeOxygen;
    
    ASTRO_API FAstroCustomOxygenSettings();
};

