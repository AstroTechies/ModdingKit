#include "CheatPlinthBase.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

ACheatPlinthBase::ACheatPlinthBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnableItems = NULL;
    this->SpawnableItems_GW = NULL;
    this->SelectionIndex = 0;
    this->CurrentlySelectedItemType = NULL;
    this->ActiveSpawnableItems = NULL;
}

void ACheatPlinthBase::OnRep_SelectionIndex() {
}

void ACheatPlinthBase::IncrementSelectionIndex() {
}

TSubclassOf<UItemType> ACheatPlinthBase::GetCurrentlySelectedItemType() {
    return NULL;
}

void ACheatPlinthBase::DecrementSelectionIndex() {
}

void ACheatPlinthBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACheatPlinthBase, SelectionIndex);
}


