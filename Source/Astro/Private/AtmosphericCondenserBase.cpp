#include "AtmosphericCondenserBase.h"
#include "Net/UnrealNetwork.h"

void AAtmosphericCondenserBase::OnReplicationDataChanged() {
}

void AAtmosphericCondenserBase::OnRep_LoopProduction() {
}

float AAtmosphericCondenserBase::GetEffectiveProductionDuration() const {
    return 0.0f;
}

void AAtmosphericCondenserBase::AuthoritySetOuputResourceIndex(int32 NewSelectedOutputResourceIndex) {
}

void AAtmosphericCondenserBase::AuthoritySetLoopProductionEnabled(bool LoopProductionIsEnabled) {
}

void AAtmosphericCondenserBase::AuthorityIncrementOuputResourceIndex() {
}

void AAtmosphericCondenserBase::AuthorityDecrementOuputResourceIndex() {
}

void AAtmosphericCondenserBase::AuthorityAttemptToToggleProduction() {
}

void AAtmosphericCondenserBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAtmosphericCondenserBase, ReplicationData);
    DOREPLIFETIME(AAtmosphericCondenserBase, bLoopProduction);
}

AAtmosphericCondenserBase::AAtmosphericCondenserBase() {
    this->BaseProductionRate = 0.00f;
    this->bLoopProduction = false;
    this->CondenserState = EAtmosphericCondenserState::Invalid;
    this->CurrentAtmosphericResourceType = NULL;
    this->CurrentHarvestedAtmosphereAmount = 0.00f;
    this->CurrentPlanet = NULL;
    this->PowerComponent = NULL;
}

