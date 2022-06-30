#pragma once
#include "CoreMinimal.h"
#include "RailConnectionLocalData.generated.h"

class USplineMeshComponent;

USTRUCT(BlueprintType)
struct FRailConnectionLocalData {
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    USplineMeshComponent* Spline;
    
    ASTRO_API FRailConnectionLocalData();
};

