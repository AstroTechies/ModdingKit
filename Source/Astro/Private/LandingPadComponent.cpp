#include "LandingPadComponent.h"

class APhysicalItem;

void ULandingPadComponent::OnOwnerItemMotionStateChanged() {
}

void ULandingPadComponent::OnItemSetInLandingPadSlot(APhysicalItem* Item) {
}

void ULandingPadComponent::OnItemRemovedFromLandingPadSlot(APhysicalItem* Item) {
}

bool ULandingPadComponent::IsOccupied() const {
    return false;
}

bool ULandingPadComponent::CanDeploy() const {
    return false;
}

bool ULandingPadComponent::CanCheckObstruction() const {
    return false;
}

void ULandingPadComponent::AuthorityTeardownLandingPad() {
}

bool ULandingPadComponent::AuthorityDeployLandingPad() {
    return false;
}

ULandingPadComponent::ULandingPadComponent() {
    this->PlanetMarkerType = NULL;
    this->MaximumOperationalTilt = 15.00f;
    this->SkyObstructionTestRadius = 300.00f;
    this->PlanetMarker = NULL;
    this->OwnerItem = NULL;
    this->bDeployed = false;
    this->bSkipOrientationValidation = false;
    this->bAutomaticDeployment = false;
    this->bSkyObstructed = false;
}

