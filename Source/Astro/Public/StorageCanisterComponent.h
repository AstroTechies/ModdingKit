#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "StorageCanisterComponent.generated.h"

class UItemType;
class UStorageChassisComponent;
class UItemComponent;
class UStorageCanisterOrganizationRule;
class APhysicalItem;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UStorageCanisterComponent : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable)
    FSignal OnStartTransfer;

    UPROPERTY(BlueprintAssignable)
    FSignal OnSwitchItemsWhileTransferring;

    UPROPERTY(BlueprintAssignable)
    FSignal OnStopTransfer;

    UPROPERTY(EditDefaultsOnly)
    TArray<FName> InputSlotNames;

    UPROPERTY(EditDefaultsOnly)
    TArray<FName> OutputSlotNames;

    UPROPERTY(Export, Transient)
    UStorageChassisComponent *CurrentOuterMostChassis;

    UPROPERTY(EditDefaultsOnly)
    float ItemTransferRate;

    UPROPERTY()
    TWeakObjectPtr<UStorageCanisterOrganizationRule> InputOrganizationRule;

    UPROPERTY()
    TWeakObjectPtr<UStorageCanisterOrganizationRule> OutputOrganizationRule;

    UPROPERTY()
    TArray<FSlotReference> InputSlotRefs;

    UPROPERTY()
    TArray<FSlotReference> OutputSlotRefs;

public:
    UStorageCanisterComponent();

protected:
    UFUNCTION()
    void OnSlottedItemsChanged(APhysicalItem *changedItem);

    UFUNCTION()
    void OnItemTypeChanged(UItemComponent *ItemComponent, TSubclassOf<UItemType> NewItemType);

    UFUNCTION()
    void OnAmountChanged();

    UFUNCTION()
    void HandleSlotEvent(APhysicalItem *Item);

    UFUNCTION()
    void HandleOnReleasedFromSlot(bool NewOwner);

    UFUNCTION()
    void HandleOnPlacedInSlot();

    UFUNCTION(BlueprintPure)
    bool CanMoveItems() const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetIsDispensing(bool isDispensing);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityQueueStopDispensingWhenItemComplete();
};
