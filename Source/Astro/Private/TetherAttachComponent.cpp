#include "TetherAttachComponent.h"

class UOxygenatorComponent;
class AActor;
class UTetherAttachComponent;

void UTetherAttachComponent::UpdateExplicitNetwork() {
}

void UTetherAttachComponent::TeardownLinkToOxygenator(UOxygenatorComponent* oxygenator) {
}

void UTetherAttachComponent::SetCanAttach(bool NewCanAttach, bool ForceUpdate, bool fromSave) {
}

void UTetherAttachComponent::OnOwnerMotionStateChanged() {
}

void UTetherAttachComponent::OnOwnerDestroy(AActor* Actor) {
}

void UTetherAttachComponent::OnBuiltInOxygenatorOxygenChanged(UOxygenatorComponent* oxygenator) {
}

void UTetherAttachComponent::OnBuiltInOxygenatorDestroyed(UOxygenatorComponent* oxygenator) {
}

ETetherAttachmentType UTetherAttachComponent::GetTetherAttachmentType() {
    return ETetherAttachmentType::Chassis;
}

float UTetherAttachComponent::GetPowerFlowOnVampireConnections() {
    return 0.0f;
}

FVector UTetherAttachComponent::GetAttachPoint(FSlotReference SlotRef, const FVector& InLocation, bool allowConnections) {
    return FVector{};
}

UTetherAttachComponent* UTetherAttachComponent::GetActorTetherAttachComponent(AActor* Actor) {
    return NULL;
}

UTetherAttachComponent* UTetherAttachComponent::GetActorHierarchyTetherAttachComponent(AActor* Actor) {
    return NULL;
}

UTetherAttachComponent::UTetherAttachComponent() {
    this->CanAttach = true;
    this->AttachToConnections = false;
    this->HaveConnectedOxygen = false;
    this->HaveDirectOrConnectedOxygen = false;
    this->TetherAttachDistance = 2500.00f;
    this->Network = NULL;
    this->BuiltInOxygenator = NULL;
    this->TetherAttachmentType = ETetherAttachmentType::Chassis;
    this->bConnectToCharactersOnlyWithoutExternalOxygenator = false;
}

