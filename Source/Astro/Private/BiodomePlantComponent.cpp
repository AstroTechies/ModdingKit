#include "BiodomePlantComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UBiodomePlantComponent::UBiodomePlantComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentLifeStage = EPlantLifeStage::Seedling;
    this->bPlantedInBiodome = false;
    this->bTimerActive = false;
    this->bIsGrowBonusActive = false;
    this->TimeToFullyGrow = 0.00f;
    this->TimeToWilt = 0.00f;
    this->TimeToDie = 0.00f;
    this->EmoteBonus = 5.00f;
    this->TimeElapsed = 0.00f;
    this->TimeToUse = 0.00f;
    this->CurrentGrowRate = 1.00f;
}

void UBiodomePlantComponent::SetTimeToFullyGrow(const int32 newTimeToFullyGrow) {
}

void UBiodomePlantComponent::ResourcesDropped(TArray<APhysicalItem*> physicalItems) {
}

void UBiodomePlantComponent::OnRep_LifeStageChanged() {
}

float UBiodomePlantComponent::GetTimeToDie() const {
    return 0.0f;
}

FSlotReference UBiodomePlantComponent::GetSlotReference() const {
    return FSlotReference{};
}

int32 UBiodomePlantComponent::GetSeedDropCountForStage(EPlantLifeStage lifeStage) const {
    return 0;
}

bool UBiodomePlantComponent::GetPlantedInBiodome() const {
    return false;
}

TArray<TSubclassOf<UItemType>> UBiodomePlantComponent::GetPlantDropForStage(EPlantLifeStage lifeStage) {
    return TArray<TSubclassOf<UItemType>>();
}

EPlantLifeStage UBiodomePlantComponent::GetLifeStage() const {
    return EPlantLifeStage::Seedling;
}

float UBiodomePlantComponent::GetEmoteBonus() const {
    return 0.0f;
}

float UBiodomePlantComponent::GetCurrentActiveTimerRemainingTime() {
    return 0.0f;
}

void UBiodomePlantComponent::AuthoritySetSlotReference(FSlotReference newSlotReference) {
}

bool UBiodomePlantComponent::AuthoritySetPlantedInBiodome(const bool bIsInBiodome) {
    return false;
}

void UBiodomePlantComponent::AuthoritySetLifeStage(EPlantLifeStage newLifeStage) {
}

void UBiodomePlantComponent::AuthoritySetGrowBonus(const ABiodome* Biodome, const bool isBonusActive) {
}

void UBiodomePlantComponent::AddBonusToCurrentActiveTimer(const float bonusToAdd) {
}

void UBiodomePlantComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UBiodomePlantComponent, SlotReference);
    DOREPLIFETIME(UBiodomePlantComponent, CurrentLifeStage);
    DOREPLIFETIME(UBiodomePlantComponent, bPlantedInBiodome);
    DOREPLIFETIME(UBiodomePlantComponent, bIsGrowBonusActive);
    DOREPLIFETIME(UBiodomePlantComponent, CurrentGrowRate);
}


