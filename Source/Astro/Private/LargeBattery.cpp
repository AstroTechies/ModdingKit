#include "LargeBattery.h"
#include "Net/UnrealNetwork.h"

ALargeBattery::ALargeBattery(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PowerBarMaterial = NULL;
    this->PowerBarFillInterpolationRate = 0.50f;
    this->PowerComponent = NULL;
    this->CurrentChargePercent = 0.00f;
}

void ALargeBattery::UpdateView() {
}

void ALargeBattery::OnRep_CurrentChargePercent() {
}

void ALargeBattery::OnChargeLevelChangedEvent(float NewCharge, float ChargeDelta) {
}

void ALargeBattery::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ALargeBattery, CurrentChargePercent);
}


