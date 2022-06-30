#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LandingInfo.generated.h"

USTRUCT(BlueprintType)
struct FLandingInfo {
    GENERATED_BODY()
public:
    UPROPERTY()
    uint8 HasValidLandingPoint: 1;
    
    UPROPERTY()
    FVector ImpactPoint;
    
    UPROPERTY()
    FVector AdjustedLocation;
    
    UPROPERTY()
    FVector ImpactNormal;
    
    UPROPERTY()
    FVector LastVelocity;
    
    ASTRO_API FLandingInfo();
};

