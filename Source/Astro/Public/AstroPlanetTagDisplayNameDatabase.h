#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "PlanetBiomeTagsToDisplayNames.h"
#include "AstroPlanetTagDisplayNameDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroPlanetTagDisplayNameDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FPlanetBiomeTagsToDisplayNames> PlanetToBiomeNameMap;
    
    UAstroPlanetTagDisplayNameDatabase();

};

