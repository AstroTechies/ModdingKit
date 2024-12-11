#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "IndicatorMeshDefinition.h"
#include "PlanetGateObjectIndicatorDefinitions.generated.h"

class UGateObjectIndicatorDefinition;

UCLASS(Blueprintable)
class ASTRO_API UPlanetGateObjectIndicatorDefinitions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGateObjectIndicatorDefinition* ChamberIndicatorDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGateObjectIndicatorDefinition* EngineIndicatorDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGateObjectIndicatorDefinition* PlanetIndicatorDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIndicatorMeshDefinition PlanetMeshDefinition;
    
    UPlanetGateObjectIndicatorDefinitions();

};

