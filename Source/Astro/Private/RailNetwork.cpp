#include "RailNetwork.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=InstancedStaticMeshComponent -FallbackName=InstancedStaticMeshComponent
#include "ClickableComponent.h"
#include "Net/UnrealNetwork.h"

class UClickQuery;
class URailPostComponent;

void ARailNetwork::OnRep_RailConnections() {
}

void ARailNetwork::MulticastStartConnectionFinalization_Implementation(int32 ConnectionId, URailPostComponent* nearPost, URailPostComponent* farPost) {
}

void ARailNetwork::HandleQueryClickable(UClickQuery* Query) {
}

void ARailNetwork::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARailNetwork, RailConnections);
}

ARailNetwork::ARailNetwork() {
    this->MaxRailAttachDistance = 5000.00f;
    this->MinRailAttachDistance = 500.00f;
    this->MaxPostSlottingDistanceSquared = 500000.00f;
    this->MaxCarSlottingDistanceSquared = 1000000.00f;
    this->RailAttachMaxAngleDegrees = 90.00f;
    this->RailDeformVerticalOffset = 65.00f;
    this->MaxCaravanLength = 10;
    this->NumCapsulesPerRailSpline = 6;
    this->RailSplineCapsuleRadius = 70.00f;
    this->ConnectionFinalizationDuration = 1.50f;
    this->GaugeEmissivePulseFailedTime = 1.50f;
    this->GaugeEmissiveSlowBlinksPerSecond = 0.50f;
    this->GaugeEmissiveFastBlinksPerSecond = 2.00f;
    this->GaugeEmissiveSuperFastBlinksPerSecond = 4.00f;
    this->GaugeEmissiveMin = 0.20f;
    this->GaugeEmissiveMax = 0.80f;
    this->GaugeEmissiveMinColorMultiplier = 0.40f;
    this->RailMesh = NULL;
    this->ConnectionIndicatorMaterial = NULL;
    this->PercentageOfMaxDistanceToShowGoodIndicator = 0.85f;
    this->clickable = CreateDefaultSubobject<UClickableComponent>(TEXT("clickable"));
    this->StopperMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("StopperMeshes"));
    this->NextRailConnectionID = 0;
}

