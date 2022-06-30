#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "HarvestableSystem.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UHarvestableSystem : public UAstroEntitySystem
{
    GENERATED_BODY()
public:
    UHarvestableSystem();
};
