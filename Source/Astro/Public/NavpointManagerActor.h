#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavpointManagerActor.generated.h"

class UNavpointManager;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ANavpointManagerActor : public AActor
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export, Transient)
    UNavpointManager *NavpointManager;

public:
    ANavpointManagerActor();
};
