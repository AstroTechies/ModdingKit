#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AstroMissionData.h"
#include "AstroMissionDataAsset.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroMissionDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAstroMissionData> MissionsData;
    
    UAstroMissionDataAsset();

};

