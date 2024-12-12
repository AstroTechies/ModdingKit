#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PlanetBiomeDisplayNames.generated.h"

USTRUCT(BlueprintType)
struct FPlanetBiomeDisplayNames {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FText> BiomeToDisplayNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FString> BiomeTagToVoxelStringIds;
    
    ASTRO_API FPlanetBiomeDisplayNames();
};

