#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "VelocityPitchModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UVelocityPitchModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float VelocitySmoothing;

    UPROPERTY(EditAnywhere)
    float SaturationSpeed;

    UVelocityPitchModifierComponent();
};
