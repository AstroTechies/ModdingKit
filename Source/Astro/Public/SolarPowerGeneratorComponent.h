#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "SolarPowerGeneratorComponent.generated.h"

USTRUCT(BlueprintType)
struct FSolarPowerGeneratorComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    ASTRO_API FSolarPowerGeneratorComponent();
};

