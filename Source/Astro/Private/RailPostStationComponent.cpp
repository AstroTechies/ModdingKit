#include "RailPostStationComponent.h"
#include "Net/UnrealNetwork.h"

URailPostStationComponent::URailPostStationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StopMode = EStationStopState::EInert;
    this->LoadMode = EStationLoadingState::EInert;
    this->CurrentTierMode = EStationTierState::T1;
    this->CurrentInternalConnectionID = -1;
    this->lastStoppedCar = NULL;
}

void URailPostStationComponent::OnRep_StationSettings() {
}

EStationTierState URailPostStationComponent::GetCurrentTierMode() const {
    return EStationTierState::T1;
}

EStationStopState URailPostStationComponent::GetCurrentStopMode() {
    return EStationStopState::EInert;
}

EStationLoadingState URailPostStationComponent::GetCurrentLoadMode() {
    return EStationLoadingState::EInert;
}

void URailPostStationComponent::AuthoritySetTierMode(EStationTierState newTierMode) {
}

void URailPostStationComponent::AuthoritySetStopMode(EStationStopState Mode) {
}

void URailPostStationComponent::AuthoritySetLoadMode(EStationLoadingState Mode) {
}

void URailPostStationComponent::AuthorityDispatchStoppedCar(bool bToLeft) {
}

void URailPostStationComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(URailPostStationComponent, StopMode);
    DOREPLIFETIME(URailPostStationComponent, LoadMode);
    DOREPLIFETIME(URailPostStationComponent, CurrentTierMode);
    DOREPLIFETIME(URailPostStationComponent, CurrentInternalConnectionID);
}


