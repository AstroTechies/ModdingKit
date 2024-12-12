#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "AstroEntitySceneComponentSystem.generated.h"

class UAstroEntitySceneComponentTaskManager;

UCLASS(Blueprintable)
class ASTRO_API UAstroEntitySceneComponentSystem : public UAstroEntitySystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroEntitySceneComponentTaskManager* SceneComponentTaskManager;
    
public:
    UAstroEntitySceneComponentSystem();

};

