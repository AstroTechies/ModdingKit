#pragma once
#include "CoreMinimal.h"
#include "AstroCustomPowerSettings.generated.h"

USTRUCT(BlueprintType)
struct FAstroCustomPowerSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float GlobalPowerGenerationScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float GlobalPowerConsumptionScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float SolarPowerGenerationScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float WindPowerGenerationScalar;
    
    ASTRO_API FAstroCustomPowerSettings();
};

