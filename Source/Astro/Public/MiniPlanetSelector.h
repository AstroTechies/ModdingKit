#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "MiniPlanetSelector.generated.h"

class UMiniPlanetDefinitions;

UCLASS(Blueprintable)
class ASTRO_API AMiniPlanetSelector : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMiniPlanetDefinitions* MiniPlanetDefinitions;
    
public:
    AMiniPlanetSelector(const FObjectInitializer& ObjectInitializer);

};

