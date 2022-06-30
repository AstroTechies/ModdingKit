#pragma once
#include "CoreMinimal.h"
#include "AstroEntityTaskManager.h"
#include "AstroEntitySceneComponentTaskManager.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroEntitySceneComponentTaskManager : public UAstroEntityTaskManager
{
    GENERATED_BODY()
public:
    UAstroEntitySceneComponentTaskManager();
};
