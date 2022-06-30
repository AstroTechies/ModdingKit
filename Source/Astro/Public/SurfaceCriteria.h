#pragma once
#include "CoreMinimal.h"
#include "ESurfaceCriteriaSkyMode.h"
#include "ESurfaceCriteriaNormalMode.h"
#include "SurfaceCriteria.generated.h"

USTRUCT(BlueprintType)
struct FSurfaceCriteria {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    ESurfaceCriteriaNormalMode NormalMode;
    
    UPROPERTY(EditAnywhere)
    ESurfaceCriteriaSkyMode SkyMode;
    
    UPROPERTY(EditAnywhere)
    float NormalThreshold;
    
    ASTRO_API FSurfaceCriteria();
};

