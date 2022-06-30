#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "AxisOffsetConstraintModifier.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UAxisOffsetConstraintModifier : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 bConstrainForward : 1;

    UPROPERTY(EditAnywhere)
    uint8 bConstrainUp : 1;

    UPROPERTY(EditAnywhere)
    uint8 bConstrainRight : 1;

    UPROPERTY(EditAnywhere)
    float ForwardMax;

    UPROPERTY(EditAnywhere)
    float ForwardMin;

    UPROPERTY(EditAnywhere)
    float ForwardCorrectionSpeed;

    UPROPERTY(EditAnywhere)
    float UpMax;

    UPROPERTY(EditAnywhere)
    float UpMin;

    UPROPERTY(EditAnywhere)
    float UpCorrectionSpeed;

    UPROPERTY(EditAnywhere)
    float RightMax;

    UPROPERTY(EditAnywhere)
    float RightMin;

    UPROPERTY(EditAnywhere)
    float RightCorrectionSpeed;

    UAxisOffsetConstraintModifier();
};
