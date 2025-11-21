#include "BiodomeFertiliser.h"
#include "Net/UnrealNetwork.h"
#include "PowerComponent.h"

ABiodomeFertiliser::ABiodomeFertiliser(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PowerComponent = CreateDefaultSubobject<UPowerComponent>(TEXT("PowerComponent"));
    this->REP_TimeElapsed = 0.00f;
    this->TimeToCheck = 0.00f;
    this->FertiliserBonus = 15.00f;
    this->WaitingTime = 300.00f;
    this->SprinklingTime = 3.00f;
    this->ResourceItemType = NULL;
    this->REP_bHasResources = false;
    this->REP_bIsAttached = false;
    this->CurrentState = EBiodomeFertiliserState::Inactive;
    this->FertiliserParticle = NULL;
}

void ABiodomeFertiliser::SetSprinkleParticle(UParticleSystemComponent* Particle) {
}

void ABiodomeFertiliser::SetResourcesSlotRef(const FSlotReference& SlotRef) {
}

void ABiodomeFertiliser::SetParticleState(bool NewState) {
}

void ABiodomeFertiliser::OnRep_OnCurrentStateChanged() {
}

void ABiodomeFertiliser::AuthorityOnSetResourceInSlot(APhysicalItem* slottedItem) {
}

void ABiodomeFertiliser::AuthorityOnReleasedResourceFromSlot(APhysicalItem* slottedItem) {
}

void ABiodomeFertiliser::AuthorityOnPowerStateChanged(bool bIsPowered) {
}

void ABiodomeFertiliser::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABiodomeFertiliser, REP_TimeElapsed);
    DOREPLIFETIME(ABiodomeFertiliser, REP_bHasResources);
    DOREPLIFETIME(ABiodomeFertiliser, REP_bIsAttached);
    DOREPLIFETIME(ABiodomeFertiliser, CurrentState);
}


