#include "Wreck.h"
#include "Net/UnrealNetwork.h"

AWreck::AWreck(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->destinationLandingPad = NULL;
    this->LoadedAnchorItemTypeClass = NULL;
    this->CurrentState = EWreckState::Unloaded;
    this->bIsInPlanetSelection = false;
    this->bIsOPSpawned = false;
    this->bIsOPComplete = false;
    this->OPPlanetId = EPlanetIdentifier::None;
}

void AWreck::SetPlanetSelection(const bool Enable) {
}

void AWreck::SetOrbitalPlatformComplete(bool isComplete) {
}

void AWreck::SetDestinationLandingPad(APhysicalItem* inDestinationLandingPad) {
}

void AWreck::SetCurrentState(EWreckState NewState) {
}

void AWreck::SetButtonPressedName(const FString& inButtonPressedName) {
}

void AWreck::SetAnchorRestockableState(const FString& AnchorName, const bool isRestockable) {
}

void AWreck::OnSolarBodyClick(ASolarBody* SolarBody) {
}

void AWreck::OnRep_OPPlanetIdChanged() {
}

void AWreck::OnRep_DestinationLandingPadChanged() const {
}

void AWreck::OnRep_ButtonNamePressed() const {
}

void AWreck::OnOPSpawned() {
}

void AWreck::LaunchAnchor(APhysicalItem* inDestinationLandingPad) {
}

void AWreck::HandleOrbitalPlatformSpawn(const EPlanetIdentifier planetID) {
}

void AWreck::HandleOrbitalPlatformExtraStages() {
}

void AWreck::HandleAnchorLoadUnload(const FString& inButtonPressedName) {
}

void AWreck::EjectOrbitalPlatformAnchor() {
}

void AWreck::CheckAnchorCanLaunch(EMegastructureType megastructureType, APhysicalItem* inDestinationLandingPad) {
}

void AWreck::AuthoritySetEntitledMegaStructureActive() {
}


void AWreck::AuthorityOnOPSpawningSequenceBegin() {
}

void AWreck::AddAnchorToRestock(const FString& AnchorName, const bool isRestockable) {
}

void AWreck::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AWreck, ButtonPressedName);
    DOREPLIFETIME(AWreck, destinationLandingPad);
    DOREPLIFETIME(AWreck, CurrentState);
    DOREPLIFETIME(AWreck, bIsOPSpawned);
    DOREPLIFETIME(AWreck, bIsOPComplete);
    DOREPLIFETIME(AWreck, TargetOPSpawnPlanetActor);
    DOREPLIFETIME(AWreck, OPPlanetId);
}


