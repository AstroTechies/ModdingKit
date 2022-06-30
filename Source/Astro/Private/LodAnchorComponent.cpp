#include "LodAnchorComponent.h"
#include "Net/UnrealNetwork.h"

bool ULodAnchorComponent::UpdateInternal(const FVector& NewPosition) {
    return false;
}

void ULodAnchorComponent::ToggleActivated() {
}

void ULodAnchorComponent::ShowPreviz(bool show) {
}

void ULodAnchorComponent::SetBeaconVisibility(bool Enabled) {
}

void ULodAnchorComponent::SetActivated(bool makeActive, bool ForceUpdate) {
}

void ULodAnchorComponent::ServerChangeActivated_Implementation(bool makeActive, bool ForceUpdate) {
}
bool ULodAnchorComponent::ServerChangeActivated_Validate(bool makeActive, bool ForceUpdate) {
    return true;
}

void ULodAnchorComponent::OnReplicated_IsAnchored() {
}

void ULodAnchorComponent::HandleDeformed(const FDeformationParamsT2& params) {
}

void ULodAnchorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ULodAnchorComponent, IsAnchored);
}

ULodAnchorComponent::ULodAnchorComponent() {
    this->IsAnchored = ELodAnchorState::Invalid;
    this->bIsActivated = false;
}

