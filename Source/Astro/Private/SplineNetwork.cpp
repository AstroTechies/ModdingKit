#include "SplineNetwork.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Net/UnrealNetwork.h"

ASplineNetwork::ASplineNetwork(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = true;
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->MaxSplineAttachDistance = 5000.00f;
    this->MinSplineAttachDistance = 500.00f;
    this->MaxSplineSlottingDistanceSquared = 500000.00f;
    this->MaxFrontBackSlottingDistanceSquared = 1000000.00f;
    this->SplineAttachMaxAngleDegrees = 90.00f;
    this->SplineDeformVerticalOffset = 65.00f;
    this->ConnectionFinalizationDuration = 1.50f;
    this->GaugeEmissiveMin = 0.20f;
    this->GaugeEmissiveMax = 0.80f;
    this->GaugeEmissiveMinColorMultiplier = 0.40f;
    this->MeshSize = 100.00f;
    this->SplinePathwayMesh = NULL;
    this->ConnectionIndicatorMaterial = NULL;
    this->PercentageOfMaxDistanceToShowGoodIndicator = 0.85f;
    this->StopperMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("StopperMeshes"));
    this->NextSplineConnectionID = 0;
    this->StopperMeshes->SetupAttachment(RootComponent);
}

void ASplineNetwork::OnRep_SplineConnections() {
}

void ASplineNetwork::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASplineNetwork, SplineConnections);
}


