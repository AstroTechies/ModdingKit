#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentSubobject.h"
#include "LockChangedEventMetadata.h"
#include "LockEventListener.generated.h"

UCLASS(Blueprintable)
class ULockEventListener : public UAstroEntityComponentSubobject {
    GENERATED_BODY()
public:
    ULockEventListener();
    UFUNCTION(BlueprintCallable)
    void OnLockLockedStateChanged(FAstroDatumRef lockRef, const FLockChangedEventMetadata& EventData);
    
};

