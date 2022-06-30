#pragma once
#include "CoreMinimal.h"
#include "InteractionRedirect.generated.h"

class AActor;
class USceneComponent;

USTRUCT(BlueprintType)
struct FInteractionRedirect {
    GENERATED_BODY()
public:
    UPROPERTY()
    AActor* NewActor;
    
    UPROPERTY(Export)
    USceneComponent* PivotComponent;
    
    ASTRO_API FInteractionRedirect();
};

