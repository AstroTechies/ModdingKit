#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FixedYawModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UFixedYawModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float UpperLimit;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LowerLimit;

    UPROPERTY(EditAnywhere)
    float TargetSpeed;

    UPROPERTY(EditAnywhere)
    uint8 RelativeToTarget : 1;

    UPROPERTY(EditAnywhere)
    uint8 bScaleSpeedWithSpeed : 1;

    UFixedYawModifierComponent();
};
