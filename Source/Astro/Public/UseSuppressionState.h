#pragma once
#include "CoreMinimal.h"
#include "EUseType.h"
#include "FPerPlayerUseSuppressionMode.h"
#include "UseSuppressionState.generated.h"

USTRUCT(BlueprintType)
struct FUseSuppressionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUseType SuppressedUseTypeFlags;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerPlayerUseSuppressionMode PerPlayerMode;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint64> PlayerGuidWhitelist;
    
    ASTRO_API FUseSuppressionState();
};

