#include "RailPostStation.h"
#include "Net/UnrealNetwork.h"

class ARailPostStation;
class ASolarBody;




void ARailPostStation::OnCarArrivedAtDestination() {
}

ARailPostStation* ARailPostStation::GetStationFromMarker(EStationMarkerType marker) {
    return NULL;
}

FCalledCarStatus ARailPostStation::GetCalledCarStatus() {
    return FCalledCarStatus{};
}

void ARailPostStation::AuthorityTrySetStationMarker(EStationMarkerType markerType) {
}

void ARailPostStation::AuthorityTrySetDestinationStationForDockedCar(EStationMarkerType destinationMarker) {
}

void ARailPostStation::AuthorityTryRecallCar() {
}

void ARailPostStation::AuthoritySetStopMode(EStationStopState Mode) {
}

void ARailPostStation::AuthoritySetStationMode(EStationStopState State) {
}

void ARailPostStation::AuthorityHandleStationPlanetChanged(ASolarBody* previousPlanet) {
}

EStationMarkerType ARailPostStation::AuthorityGetNextAvailableStationMarker(EStationMarkerType currMarker, bool incrementSelection) {
    return EStationMarkerType::Blue;
}

EStationStopState ARailPostStation::AuthorityGetCurrentStopMode() {
    return EStationStopState::EInert;
}

void ARailPostStation::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARailPostStation, CurrentStationState);
    DOREPLIFETIME(ARailPostStation, CurrentCarSlotConnectionID);
}

ARailPostStation::ARailPostStation() {
    this->OnlyStopIfTerminus = false;
    this->StopMode = EStationStopState::EInert;
    this->CurrentStationState = EStationStopState::EInert;
    this->StationMarker = EStationMarkerType::None;
    this->DestinationStation = NULL;
    this->StoppedCar = NULL;
    this->CurrentCarSlotConnectionID = -1;
}

