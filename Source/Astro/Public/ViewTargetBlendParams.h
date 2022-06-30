#pragma once
#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "ViewTargetBlendParams.generated.h"

USTRUCT(BlueprintType)
struct ASTRO_API FViewTargetBlendParams {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float BlendTime;
    
    UPROPERTY(EditDefaultsOnly)
    float BlendExponent;
    
    UPROPERTY(EditDefaultsOnly)
    TEnumAsByte<EViewTargetBlendFunction> BlendFunction;
    
    UPROPERTY(EditDefaultsOnly)
    bool bLockOutgoing;
    
    FViewTargetBlendParams();
};

