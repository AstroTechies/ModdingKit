#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraModifierComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class UCameraModifierComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bEnabled : 1;

    UPROPERTY(EditAnywhere)
    uint8 Priority;

    UPROPERTY(EditAnywhere)
    float ShutoffLatency;

    UPROPERTY(EditAnywhere)
    uint8 bDeactivateOnCameraInput : 1;

    UPROPERTY(EditAnywhere)
    uint8 bDeactivateOnCollision : 1;

    UPROPERTY(EditAnywhere)
    uint8 bActiveOnlyWithCameraInput : 1;

    UPROPERTY(EditAnywhere)
    uint8 bActiveOnlyWithCollision : 1;

    UPROPERTY(EditAnywhere)
    uint8 bDeactivateOnClicks : 1;

    UPROPERTY(EditAnywhere)
    uint8 bReactivateOnlyOnMovement : 1;

    UPROPERTY(EditAnywhere)
    uint8 bDeactivateOnlyOnMovement : 1;

    UPROPERTY(EditAnywhere)
    uint8 bScaleWithZoomInput : 1;

    UPROPERTY(EditAnywhere)
    float MaxZoomScale;

    UPROPERTY(EditAnywhere)
    float MaxZoomClamp;

    UPROPERTY(EditAnywhere)
    float MinZoomScale;

    UPROPERTY(EditAnywhere)
    float MinZoomClamp;

    UPROPERTY(EditAnywhere)
    float LerpSpeed;

    UPROPERTY(EditAnywhere)
    float PostActivationEasePeriod;

    UCameraModifierComponent();
};
