#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobject.h"
#include "LockChangedEventMetadata.h"
#include "LockingMechanismEventListener.generated.h"

class ULockingMechanism;

UCLASS(Blueprintable)
class ULockingMechanismEventListener : public UAstroEntityComponentSubobject {
    GENERATED_BODY()
public:
    ULockingMechanismEventListener();
    UFUNCTION()
    void OnLockingMechanismOpenStateChanged(ULockingMechanism* changedLockingMechanism, const FLockChangedEventMetadata& EventData);
    
};

