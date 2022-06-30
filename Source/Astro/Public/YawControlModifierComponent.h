#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "ECameraControlMask.h"
#include "YawControlModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UYawControlModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float Speed;

    UPROPERTY(EditAnywhere)
    float GamepadMultiplier;

    UPROPERTY(EditAnywhere)
    float MouseSmoothingFactor;

    UPROPERTY(EditAnywhere)
    float GamepadSmoothingFactor;

    UPROPERTY(EditAnywhere)
    float GamepadDeadZone;

    UPROPERTY(EditAnywhere)
    ECameraControlMask ControlMask;

    UYawControlModifierComponent();
};
