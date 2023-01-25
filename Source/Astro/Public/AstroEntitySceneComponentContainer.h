#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "AstroEntitySceneComponent.h"
#include "AstroEntitySceneComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroEntitySceneComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UAstroEntitySceneComponentContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAstroEntitySceneComponent GetEntitySceneComponent(FAstroDatumRef SceneComponentRef, bool& bOutSuccess);
    
};

