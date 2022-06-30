#include "RailNetwork.h"
#include "Net/UnrealNetwork.h"
#include "ClickableComponent.h"

class UClickQuery;
class ARailPostStation;
class ASolarBody;

void ARailNetwork::OnRep_RailConnections() {
}

void ARailNetwork::HandleQueryClickable(UClickQuery* Query) {
}

bool ARailNetwork::AuthoritySetStationMarkerForPlanet(ARailPostStation* Station, ASolarBody* stationPlanet, EStationMarkerType marker) {
    return false;
}

ARailPostStation* ARailNetwork::AuthorityGetStationByMarker(ASolarBody* stationPlanet, EStationMarkerType currMarker) const {
    return NULL;
}

EStationMarkerType ARailNetwork::AuthorityGetNextAvailableStationMarkerForPlanet(ASolarBody* stationPlanet, EStationMarkerType currMarker, bool incrementSelection) {
    return EStationMarkerType::Blue;
}

void ARailNetwork::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARailNetwork, RailConnections);
}

ARailNetwork::ARailNetwork() {
    this->MaxRailAttachDistance = 5000.00f;
    this->MinRailAttachDistance = 500.00f;
    this->RailAttachMaxAngleDegrees = 90.00f;
    this->RailDeformVerticalOffset = 65.00f;
    this->MaxCaravanLength = 10;
    this->RailMesh = NULL;
    this->ShortIndicatorMaterial = NULL;
    this->PercentageOfMaxDistanceToShowGoodIndicator = 0.85f;
    this->clickable = CreateDefaultSubobject<UClickableComponent>(TEXT("clickable"));
    this->NextRailConnectionID = 0;
}

