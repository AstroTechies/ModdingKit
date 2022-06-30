#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "LaunchedSignalDelegate.h"
#include "SignalDelegate.h"
#include "TradeShipDockComponent.generated.h"

class UItemType;
class APhysicalItem;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTradeShipDockComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 bTradeInProgress : 1;

    UPROPERTY(EditDefaultsOnly)
    FName ShipSlotName;

protected:
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UItemType>> IndicatorItemTypes;

    UPROPERTY(EditDefaultsOnly)
    float LaunchDelay;

    UPROPERTY(BlueprintAssignable)
    FLaunchedSignal OnShipLaunchedToOrbit;

    UPROPERTY(BlueprintAssignable)
    FLaunchedSignal OnShipLaunchedToDock;

    UPROPERTY(BlueprintAssignable)
    FSignal OnShipArrivedAtDock;

    UPROPERTY(BlueprintAssignable)
    FSignal OnInventoryChanged;

public:
    UTradeShipDockComponent();

protected:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastShipLaunchedToOrbit(float LaunchLength);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastShipLaunchedToDock(float LaunchLength);

    UFUNCTION(NetMulticast, Reliable)
    void MulticastShipArrivedAtDock();

public:
    UFUNCTION(BlueprintPure)
    bool AcceptsItem(APhysicalItem *Item) const;
};
