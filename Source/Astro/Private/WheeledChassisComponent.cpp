#include "WheeledChassisComponent.h"
#include "Net/UnrealNetwork.h"

class APhysicalItem;
class UParticleSystemComponent;
class USceneComponent;
class UAstroSaveCustomArchiveProxy;
class AActor;
class UStaticMeshComponent;

void UWheeledChassisComponent::WakePhysics() {
}

void UWheeledChassisComponent::UpdateVehicleEffects(TArray<UParticleSystemComponent*> wheelBlows, TArray<FName> AudioSurfaceTypes) {
}

void UWheeledChassisComponent::SleepPhysics(bool sleepAllConnectedVehicles) {
}

void UWheeledChassisComponent::SetThrottle(const FVector& Direction) {
}

void UWheeledChassisComponent::ServerUpdateUprightFlipComplete_Implementation(bool bReceivedUprightFlipComplete) {
}
bool UWheeledChassisComponent::ServerUpdateUprightFlipComplete_Validate(bool bReceivedUprightFlipComplete) {
    return true;
}

void UWheeledChassisComponent::ServerUpdateIsFlippingUpright_Implementation(bool bReceivedIsFlippingUpright) {
}
bool UWheeledChassisComponent::ServerUpdateIsFlippingUpright_Validate(bool bReceivedIsFlippingUpright) {
    return true;
}

void UWheeledChassisComponent::ServerUpdateClientMotionState_Implementation(FRepWheeledChassisMovement Movement) {
}
bool UWheeledChassisComponent::ServerUpdateClientMotionState_Validate(FRepWheeledChassisMovement Movement) {
    return true;
}

void UWheeledChassisComponent::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void UWheeledChassisComponent::Reset() {
}

void UWheeledChassisComponent::OnWheelHit(USceneComponent* Component, const FVector& Normal, const FHitResult& Hit) {
}

void UWheeledChassisComponent::OnWakePhysics() {
}

void UWheeledChassisComponent::OnRep_UprightFlipComplete() {
}

void UWheeledChassisComponent::OnRep_Movement() {
}

void UWheeledChassisComponent::OnRep_IsFlippingUpright() {
}

void UWheeledChassisComponent::OnActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit) {
}

void UWheeledChassisComponent::AuthorityInitiateUprightFlip(bool initiateFlipOnAllConnectedVehicles) {
}

void UWheeledChassisComponent::AddWheelCollider(APhysicalItem* WheelItem, UStaticMeshComponent* WheelCollider, const FWheelInfo& WheelInfo, bool bUseLinearMotors) {
}

void UWheeledChassisComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UWheeledChassisComponent, ReplicatedChassisMovement);
    DOREPLIFETIME(UWheeledChassisComponent, REP_bIsFlippingUpright);
    DOREPLIFETIME(UWheeledChassisComponent, REP_bUprightFlipComplete);
}

UWheeledChassisComponent::UWheeledChassisComponent() {
    this->MaxNetworkPositionErrorSquared = 40000.00f;
    this->UprightFlipSpeed = 360.00f;
    this->SpringStiffness = 0.01f;
    this->SpringDamping = 500.00f;
    this->PhysicsSleepSpeedThreshold = 20.00f;
    this->PhysicsSleepDelay = 3.00f;
    this->MyActivation = NULL;
    this->Groundedness = 1.00f;
    this->AnyGroundedness = 1.00f;
    this->ImpactThreshold = 500000.00f;
    this->LateralWheelFriction = 3000.00f;
    this->MaxDepenetrationVelocity = 12.00f;
    this->CenterOfMassAdjustment = -50.00f;
    this->LinkedWheelCount = 0;
    this->ItemOwner = NULL;
    this->ControlledMovementCompt = NULL;
    this->PhysicsMovementComp = NULL;
    this->REP_bIsFlippingUpright = false;
    this->REP_bUprightFlipComplete = false;
}

