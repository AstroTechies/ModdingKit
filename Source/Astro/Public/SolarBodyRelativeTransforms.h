#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "SolarBodyRelativeTransforms.generated.h"

class ASolarBody;

USTRUCT(BlueprintType)
struct FSolarBodyRelativeTransforms {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ASolarBody*, FTransform> Transforms;
    
    ASTRO_API FSolarBodyRelativeTransforms();
};

