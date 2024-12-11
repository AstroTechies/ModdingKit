#include "CameraModifierComponent.h"

UCameraModifierComponent::UCameraModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnabled = true;
    this->Priority = 0;
    this->ShutoffLatency = 0.00f;
    this->bDeactivateOnCameraInput = false;
    this->bDeactivateOnCollision = false;
    this->bActiveOnlyWithCameraInput = false;
    this->bActiveOnlyWithCollision = false;
    this->bDeactivateOnClicks = false;
    this->bReactivateOnlyOnMovement = false;
    this->bDeactivateOnlyOnMovement = false;
    this->bScaleWithZoomInput = false;
    this->MaxZoomScale = 0.00f;
    this->MaxZoomClamp = -1.00f;
    this->MinZoomScale = 0.00f;
    this->MinZoomClamp = -1.00f;
    this->LerpSpeed = 0.00f;
    this->PostActivationEasePeriod = 0.00f;
}


