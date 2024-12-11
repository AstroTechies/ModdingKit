#include "ControlComponent.h"
#include "Templates/SubclassOf.h"

UControlComponent::UControlComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PlayerActivation = NULL;
    this->UsingActivation = NULL;
    this->IsTool = false;
    this->PassToolToParent = false;
    this->ToolMaxDistance = 1000.00f;
    this->bAppliesToolTierOverride = false;
    this->ToolTierOverride = 0;
    this->MultiToolMode = EMultitoolMode::Multitool;
    this->OnlyTraceTerrain = false;
    this->AttachPing = true;
    this->WidgetComponent = NULL;
    this->AttachOwner = NULL;
    this->controlOwner = NULL;
    this->LastController = NULL;
}

void UControlComponent::SetMoveInputs(APlayerController* Controller, const FVector& Direction) {
}

void UControlComponent::SetControlOwner(UControlComponent* NewControlOwner) {
}

void UControlComponent::PingSymbol(TSubclassOf<UControlSymbol> Symbol) {
}

void UControlComponent::PingObjectSymbolAtLocation(UObject* WorldContextObject, UControlSymbol* Symbol, const FTransform& symbolTransform, UStaticMesh* MeshUsedAsIcon) {
}

void UControlComponent::PingObjectSymbol(UControlSymbol* Symbol) {
}

void UControlComponent::OnChildToolSlotRelease(APhysicalItem* Item) {
}

void UControlComponent::OnChildToolSlotAdd(APhysicalItem* Item) {
}

void UControlComponent::OnActivateChange(bool Enable) {
}

bool UControlComponent::IsPlayerActivated() {
    return false;
}

bool UControlComponent::IsActivated() {
    return false;
}

UControlSymbolEvents* UControlComponent::GetObjectControlSymbolEvents(UControlSymbol* Symbol) {
    return NULL;
}

UControlComponent* UControlComponent::GetMovementTarget() {
    return NULL;
}

UControlSymbolEvents* UControlComponent::GetControlSymbolEvents(TSubclassOf<UControlSymbol> Symbol) {
    return NULL;
}

UControlComponent* UControlComponent::GetActorControlComponent(AActor* Actor) {
    return NULL;
}

UControlComponent* UControlComponent::GetActiveControl() {
    return NULL;
}

void UControlComponent::FireSymbolEvent(TSubclassOf<UControlSymbol> Symbol) {
}

void UControlComponent::FireObjectSymbolEvent(UControlSymbol* Symbol) {
}

UControlSymbolEvents* UControlComponent::EnableObjectControlSymbol(UControlSymbol* Symbol, bool Enable) {
    return NULL;
}

UControlSymbolEvents* UControlComponent::EnableControlSymbol(TSubclassOf<UControlSymbol> Symbol, bool Enable) {
    return NULL;
}


