#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "HarvestableSystem.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UHarvestableSystem : public UAstroEntitySystem {
    GENERATED_BODY()
public:
    UHarvestableSystem();
};

