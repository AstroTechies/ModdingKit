#pragma once
#include "CoreMinimal.h"
#include "AutomaticMissionCompletionInfo.generated.h"

USTRUCT(BlueprintType)
struct FAutomaticMissionCompletionInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName missionId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OnlyIfNoStartingShelter;
    
    ASTRO_API FAutomaticMissionCompletionInfo();
};

