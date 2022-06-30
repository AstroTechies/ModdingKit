#pragma once
#include "CoreMinimal.h"
#include "ECameraDOF.h"
#include "CameraModifierComponent.h"
#include "SimulatedCameraLagModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class USimulatedCameraLagModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    ECameraDOF LagDOF;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxFollowLag;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MinLagVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxLagVelocity;

    USimulatedCameraLagModifierComponent();
};
