#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "PhysicsMovementReplicatedInput.generated.h"

USTRUCT(BlueprintType)
struct FPhysicsMovementReplicatedInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector_NetQuantizeNormal SteeredWheelsDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Boost;
    
    ASTRO_API FPhysicsMovementReplicatedInput();
};

