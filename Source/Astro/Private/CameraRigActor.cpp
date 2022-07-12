#include "CameraRigActor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=CameraComponent -FallbackName=CameraComponent

class AActor;



FVector ACameraRigActor::GetViewTargetUp_Implementation(const AActor* Target) {
    return FVector{};
}

FVector ACameraRigActor::GetViewTargetLocation_Implementation(const AActor* Target) {
    return FVector{};
}

FMinimalViewInfo ACameraRigActor::GetViewInfo() {
    return FMinimalViewInfo{};
}

AActor* ACameraRigActor::GetTarget() {
    return NULL;
}

UCameraComponent* ACameraRigActor::GetControlledCamera() {
    return NULL;
}

ACameraRigActor::ACameraRigActor() {
    this->DefaultFieldOfView = 90.00f;
    this->DefaultAspectRatio = 1.33f;
    this->CollisionRadius = 10.00f;
    this->CollisionRecoveryInterpSpeed = 0.90f;
    this->CollisionRecoveryRampUpDuration = 3.00f;
    this->CollisionRecoveryDelay = 0.00f;
    this->CollisionImmediateRecoveryRetractThrehsold = 0.00f;
    this->bForceManualZoomInwardWhenColliding = true;
    this->MinimumForcedZoom = 0.20f;
    this->CollisionZoomRetractInterpSpeed = 0.90f;
    this->CollisionZoomRetractRampUpDuration = 3.00f;
    this->CollisionZoomRetractDelay = 0.75f;
    this->UsePlanetUp = true;
    this->IgnoreMultitoolDistance = false;
    this->SpringFactor = 100.00f;
    this->DampingRatio = 1.00f;
    this->SubstepCount = 1.00f;
    this->bAdoptTransitionSourceView = true;
    this->bDistanceAutolock = false;
    this->bHorizontalAutolock = false;
    this->bVerticalAutolock = false;
    this->AutoTickDisable = true;
    this->bShouldAvoidCollisionWhenSwappingRigActor = false;
    this->OwningController = NULL;
    this->ViewTarget = NULL;
    this->ViewSubTarget = NULL;
    this->ControlledCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("RigCamera"));
    this->LastNearestSolarBody = NULL;
}

