#pragma once
#include "CoreMinimal.h"
#include "AstroEngineCommon.generated.h"

class UAstroErrorWidget;

USTRUCT(BlueprintType)
struct ASTRO_API FAstroEngineCommon {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Export)
    UAstroErrorWidget* ErrorWidget;
    
    UPROPERTY(Export)
    UAstroErrorWidget* SessionOperationInProgressWidget;
    
public:
    FAstroEngineCommon();
};

