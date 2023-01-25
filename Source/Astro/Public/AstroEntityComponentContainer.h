#pragma once
#include "CoreMinimal.h"
#include "AstroDatumContainer.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponent.h"
#include "AstroEntityComponentContainer.generated.h"

UCLASS(Abstract, Blueprintable)
class ASTRO_API UAstroEntityComponentContainer : public UAstroDatumContainer {
    GENERATED_BODY()
public:
    UAstroEntityComponentContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAstroEntityComponent GetEntityComponent(FAstroDatumRef ComponentRef, bool& bOutSuccess);
    
};

