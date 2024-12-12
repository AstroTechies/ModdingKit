#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobject.h"
#include "HarvestableComponentEventListener.generated.h"

class APhysicalItem;

UCLASS(Blueprintable)
class UHarvestableComponentEventListener : public UAstroEntityComponentSubobject {
    GENERATED_BODY()
public:
    UHarvestableComponentEventListener();

    UFUNCTION(BlueprintCallable)
    void OnSecondaryHarvestableItemReleased(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnPrimaryHarvestableItemReleased(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnHarvestableUprooted();
    
    UFUNCTION(BlueprintCallable)
    void OnHarvestableBuried();
    
};

