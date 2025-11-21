#include "BallPhysicsMovementComponent.h"
#include "Net/UnrealNetwork.h"

UBallPhysicsMovementComponent::UBallPhysicsMovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SphereRadius = 1.00f;
    this->AngularDampingWhenInert = 50.00f;
    this->CollisionResetDelay = 0.30f;
    this->MaxCollisionRecords = 10;
    this->MinSlopeGrade = 0.70f;
    this->MaxSlopeGrade = 1.00f;
    this->MaxLinearVelocity = 2000.00f;
    this->MaxAngularAcceleration = 2000.00f;
    this->SteeringVelocityDeviationAccelerationBoost = 3.00f;
    this->MaxNetworkPositionErrorSquared = 40000.00f;
    this->JumpImpulse = 750.00f;
    this->MaxJumpImpulseScalar = 1.75f;
    this->MinJumpBoostVelocityThreshold = 250.00f;
    this->JumpRequestExpirationDelay = 0.20f;
    this->bAI_Controlled = false;
    this->AI_DirectionPickingBehavior = EBallAI_DirectionType::Random;
    this->AI_TurnAroundVarianceDegrees = 15.00f;
    this->AI_PreemptiveJumpApproachAngleDotProduct = 0.87f;
    this->AI_StuckRadius = 50.00f;
    this->AI_PreemptiveJumpRadiusScalar = 2.00f;
    this->AI_JumpWhenStuckDelay = 1.00f;
    this->bMovementEnabled = false;
}

void UBallPhysicsMovementComponent::UpdateLocalReceivedMovement() {
}

void UBallPhysicsMovementComponent::ServerUpdateClientMotionState_Implementation(FRepMovement Movement) {
}
bool UBallPhysicsMovementComponent::ServerUpdateClientMotionState_Validate(FRepMovement Movement) {
    return true;
}

void UBallPhysicsMovementComponent::OnRep_BallMovementEnabled() {
}

void UBallPhysicsMovementComponent::OnJumpRequestExpired() {
}

void UBallPhysicsMovementComponent::OnCollisionReset() {
}

void UBallPhysicsMovementComponent::OnBallImpactOccurred(UPrimitiveComponent* Component, const FVector& NormalImpulse, const FHitResult& Hit) {
}

FVector UBallPhysicsMovementComponent::GetEffectiveHitNormal() const {
    return FVector{};
}

bool UBallPhysicsMovementComponent::GetCollisionActive() const {
    return false;
}

bool UBallPhysicsMovementComponent::GetBallMovementEnabled() const {
    return false;
}

void UBallPhysicsMovementComponent::EnableBallMovement() {
}

void UBallPhysicsMovementComponent::DisableBallMovement() {
}

void UBallPhysicsMovementComponent::CollectReplicatedMovement() {
}

void UBallPhysicsMovementComponent::ApplyCorrectionToSimulation() {
}

void UBallPhysicsMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UBallPhysicsMovementComponent, bMovementEnabled);
    DOREPLIFETIME(UBallPhysicsMovementComponent, ReplicatedBallMovement);
}


