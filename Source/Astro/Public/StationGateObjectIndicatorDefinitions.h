#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IndicatorMeshDefinition.h"
#include "StationGateObjectIndicatorDefinitions.generated.h"

class UGateObjectIndicatorDefinition;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UStationGateObjectIndicatorDefinitions : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    UGateObjectIndicatorDefinition *SolarStationIndicatorDefinition;

    UPROPERTY(EditDefaultsOnly)
    UGateObjectIndicatorDefinition *EngineStationIndicatorDefinition;

    UPROPERTY(EditDefaultsOnly)
    FIndicatorMeshDefinition SunMeshDefinition;

    UStationGateObjectIndicatorDefinitions();
};
