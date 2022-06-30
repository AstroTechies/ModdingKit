#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ReplicatedAugmentState.generated.h"

USTRUCT(BlueprintType)
struct FReplicatedAugmentState {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    float AugmentedIntensity;
    
    UPROPERTY(Transient)
    float AugmentedBrushSize;
    
    UPROPERTY(Transient)
    bool AugmentedPowerLevel;
    
    UPROPERTY(Transient)
    bool AugmentedTerrainAnalyzed;
    
    UPROPERTY(Transient)
    bool AugmentedFixedAlignment;
    
    UPROPERTY(Transient)
    float AugmentedHardnessTier;
    
    UPROPERTY(Transient)
    FLinearColor AugmentedTerrainColor;
    
    UPROPERTY(Transient)
    float AugmentedTerrainHardness;
    
    UPROPERTY(Transient)
    TEnumAsByte<EPhysicalSurface> AugmentedTerrainSurfaceType;
    
    ASTRO_API FReplicatedAugmentState();
};

