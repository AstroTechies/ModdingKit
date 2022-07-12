#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "StorageCanisterComponent.generated.h"

class UStorageChassisComponent;
class UItemType;
class APhysicalItem;
class UStorageCanisterOrganizationRule;
class UItemComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UStorageCanisterComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStartTransfer;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSwitchItemsWhileTransferring;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStopTransfer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> InputSlotNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> OutputSlotNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* CurrentOuterMostChassis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ItemTransferRate;
    
    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<UStorageCanisterOrganizationRule> InputOrganizationRule;
    
    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<UStorageCanisterOrganizationRule> OutputOrganizationRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> InputSlotRefs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> OutputSlotRefs;
    
public:
    UStorageCanisterComponent();
protected:
    UFUNCTION()
    void OnSlottedItemsChanged(APhysicalItem* changedItem);
    
    UFUNCTION()
    void OnItemTypeChanged(UItemComponent* ItemComponent, TSubclassOf<UItemType> NewItemType);
    
    UFUNCTION()
    void OnAmountChanged();
    
    UFUNCTION()
    void HandleSlotEvent(APhysicalItem* Item);
    
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

