#include "CursorMarginControlModifierComponent.h"

UCursorMarginControlModifierComponent::UCursorMarginControlModifierComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ControlledDOF = ECameraDOF::Yaw;
    this->bInverted = false;
    this->LeftMargin = 0.20f;
    this->RightMargin = 0.80f;
    this->TopMargin = 0.00f;
    this->BottomMargin = 1.00f;
    this->MaxSpeed = 180.00f;
    this->MaxTargetValue = 1000.00f;
    this->MinTargetValue = -1000.00f;
    this->ControlMask = ECameraControlMask::All;
}


