#pragma once
#include "CoreMinimal.h"
#include "Camera/CameraTypes.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "CameraRigActor.generated.h"

class UCameraModifierComponent;
class APlayController;
class UCameraComponent;
class USceneComponent;

UCLASS(Blueprintable, Blueprintable)
class ACameraRigActor : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DefaultFieldOfView;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DefaultAspectRatio;

    UPROPERTY(EditAnywhere)
    float CollisionRadius;

    UPROPERTY(EditAnywhere)
    float CollisionRecoveryInterpSpeed;

    UPROPERTY(EditAnywhere)
    bool UsePlanetUp;

    UPROPERTY(EditAnywhere)
    bool IgnoreMultitoolDistance;

    UPROPERTY(EditAnywhere)
    float SpringFactor;

    UPROPERTY(EditAnywhere)
    float DampingRatio;

    UPROPERTY(EditAnywhere)
    float SubstepCount;

    UPROPERTY(EditAnywhere)
    uint8 bAdoptTransitionSourceView : 1;

    UPROPERTY(EditAnywhere)
    uint8 bDistanceAutolock : 1;

    UPROPERTY(EditAnywhere)
    uint8 bHorizontalAutolock : 1;

    UPROPERTY(EditAnywhere)
    uint8 bVerticalAutolock : 1;

    UPROPERTY(EditAnywhere)
    uint8 AutoTickDisable : 1;

    UPROPERTY(EditAnywhere)
    uint8 bShouldAvoidCollisionWhenSwappingRigActor : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    APlayController *OwningController;

    UPROPERTY(Export)
    TArray<UCameraModifierComponent *> Modifiers;

private:
    UPROPERTY()
    AActor *ViewTarget;

    UPROPERTY(Export)
    USceneComponent *ViewSubTarget;

    UPROPERTY(Export, VisibleAnywhere)
    UCameraComponent *ControlledCamera;

    UPROPERTY()
    AActor *LastNearestSolarBody;

public:
    ACameraRigActor();
    UFUNCTION(BlueprintImplementableEvent)
    void OnSetView();

    UFUNCTION(BlueprintImplementableEvent)
    void OnRemoveView();

    UFUNCTION(BlueprintNativeEvent)
    FVector GetViewTargetUp(const AActor *Target);

    UFUNCTION(BlueprintNativeEvent)
    FVector GetViewTargetLocation(const AActor *Target);

    UFUNCTION(BlueprintPure)
    FMinimalViewInfo GetViewInfo();

    UFUNCTION(BlueprintPure)
    AActor *GetTarget();

    UFUNCTION(BlueprintPure)
    UCameraComponent *GetControlledCamera();
};
