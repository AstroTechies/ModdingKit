#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "LockableComponent.h"
#include "LockableComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API ULockableComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    ULockableComponentContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FLockableComponent GetLockableComponent(FAstroDatumRef lockableComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FLockableComponent FindLockableComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

