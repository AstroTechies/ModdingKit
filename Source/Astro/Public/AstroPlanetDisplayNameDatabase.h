#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
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
    FText RegionTransitionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PlanetTransitionText;
    
    UAstroPlanetDisplayNameDatabase();
};

