#include "LevelingBlockComponent.h"
#include "Net/UnrealNetwork.h"

ULevelingBlockComponent::ULevelingBlockComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StampSize = 230.00f;
    this->PreviewMesh = NULL;
    this->BehaviorTerrain = NULL;
    this->particles = NULL;
    this->VisibilityPlaced = false;
}

void ULevelingBlockComponent::SetPreviewVisibility(bool IsVisible, ELevelingBlockVizSource sourceId) {
}

void ULevelingBlockComponent::OnReplicated_VisibilitySourceMask() {
}

void ULevelingBlockComponent::MulticastStartLeveling_Implementation() {
}

void ULevelingBlockComponent::MulticastPlayOrStopFX_Implementation(bool bPlayParticles, bool PlaySound, bool isSuccess, bool playRespawnSound) {
}

void ULevelingBlockComponent::CancelOperation(bool forceStopParticles) {
}

bool ULevelingBlockComponent::AddTrueFlatStump() {
    return false;
}

void ULevelingBlockComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ULevelingBlockComponent, VisibilityPlaced);
}


