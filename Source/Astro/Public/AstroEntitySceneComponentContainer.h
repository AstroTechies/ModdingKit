#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySceneComponent.h"
#include "AstroEntityComponentContainer.h"
#include "AstroDatumRef.h"
#include "AstroEntitySceneComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroEntitySceneComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UAstroEntitySceneComponentContainer();
    UFUNCTION(BlueprintPure)
    static FAstroEntitySceneComponent GetEntitySceneComponent(FAstroDatumRef SceneComponentRef, bool& bOutSuccess);
    
};

