#include "TradeShipDockComponent_ItemType.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UTradeShipDockComponent_ItemType::UTradeShipDockComponent_ItemType(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ItemType = NULL;
}

void UTradeShipDockComponent_ItemType::OnRep_ItemType() {
}

void UTradeShipDockComponent_ItemType::AuthoritySetItemType(TSubclassOf<UItemType> NewItemType) {
}

void UTradeShipDockComponent_ItemType::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UTradeShipDockComponent_ItemType, ItemType);
}


