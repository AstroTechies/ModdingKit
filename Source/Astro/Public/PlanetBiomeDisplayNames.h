#pragma once
#include "CoreMinimal.h"
#include "PlanetBiomeDisplayNames.generated.h"

USTRUCT(BlueprintType)
struct FPlanetBiomeDisplayNames {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FText> BiomeToDisplayNames;
    
    ASTRO_API FPlanetBiomeDisplayNames();
};

