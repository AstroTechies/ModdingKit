#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "OrbitControlModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UOrbitControlModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    bool UsePlanetUp;

    UPROPERTY(EditAnywhere)
    bool AffectRotation;

    UPROPERTY(EditAnywhere)
    float PitchRate;

    UPROPERTY(EditAnywhere)
    float YawRate;

    UPROPERTY(EditAnywhere)
    float GamepadRotateMultiplier;

    UPROPERTY(EditAnywhere)
    float MouseSmoothingFactor;

    UPROPERTY(EditAnywhere)
    float GamepadSmoothingFactor;

    UPROPERTY(EditAnywhere)
    float LookatHeightOffset;

    UOrbitControlModifierComponent();
};
