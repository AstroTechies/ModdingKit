#include "TetherManager.h"
#include "Net/UnrealNetwork.h"

void ATetherManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ATetherManager, repState);
}

ATetherManager::ATetherManager() {
    this->TetherPostUpdateIndex = 0;
}

