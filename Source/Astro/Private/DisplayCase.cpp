#include "DisplayCase.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

ADisplayCase::ADisplayCase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DisplayCaseDataAsset = NULL;
    this->MaxNumOfShelves = 4;
}

void ADisplayCase::OnRep_UniqueSlottedItems() const {
}

void ADisplayCase::OnRep_CurrentDisplayData() const {
}

void ADisplayCase::OnItemSetInShelf(APhysicalItem* inItem, ADisplayCaseShelf* inShelf) {
}

void ADisplayCase::OnItemReleasedFromShelf(APhysicalItem* inItem) {
}

TArray<ELRDType> ADisplayCase::GetUniqueSlottedLRDTypes() const {
    return TArray<ELRDType>();
}

TArray<TSubclassOf<UItemType>> ADisplayCase::GetUniqueSlottedItems() const {
    return TArray<TSubclassOf<UItemType>>();
}

ECollectionReward ADisplayCase::GetCurrentCollectionReward() const {
    return ECollectionReward::None;
}

FCollectionData ADisplayCase::GetCollectionData() const {
    return FCollectionData{};
}

bool ADisplayCase::CheckIfMuseumIsOnCurrentPlanet() {
    return false;
}

void ADisplayCase::AuthorityTrySetBuffRewardInactive() {
}

void ADisplayCase::AuthorityToggleBuffRewardActive() {
}

void ADisplayCase::AuthorityRemoveShelf(APhysicalItem* inPhysicalItem) {
}

void ADisplayCase::AuthorityAddShelf(APhysicalItem* inPhysicalItem) {
}

void ADisplayCase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADisplayCase, CurrentDisplayData);
    DOREPLIFETIME(ADisplayCase, UniqueSlottedItems);
    DOREPLIFETIME(ADisplayCase, UniqueSlottedLRDTypes);
}


