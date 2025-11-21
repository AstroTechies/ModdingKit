#include "VendingMachinePrinterLogicComponent.h"
#include "Net/UnrealNetwork.h"

UVendingMachinePrinterLogicComponent::UVendingMachinePrinterLogicComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UVendingMachinePrinterLogicComponent::OnSpawnedInSlot() {
}

void UVendingMachinePrinterLogicComponent::OnRep_Blueprints() {
}

void UVendingMachinePrinterLogicComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UVendingMachinePrinterLogicComponent, REP_Blueprints);
}


