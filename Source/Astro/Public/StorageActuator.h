#pragma once
#include "CoreMinimal.h"
#include "FullnessActuator.h"
#include "StorageActuator.generated.h"

class APhysicalItem;

UCLASS(Blueprintable)
class ASTRO_API AStorageActuator : public AFullnessActuator {
    GENERATED_BODY()
public:
    AStorageActuator(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleLeadRailCarReleasedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleLeadRailCarPlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleAttachStorageSlotEvent(APhysicalItem* movedItem);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleAttachStorageItemAmountEvent();
    
};

