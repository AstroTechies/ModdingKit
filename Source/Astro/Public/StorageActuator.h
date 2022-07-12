#pragma once
#include "CoreMinimal.h"
#include "FullnessActuator.h"
#include "StorageActuator.generated.h"

class APhysicalItem;

UCLASS(Blueprintable)
class ASTRO_API AStorageActuator : public AFullnessActuator {
    GENERATED_BODY()
public:
    AStorageActuator();
protected:
    UFUNCTION()
    void AuthorityHandleLeadRailCarReleasedFromSlot(bool NewOwner);
    
    UFUNCTION()
    void AuthorityHandleLeadRailCarPlacedInSlot();
    
    UFUNCTION()
    void AuthorityHandleAttachStorageSlotEvent(APhysicalItem* movedItem);
    
    UFUNCTION()
    void AuthorityHandleAttachStorageItemAmountEvent();
    
};

