#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentSubobject.h"
#include "LockChangedEventMetadata.h"
#include "UnlockBehavior.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UUnlockBehavior : public UAstroEntityComponentSubobject {
    GENERATED_BODY()
public:
    UUnlockBehavior();

    UFUNCTION(BlueprintCallable)
    void RespondToLockedStateChanged(FAstroDatumRef changedLockableComponent, const FLockChangedEventMetadata& EventData);
    
};

