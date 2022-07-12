#pragma once
#include "CoreMinimal.h"
#include "TickingObject.generated.h"

class UActorComponent;
class AActor;

USTRUCT(BlueprintType)
struct FTickingObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* m_actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UActorComponent* m_component;
    
    ASTRO_API FTickingObject();
};

