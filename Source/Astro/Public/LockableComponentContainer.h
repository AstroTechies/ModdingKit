#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "LockableComponent.h"
#include "AstroDatumRef.h"
#include "LockableComponentContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ULockableComponentContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    ULockableComponentContainer();
    UFUNCTION(BlueprintPure)
    static FLockableComponent GetLockableComponent(FAstroDatumRef lockableComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FLockableComponent FindLockableComponent(FAstroDatumRef EntityRef, bool &bOutSuccess);
};
