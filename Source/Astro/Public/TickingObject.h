#pragma once
#include "CoreMinimal.h"
#include "TickingObject.generated.h"

class AActor;
class UActorComponent;

USTRUCT(BlueprintType)
struct FTickingObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* m_actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UActorComponent* m_component;
    
    ASTRO_API FTickingObject();
};

