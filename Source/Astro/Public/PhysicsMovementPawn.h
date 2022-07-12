#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Pawn -FallbackName=Pawn
#include "PhysicsMovementPawn.generated.h"

UCLASS(Blueprintable)
class ASTRO_API APhysicsMovementPawn : public APawn {
    GENERATED_BODY()
public:
    APhysicsMovementPawn();
};

