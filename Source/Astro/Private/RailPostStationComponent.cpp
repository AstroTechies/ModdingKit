#include "RailPostStationComponent.h"
#include "Net/UnrealNetwork.h"

void URailPostStationComponent::OnRep_StationSettings() {
}

EStationStopState URailPostStationComponent::GetCurrentStopMode() {
    return EStationStopState::EInert;
}

EStationLoadingState URailPostStationComponent::GetCurrentLoadMode() {
    return EStationLoadingState::EInert;
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
    DOREPLIFETIME(URailPostStationComponent, CurrentInternalConnectionID);
}

URailPostStationComponent::URailPostStationComponent() {
    this->StopMode = EStationStopState::EInert;
    this->LoadMode = EStationLoadingState::EInert;
    this->CurrentInternalConnectionID = -1;
    this->lastStoppedCar = NULL;
}

