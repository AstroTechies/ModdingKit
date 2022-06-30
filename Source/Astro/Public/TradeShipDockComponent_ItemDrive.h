#pragma once
#include "CoreMinimal.h"
#include "TradeShipDockComponent.h"
#include "TradeShipDockComponent_ItemDrive.generated.h"

class UItemDriveComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTradeShipDockComponent_ItemDrive : public UTradeShipDockComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export)
    UItemDriveComponent *ItemDriveComponent;

public:
    UTradeShipDockComponent_ItemDrive();
    UFUNCTION(BlueprintCallable)
    void HandleActiveEventChanged();
};
