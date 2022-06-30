#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EDeformType.h"
#include "ReplicatedBrushState.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedBrushState {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    bool TerrainBrushActive;
    
    UPROPERTY(Transient)
    uint8 bTerrainBrushCanUse: 1;
    
    UPROPERTY(Transient)
    float CurrentBrushIndicatorUsing;
    
    UPROPERTY(Transient)
    float CurrentBrushIndicatorIntensity;
    
    UPROPERTY(Transient)
    float CurrentBrushIndicatorScale;
    
    UPROPERTY(Transient)
    FVector CurrentDeformNormal;
    
    UPROPERTY(Transient)
    FVector CurrentDeformLocation;
    
    UPROPERTY(Transient)
    EDeformType CurrentOperation;
    
    UPROPERTY(Transient)
    float SedimentGaugePercent;
    
    UPROPERTY(Transient)
    float TotalSedimentCapacity;
    
    ASTRO_API FReplicatedBrushState();
};

