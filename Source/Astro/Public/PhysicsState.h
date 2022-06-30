#pragma once
#include "CoreMinimal.h"
#include "PhysicsState.generated.h"

USTRUCT(BlueprintType)
struct FPhysicsState {
    GENERATED_BODY()
public:
    UPROPERTY()
    uint32 PhysicsFlags;
    
    UPROPERTY()
    FName CollisionProfile;
    
    ASTRO_API FPhysicsState();
};

