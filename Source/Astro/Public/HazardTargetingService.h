#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "HazardTargetingService.generated.h"

UCLASS(Blueprintable, Blueprintable)
class UHazardTargetingService : public UBTService
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    bool RequireLineOfSight;

    UPROPERTY(EditAnywhere)
    bool NearestTargetOnly;

    UPROPERTY(EditAnywhere)
    float MaximumTargetDistance;

    UHazardTargetingService();
};
