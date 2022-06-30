#pragma once
#include "CoreMinimal.h"
#include "TickingObject.generated.h"

class UActorComponent;
class AActor;

USTRUCT(BlueprintType)
struct FTickingObject {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    AActor* m_actor;
    
    UPROPERTY(Export, Transient)
    UActorComponent* m_component;
    
    ASTRO_API FTickingObject();
};

