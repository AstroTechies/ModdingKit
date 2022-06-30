#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FollowBehindModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UFollowBehindModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 bScaleSpeedWithDistance : 1;

    UPROPERTY(EditAnywhere)
    uint8 bScaleSpeedWithSpeed : 1;

    UPROPERTY(EditAnywhere)
    float NormalScaleDistance;

    UPROPERTY(EditAnywhere)
    float MaximumTargetSpeed;

    UFollowBehindModifierComponent();
};
