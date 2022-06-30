#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "WindPowerGeneratorComponent.generated.h"

USTRUCT(BlueprintType)
struct FWindPowerGeneratorComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    ASTRO_API FWindPowerGeneratorComponent();
};

