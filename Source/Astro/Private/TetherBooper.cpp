#include "TetherBooper.h"
#include "Net/UnrealNetwork.h"
#include "PowerComponent.h"
#include "StorageChassisComponent.h"

ATetherBooper::ATetherBooper(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PowerComponent = CreateDefaultSubobject<UPowerComponent>(TEXT("PowerComponent"));
    this->ChassisComponent = CreateDefaultSubobject<UStorageChassisComponent>(TEXT("StorageChassisComponent"));
    this->TetherItem = NULL;
    this->TetherAttachDistOverride = 2000.00f;
    this->DropDistancePercentage = 0.95f;
    this->ReloadDelay = 0.50f;
    this->ForgetLastTetherDelay = 1.00f;
    this->CurrentCharacterOwner = NULL;
    this->bIsTurnedOn = true;
    this->LastPlacedTether = NULL;
    this->LocalAstroCharacterTetherAttachComp = NULL;
    this->LocalVehicleTetherAttachComp = NULL;
}

void ATetherBooper::UpdateCharacterDrivingState() {
}

void ATetherBooper::ServerTurnOn_Implementation() {
}

void ATetherBooper::ServerTurnOff_Implementation() {
}

void ATetherBooper::ServerToggleEnabledState_Implementation() {
}


void ATetherBooper::OnRep_OnEnableStateChanged() {
}

void ATetherBooper::Multicast_PlayTetherPlacedSFX_Implementation() {
}

void ATetherBooper::AuthorityHandleReleasedFromSlot(bool NewOwner) {
}

void ATetherBooper::AuthorityHandleOnPlacedInSlot() {
}

void ATetherBooper::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ATetherBooper, bIsTurnedOn);
}


