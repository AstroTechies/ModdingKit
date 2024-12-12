#pragma once
#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "AstroLevelScriptActor.generated.h"

UCLASS(Blueprintable)
class ASTRO_API AAstroLevelScriptActor : public ALevelScriptActor {
    GENERATED_BODY()
public:
    AAstroLevelScriptActor(const FObjectInitializer& ObjectInitializer);

};

