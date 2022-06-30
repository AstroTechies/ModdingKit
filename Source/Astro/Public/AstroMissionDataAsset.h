#pragma once
#include "CoreMinimal.h"
#include "AstroMissionData.h"
#include "Engine/DataAsset.h"
#include "AstroMissionDataAsset.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroMissionDataAsset : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TArray<FAstroMissionData> MissionsData;

    UAstroMissionDataAsset();
};
