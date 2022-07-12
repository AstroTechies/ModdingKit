#pragma once
#include "CoreMinimal.h"
#include "ESurfaceCriteriaNormalMode.h"
#include "ESurfaceCriteriaSkyMode.h"
#include "SurfaceCriteria.generated.h"

USTRUCT(BlueprintType)
struct FSurfaceCriteria {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESurfaceCriteriaNormalMode NormalMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESurfaceCriteriaSkyMode SkyMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NormalThreshold;
    
    ASTRO_API FSurfaceCriteria();
};

