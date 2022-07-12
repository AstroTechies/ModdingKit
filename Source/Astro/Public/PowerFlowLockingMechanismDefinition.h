#pragma once
#include "CoreMinimal.h"
#include "LockingMechanismDefinition.h"
#include "PowerFlowLockingMechanismDefinition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UPowerFlowLockingMechanismDefinition : public ULockingMechanismDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullyPoweredMaintenanceTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AccumulatedFullyPoweredTimeDecayDuration;
    
    UPowerFlowLockingMechanismDefinition();
};

