#pragma once
#include "CoreMinimal.h"
#include "EAstroWindowMode.h"
#include "UObject/NoExportTypes.h"
#include "GameSettingsDisplayOptions.generated.h"

USTRUCT(BlueprintType)
struct FGameSettingsDisplayOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EAstroWindowMode WindowModeOpt;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool VSyncOpt;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> AvailableResolutions;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 CurrentResolutionIndex;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 BrightnessOpt;
    
    ASTRO_API FGameSettingsDisplayOptions();
};

