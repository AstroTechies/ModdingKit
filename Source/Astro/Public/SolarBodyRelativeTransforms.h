#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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

