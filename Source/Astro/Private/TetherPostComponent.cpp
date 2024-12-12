#include "TetherPostComponent.h"

UTetherPostComponent::UTetherPostComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Placing = false;
    this->Placed = false;
    this->IndicatorAttach = NULL;
    this->PowerComponent = NULL;
    this->AttachComponent = NULL;
    this->IndicatorInstancedMesh = NULL;
    this->LightFader = NULL;
}

void UTetherPostComponent::SetPlacing(bool newPlacing) {
}

void UTetherPostComponent::OnOwnerPlacedInSlot() {
}

void UTetherPostComponent::BreakTethers() {
}

void UTetherPostComponent::AttachTethers(bool fromSave) {
}


