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
    UFUNCTION()
    void OnSecondaryHarvestableItemReleased(APhysicalItem* Item);
    
    UFUNCTION()
    void OnPrimaryHarvestableItemReleased(APhysicalItem* Item);
    
    UFUNCTION()
    void OnHarvestableUprooted();
    
    UFUNCTION()
    void OnHarvestableBuried();
    
};

