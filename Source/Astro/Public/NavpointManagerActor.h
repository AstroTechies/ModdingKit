#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "NavpointManagerActor.generated.h"

class UNavpointManager;

UCLASS(Blueprintable)
class ASTRO_API ANavpointManagerActor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UNavpointManager* NavpointManager;
    
public:
    ANavpointManagerActor();
};

