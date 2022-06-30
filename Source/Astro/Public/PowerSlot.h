#pragma once
#include "CoreMinimal.h"
#include "ItemSlot.h"
#include "PowerSlot.generated.h"

class APhysicalItem;

UCLASS(Blueprintable, Abstract)
class ASTRO_API APowerSlot : public AItemSlot
{
    GENERATED_BODY()
public:
    APowerSlot();
    UFUNCTION()
    void SetPoweredTrue();

    UFUNCTION()
    void SetPoweredFalse();

    UFUNCTION(BlueprintImplementableEvent)
    void SetPowered(bool Powered);

    UFUNCTION(BlueprintImplementableEvent)
    void SetOxygen(bool Oxygen);

    UFUNCTION()
    void PowerSetItem(APhysicalItem *Item);

    UFUNCTION()
    void PowerReleaseItem(APhysicalItem *Item);
};
