#pragma once
#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "ViewTargetBlendParams.generated.h"

USTRUCT(BlueprintType)
struct ASTRO_API FViewTargetBlendParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendExponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EViewTargetBlendFunction> BlendFunction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockOutgoing;
    
    FViewTargetBlendParams();
};

