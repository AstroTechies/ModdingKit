#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "T2CanisterComponent.generated.h"

class UItemComponent;
class UT2CanisterOrganizationRule;
class UItemType;
class APhysicalItem;

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
    
    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<UT2CanisterOrganizationRule> OrganizationRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> InputSlotRefs;
    
public:
    UT2CanisterComponent();
protected:
    UFUNCTION()
    void OnSlottedItemsChanged(APhysicalItem* changedItem);
    
    UFUNCTION()
    void OnItemTypeChanged(UItemComponent* ItemComponent, TSubclassOf<UItemType> NewItemType);
    
    UFUNCTION()
    void OnAmountChanged();
    
    UFUNCTION(BlueprintPure)
    bool CanMoveItems() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetIsDispensing(bool isDispensing);
    
};

