#pragma once
#include "CoreMinimal.h"
#include "FullnessActuator.h"
#include "BatteryActuator.generated.h"

class APhysicalItem;

UCLASS(Blueprintable)
class ASTRO_API ABatteryActuator : public AFullnessActuator {
    GENERATED_BODY()
public:
    ABatteryActuator(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnAuthorityFullyCharged();
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityEndFullyCharged();
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityEndEmptyCharge();
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityEmptyCharge();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleTargetStorageSlotsReset();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleAttachedStorageSlotEvent(APhysicalItem* movedItem);
    
};

