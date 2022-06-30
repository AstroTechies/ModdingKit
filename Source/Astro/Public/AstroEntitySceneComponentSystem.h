#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "AstroEntitySceneComponentSystem.generated.h"

class UAstroEntitySceneComponentTaskManager;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroEntitySceneComponentSystem : public UAstroEntitySystem
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    UAstroEntitySceneComponentTaskManager *SceneComponentTaskManager;

public:
    UAstroEntitySceneComponentSystem();
};
