#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "AstroDatumRef.h"
#include "HarvestableComponent.h"
#include "HarvestableComponentContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UHarvestableComponentContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    UHarvestableComponentContainer();
    UFUNCTION(BlueprintPure)
    static FHarvestableComponent GetHarvestableComponent(FAstroDatumRef HarvestableComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FHarvestableComponent FindHarvestableComponent(FAstroDatumRef EntityRef, bool &bOutSuccess);
};
