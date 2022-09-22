#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "MidRangeScanSettings.h"
#include "ScannableStatus.h"
#include "SignalDelegate.h"
#include "EScannerMode.h"
#include "EScannerTargetDistance.h"
#include "Scanner.generated.h"

class UCurveFloat;
class AAstroCharacter;
class AAstroPlayerController;

UCLASS(Blueprintable)
class ASTRO_API AScanner : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPing;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnScanFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnScannerModeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnTargetDistanceChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMidRangeDistancePercentageChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ScannerMode, meta=(AllowPrivateAccess=true))
    EScannerMode ScannerMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_TargetDistance, meta=(AllowPrivateAccess=true))
    EScannerTargetDistance TargetDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MidRangeDistancePercentage, meta=(AllowPrivateAccess=true))
    float MidRangeDistancePercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PitchAnimationValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YawAnimationValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScanCooldownTimeSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShortRangeMaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MidRangeMaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* PitchAlphaCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShortRangeScanDurationSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LongRangeScanDurationSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMidRangeScanSettings MidRangeMinDistanceScanParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMidRangeScanSettings MidRangeMaxDistanceScanParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* MidRangeScanSpeedTransitionCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* MidRangeScanSpeedSelectionCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MidRangeScanSweepCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ObfuscationYawOffsetCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObfuscationYawOffsetCurveFrequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxObfuscationYawOffsetMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MidRangeScanIntroAnimationLengthSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FScannableStatus CurrentTarget;
    
    UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_UsingCharacter)
    TWeakObjectPtr<AAstroCharacter> UsingCharacter;
    
public:
    AScanner();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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
    void HandleVehicleUnmanned(AAstroPlayerController* oldUsingPlayer);
    
    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController* newUsingPlayer);
    
    UFUNCTION()
    void HandleReleasedFromSlot(bool NewOwner);
    
    UFUNCTION()
    void HandlePlacedInSlot();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTryScan();
    
    UFUNCTION()
    void AuthorityOnScanCompleted();
    
};

