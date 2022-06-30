#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "UObject/NoExportTypes.h"
#include "OnRoverWheelSteerAnimStateChangedDelegate.h"
#include "WheeledChassisAnimInstance.generated.h"

class UWheeledChassisComponent;
class UPhysicsMovementComponent;

UCLASS(Blueprintable, NonTransient)
class UWheeledChassisAnimInstance : public UAnimInstance
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector Wheel1Left;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector Wheel1Right;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector Wheel2Left;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector Wheel2Right;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector Wheel3Left;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector Wheel3Right;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector Wheel4Left;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector Wheel4Right;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FRotator WheelSteerForward;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FRotator WheelSteerBackward;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FRotator WheelHalfSteerForward;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FRotator WheelHalfSteerBackward;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FRotator WheelSteerMiddle;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FRotator WheelRotation;

    UPROPERTY(EditAnywhere)
    float WheelRotationScale;

    UPROPERTY(EditAnywhere)
    float WheelMaxSteerAngle;

    UPROPERTY(EditAnywhere)
    float WheelColliderToHubInwardPositionOffset;

protected:
    UPROPERTY(BlueprintAssignable)
    FOnRoverWheelSteerAnimStateChanged OnRoverWheelSteerAnimStateChanged;

    UPROPERTY(EditDefaultsOnly)
    FVector Wheel1LeftDefaultLocation;

    UPROPERTY(EditDefaultsOnly)
    FVector Wheel1RightDefaultLocation;

    UPROPERTY(EditDefaultsOnly)
    FVector Wheel2LeftDefaultLocation;

    UPROPERTY(EditDefaultsOnly)
    FVector Wheel2RightDefaultLocation;

    UPROPERTY(EditDefaultsOnly)
    FVector Wheel3LeftDefaultLocation;

    UPROPERTY(EditDefaultsOnly)
    FVector Wheel3RightDefaultLocation;

    UPROPERTY(EditDefaultsOnly)
    FVector Wheel4LeftDefaultLocation;

    UPROPERTY(EditDefaultsOnly)
    FVector Wheel4RightDefaultLocation;

private:
    UPROPERTY(Export, Transient)
    UWheeledChassisComponent *ChassisComponent;

    UPROPERTY(Export, Transient)
    UPhysicsMovementComponent *MovementComponent;

public:
    UWheeledChassisAnimInstance();
};
