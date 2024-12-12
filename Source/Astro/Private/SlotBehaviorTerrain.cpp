#include "SlotBehaviorTerrain.h"

USlotBehaviorTerrain::USlotBehaviorTerrain() {
    this->AllowBodies = false;
    this->HoverHeight = 0.00f;
    this->PlaceUpright = false;
    this->bDisableCollisionAfterPlace = false;
    this->bHighlightChildrenOfTarget = false;
    this->Parent = NULL;
}

void USlotBehaviorTerrain::OnParentDeformed(const FDeformationParamsT2& params) {
}


