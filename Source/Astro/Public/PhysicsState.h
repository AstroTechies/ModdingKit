#pragma once
#include "CoreMinimal.h"
#include "PhysicsState.generated.h"

USTRUCT(BlueprintType)
struct FPhysicsState {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 PhysicsFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CollisionProfile;
    
    ASTRO_API FPhysicsState();
};

