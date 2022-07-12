#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "AstroProceduralStateSystem.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroProceduralStateSystem : public UAstroEntitySystem {
    GENERATED_BODY()
public:
    UAstroProceduralStateSystem();
};

