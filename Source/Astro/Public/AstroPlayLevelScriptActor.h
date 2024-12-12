#pragma once
#include "CoreMinimal.h"
#include "AstroLevelScriptActor.h"
#include "AstroPlayLevelScriptActor.generated.h"

UCLASS(Blueprintable)
class ASTRO_API AAstroPlayLevelScriptActor : public AAstroLevelScriptActor {
    GENERATED_BODY()
public:
    AAstroPlayLevelScriptActor(const FObjectInitializer& ObjectInitializer);

};

