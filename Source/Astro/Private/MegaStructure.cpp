#include "MegaStructure.h"
#include "DamageComponent.h"
#include "Net/UnrealNetwork.h"

AMegaStructure::AMegaStructure(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bRegisterToManager = true;
    this->REP_MegastructureStage = 0;
    this->DamageComponent = CreateDefaultSubobject<UDamageComponent>(TEXT("Damage"));
}

void AMegaStructure::OnTerrainGenerated() {
}

void AMegaStructure::OnRep_MegastructureStageChanged() const {
}

void AMegaStructure::HandlePostSpawn_Implementation() {
}

void AMegaStructure::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AMegaStructure, REP_MegastructureStage);
}


