#include "BiodomeHarvester.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "PowerComponent.h"
#include "StorageChassisComponent.h"

ABiodomeHarvester::ABiodomeHarvester(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
    this->ClawMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClawMesh"));
    this->MovementSpline = CreateDefaultSubobject<USplineComponent>(TEXT("MovementSpline"));
    this->StorageChassisComponent = CreateDefaultSubobject<UStorageChassisComponent>(TEXT("StorageChassisComponent"));
    this->PowerComponent = CreateDefaultSubobject<UPowerComponent>(TEXT("PowerComponent"));
    this->HarvesterHoverHeight = 1000.00f;
    this->MovementSpeed = 1500.00f;
    this->WaitInSectionTime = 0.50f;
    this->UpdateSectionWaitTime = 2.00f;
    this->PlantsToHarvestPerTrip = 1;
    this->CurrentState = Inactive;
    this->CurrentSplineLength = 0.00f;
    this->CurrentDistanceAlongSpline = 0.00f;
    this->ClosestBiodomeSectionIndex = -1;
    this->TargetBiodomeSectionIndex = -1;
    this->CurrentDirection = 1;
    this->bClientUpdatingMovement = false;
    this->bIsEnabled = false;
    this->BallMesh->SetupAttachment(RootComponent);
    this->ClawMesh->SetupAttachment(BallMesh);
}


void ABiodomeHarvester::OnStorageStateChanged(APhysicalItem* movedItem) {
}

void ABiodomeHarvester::OnRep_OnEnableStateChanged() {
}

void ABiodomeHarvester::OnPlantSpawnedInBiodome() {
}

void ABiodomeHarvester::OnPlantHarvested(UBiodomePlantComponent* plant, TArray<APhysicalItem*> droppedItems) {
}

void ABiodomeHarvester::OnItemAmountChanged() {
}

void ABiodomeHarvester::Multicast_PlaySFX_Implementation(EBiodomeHarvesterSFX harvesterSFX) {
}

void ABiodomeHarvester::Multicast_MoveDroneToBiodomeSection_Implementation(int8 SectionIndex) {
}

void ABiodomeHarvester::AuthorityToggleIsEnabled() {
}

void ABiodomeHarvester::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABiodomeHarvester, bIsEnabled);
}


