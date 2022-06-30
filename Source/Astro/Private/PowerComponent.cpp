#include "PowerComponent.h"
#include "Net/UnrealNetwork.h"

class USceneComponent;
class UPowerComponent;
class AActor;

void UPowerComponent::SetSuppliedVisibility(USceneComponent* Component) {
}

void UPowerComponent::SetNetPowerOutput(float NewNetPowerOutput) {
}

bool UPowerComponent::SetEnabled(bool NewIsEnabled) {
    return false;
}

float UPowerComponent::SetCurrentCharge(float Charge) {
    return 0.0f;
}

FText UPowerComponent::ReportPowerComponent() {
    return FText::GetEmpty();
}

void UPowerComponent::PingIndicator(bool Discharging) {
}

void UPowerComponent::OnRep_ReplicationData() {
}

bool UPowerComponent::IsSupplied() const {
    return false;
}

bool UPowerComponent::IsPowered() const {
    return false;
}

bool UPowerComponent::IsFullySupplied() const {
    return false;
}

bool UPowerComponent::IsFullyPowered() const {
    return false;
}

bool UPowerComponent::IsFullyCharged() const {
    return false;
}

float UPowerComponent::IsEnabled() {
    return 0.0f;
}

bool UPowerComponent::IsAnyPowerAvailable() const {
    return false;
}

void UPowerComponent::HandleFreePowerChanged(bool NewFreePowerChanged) {
}

float UPowerComponent::GetNetPowerOutput() {
    return 0.0f;
}

float UPowerComponent::GetCurrentCharge() const {
    return 0.0f;
}

void UPowerComponent::DrainBattery(float Speed) {
}

bool UPowerComponent::CanPowerFor(float Amount) const {
    return false;
}

bool UPowerComponent::CanPower() const {
    return false;
}

float UPowerComponent::AddCharge(float Charge) {
    return 0.0f;
}

UPowerComponent* UPowerComponent::ActorPowerComponent(AActor* Actor) {
    return NULL;
}

void UPowerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPowerComponent, ReplicatedState);
}

UPowerComponent::UPowerComponent() {
    this->bIsGenerator = false;
    this->bIsLoad = false;
    this->ShouldReplicate = false;
    this->SelfDischargeOnly = false;
    this->IsIntegratedBattery = false;
    this->QueryPower = false;
    this->Enabled = true;
    this->StorageCapacity = 0.00f;
    this->DischargeRate = 0.00f;
    this->ChargeRate = 0.00f;
    this->CurrentChargeRate = 0.00f;
    this->NetActualLoad = 0.00f;
    this->CurrentAvailablePower = 0.00f;
    this->CurrentMaximumLoad = 0.00f;
    this->DiscreteDelta = 0.00f;
    this->UIComponent = NULL;
    this->WhilePowered = NULL;
    this->WhileGeneratingPower = NULL;
    this->WhileDischarging = NULL;
    this->WhileFullCharge = NULL;
    this->WhileEmptyCharge = NULL;
    this->WhileFullyPowered = NULL;
    this->PowerID = 0;
    this->NetPowerOutput = 0.00f;
    this->CurrentCharge = 0.00f;
}

