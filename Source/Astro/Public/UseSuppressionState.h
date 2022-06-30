#pragma once
#include "CoreMinimal.h"
#include "FPerPlayerUseSuppressionMode.h"
#include "EUseType.h"
#include "UseSuppressionState.generated.h"

USTRUCT(BlueprintType)
struct FUseSuppressionState {
    GENERATED_BODY()
public:
    UPROPERTY()
    EUseType SuppressedUseTypeFlags;
    
    UPROPERTY()
    FPerPlayerUseSuppressionMode PerPlayerMode;
    
    UPROPERTY()
    TArray<uint64> PlayerGuidWhitelist;
    
    ASTRO_API FUseSuppressionState();
};

