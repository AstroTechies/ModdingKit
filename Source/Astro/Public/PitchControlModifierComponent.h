#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "ECameraControlMask.h"
#include "PitchControlModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UPitchControlModifierComponent : public UCameraModifierComponent
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
    float UpperLimit;

    UPROPERTY(EditAnywhere)
    float LowerLimit;

    UPROPERTY(EditAnywhere)
    float SpongeRange;

    UPROPERTY(EditAnywhere)
    ECameraControlMask ControlMask;

    UPitchControlModifierComponent();
};
