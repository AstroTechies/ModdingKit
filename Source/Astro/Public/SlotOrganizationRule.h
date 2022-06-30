#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EIndicatorTooltipType.h"
#include "SlotReference.h"
#include "SlotOrganizationRule.generated.h"

UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class USlotOrganizationRule : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FName RuleName;

    UPROPERTY(EditDefaultsOnly)
    TArray<FName> ManagedSlots;

    UPROPERTY(EditDefaultsOnly)
    int32 Priority;

    UPROPERTY(EditDefaultsOnly)
    EIndicatorTooltipType IndicatorType;

    UPROPERTY(EditDefaultsOnly)
    uint8 bPushUnwantedItems : 1;

protected:
    UPROPERTY(EditDefaultsOnly)
    uint8 bEjectUnwantedItems : 1;

    UPROPERTY(EditDefaultsOnly, Replicated)
    uint8 bIsEnabled : 1;

    UPROPERTY(EditDefaultsOnly)
    float UnwantedItemEjectionForce;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> ManagedSlotRefs;

public:
    USlotOrganizationRule();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetUnwantedItemsEjectionForce(float ejectionForce);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetPushUnwantedItems(bool push);

    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool Enabled);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetEjectUnwantedItems(bool eject);
};
