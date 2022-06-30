#include "PlacingActuatorConnection.h"
#include "Net/UnrealNetwork.h"

class UPrimitiveComponent;

void APlacingActuatorConnection::ServerPlaceRerouteNode_Implementation(UPrimitiveComponent* Component, const FVector Location, const FVector Normal) {
}
bool APlacingActuatorConnection::ServerPlaceRerouteNode_Validate(UPrimitiveComponent* Component, const FVector Location, const FVector Normal) {
    return true;
}

void APlacingActuatorConnection::RefreshTooltipStatus() {
}

void APlacingActuatorConnection::OnUsePressed() {
}

void APlacingActuatorConnection::OnRep_SourceRerouteNode() {
}

void APlacingActuatorConnection::MulticastPlayBreakAudio_Implementation() {
}

void APlacingActuatorConnection::InitializeSourceSlot() {
}

void APlacingActuatorConnection::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(APlacingActuatorConnection, SourceRerouteNode);
}

APlacingActuatorConnection::APlacingActuatorConnection() {
    this->RerouteNodeMesh = NULL;
    this->ActuatorConnectorPlacementOffset = 1.00f;
    this->RerouteNodePlacementOffset = 2.00f;
    this->MaxActuatorCablesPerSlot = 8;
    this->ActuateFlashCount = 3;
    this->ActuateFlashDuration = 1.00f;
    this->ActuatorPinSlotClass = NULL;
    this->AttachItemTypeBlacklist = NULL;
    this->ConnectorMaterial = NULL;
}

