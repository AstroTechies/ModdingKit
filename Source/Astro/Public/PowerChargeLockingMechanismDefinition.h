#pragma once
#include "CoreMinimal.h"
#include "LockingMechanismDefinition.h"
#include "PowerChargeLockingMechanismDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UPowerChargeLockingMechanismDefinition : public ULockingMechanismDefinition {
    GENERATED_BODY()
public:
    UPowerChargeLockingMechanismDefinition();

};

