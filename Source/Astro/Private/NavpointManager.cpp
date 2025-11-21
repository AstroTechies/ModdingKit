#include "NavpointManager.h"
#include "Net/UnrealNetwork.h"

UNavpointManager::UNavpointManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UNavpointManager::OnRep_RelevantNavpoints() {
}

void UNavpointManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UNavpointManager, PlayerRelevantNavpoints);
}


