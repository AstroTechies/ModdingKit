#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "HazardTargetingService.generated.h"

UCLASS(Blueprintable)
class UHazardTargetingService : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequireLineOfSight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NearestTargetOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumTargetDistance;
    
    UHazardTargetingService();

};

