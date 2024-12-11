#include "ActorStreamingPowerCableComponent.h"
#include "Net/UnrealNetwork.h"

UActorStreamingPowerCableComponent::UActorStreamingPowerCableComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
}

void UActorStreamingPowerCableComponent::SetDirectionalConnectionSplitRatio(float ratio) {
}

void UActorStreamingPowerCableComponent::OnSelfDestroyed(AActor* Actor) {
}

void UActorStreamingPowerCableComponent::OnRep_VisualizationData() {
}

void UActorStreamingPowerCableComponent::MakeSlotConnection(FSlotReference From, FSlotReference To) {
}

void UActorStreamingPowerCableComponent::Disconnect() {
}

void UActorStreamingPowerCableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorStreamingPowerCableComponent, StreamingPowerCableVisualizationData);
}


