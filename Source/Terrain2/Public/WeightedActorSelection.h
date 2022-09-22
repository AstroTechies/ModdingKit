#pragma once
#include "CoreMinimal.h"
#include "WeightedActorSelection.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FWeightedActorSelection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Weight;
    
    TERRAIN2_API FWeightedActorSelection();
};

