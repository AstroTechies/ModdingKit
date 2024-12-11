#include "CameraFacingWidgetComponent.h"

UCameraFacingWidgetComponent::UCameraFacingWidgetComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bWindowFocusable = false;
    this->WorldPositioningAnchor = NULL;
}


