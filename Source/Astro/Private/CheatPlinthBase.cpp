#include "CheatPlinthBase.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class UItemType;

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

ACheatPlinthBase::ACheatPlinthBase() {
    this->SpawnableItems = NULL;
    this->SelectionIndex = 0;
    this->CurrentlySelectedItemType = NULL;
}

