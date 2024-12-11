#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "EPlanetIdentifier.h"
#include "PlanetBiomeDisplayNames.h"
#include "AstroPlanetDisplayNameDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroPlanetDisplayNameDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlanetIdentifier, FPlanetBiomeDisplayNames> PlanetToBiomeNameMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlanetIdentifier, FText> PlanetToPlanetNameMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlanetIdentifier, FGameplayTag> PlanetToPlanetTagMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText RegionTransitionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PlanetTransitionText;
    
    UAstroPlanetDisplayNameDatabase();

};

