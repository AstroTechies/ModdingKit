#include "PlayerToolComponent.h"
#include "Net/UnrealNetwork.h"

class AActor;

void UPlayerToolComponent::OnRep_Activated() {
}

void UPlayerToolComponent::OnControlDeactivate() {
}

void UPlayerToolComponent::OnControlActivate() {
}

void UPlayerToolComponent::OnActorClicked(AActor* Actor, FKey Key) {
}

void UPlayerToolComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPlayerToolComponent, m_activated);
}

UPlayerToolComponent::UPlayerToolComponent() {
    this->UnencapsulateChildrenWhileActive = false;
    this->HeldTool = false;
    this->AttachLocationComponent = NULL;
    this->TableComponent = NULL;
    this->CrackedValue = 0.00f;
    this->m_activated = false;
}

