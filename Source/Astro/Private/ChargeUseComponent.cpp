#include "ChargeUseComponent.h"
#include "Net/UnrealNetwork.h"

UChargeUseComponent::UChargeUseComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DischargeRate = 1.00f;
    this->canUse = false;
    this->Usable = false;
    this->Discharging = false;
    this->DischargeProgress = 0.00f;
    this->PowerComponent = NULL;
}

void UChargeUseComponent::UseCharge() {
}

void UChargeUseComponent::UpdateCanUse() {
}

void UChargeUseComponent::SetUsable(bool newUsable) {
}

void UChargeUseComponent::OnRep_State() {
}

void UChargeUseComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UChargeUseComponent, canUse);
    DOREPLIFETIME(UChargeUseComponent, Discharging);
    DOREPLIFETIME(UChargeUseComponent, DischargeProgress);
}


