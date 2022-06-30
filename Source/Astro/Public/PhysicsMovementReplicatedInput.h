#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "PhysicsMovementReplicatedInput.generated.h"

USTRUCT(BlueprintType)
struct FPhysicsMovementReplicatedInput {
    GENERATED_BODY()
public:
    UPROPERTY()
    FVector_NetQuantizeNormal SteeredWheelsDirection;
    
    UPROPERTY()
    float Boost;
    
    ASTRO_API FPhysicsMovementReplicatedInput();
};

