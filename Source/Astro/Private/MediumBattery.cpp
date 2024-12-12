#include "MediumBattery.h"
#include "Net/UnrealNetwork.h"

AMediumBattery::AMediumBattery(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RingMaterial = NULL;
    this->PowerComponent = NULL;
    this->RingMeshComponent = NULL;
    this->CurrentChargePercent = 0.00f;
}

void AMediumBattery::OnRep() {
}

void AMediumBattery::OnChargeLevelChangedEvent(float NewCharge, float ChargeDelta) {
}

void AMediumBattery::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AMediumBattery, CurrentChargePercent);
}


