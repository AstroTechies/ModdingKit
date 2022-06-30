#pragma once
#include "CoreMinimal.h"
#include "T2MaterialArray.h"
#include "T2MaterialCache.generated.h"

USTRUCT(BlueprintType)
struct FT2MaterialCache {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    TMap<FName, FT2MaterialArray> ByName;
    
    TERRAIN2_API FT2MaterialCache();
};

