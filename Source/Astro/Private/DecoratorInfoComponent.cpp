#include "DecoratorInfoComponent.h"
#include "Net/UnrealNetwork.h"

void UDecoratorInfoComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UDecoratorInfoComponent, Planet);
}

UDecoratorInfoComponent::UDecoratorInfoComponent() {
    this->Planet = NULL;
}

