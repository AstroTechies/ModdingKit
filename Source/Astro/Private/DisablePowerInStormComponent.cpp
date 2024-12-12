#include "DisablePowerInStormComponent.h"
#include "Net/UnrealNetwork.h"

UDisablePowerInStormComponent::UDisablePowerInStormComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsInStorm = false;
}

bool UDisablePowerInStormComponent::IsPowerDisabled() {
    return false;
}

void UDisablePowerInStormComponent::AuthoritySetIsInStorm(bool isInStorm) {
}

void UDisablePowerInStormComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UDisablePowerInStormComponent, bIsInStorm);
}


