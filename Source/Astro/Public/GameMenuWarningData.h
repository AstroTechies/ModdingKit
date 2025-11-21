#pragma once
#include "CoreMinimal.h"
#include "EGameMenuWarningWidgetTypes.h"
#include "FAstroCGMPlayfabFailureReason.h"
#include "GameMenuWarningData.generated.h"

USTRUCT(BlueprintType)
struct FGameMenuWarningData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameMenuWarningWidgetTypes> VisibleWidgetTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroCGMPlayfabFailureReason CurrentPlayfabFailureReason;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText saveErrorText;
    
    ASTRO_API FGameMenuWarningData();
};

