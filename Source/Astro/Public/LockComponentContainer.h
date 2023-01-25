#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "LockComponent.h"
#include "LockComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API ULockComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    ULockComponentContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FLockComponent GetLockComponent(FAstroDatumRef lockComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FLockComponent FindLockComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

