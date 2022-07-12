#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "AstroEntitySlotBackupComponentSystem.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroEntitySlotBackupComponentSystem : public UAstroEntitySystem {
    GENERATED_BODY()
public:
    UAstroEntitySlotBackupComponentSystem();
};

