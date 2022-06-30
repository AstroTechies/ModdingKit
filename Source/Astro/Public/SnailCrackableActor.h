#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "SnailCrackableActor.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ASnailCrackableActor : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FComponentReference ClickableComponentRef;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference CrackableComponentRef;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference SnailSkeletonComponentRef;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference TerrariumMeshComponentRef;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference SlotsComponentRef;

    ASnailCrackableActor();
};
