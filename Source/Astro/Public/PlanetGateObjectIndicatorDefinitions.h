#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IndicatorMeshDefinition.h"
#include "PlanetGateObjectIndicatorDefinitions.generated.h"

class UGateObjectIndicatorDefinition;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UPlanetGateObjectIndicatorDefinitions : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    UGateObjectIndicatorDefinition *ChamberIndicatorDefinition;

    UPROPERTY(EditDefaultsOnly)
    UGateObjectIndicatorDefinition *EngineIndicatorDefinition;

    UPROPERTY(EditDefaultsOnly)
    UGateObjectIndicatorDefinition *PlanetIndicatorDefinition;

    UPROPERTY(EditDefaultsOnly)
    FIndicatorMeshDefinition PlanetMeshDefinition;

    UPlanetGateObjectIndicatorDefinitions();
};
