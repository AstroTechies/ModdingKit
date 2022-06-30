#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "IndicatorsForTradeShipSlot.h"
#include "SlotReference.h"
#include "TradeShipComponent.generated.h"

class APlayController;
class UItemComponent;
class UTradeShipDockComponent;
class UOrbitalNavigationComponent;
class UItemType;
class APhysicalItem;
class UClickQuery;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTradeShipComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> ResourceSlotRefs;

    UPROPERTY(SaveGame)
    APlayController *LaunchingPlayController;

    UPROPERTY(EditDefaultsOnly)
    float RejectedItemForce;

protected:
    UPROPERTY(EditDefaultsOnly)
    TArray<FName> ResourceSlots;

    UPROPERTY(Transient)
    TMap<FSlotReference, FIndicatorsForTradeShipSlot> IndicatorsForResourceSlots;

    UPROPERTY(Export, Transient)
    UOrbitalNavigationComponent *OrbitalNav;

    UPROPERTY(Export, Transient, ReplicatedUsing = OnRep_ParentDockComponent)
    UTradeShipDockComponent *ParentDockComponent;

    UPROPERTY(Transient)
    FTimerHandle LaunchDelayTimer;

    UPROPERTY(EditDefaultsOnly)
    uint8 bManageIndicators : 1;

public:
    UTradeShipComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void UpdateIndicators();

    UFUNCTION()
    void SlottedItemsContentChanged();

    UFUNCTION()
    void SlottedItemContainedTypeChanged(UItemComponent *ItemComponent, TSubclassOf<UItemType> NewItemType);

    UFUNCTION()
    void ShipLaunchEnded();

    UFUNCTION()
    void ShipLaunched();

    UFUNCTION()
    void SetupIndicatorList();

    UFUNCTION()
    void OnRep_ParentDockComponent();

    UFUNCTION()
    void ItemSetOnResourceSlot(APhysicalItem *Item);

    UFUNCTION()
    void ItemReleasedFromResourceSlot(APhysicalItem *Item);

public:
    UFUNCTION(BlueprintPure)
    bool IsDocked() const;

protected:
    UFUNCTION()
    void HandleQueryClickable(UClickQuery *Query);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySnapToOrbitAndLand();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetParentDock(UTradeShipDockComponent *dock);

protected:
    UFUNCTION()
    void AuthorityReturnLaunchedShip();

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityLaunchShip(APlayController *NewLaunchingPlayController);
};
