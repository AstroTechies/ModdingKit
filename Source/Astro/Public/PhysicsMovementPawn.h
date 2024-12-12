#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PhysicsMovementPawn.generated.h"

UCLASS(Blueprintable)
class ASTRO_API APhysicsMovementPawn : public APawn {
    GENERATED_BODY()
public:
    APhysicsMovementPawn(const FObjectInitializer& ObjectInitializer);

};

