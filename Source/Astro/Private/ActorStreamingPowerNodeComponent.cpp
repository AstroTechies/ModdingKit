#include "ActorStreamingPowerNodeComponent.h"
#include "Net/UnrealNetwork.h"

UActorStreamingPowerNodeComponent::UActorStreamingPowerNodeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CanPropagateDirectionalConnectionSwaps = false;
    this->bSkipPacketLoopProtectionCheck = false;
}

void UActorStreamingPowerNodeComponent::OnRep_VisualizationData() {
}

void UActorStreamingPowerNodeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorStreamingPowerNodeComponent, PowerVisualizationDataReplicated);
}


