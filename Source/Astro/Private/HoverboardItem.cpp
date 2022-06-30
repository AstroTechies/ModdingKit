#include "HoverboardItem.h"
#include "Net/UnrealNetwork.h"
#include "HoverboardMovementOverrideComponent.h"

class APhysicalItem;

void AHoverboardItem::SelfAbortedOverride() {
}


void AHoverboardItem::OnRep_HoverboardActive() {
}

void AHoverboardItem::OnMovementOverrideTick(float DeltaTime) {
}

void AHoverboardItem::OnJumpStarted() {
}

void AHoverboardItem::OnItemSelectionChanged(APhysicalItem* Item) {
}


void AHoverboardItem::OnHasPowerAvailableChanged(bool HasAvailablePower) {
}

void AHoverboardItem::OnEndOperation() {
}

void AHoverboardItem::OnClientActionPressed() {
}

void AHoverboardItem::OnAuthorityOverrideRemoved() {
}

void AHoverboardItem::OnAuthorityOverrideAdded() {
}

void AHoverboardItem::HandleRemovedFromSlot(bool NewOwner) {
}

void AHoverboardItem::HandlePlacedInSlot() {
}

void AHoverboardItem::HandleOnSpawnedInSlot() {
}

bool AHoverboardItem::GetHoverboardActive() {
    return false;
}

FRotator AHoverboardItem::CalculateHoverboardRotation(float minVelocitySize, float maxPitchDegrees, float maxRollDegrees, float maxTurnDegrees, float& outRollDegree) {
    return FRotator{};
}

void AHoverboardItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AHoverboardItem, Guid);
    DOREPLIFETIME(AHoverboardItem, bHoverboardActive);
}

AHoverboardItem::AHoverboardItem() {
    this->PowerComponent = NULL;
    this->HoverboardMovementOverride = CreateDefaultSubobject<UHoverboardMovementOverrideComponent>(TEXT("Hoverboard Movement Override Component"));
    this->AstroCharacter = NULL;
    this->DoubleJumpInputWindow = 0.60f;
    this->bHoverboardActive = false;
}

