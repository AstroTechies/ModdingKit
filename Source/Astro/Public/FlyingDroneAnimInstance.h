#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FlyingDroneAnimInstance.generated.h"

class UFlyingDroneMovementComponent;

UCLASS(Blueprintable, NonTransient)
class UFlyingDroneAnimInstance : public UAnimInstance
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float Speed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float Strafe;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SpeedStrafeLerpStrength;

private:
    UPROPERTY(Export, Transient)
    UFlyingDroneMovementComponent *MovementComponent;

public:
    UFlyingDroneAnimInstance();
};
