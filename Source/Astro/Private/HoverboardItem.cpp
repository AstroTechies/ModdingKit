#include "HoverboardItem.h"
#include "Components/InputComponent.h"
#include "HoverboardMovementOverrideComponent.h"
#include "Net/UnrealNetwork.h"

AHoverboardItem::AHoverboardItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("Hoverboard Input Component"));
    this->PowerComponent = NULL;
    this->HoverboardMovementOverride = CreateDefaultSubobject<UHoverboardMovementOverrideComponent>(TEXT("Hoverboard Movement Override Component"));
    this->AstroCharacter = NULL;
    this->DoubleJumpInputWindow = 0.60f;
    this->bHoverboardActive = false;
}


void AHoverboardItem::OnRep_HoverboardActive() {
}

void AHoverboardItem::OnMovementOverrideTick(float DeltaTime) {
}

void AHoverboardItem::OnJumpStarted() {
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


