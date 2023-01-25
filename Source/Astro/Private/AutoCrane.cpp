#include "AutoCrane.h"
#include "AstroActionComponent.h"
#include "Net/UnrealNetwork.h"
#include "PowerComponent.h"

class AActor;
class APhysicalItem;
class UAnimationAsset;

void AAutoCrane::OnRep_TransferProgress() {
}

void AAutoCrane::OnRep_CraneState() {
}

void AAutoCrane::MulticastPlayOneOffAnimation_Implementation(UAnimationAsset* Anim) {
}

void AAutoCrane::HandleSelfOnReleasedFromSlot(bool NewOwner) {
}

void AAutoCrane::HandleSelfOnPlacedInSlot() {
}

void AAutoCrane::HandleOnSetItem(APhysicalItem* Item) {
}

void AAutoCrane::HandleOnReleaseItem(APhysicalItem* Item) {
}

void AAutoCrane::HandleOnReleasedFromSlot(bool NewOwner) {
}

void AAutoCrane::HandleOnItemDestroyed(AActor* DestroyedActor) {
}

void AAutoCrane::HandleOnHasPowerAvailableChanged(bool HasAvailablePower) {
}

void AAutoCrane::HandleOnFullyEmplaced() {
}

void AAutoCrane::HandleOnFilterSlotChanged(APhysicalItem* Item) {
}

void AAutoCrane::HandleChassisSlotEvent(APhysicalItem* Item) {
}

void AAutoCrane::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAutoCrane, TransferProgress);
    DOREPLIFETIME(AAutoCrane, PowerRatio);
    DOREPLIFETIME(AAutoCrane, TransferStage);
    DOREPLIFETIME(AAutoCrane, bIsTurnedOn);
    DOREPLIFETIME(AAutoCrane, bHasPower);
    DOREPLIFETIME(AAutoCrane, bIsSlotted);
}

AAutoCrane::AAutoCrane() {
    this->PickupCollider = NULL;
    this->DropoffCollider = NULL;
    this->Skeleton = NULL;
    this->TransferItem = NULL;
    this->ActionComponent = CreateDefaultSubobject<UAstroActionComponent>(TEXT("ActionComponent"));
    this->BaseRotationTime = 2.00f;
    this->MaxLowPowerRotationTime = 0.00f;
    this->ItemSlottingTime = 1.00f;
    this->PowerComponent = CreateDefaultSubobject<UPowerComponent>(TEXT("PowerComponent"));
    this->ActivateAnim = NULL;
    this->DeactivateAnim = NULL;
    this->ActivateToHeldAnim = NULL;
    this->ActiveToHeldAnim = NULL;
    this->HeldToInactiveAnim = NULL;
    this->HeldToActiveAnim = NULL;
    this->HeldIdleAnim = NULL;
    this->ActiveIdleAnim = NULL;
    this->GrabHighAnim = NULL;
    this->GrabMedAnim = NULL;
    this->GrabLowAnim = NULL;
    this->PlaceHighAnim = NULL;
    this->PlaceMedAnim = NULL;
    this->PlaceLowAnim = NULL;
    this->GrabLowHeight = 200.00f;
    this->GrabHighHeight = 1000.00f;
    this->TransferProgress = 1.00f;
    this->PowerRatio = 0.00f;
    this->TransferStage = EAutoCraneTransferStage::TransferToPickup;
    this->bIsTurnedOn = false;
    this->bHasPower = false;
    this->bIsSlotted = false;
}

