#include "TradeShipDockComponent.h"

UTradeShipDockComponent::UTradeShipDockComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->bTradeInProgress = false;
    this->LaunchDelay = 30.00f;
}

void UTradeShipDockComponent::MulticastShipLaunchedToOrbit_Implementation(float LaunchLength) {
}

void UTradeShipDockComponent::MulticastShipLaunchedToDock_Implementation(float LaunchLength) {
}

void UTradeShipDockComponent::MulticastShipArrivedAtDock_Implementation() {
}

bool UTradeShipDockComponent::AcceptsItem(APhysicalItem* Item) const {
    return false;
}


