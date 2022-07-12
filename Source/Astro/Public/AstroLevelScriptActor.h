#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=LevelScriptActor -FallbackName=LevelScriptActor
#include "Engine/LevelScriptActor.h"
#include "AstroLevelScriptActor.generated.h"

UCLASS(Blueprintable)
class ASTRO_API AAstroLevelScriptActor : public ALevelScriptActor {
    GENERATED_BODY()
public:
    AAstroLevelScriptActor();
};

