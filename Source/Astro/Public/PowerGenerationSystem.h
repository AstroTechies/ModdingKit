#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "PowerGenerationSystem.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UPowerGenerationSystem : public UAstroEntitySystem
{
    GENERATED_BODY()
public:
    UPowerGenerationSystem();
};
