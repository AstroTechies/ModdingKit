#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FreeControlModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UFreeControlModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float TranslateSpeed;

    UPROPERTY(EditAnywhere)
    float MaxBoostMultiplier;

    UPROPERTY(EditAnywhere)
    float PitchRate;

    UPROPERTY(EditAnywhere)
    float YawRate;

    UPROPERTY(EditAnywhere)
    float GamepadRotateMultiplier;

    UFreeControlModifierComponent();
};
