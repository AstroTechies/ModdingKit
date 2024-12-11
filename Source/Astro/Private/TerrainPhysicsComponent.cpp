#include "TerrainPhysicsComponent.h"
#include "Net/UnrealNetwork.h"

UTerrainPhysicsComponent::UTerrainPhysicsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AutoBlockCamera = false;
    this->CanUnbury = true;
    this->Buried = false;
}

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

void UTerrainPhysicsComponent::OnRep_Buried(bool previousIsBuried) {
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


