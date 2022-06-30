#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "EScannerTargetDistance.h"
#include "EScannerMode.h"
#include "SignalDelegate.h"
#include "MidRangeScanSettings.h"
#include "ScannableStatus.h"
#include "Scanner.generated.h"

class AAstroCharacter;
class UCurveFloat;
class AAstroPlayerController;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AScanner : public APhysicalItem
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable)
    FSignal OnPing;

    UPROPERTY(BlueprintAssignable)
    FSignal OnScanFailed;

    UPROPERTY(BlueprintAssignable)
    FSignal OnScannerModeChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnTargetDistanceChanged;

    UPROPERTY(BlueprintAssignable)
    FSignal OnMidRangeDistancePercentageChanged;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_ScannerMode, meta = (AllowPrivateAccess = true))
    EScannerMode ScannerMode;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_TargetDistance, meta = (AllowPrivateAccess = true))
    EScannerTargetDistance TargetDistance;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_MidRangeDistancePercentage, meta = (AllowPrivateAccess = true))
    float MidRangeDistancePercentage;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float PitchAnimationValue;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float YawAnimationValue;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float ScanCooldownTimeSeconds;

    UPROPERTY(EditDefaultsOnly)
    float ShortRangeMaxDistance;

    UPROPERTY(EditDefaultsOnly)
    float MidRangeMaxDistance;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *PitchAlphaCurve;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float ShortRangeScanDurationSeconds;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float LongRangeScanDurationSeconds;

    UPROPERTY(EditDefaultsOnly)
    FMidRangeScanSettings MidRangeMinDistanceScanParameters;

    UPROPERTY(EditDefaultsOnly)
    FMidRangeScanSettings MidRangeMaxDistanceScanParameters;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *MidRangeScanSpeedTransitionCurve;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *MidRangeScanSpeedSelectionCurve;

    UPROPERTY(EditDefaultsOnly)
    int32 MidRangeScanSweepCount;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *ObfuscationYawOffsetCurve;

    UPROPERTY(EditDefaultsOnly)
    float ObfuscationYawOffsetCurveFrequency;

    UPROPERTY(EditDefaultsOnly)
    float MaxObfuscationYawOffsetMultiplier;

    UPROPERTY(EditDefaultsOnly)
    float MidRangeScanIntroAnimationLengthSeconds;

    UPROPERTY(Replicated)
    FScannableStatus CurrentTarget;

    UPROPERTY(ReplicatedUsing = OnRep_UsingCharacter)
    TWeakObjectPtr<AAstroCharacter> UsingCharacter;

public:
    AScanner();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void OnRep_UsingCharacter();

    UFUNCTION()
    void OnRep_TargetDistance();

    UFUNCTION()
    void OnRep_ScannerMode();

    UFUNCTION()
    void OnRep_MidRangeDistancePercentage();

    UFUNCTION()
    void OnPowerAvailableChanged(bool hasPower);

    UFUNCTION()
    void OnMidRangeScanIntroAnimationCompleted();

    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController *oldUsingPlayer);

    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController *newUsingPlayer);

    UFUNCTION()
    void HandleReleasedFromSlot(bool NewOwner);

    UFUNCTION()
    void HandlePlacedInSlot();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTryScan();

    UFUNCTION()
    void AuthorityOnScanCompleted();
};
