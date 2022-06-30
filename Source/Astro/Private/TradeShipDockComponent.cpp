#include "TradeShipDockComponent.h"

class APhysicalItem;

void UTradeShipDockComponent::MulticastShipLaunchedToOrbit_Implementation(float LaunchLength) {
}

void UTradeShipDockComponent::MulticastShipLaunchedToDock_Implementation(float LaunchLength) {
}

void UTradeShipDockComponent::MulticastShipArrivedAtDock_Implementation() {
}

bool UTradeShipDockComponent::AcceptsItem(APhysicalItem* Item) const {
    return false;
}

UTradeShipDockComponent::UTradeShipDockComponent() {
    this->bTradeInProgress = false;
    this->LaunchDelay = 30.00f;
}

