#include "ShuttleAutomationComponent.h"

UShuttleAutomationComponent::UShuttleAutomationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsAutomatedShuttle = false;
    this->bIsShuttleLost = false;
    this->DestinationPlanetID = EPlanetIdentifier::None;
    this->DestinationPadChannel = ELogisticsComplexChannel::None;
    this->ShuttleSequenceState = EShuttleSequenceState::Landed;
    this->ShuttleAutomationRule = EShuttleAutomationRule::Manual;
    this->ShuttleSlotOrgRule = EShuttleSlotOrgRule::Empty;
    this->LaunchShuttleTimerDelay = 2.00f;
}

void UShuttleAutomationComponent::SetShuttleSlotOrgRule(const EShuttleSlotOrgRule InAutomationRule) {
}

void UShuttleAutomationComponent::SetIsAutomatedShuttle(const bool bInIsAutomatedShuttle) {
}

void UShuttleAutomationComponent::SetDestination(const EPlanetIdentifier inPlanetId, const ELogisticsComplexChannel InPadChannel) {
}

void UShuttleAutomationComponent::SetAutomationRule(const EShuttleAutomationRule InAutomationRule) {
}

void UShuttleAutomationComponent::OnShuttleUnslotted() {
}

void UShuttleAutomationComponent::OnShuttleArrivedAtDestination() {
}

void UShuttleAutomationComponent::OnReleaseItem(APhysicalItem* inItem) {
}

void UShuttleAutomationComponent::MarkShuttleLost() {
}

EShuttleSlotOrgRule UShuttleAutomationComponent::GetShuttleSlotOrgRule() const {
    return EShuttleSlotOrgRule::Empty;
}

EShuttleAutomationRule UShuttleAutomationComponent::GetShuttleAutomationRule() const {
    return EShuttleAutomationRule::Manual;
}

bool UShuttleAutomationComponent::GetIsShuttleLost() const {
    return false;
}

bool UShuttleAutomationComponent::GetIsAutomatedShuttle() const {
    return false;
}

void UShuttleAutomationComponent::BeginAutomationSequence() {
}

void UShuttleAutomationComponent::AuthoritySetParentStorageChassisOverride(UStorageChassisComponent* InParentStorageChassisComponent, const bool bInCanNest) {
}


