#include "NavpointManager.h"
#include "Net/UnrealNetwork.h"

void UNavpointManager::OnRep_Navpoints() {
}

void UNavpointManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UNavpointManager, Navpoints);
}

UNavpointManager::UNavpointManager() {
}

