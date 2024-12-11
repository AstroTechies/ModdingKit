#include "JetpackItem.h"
#include "Components/InputComponent.h"
#include "FuelConsumerComponent.h"
#include "JetpackMovementOverrideComponent.h"
#include "Net/UnrealNetwork.h"

AJetpackItem::AJetpackItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("Jetpack Input Component"));
    this->FuelConsumerComponent = CreateDefaultSubobject<UFuelConsumerComponent>(TEXT("Fuel Consumer Component"));
    this->JetpackMovementOverride = CreateDefaultSubobject<UJetpackMovementOverrideComponent>(TEXT("Jetpack Movement Override Component"));
    this->AstroCharacter = NULL;
    this->Backpack = NULL;
    this->FuelPortionAmount = 0.00f;
    this->JumpActivationTime = 0.00f;
    this->RemainingFuelStateReplicated = ERemainingFuelState::Plenty;
    this->bJetpackActive = false;
}

void AJetpackItem::SendStateTelemetry() {
}

void AJetpackItem::SendPostRateLimitTelemetry() {
}


void AJetpackItem::OnSlottedItemsChanged() {
}

void AJetpackItem::OnRep_RemainingFuelState() {
}

void AJetpackItem::OnRep_NozzleDirection() {
}

void AJetpackItem::OnRep_JetpackActive() {
}

void AJetpackItem::OnRep_FuelPortionAmount() {
}



void AJetpackItem::OnMovementOverrideTick(float DeltaTime) {
}

void AJetpackItem::OnLanded(TEnumAsByte<EPhysicalSurface> GroundSurface) {
}

void AJetpackItem::OnJumpStopped() {
}

void AJetpackItem::OnJumpStarted() {
}

void AJetpackItem::OnJumpingTick(float DeltaTime) {
}




void AJetpackItem::OnItemSelectionChanged(APhysicalItem* Item) {
}

void AJetpackItem::OnItemDrained() {
}

void AJetpackItem::OnFuelRecipeAmountChanged(float Amount) {
}


void AJetpackItem::OnEndOperation() {
}

void AJetpackItem::OnCreativeFreeFuelChanged(bool State) {
}

void AJetpackItem::OnClientActionReleased() {
}

void AJetpackItem::OnClientActionPressed() {
}

void AJetpackItem::OnBackpackCracked() {
}

void AJetpackItem::OnAuthorityOverrideRemoved() {
}

void AJetpackItem::OnAuthorityOverrideAdded() {
}



void AJetpackItem::HandleRemovedFromSlot(bool NewOwner) {
}

void AJetpackItem::HandlePlacedInSlot() {
}

void AJetpackItem::HandleOnSpawnedInSlot() {
}

void AJetpackItem::HandleFullyEmplaced() {
}

void AJetpackItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AJetpackItem, NozzleDirection);
    DOREPLIFETIME(AJetpackItem, FuelPortionAmount);
    DOREPLIFETIME(AJetpackItem, Guid);
    DOREPLIFETIME(AJetpackItem, RemainingFuelStateReplicated);
    DOREPLIFETIME(AJetpackItem, bJetpackActive);
}


