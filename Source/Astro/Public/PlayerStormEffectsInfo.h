#pragma once
#include "CoreMinimal.h"
#include "EAstroPlayerStormRadiusStates.h"
#include "PlayerStormEffectsInfo.generated.h"

USTRUCT(BlueprintType)
struct FPlayerStormEffectsInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BackendPlayerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayBeforeApplyingEffectsSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayBeforeApplyingEffectsCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroPlayerStormRadiusStates PlayerStormRadiusState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEffectsApplied;
    
    ASTRO_API FPlayerStormEffectsInfo();
};

