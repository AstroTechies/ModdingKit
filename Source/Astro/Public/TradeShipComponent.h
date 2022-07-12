#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SlotReference.h"
#include "IndicatorsForTradeShipSlot.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "TradeShipComponent.generated.h"

class APlayController;
class UClickQuery;
class UItemComponent;
class UOrbitalNavigationComponent;
class UTradeShipDockComponent;
class UItemType;
class APhysicalItem;

static uint32 GetTypeHash(const FSlotReference& TypeVar) {
	return 0;
}

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UOrbitalNavigationComponent* OrbitalNav;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, ReplicatedUsing=OnRep_ParentDockComponent, meta=(AllowPrivateAccess=true))
    UTradeShipDockComponent* ParentDockComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle LaunchDelayTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bManageIndicators: 1;
    
public:
    UTradeShipComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void UpdateIndicators();
    
    UFUNCTION()
    void SlottedItemsContentChanged();
    
    UFUNCTION()
    void SlottedItemContainedTypeChanged(UItemComponent* ItemComponent, TSubclassOf<UItemType> NewItemType);
    
    UFUNCTION()
    void ShipLaunchEnded();
    
    UFUNCTION()
    void ShipLaunched();
    
    UFUNCTION()
    void SetupIndicatorList();
    
    UFUNCTION()
    void OnRep_ParentDockComponent();
    
    UFUNCTION()
    void ItemSetOnResourceSlot(APhysicalItem* Item);
    
    UFUNCTION()
    void ItemReleasedFromResourceSlot(APhysicalItem* Item);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsDocked() const;
    
protected:
    UFUNCTION()
    void HandleQueryClickable(UClickQuery* Query);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySnapToOrbitAndLand();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetParentDock(UTradeShipDockComponent* dock);
    
protected:
    UFUNCTION()
    void AuthorityReturnLaunchedShip();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityLaunchShip(APlayController* NewLaunchingPlayController);
    
};

