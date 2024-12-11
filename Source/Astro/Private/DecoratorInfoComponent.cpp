#include "DecoratorInfoComponent.h"
#include "Net/UnrealNetwork.h"

UDecoratorInfoComponent::UDecoratorInfoComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->Planet = NULL;
}

void UDecoratorInfoComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UDecoratorInfoComponent, Planet);
}


