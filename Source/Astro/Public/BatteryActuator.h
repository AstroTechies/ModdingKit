#pragma once
#include "CoreMinimal.h"
#include "FullnessActuator.h"
#include "BatteryActuator.generated.h"

class APhysicalItem;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ABatteryActuator : public AFullnessActuator
{
    GENERATED_BODY()
public:
    ABatteryActuator();

protected:
    UFUNCTION()
    void OnAuthorityFullyCharged();

    UFUNCTION()
    void OnAuthorityEndFullyCharged();

    UFUNCTION()
    void OnAuthorityEndEmptyCharge();

    UFUNCTION()
    void OnAuthorityEmptyCharge();

    UFUNCTION()
    void AuthorityHandleTargetStorageSlotsReset();

    UFUNCTION()
    void AuthorityHandleAttachedStorageSlotEvent(APhysicalItem *movedItem);
};
