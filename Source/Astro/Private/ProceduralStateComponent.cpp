#include "ProceduralStateComponent.h"
#include "Net/UnrealNetwork.h"

class UTerrainPhysicsComponent;

void UProceduralStateComponent::OnTerrainPhysicsBuriedChanged(UTerrainPhysicsComponent* TerrainPhysics) {
}

void UProceduralStateComponent::OnOwnerSpawnedInSlot() {
}

void UProceduralStateComponent::ApplyStateToOwner() {
}

void UProceduralStateComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UProceduralStateComponent, repState);
}

UProceduralStateComponent::UProceduralStateComponent() {
    this->ProceduralPlacementSaveID = 4294967295;
    this->bRuntimeGenerated = true;
    this->bApplyTintFromAttachParent = false;
}

