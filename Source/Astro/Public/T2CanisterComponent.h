#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "T2CanisterComponent.generated.h"

class APhysicalItem;
class UT2CanisterOrganizationRule;
class UItemComponent;
class UItemType;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UT2CanisterComponent : public UActorComponent
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
    float ItemTransferRate;

    UPROPERTY()
    TWeakObjectPtr<UT2CanisterOrganizationRule> OrganizationRule;

    UPROPERTY()
    TArray<FSlotReference> InputSlotRefs;

public:
    UT2CanisterComponent();

protected:
    UFUNCTION()
    void OnSlottedItemsChanged(APhysicalItem *changedItem);

    UFUNCTION()
    void OnItemTypeChanged(UItemComponent *ItemComponent, TSubclassOf<UItemType> NewItemType);

    UFUNCTION()
    void OnAmountChanged();

    UFUNCTION(BlueprintPure)
    bool CanMoveItems() const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetIsDispensing(bool isDispensing);
};
