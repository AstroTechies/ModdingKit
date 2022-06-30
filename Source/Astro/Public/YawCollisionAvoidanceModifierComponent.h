#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "YawCollisionAvoidanceModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UYawCollisionAvoidanceModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float WhiskerCastSize;

    UPROPERTY(EditAnywhere)
    float VelocityScaleDivisor;

    UYawCollisionAvoidanceModifierComponent();
};
