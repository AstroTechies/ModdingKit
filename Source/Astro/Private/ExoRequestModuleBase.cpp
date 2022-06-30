#include "ExoRequestModuleBase.h"
#include "Net/UnrealNetwork.h"

class APhysicalItem;
class APlayController;
class UTexture;

void AExoRequestModuleBase::UpdateScore() {
}

void AExoRequestModuleBase::UpdateRewardData() {
}




void AExoRequestModuleBase::UpdateActiveItemDrive() {
}

void AExoRequestModuleBase::UpdateActiveEvent() {
}

void AExoRequestModuleBase::OnRep_ExoRequestModuleData() {
}

bool AExoRequestModuleBase::ItemDriveAcceptsItem(APhysicalItem* Item) const {
    return false;
}

bool AExoRequestModuleBase::IsEventActive() const {
    return false;
}

bool AExoRequestModuleBase::HasUnclaimedPhysicalItemRewards(APlayController* PlayController) const {
    return false;
}

UTexture* AExoRequestModuleBase::GetEventInputIcon() const {
    return NULL;
}

void AExoRequestModuleBase::AuthoritySetShipAttachedToDock(bool IsAttached) {
}

void AExoRequestModuleBase::AuthorityDeliverItems() {
}

void AExoRequestModuleBase::ActivatedThroughControlPanel(APlayController* ClickingPlayer) {
}

void AExoRequestModuleBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AExoRequestModuleBase, RequestStatus);
    DOREPLIFETIME(AExoRequestModuleBase, TradeShipComponent);
}

AExoRequestModuleBase::AExoRequestModuleBase() {
    this->CurrentScore = 0;
    this->LaunchByteCost = 0;
    this->ItemDriveProgress = 0;
    this->EventProgressBarMax = 0;
    this->EventProgressBarMin = 0;
    this->RequestStatus = EExoRequestStatus::NoMission;
    this->ActiveItemDrive = NULL;
    this->LocalItemDrive = NULL;
    this->ShipActor = NULL;
    this->TradeShipComponent = NULL;
    this->TradeShipDockComponentItemDrive = NULL;
    this->bCanClaimPendingRewardForFree = false;
}

