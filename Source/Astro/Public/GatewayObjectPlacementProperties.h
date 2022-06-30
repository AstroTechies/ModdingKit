#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GatewayObjectPlacementProperties.generated.h"

class AGateChamber;
class AGateEngine;
class UPlanetGateObjectIndicatorDefinitions;

USTRUCT(BlueprintType)
struct FGatewayObjectPlacementProperties {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSoftClassPtr<AGateChamber> ChamberType;
    
    UPROPERTY(EditAnywhere)
    int32 ChamberOctreeResOffset;
    
    UPROPERTY(EditAnywhere)
    float ChamberExclusionRadius;
    
    UPROPERTY(EditAnywhere)
    TArray<FVector> ChamberPlacementCoordinates;
    
    UPROPERTY(EditAnywhere)
    uint8 bApplyRandomRotationToChamberPlacement: 1;
    
    UPROPERTY(EditAnywhere)
    uint8 bShouldHollowOutCoreAroundEngine: 1;
    
    UPROPERTY(EditAnywhere)
    FRotator ChamberPlacementRotation;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<AGateEngine> EngineType;
    
    UPROPERTY(EditAnywhere)
    int32 EngineOctreeResOffset;
    
    UPROPERTY(EditAnywhere)
    float HollowCoreRadius;
    
    UPROPERTY(EditAnywhere)
    float HollowCoreSmoothingZoneSize;
    
    UPROPERTY(EditAnywhere)
    int32 SamePlanetChambersRequiredForEngineActivation;
    
    UPROPERTY(EditAnywhere)
    int32 SolarSystemChambersRequiredForEngineActivation;
    
    UPROPERTY(EditAnywhere)
    UPlanetGateObjectIndicatorDefinitions* GateObjectIndicators;
    
    ASTRO_API FGatewayObjectPlacementProperties();
};

