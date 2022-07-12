#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "IndicatorMeshDefinition.h"
#include "StationGateObjectIndicatorDefinitions.generated.h"

class UGateObjectIndicatorDefinition;

UCLASS(Blueprintable)
class ASTRO_API UStationGateObjectIndicatorDefinitions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGateObjectIndicatorDefinition* SolarStationIndicatorDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGateObjectIndicatorDefinition* EngineStationIndicatorDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIndicatorMeshDefinition SunMeshDefinition;
    
    UStationGateObjectIndicatorDefinitions();
};

