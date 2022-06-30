#pragma once
#include "CoreMinimal.h"
#include "GameSettingsControlsOptions.generated.h"

USTRUCT(BlueprintType)
struct FGameSettingsControlsOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool CameraMouseYAxisInverted;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool CameraGamepadYAxisInverted;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool HoldToSprintMouse;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool HoldToSprintGamepad;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool HoldToOrbitCamera;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool HoldToVirtualCursorGamepad;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 MouseSensitivity;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool VehiclesUseAbosluteSteering;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    bool VehiclesUseYawAirControls;
    
    ASTRO_API FGameSettingsControlsOptions();
};

