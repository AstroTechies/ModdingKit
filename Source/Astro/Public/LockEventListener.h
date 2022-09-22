#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobject.h"
#include "AstroDatumRef.h"
#include "LockChangedEventMetadata.h"
#include "LockEventListener.generated.h"

UCLASS(Blueprintable)
class ULockEventListener : public UAstroEntityComponentSubobject {
    GENERATED_BODY()
public:
    ULockEventListener();
    UFUNCTION()
    void OnLockLockedStateChanged(FAstroDatumRef lockRef, const FLockChangedEventMetadata& EventData);
    
};

