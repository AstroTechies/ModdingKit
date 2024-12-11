#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "IndicatorsForTradeShipSlot.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "TradeShipComponent.generated.h"

class APhysicalItem;
class APlayController;
class UClickQuery;
class UItemComponent;
class UItemType;
class UOrbitalNavigationComponent;
class UTradeShipDockComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTradeShipComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ResourceSlotRefs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    APlayController* LaunchingPlayController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RejectedItemForce;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ResourceSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FSlotReference, FIndicatorsForTradeShipSlot> IndicatorsForResourceSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOrbitalNavigationComponent* OrbitalNav;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, ReplicatedUsing=OnRep_ParentDockComponent, meta=(AllowPrivateAccess=true))
    UTradeShipDockComponent* ParentDockComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle LaunchDelayTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bManageIndicators: 1;
    
public:
    UTradeShipComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateIndicators();
    
    UFUNCTION(BlueprintCallable)
    void SlottedItemsContentChanged();
    
    UFUNCTION(BlueprintCallable)
    void SlottedItemContainedTypeChanged(UItemComponent* ItemComponent, TSubclassOf<UItemType> NewItemType);
    
    UFUNCTION(BlueprintCallable)
    void ShipLaunchEnded();
    
    UFUNCTION(BlueprintCallable)
    void ShipLaunched();
    
    UFUNCTION(BlueprintCallable)
    void SetupIndicatorList();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ParentDockComponent();
    
    UFUNCTION(BlueprintCallable)
    void ItemSetOnResourceSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void ItemReleasedFromResourceSlot(APhysicalItem* Item);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDocked() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleQueryClickable(UClickQuery* Query);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySnapToOrbitAndLand();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetParentDock(UTradeShipDockComponent* dock);
    
protected:
    UFUNCTION(BlueprintCallable)
    void AuthorityReturnLaunchedShip();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityLaunchShip(APlayController* NewLaunchingPlayController);
    
};

