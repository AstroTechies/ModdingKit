#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobject.h"
#include "AstroDatumRef.h"
#include "LockChangedEventMetadata.h"
#include "UnlockBehavior.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UUnlockBehavior : public UAstroEntityComponentSubobject {
    GENERATED_BODY()
public:
    UUnlockBehavior();
    UFUNCTION()
    void RespondToLockedStateChanged(FAstroDatumRef changedLockableComponent, const FLockChangedEventMetadata& EventData);
    
};

