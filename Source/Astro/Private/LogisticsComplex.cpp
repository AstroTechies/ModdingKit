#include "LogisticsComplex.h"
#include "Net/UnrealNetwork.h"

ALogisticsComplex::ALogisticsComplex(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bLogistcsComplexSetupComplete = false;
}

void ALogisticsComplex::RecallLostShuttle(const ULandingPadComponent* inLandingPad) {
}

void ALogisticsComplex::OnRep_LogistcsComplexSetupComplete() const {
}

EPlanetIdentifier ALogisticsComplex::IncrementSelectedPlanetIndex_Helper(const int32 inCurrentIndex, const TArray<bool>& inPlanetsWithLogisticsComplex, const TArray<EPlanetIdentifier>& inPlanetIdentifierList) {
    return EPlanetIdentifier::None;
}

bool ALogisticsComplex::GetIsLogisticsComplexReady() const {
    return false;
}

EPlanetIdentifier ALogisticsComplex::DecrementSelectedPlanetIndex_Helper(const int32 inCurrentIndex, const TArray<bool>& inPlanetsWithLogisticsComplex, const TArray<EPlanetIdentifier>& inPlanetIdentifierList) {
    return EPlanetIdentifier::None;
}

void ALogisticsComplex::CallShuttle(const ULandingPadComponent* inLandingPad) {
}

void ALogisticsComplex::AuthorityUnbindEventsFromSavedLandingPad() {
}

void ALogisticsComplex::AuthoritySetLogisticsComplexReady() {
}

void ALogisticsComplex::AuthorityOnTargetShuttleRemovedFromOtherComplex(APhysicalItem* inItem) {
}

void ALogisticsComplex::AuthorityOnShuttleDockedAtOtherComplex(APhysicalItem* inItem) {
}

bool ALogisticsComplex::AuthorityBindToDesiredLandingPadAndCheckForShuttle(const EPlanetIdentifier inPlanetId, const ELogisticsComplexChannel InChannel) {
    return false;
}

void ALogisticsComplex::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ALogisticsComplex, bLogistcsComplexSetupComplete);
}


