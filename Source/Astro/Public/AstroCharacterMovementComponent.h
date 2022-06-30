#pragma once
#include "CoreMinimal.h"
#include "Interfaces/NetworkPredictionInterface.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "AstroCharacterActiveOverrides.h"
#include "AstroCharacterEncumbrance.h"
#include "AstroMovementMode.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "MovementOverrideCorrection.h"
#include "AstroCharacterMovementComponent.generated.h"

class AAstroCharacter;
class UPrimitiveComponent;
class UAstroCharacterMovementOverrideComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class UAstroCharacterMovementComponent : public UActorComponent, public INetworkPredictionInterface
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY()
    AAstroCharacter *CharacterOwner;

    UPROPERTY(BlueprintReadWrite, DuplicateTransient, Export, meta = (AllowPrivateAccess = true))
    UPrimitiveComponent *UpdatedComponent;

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector Velocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float Gravity;

    UPROPERTY(Transient)
    uint8 bNetworkUpdateReceived : 1;

    UPROPERTY(Transient)
    uint8 bNetworkMovementModeChanged : 1;

    UPROPERTY(AdvancedDisplay, EditDefaultsOnly)
    float NetworkSimulatedSmoothLocationTime;

    UPROPERTY(AdvancedDisplay, EditDefaultsOnly)
    float NetworkSimulatedSmoothRotationTime;

    UPROPERTY()
    float MinTimeBetweenTimeStampResets;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bIsCreativeModeDrone;

protected:
    UPROPERTY()
    uint8 bMovementInProgress : 1;

    UPROPERTY()
    FVector Acceleration;

    UPROPERTY()
    FVector PendingForceToApply;

    UPROPERTY()
    FVector PendingImpulseToApply;

    UPROPERTY(EditDefaultsOnly)
    float GravitySourceInterpolationTime;

    UPROPERTY()
    FVector CurrentGravity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float Mass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RotationSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SprintMultiplier;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxAcceleration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float InitialPushForceFactor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PushForceFactor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BrakingDecelerationWalking;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float GroundFriction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float UpslopeSlowdownStartThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxSpeedSliding;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SlideStartSpeedThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SlideExitSpeedThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BrakingDecelerationSliding;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float GroundFrictionSliding;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SlideMaxHangTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SlideBlockedDistanceThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SlideBlockedBrakingDeceleration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SlideBlockedGroundFriction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BrakingDecelerationFalling;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float AirFriction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingSurfaceFriction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingSurfaceBrakingDeceleration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingAirFriction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingAirBrakingDeceleration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingSlideOnSurfaceDotProductThreshold;

    UPROPERTY(EditAnywhere)
    FAstroCharacterEncumbrance LimitedMovementEncumbrance;

    UPROPERTY(EditAnywhere)
    FAstroCharacterEncumbrance HeavyCarryEncumbrance;

    UPROPERTY(EditAnywhere)
    TArray<FAstroCharacterEncumbrance> HeldItemEncumbranceByTier;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DownhillBias;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float JumpVerticalImpulse;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float JumpBoostImpulse;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AstroMovementMode CurrentMovementMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float AirControlDampening;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bHasAirControl : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MinFallingDamageVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxFallingDamageVelocity;

    UPROPERTY(EditAnywhere)
    FString GravityVolumeChangedAudioEvent;

    UPROPERTY(EditAnywhere)
    float MinCreativeModeFlightSpeedScalar;

    UPROPERTY(EditAnywhere)
    float MaxCreativeModeFlightSpeedScalar;

    UPROPERTY(SaveGame)
    float CreativeModeFlightSpeedScalar;

public:
    UAstroCharacterMovementComponent();
    UFUNCTION(BlueprintCallable)
    void ZeroVelocity();

    UFUNCTION(BlueprintCallable)
    void SetUpdatedComponent(UPrimitiveComponent *NewUpdatedComponent);

    UFUNCTION(BlueprintCallable)
    void SetCreativeModeFlightSpeedScalarNormalized(float NormalizedCreativeModeFlightSpeedScalar);

    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerMoveOld(float OldTimeStamp, FVector_NetQuantize10 OldInputAccel, uint8 OldMoveFlags, const FAstroCharacterEncumbrance &Encumbrance, const FAstroCharacterActiveOverrides &Overrides);

    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerMoveFocus(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 clientLoc, FVector_NetQuantize100 FocusLoc, uint8 CompressedMoveFlags, uint8 ClientMovementMode, const FAstroCharacterEncumbrance &Encumbrance, const FAstroCharacterActiveOverrides &Overrides);

    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerMoveDual(float TimeStamp0, FVector_NetQuantize10 InAccel0, uint8 PendingFlags, uint32 View0, const FAstroCharacterEncumbrance &Encumbrance0, const FAstroCharacterActiveOverrides &Overrides0, float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 clientLoc, uint8 NewFlags, uint16 clientRoll, uint32 View, const FAstroCharacterEncumbrance &Encumbrance, const FAstroCharacterActiveOverrides &Overrides, uint8 ClientMovementMode);

    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerMove(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 clientLoc, uint8 CompressedMoveFlags, uint16 clientRoll, uint32 View, uint8 ClientMovementMode, const FAstroCharacterEncumbrance &Encumbrance, const FAstroCharacterActiveOverrides &Overrides);

    UFUNCTION(BlueprintPure)
    float GetCreativeModeFlightSpeedScalarNormalized();

protected:
    UFUNCTION(BlueprintPure)
    AAstroCharacter *GetCharacterOwner() const;

public:
    UFUNCTION(BlueprintPure)
    bool ContainsMovementOverride(UAstroCharacterMovementOverrideComponent *movementOverride);

    UFUNCTION(BlueprintCallable)
    FVector ConsumeInputVector();

    UFUNCTION(Client, Unreliable)
    void ClientVeryShortAdjustPosition(float Timestamp, FVector NewLoc, uint8 ServerMovementMode, const TArray<FMovementOverrideCorrection> &OverrideCorrections);

    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void ClientBumpVelocity(const FVector &velocityBump);

    UFUNCTION(Client, Unreliable)
    void ClientAdjustPosition(float Timestamp, FVector NewLoc, FVector NewVel, uint8 ServerMovementMode, const TArray<FMovementOverrideCorrection> &OverrideCorrections);

    UFUNCTION(Client, Unreliable)
    void ClientAckGoodMove(float Timestamp);

private:
    UFUNCTION()
    void CleanupMovementOverridesOnDriving();

public:
    UFUNCTION(BlueprintCallable)
    void AddMovementOverride(UAstroCharacterMovementOverrideComponent *movementOverride);

    UFUNCTION(BlueprintCallable)
    void AddInstantaneousVelocity(FVector velocityImpulse);

    UFUNCTION(BlueprintCallable)
    void AddImpulse(FVector Impulse);

    UFUNCTION(BlueprintCallable)
    void AddForce(FVector force);

    UFUNCTION(BlueprintCallable)
    void AddAcceleration(FVector NewAcceleration);

    // Fix for true pure virtual functions not being implemented
};
