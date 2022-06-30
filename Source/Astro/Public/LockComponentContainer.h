#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "LockComponent.h"
#include "AstroDatumRef.h"
#include "LockComponentContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ULockComponentContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    ULockComponentContainer();
    UFUNCTION(BlueprintPure)
    static FLockComponent GetLockComponent(FAstroDatumRef lockComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FLockComponent FindLockComponent(FAstroDatumRef EntityRef, bool &bOutSuccess);
};
