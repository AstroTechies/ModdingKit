#include "AstroCharacterMovementComponent.h"

class UPrimitiveComponent;
class UAstroCharacterMovementOverrideComponent;
class AAstroCharacter;

void UAstroCharacterMovementComponent::ZeroVelocity() {
}

void UAstroCharacterMovementComponent::SetUpdatedComponent(UPrimitiveComponent* NewUpdatedComponent) {
}

void UAstroCharacterMovementComponent::SetCreativeModeFlightSpeedScalarNormalized(float NormalizedCreativeModeFlightSpeedScalar) {
}

void UAstroCharacterMovementComponent::ServerMoveOld_Implementation(float OldTimeStamp, FVector_NetQuantize10 OldInputAccel, uint8 OldMoveFlags, const FAstroCharacterEncumbrance& Encumbrance, const FAstroCharacterActiveOverrides& Overrides) {
}
bool UAstroCharacterMovementComponent::ServerMoveOld_Validate(float OldTimeStamp, FVector_NetQuantize10 OldInputAccel, uint8 OldMoveFlags, const FAstroCharacterEncumbrance& Encumbrance, const FAstroCharacterActiveOverrides& Overrides) {
    return true;
}

void UAstroCharacterMovementComponent::ServerMoveFocus_Implementation(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 clientLoc, FVector_NetQuantize100 FocusLoc, uint8 CompressedMoveFlags, uint8 ClientMovementMode, const FAstroCharacterEncumbrance& Encumbrance, const FAstroCharacterActiveOverrides& Overrides) {
}
bool UAstroCharacterMovementComponent::ServerMoveFocus_Validate(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 clientLoc, FVector_NetQuantize100 FocusLoc, uint8 CompressedMoveFlags, uint8 ClientMovementMode, const FAstroCharacterEncumbrance& Encumbrance, const FAstroCharacterActiveOverrides& Overrides) {
    return true;
}

void UAstroCharacterMovementComponent::ServerMoveDual_Implementation(float TimeStamp0, FVector_NetQuantize10 InAccel0, uint8 PendingFlags, uint32 View0, const FAstroCharacterEncumbrance& Encumbrance0, const FAstroCharacterActiveOverrides& Overrides0, float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 clientLoc, uint8 NewFlags, uint16 clientRoll, uint32 View, const FAstroCharacterEncumbrance& Encumbrance, const FAstroCharacterActiveOverrides& Overrides, uint8 ClientMovementMode) {
}
bool UAstroCharacterMovementComponent::ServerMoveDual_Validate(float TimeStamp0, FVector_NetQuantize10 InAccel0, uint8 PendingFlags, uint32 View0, const FAstroCharacterEncumbrance& Encumbrance0, const FAstroCharacterActiveOverrides& Overrides0, float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 clientLoc, uint8 NewFlags, uint16 clientRoll, uint32 View, const FAstroCharacterEncumbrance& Encumbrance, const FAstroCharacterActiveOverrides& Overrides, uint8 ClientMovementMode) {
    return true;
}

void UAstroCharacterMovementComponent::ServerMove_Implementation(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 clientLoc, uint8 CompressedMoveFlags, uint16 clientRoll, uint32 View, uint8 ClientMovementMode, const FAstroCharacterEncumbrance& Encumbrance, const FAstroCharacterActiveOverrides& Overrides) {
}
bool UAstroCharacterMovementComponent::ServerMove_Validate(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 clientLoc, uint8 CompressedMoveFlags, uint16 clientRoll, uint32 View, uint8 ClientMovementMode, const FAstroCharacterEncumbrance& Encumbrance, const FAstroCharacterActiveOverrides& Overrides) {
    return true;
}

float UAstroCharacterMovementComponent::GetCreativeModeFlightSpeedScalarNormalized() {
    return 0.0f;
}

AAstroCharacter* UAstroCharacterMovementComponent::GetCharacterOwner() const {
    return NULL;
}

bool UAstroCharacterMovementComponent::ContainsMovementOverride(UAstroCharacterMovementOverrideComponent* movementOverride) {
    return false;
}

FVector UAstroCharacterMovementComponent::ConsumeInputVector() {
    return FVector{};
}

void UAstroCharacterMovementComponent::ClientVeryShortAdjustPosition_Implementation(float Timestamp, FVector NewLoc, uint8 ServerMovementMode, const TArray<FMovementOverrideCorrection>& OverrideCorrections) {
}

void UAstroCharacterMovementComponent::ClientBumpVelocity_Implementation(const FVector& velocityBump) {
}

void UAstroCharacterMovementComponent::ClientAdjustPosition_Implementation(float Timestamp, FVector NewLoc, FVector NewVel, uint8 ServerMovementMode, const TArray<FMovementOverrideCorrection>& OverrideCorrections) {
}

void UAstroCharacterMovementComponent::ClientAckGoodMove_Implementation(float Timestamp) {
}

void UAstroCharacterMovementComponent::CleanupMovementOverridesOnDriving() {
}

void UAstroCharacterMovementComponent::AddMovementOverride(UAstroCharacterMovementOverrideComponent* movementOverride) {
}

void UAstroCharacterMovementComponent::AddInstantaneousVelocity(FVector velocityImpulse) {
}

void UAstroCharacterMovementComponent::AddImpulse(FVector Impulse) {
}

void UAstroCharacterMovementComponent::AddForce(FVector force) {
}

void UAstroCharacterMovementComponent::AddAcceleration(FVector NewAcceleration) {
}

UAstroCharacterMovementComponent::UAstroCharacterMovementComponent() {
    this->CharacterOwner = NULL;
    this->UpdatedComponent = NULL;
    this->Gravity = 9.81f;
    this->bNetworkUpdateReceived = false;
    this->bNetworkMovementModeChanged = false;
    this->NetworkSimulatedSmoothLocationTime = 0.10f;
    this->NetworkSimulatedSmoothRotationTime = 0.03f;
    this->MinTimeBetweenTimeStampResets = 240.00f;
    this->bIsCreativeModeDrone = false;
    this->bMovementInProgress = false;
    this->GravitySourceInterpolationTime = 0.50f;
    this->Mass = 7000.00f;
    this->RotationSpeed = 0.10f;
    this->SprintMultiplier = 1.60f;
    this->MaxAcceleration = 10000.00f;
    this->InitialPushForceFactor = 500.00f;
    this->PushForceFactor = 750000.00f;
    this->MaxSpeed = 800.00f;
    this->BrakingDecelerationWalking = 5.00f;
    this->GroundFriction = 1.00f;
    this->UpslopeSlowdownStartThreshold = 1.00f;
    this->MaxSpeedSliding = 2400.00f;
    this->SlideStartSpeedThreshold = 700.00f;
    this->SlideExitSpeedThreshold = 500.00f;
    this->BrakingDecelerationSliding = 1.50f;
    this->GroundFrictionSliding = 0.30f;
    this->SlideMaxHangTime = 1.00f;
    this->SlideBlockedDistanceThreshold = 1.00f;
    this->SlideBlockedBrakingDeceleration = 400.00f;
    this->SlideBlockedGroundFriction = 2.00f;
    this->BrakingDecelerationFalling = 1.00f;
    this->AirFriction = 0.10f;
    this->FlyingSurfaceFriction = 5.00f;
    this->FlyingSurfaceBrakingDeceleration = 1000.00f;
    this->FlyingAirFriction = 0.00f;
    this->FlyingAirBrakingDeceleration = 0.00f;
    this->FlyingSlideOnSurfaceDotProductThreshold = 0.10f;
    this->DownhillBias = 0.10f;
    this->JumpVerticalImpulse = 1000.00f;
    this->JumpBoostImpulse = 200.00f;
    this->CurrentMovementMode = AstroMovementMode::Walking;
    this->AirControlDampening = 0.20f;
    this->bHasAirControl = true;
    this->MinFallingDamageVelocity = 1650.00f;
    this->MaxFallingDamageVelocity = 2950.00f;
    this->MinCreativeModeFlightSpeedScalar = 1.00f;
    this->MaxCreativeModeFlightSpeedScalar = 5.00f;
    this->CreativeModeFlightSpeedScalar = 0.00f;
}

