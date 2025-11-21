#include "BiodomePlanter.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "PowerComponent.h"

ABiodomePlanter::ABiodomePlanter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ArmMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArmMesh"));
    this->MovementSpline = CreateDefaultSubobject<USplineComponent>(TEXT("SplineToSlot"));
    this->ClientSeedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClientSeedMesh"));
    this->PowerComponent = CreateDefaultSubobject<UPowerComponent>(TEXT("PowerComponent"));
    this->SeedMovementSpeed = 2000.00f;
    this->bSmoothSeedHeight = true;
    this->ItemTypeWhitelist = NULL;
    this->ReloadDelay = 1.00f;
    this->SeedToPlant = NULL;
    this->InputItemType = NULL;
    this->InputPhysicalItem = NULL;
    this->DrainedAmount = 0;
    this->bIsEnabled = false;
    this->ArmMesh->SetupAttachment(RootComponent);
    this->ClientSeedMesh->SetupAttachment(RootComponent);
}


void ABiodomePlanter::OnSeedSetInTargetSeedSlot(APhysicalItem* Item) {
}

void ABiodomePlanter::OnRep_OnEnableStateChanged() {
}

void ABiodomePlanter::OnItemSetInResourceSlot(APhysicalItem* Item) {
}

void ABiodomePlanter::OnItemSetInOutputSlot(APhysicalItem* Item) {
}

void ABiodomePlanter::OnItemReleasedFromInputSlot(APhysicalItem* Item) {
}

void ABiodomePlanter::Multicast_SpawnSeedMeshOnSpline_Implementation(FSlotReference TargetSlot) {
}


void ABiodomePlanter::AuthorityToggleIsEnabled() {
}

void ABiodomePlanter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABiodomePlanter, SeedToPlant);
    DOREPLIFETIME(ABiodomePlanter, bIsEnabled);
}


