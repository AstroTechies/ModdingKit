#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavpointManagerActor.generated.h"

class UNavpointManager;

UCLASS(Blueprintable)
class ASTRO_API ANavpointManagerActor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNavpointManager* NavpointManager;
    
public:
    ANavpointManagerActor();
};

