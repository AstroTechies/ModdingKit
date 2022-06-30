#include "TerrainPhysicsComponent.h"
#include "Net/UnrealNetwork.h"

class UAstroSaveCustomArchiveProxy;

void UTerrainPhysicsComponent::SetWorldPhysics() {
}

void UTerrainPhysicsComponent::SetPickupPhysics() {
}

void UTerrainPhysicsComponent::SetIsBuried(bool NewIsBuried) {
}

void UTerrainPhysicsComponent::SetBuryPhysics() {
}

void UTerrainPhysicsComponent::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void UTerrainPhysicsComponent::OnRep_Buried() {
}

void UTerrainPhysicsComponent::OnDeformationComplete(const FDeformationParamsT2& deformationParams) {
}

bool UTerrainPhysicsComponent::IsTerrainBuried() {
    return false;
}

bool UTerrainPhysicsComponent::GetIsBuried() const {
    return false;
}

void UTerrainPhysicsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UTerrainPhysicsComponent, Buried);
}

UTerrainPhysicsComponent::UTerrainPhysicsComponent() {
    this->AutoBlockCamera = false;
    this->CanUnbury = true;
    this->Buried = false;
}

