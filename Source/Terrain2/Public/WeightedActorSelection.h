#pragma once
#include "CoreMinimal.h"
#include "WeightedActorSelection.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FWeightedActorSelection {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSoftClassPtr<AActor> Actor;
    
    UPROPERTY(EditAnywhere)
    float Weight;
    
    TERRAIN2_API FWeightedActorSelection();
};

