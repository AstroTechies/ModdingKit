#pragma once
#include "CoreMinimal.h"
#include "MovementOverrideNetData.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FMovementOverrideNetData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* OverrideOwner;
    
    ASTRO_API FMovementOverrideNetData();
};

