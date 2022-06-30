#include "ActorStreamingPowerNodeComponent.h"
#include "Net/UnrealNetwork.h"

void UActorStreamingPowerNodeComponent::OnRep_VisualizationData() {
}

void UActorStreamingPowerNodeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorStreamingPowerNodeComponent, PowerVisualizationDataReplicated);
}

UActorStreamingPowerNodeComponent::UActorStreamingPowerNodeComponent() {
    this->CanPropagateDirectionalConnectionSwaps = false;
    this->bSkipPacketLoopProtectionCheck = false;
}

