#pragma once
#include "CoreMinimal.h"
#include "ItemSlot.h"
#include "PowerSlot.generated.h"

class APhysicalItem;

UCLASS(Abstract, Blueprintable)
class ASTRO_API APowerSlot : public AItemSlot {
    GENERATED_BODY()
public:
    APowerSlot();
    UFUNCTION(BlueprintCallable)
    void SetPoweredTrue();
    
    UFUNCTION(BlueprintCallable)
    void SetPoweredFalse();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPowered(bool Powered);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetOxygen(bool Oxygen);
    
    UFUNCTION(BlueprintCallable)
    void PowerSetItem(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void PowerReleaseItem(APhysicalItem* Item);
    
};

