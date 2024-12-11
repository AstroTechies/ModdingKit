#pragma once
#include "CoreMinimal.h"
#include "StormGenerationIDContainer.generated.h"

USTRUCT(BlueprintType)
struct FStormGenerationIDContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> StormIDs;
    
    ASTRO_API FStormGenerationIDContainer();
};

