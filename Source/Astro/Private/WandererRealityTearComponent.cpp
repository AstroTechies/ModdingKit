#include "WandererRealityTearComponent.h"
#include "Net/UnrealNetwork.h"

UWandererRealityTearComponent::UWandererRealityTearComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->DestroyTimeoutSeconds = 0.00f;
    this->PhotoWidgetClass = NULL;
    this->DeformRadius = 1200.00f;
    this->ActivatingPlayerID = 0;
    this->ProbeItemType = NULL;
}

bool UWandererRealityTearComponent::WasActivatedByPlayer(const APlayerController* Player) {
    return false;
}

void UWandererRealityTearComponent::TakePhoto(APlayerController* inputPlayer) {
}

void UWandererRealityTearComponent::OnRep_ActivatingPlayer() {
}

void UWandererRealityTearComponent::MarkActivated_AuthorityOnly() {
}

void UWandererRealityTearComponent::DisplayPhotoWidget_Multicast_Implementation(AAstroPlayerController* inputPlayer) {
}

void UWandererRealityTearComponent::DisplayPhotoWidget(APlayerController* inputPlayer) {
}

void UWandererRealityTearComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UWandererRealityTearComponent, ActivatingPlayerID);
}


