#include "Biodome.h"
#include "Components/SplineComponent.h"
#include "Net/UnrealNetwork.h"
#include "PowerComponent.h"

ABiodome::ABiodome(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SeedSectionSpline = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
    this->PowerComponent = CreateDefaultSubobject<UPowerComponent>(TEXT("PowerComponent"));
    this->LitThreshold = 0.20f;
    this->GrowLampStage = 2;
    this->bIsLit = false;
    this->bIsGrowBonusActive = false;
    this->GrowBonus = 1.20f;
    this->DefaultGrowBonus = 0.20f;
    this->GrowLampPowerRequirement = 5.00f;
    this->MaxPowerFufillmentMultiplier = 1.20f;
    this->MissionsManager = NULL;
    this->sunDetector = NULL;
}

void ABiodome::SetSunDetector(USceneComponent* NewSunDetector) {
}

void ABiodome::RemoveBiodomeSection(FBiodomeSection& sectionToRemove) {
}

void ABiodome::OnSeedSetInSlot(APhysicalItem* Seed) {
}

void ABiodome::OnRep_OnLitChanged() const {
}

void ABiodome::OnRep_GrowBonus() const {
}

void ABiodome::OnRep_BiodomeSections() {
}

void ABiodome::OnPlantSpawnedInBiodome(FSlotReference Slot, UBiodomePlantComponent* plant) {
}

void ABiodome::OnPlantHarvested(UBiodomePlantComponent* plant, TArray<APhysicalItem*> Resources) {
}

void ABiodome::OnItemUnemplacedInSlot(APhysicalItem* Item) {
}


void ABiodome::OnItemSetInSlot(APhysicalItem* Item) {
}


void ABiodome::OnItemReleasedFromSlot(APhysicalItem* Item) {
}


void ABiodome::OnItemEmplacedInSlot(APhysicalItem* Item) {
}


void ABiodome::AuthoritySetGrowBonusToBiodome(bool IsActive) {
}

void ABiodome::AddSlotToBiodomeSection(int32 SectionIndex, FSlotReference Slot, USceneComponent* SectionMidpoint, UPrimitiveComponent* canopyCollision) {
}

void ABiodome::AddExtensionToBiodomeSections(FBiodomeSection& sectionToAdd) {
}

void ABiodome::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABiodome, BiodomeSections);
    DOREPLIFETIME(ABiodome, bIsLit);
    DOREPLIFETIME(ABiodome, bIsGrowBonusActive);
    DOREPLIFETIME(ABiodome, GrowBonus);
}


