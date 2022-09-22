#pragma once
#include "CoreMinimal.h"
#include "AstroDatumContainer.h"
#include "AstroEntityComponent.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.generated.h"

UCLASS(Abstract, Blueprintable)
class ASTRO_API UAstroEntityComponentContainer : public UAstroDatumContainer {
    GENERATED_BODY()
public:
    UAstroEntityComponentContainer();
    UFUNCTION(BlueprintPure)
    static FAstroEntityComponent GetEntityComponent(FAstroDatumRef ComponentRef, bool& bOutSuccess);
    
};

