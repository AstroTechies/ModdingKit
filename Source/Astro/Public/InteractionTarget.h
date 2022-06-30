#pragma once
#include "CoreMinimal.h"
#include "InteractionTarget.generated.h"

class AActor;
class UClickableComponent;
class USceneComponent;

USTRUCT(BlueprintType)
struct FInteractionTarget {
    GENERATED_BODY()
public:
    UPROPERTY()
    AActor* Actor;
    
    UPROPERTY(Export)
    USceneComponent* AttachParent;
    
    UPROPERTY(Export)
    UClickableComponent* ClickableComponent;
    
    ASTRO_API FInteractionTarget();
};

