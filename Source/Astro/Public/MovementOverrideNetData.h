#pragma once
#include "CoreMinimal.h"
#include "MovementOverrideNetData.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FMovementOverrideNetData {
    GENERATED_BODY()
public:
    UPROPERTY()
    AActor* OverrideOwner;
    
    ASTRO_API FMovementOverrideNetData();
};

