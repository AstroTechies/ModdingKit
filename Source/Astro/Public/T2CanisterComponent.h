#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "T2CanisterComponent.generated.h"

class APhysicalItem;
class UItemComponent;
class UItemType;
class UT2CanisterOrganizationRule;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UT2CanisterComponent : public UActorComponent {
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
    float ItemTransferRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UT2CanisterOrganizationRule> OrganizationRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> InputSlotRefs;
    
public:
    UT2CanisterComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnSlottedItemsChanged(APhysicalItem* changedItem);
    
    UFUNCTION(BlueprintCallable)
    void OnItemTypeChanged(UItemComponent* ItemComponent, TSubclassOf<UItemType> NewItemType);
    
    UFUNCTION(BlueprintCallable)
    void OnAmountChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanMoveItems() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetIsDispensing(bool isDispensing);
    
};

