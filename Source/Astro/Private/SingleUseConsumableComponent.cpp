#include "SingleUseConsumableComponent.h"
#include "Net/UnrealNetwork.h"

USingleUseConsumableComponent::USingleUseConsumableComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bHasBeenConsumed = false;
    this->bSuppressUseAfterConsumption = true;
    this->bSuppressExamineAfterConsumption = true;
    this->ConsumptionVFX = NULL;
    this->VFXSpawnScale = 1.00f;
}

void USingleUseConsumableComponent::OnRep_HasBeenConsumed(bool bWasConsumed) {
}

void USingleUseConsumableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(USingleUseConsumableComponent, bHasBeenConsumed);
}


