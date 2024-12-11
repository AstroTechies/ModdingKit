#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "HarvestableComponent.h"
#include "HarvestableComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UHarvestableComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UHarvestableComponentContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FHarvestableComponent GetHarvestableComponent(FAstroDatumRef HarvestableComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FHarvestableComponent FindHarvestableComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

