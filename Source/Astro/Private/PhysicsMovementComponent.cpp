#include "PhysicsMovementComponent.h"
#include "Net/UnrealNetwork.h"

UPhysicsMovementComponent::UPhysicsMovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->MaxSteerAngle = 40.00f;
    this->RotationForce = 40.00f;
    this->HeadingStabilization = 0.25f;
    this->SteeringInterpolationSpeed = 2.00f;
    this->SteeringCorrectionResetThresholdAngle = 10.00f;
    this->CrossFriction = 0.00f;
    this->MinMovementStrength = 14000.00f;
    this->MovementStrength = 14000.00f;
    this->Upright = true;
    this->MaxSpeed = 475.00f;
    this->BrakingForceScalar = 1.50f;
    this->RotationDrag = 0.00f;
    this->ForceOffset = 200.00f;
    this->Groundedness = 1.00f;
    this->ForceLocation = NULL;
    this->ReverseThreshold = 0.75f;
    this->ResistanceHillBoost = 2.00f;
    this->TowBoostViaSlot = 0.17f;
    this->MaxBoostedTowCount = 4;
    this->OverallFrictionForceScalar = 800.00f;
    this->ParkingBreakVelocityThreshold = 500.00f;
    this->MinResistanceDampner = 0.62f;
    this->MaxResistanceDampner = 0.25f;
    this->MaxResistanceLevel = 2;
    this->MaxSpeedSteeringAngleScalar = 0.25f;
    this->DrillingSteerAngleReduction = 0.50f;
    this->MinimumSpeedForAnyAirControl = 0.05f;
    this->MaximumSpeedForFullAutoStabilization = 0.25f;
    this->MaximumGroundednessForAnyAirControl = 0.90f;
    this->MinimumGroundednessForFullAutoStabilization = 0.75f;
    this->MinimumGravityAlignmentAngleAnyAutoStabilization = 10.00f;
    this->MaximumGravityAlignmentAngleForFullAutoStabilization = 30.00f;
    this->AutoStabilizationInterpolationRate = 10.00f;
    this->PrimaryManualAirControlRate = 75.00f;
    this->SecondaryManualAirControlRate = 90.00f;
    this->ManualAirControlInterpolationRate = 4.00f;
    this->ManualAirControlSecondaryType = EAirControlSecondaryType::Roll;
    this->RoverTierForTelemetry = ERoverID::UntrackedRover;
    this->StorageComponent = NULL;
    this->CurrentOperatingController = NULL;
    this->REP_ResistanceLevel = 0;
}

void UPhysicsMovementComponent::ServerUpdateClientMovementInput_Implementation(FPhysicsMovementReplicatedInput ClientSteeringInput) {
}
bool UPhysicsMovementComponent::ServerUpdateClientMovementInput_Validate(FPhysicsMovementReplicatedInput ClientSteeringInput) {
    return true;
}

void UPhysicsMovementComponent::Move(APlayerController* Controller, const FVector2D& Value, float Multiplier) {
}

void UPhysicsMovementComponent::HandleVehicleUnmanned(AAstroPlayerController* OldPilot) {
}

void UPhysicsMovementComponent::HandleVehicleManned(AAstroPlayerController* NewPilot) {
}

void UPhysicsMovementComponent::ApplyResistanceLevel() {
}

void UPhysicsMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPhysicsMovementComponent, ReplicatedInput);
    DOREPLIFETIME(UPhysicsMovementComponent, REP_ResistanceLevel);
}


