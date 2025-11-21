#include "LandingPadComponent.h"
#include "Net/UnrealNetwork.h"

ULandingPadComponent::ULandingPadComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LandingPadChannel = ELogisticsComplexChannel::None;
    this->TargetPlanetId = EPlanetIdentifier::None;
    this->ShuttleAutomationRule = EShuttleAutomationRule::Manual;
    this->ShuttleSlotOrgRule = EShuttleSlotOrgRule::Empty;
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

void ULandingPadComponent::SetTargetPlanetId(const EPlanetIdentifier InTargetPlanetId) {
}

void ULandingPadComponent::SetLandingPadShuttleSlotOrgRule(const EShuttleSlotOrgRule InShuttleSlotOrgRule) {
}

void ULandingPadComponent::SetLandingPadShuttleAutomationRule(const EShuttleAutomationRule InShuttleAutomationRule) {
}

void ULandingPadComponent::SetLandingPadChannel(const ELogisticsComplexChannel InLandingPadChannel) {
}

void ULandingPadComponent::OnRep_ShuttleSlotOrgRuleChanged() const {
}

void ULandingPadComponent::OnRep_ShuttleAutomationRuleChanged() const {
}

void ULandingPadComponent::OnRep_PlanetChanged() const {
}

void ULandingPadComponent::OnOwnerItemMotionStateChanged() {
}

void ULandingPadComponent::OnItemSetInLandingPadSlot(APhysicalItem* Item) {
}

void ULandingPadComponent::OnItemRemovedFromLandingPadSlot(APhysicalItem* Item) {
}

bool ULandingPadComponent::IsOccupied() const {
    return false;
}

EPlanetIdentifier ULandingPadComponent::GetTargetPlanetId() const {
    return EPlanetIdentifier::None;
}

EShuttleSlotOrgRule ULandingPadComponent::GetLandingPadShuttleSlotOrgRule() const {
    return EShuttleSlotOrgRule::Empty;
}

EShuttleAutomationRule ULandingPadComponent::GetLandingPadShuttleAutomationRule() const {
    return EShuttleAutomationRule::Manual;
}

ELogisticsComplexChannel ULandingPadComponent::GetLandingPadChannel() const {
    return ELogisticsComplexChannel::None;
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

void ULandingPadComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ULandingPadComponent, LandingPadChannel);
    DOREPLIFETIME(ULandingPadComponent, TargetPlanetId);
    DOREPLIFETIME(ULandingPadComponent, ShuttleAutomationRule);
    DOREPLIFETIME(ULandingPadComponent, ShuttleSlotOrgRule);
}


