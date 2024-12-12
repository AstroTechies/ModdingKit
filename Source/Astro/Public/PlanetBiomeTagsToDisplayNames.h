#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PlanetBiomeTagsToDisplayNames.generated.h"

USTRUCT(BlueprintType)
struct FPlanetBiomeTagsToDisplayNames {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PlanetDisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FText> BiomeTagToDisplayNames;
    
    ASTRO_API FPlanetBiomeTagsToDisplayNames();
};

