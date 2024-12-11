#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LaunchedSignalDelegate.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "TradeShipDockComponent.generated.h"

class APhysicalItem;
class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTradeShipDockComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bTradeInProgress: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShipSlotName;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> IndicatorItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LaunchDelay;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLaunchedSignal OnShipLaunchedToOrbit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLaunchedSignal OnShipLaunchedToDock;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnShipArrivedAtDock;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnInventoryChanged;
    
public:
    UTradeShipDockComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastShipLaunchedToOrbit(float LaunchLength);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastShipLaunchedToDock(float LaunchLength);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastShipArrivedAtDock();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AcceptsItem(APhysicalItem* Item) const;
    
};

