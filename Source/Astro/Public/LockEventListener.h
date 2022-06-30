#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobject.h"
#include "LockChangedEventMetadata.h"
#include "AstroDatumRef.h"
#include "LockEventListener.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ULockEventListener : public UAstroEntityComponentSubobject
{
    GENERATED_BODY()
public:
    ULockEventListener();
    UFUNCTION()
    void OnLockLockedStateChanged(FAstroDatumRef lockRef, const FLockChangedEventMetadata &EventData);
};
