#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EIndicatorTooltipType.h"
#include "SlotReference.h"
#include "SlotOrganizationRule.generated.h"

class UStorageChassisComponent;

UCLASS(Blueprintable, EditInlineNew)
class USlotOrganizationRule : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RuleName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ManagedSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* AllowedStorageChassis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIndicatorTooltipType IndicatorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPushUnwantedItems: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bEjectUnwantedItems: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bIsEnabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bShouldFillAllSlots: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UnwantedItemEjectionForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ManagedSlotRefs;
    
public:
    USlotOrganizationRule();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetUnwantedItemsEjectionForce(float ejectionForce);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetPushUnwantedItems(bool push);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool Enabled, bool broadcastSettingsChanged);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetEjectUnwantedItems(bool eject);
    
};

