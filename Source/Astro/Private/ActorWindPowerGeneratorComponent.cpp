#include "ActorWindPowerGeneratorComponent.h"
#include "Net/UnrealNetwork.h"

UActorWindPowerGeneratorComponent::UActorWindPowerGeneratorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DebugLineWindVectorVerticalOffset = 150.00f;
    this->DebugLineWindDirectionScale = 150.00f;
    this->MinPowerOutput = 0.00f;
    this->MaxPowerOutput = 2.00f;
    this->WindSpeedAnimationInterpolationStrength = 8.00f;
    this->WindDirAnimationInterpolationStrength = 8.00f;
}

void UActorWindPowerGeneratorComponent::OnRep_AnimatedWindVec() {
}

void UActorWindPowerGeneratorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorWindPowerGeneratorComponent, WindPowerAnimationData);
}


