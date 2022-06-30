#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
#include "UseToDiscoverItem.generated.h"

class USingleUseConsumableComponent;
class UItemType;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AUseToDiscoverItem : public APhysicalItem
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemType> ItemTypeDiscoveredOnUse;

    UPROPERTY(Export, VisibleAnywhere)
    USingleUseConsumableComponent *ConsumableComponent;

public:
    AUseToDiscoverItem();

protected:
    UFUNCTION()
    void OnUsed();
};
