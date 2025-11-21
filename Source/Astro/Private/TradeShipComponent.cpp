#include "TradeShipComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UTradeShipComponent::UTradeShipComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LaunchingPlayController = NULL;
    this->RejectedItemForce = 0.00f;
    this->OrbitalNav = NULL;
    this->ParentDockComponent = NULL;
    this->bManageIndicators = true;
}

void UTradeShipComponent::UpdateIndicators() {
}

void UTradeShipComponent::SlottedItemsContentChanged() {
}

void UTradeShipComponent::SlottedItemContainedTypeChanged(UItemComponent* ItemComponent, TSubclassOf<UItemType> NewItemType) {
}

void UTradeShipComponent::ShipLaunchEnded() {
}

void UTradeShipComponent::ShipLaunched() {
}

void UTradeShipComponent::SetupIndicatorList() {
}

void UTradeShipComponent::OnRep_ParentDockComponent() {
}

void UTradeShipComponent::ItemSetOnResourceSlot(APhysicalItem* Item) {
}

void UTradeShipComponent::ItemReleasedFromResourceSlot(APhysicalItem* Item) {
}

bool UTradeShipComponent::IsDocked() const {
    return false;
}

void UTradeShipComponent::HandleQueryClickable(UClickQuery* Query) {
}

void UTradeShipComponent::AuthoritySnapToOrbitAndLand() {
}

void UTradeShipComponent::AuthoritySetParentDock(UTradeShipDockComponent* dock) {
}

void UTradeShipComponent::AuthorityReturnLaunchedShip() {
}

void UTradeShipComponent::AuthorityLaunchShip(APlayController* NewLaunchingPlayController) {
}

void UTradeShipComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UTradeShipComponent, ParentDockComponent);
}


