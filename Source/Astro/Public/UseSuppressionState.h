#pragma once
#include "CoreMinimal.h"
#include "FPerPlayerUseSuppressionMode.h"
#include "EUseType.h"
#include "UseSuppressionState.generated.h"

USTRUCT(BlueprintType)
struct FUseSuppressionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUseType SuppressedUseTypeFlags;
    
    UPROPERTY(EditAnywhere)
    FPerPlayerUseSuppressionMode PerPlayerMode;
    
    UPROPERTY(EditAnywhere)
    TArray<uint64> PlayerGuidWhitelist;
    
    ASTRO_API FUseSuppressionState();
};

