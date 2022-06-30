#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EnableSignalDelegate.h"
#include "PhysicalItem.h"
#include "UObject/NoExportTypes.h"
#include "VehicleDrillOperationConstants.h"
#include "OnDummyDrillRemovedDelegate.h"
#include "VehicleDrillSedimentReplicationData.h"
#include "VehicleDrillReplicationData.h"
#include "UObject/NoExportTypes.h"
#include "DrillAudioEventDelegate.h"
#include "OnSampledTerrainMaterialChangedDelegate.h"
#include "EVehicleDrillToolMode.h"
#include "VoxelMaterialProperties.h"
#include "VehicleDrill.generated.h"

class USceneComponent;
class AVehicleDrill;
class UCurveFloat;
class UControlComponent;
class UDeformEventReceiver;
class UPowerComponent;
class UMaterialInterface;
class UParticleSystemComponent;
class ARoverBase;
class AAstroPlanet;
class AAstroPlayerController;
class UParticleSystem;

UCLASS(Blueprintable, Blueprintable)
class AVehicleDrill : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float SedimentDeformationRatio;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FLinearColor NeutralTerrainColor;

    UPROPERTY(EditDefaultsOnly)
    float NeutralDotProdBetweenCameraAndRoverUp;

    UPROPERTY(ReplicatedUsing = OnRep_VehicleDrillReplicationData)
    FVehicleDrillReplicationData VehicleDrillReplicatedState;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnToolActiveChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnDrillCollectedExcessTerrainChanged;

    UPROPERTY()
    FOnDummyDrillRemoved OnDummyDrillReleasedFromSlot;

protected:
    UPROPERTY(Replicated)
    TArray<AVehicleDrill *> DummyLinkedDrills;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float DeformationTier;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float FoliageDestructionMassThreshold;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FVector FoliageDestructionOriginOffset;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float DestructionRadiusScaleFromDeformSize;

    UPROPERTY(EditDefaultsOnly)
    FVehicleDrillOperationConstants TunnelBoringDeformationConstants;

    UPROPERTY(EditDefaultsOnly)
    FVehicleDrillOperationConstants ExcavationDeformationConstants;

    UPROPERTY(EditDefaultsOnly)
    int32 ExcessTerrainCollectedThresholdForBurnoffEffect;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *CameraPitchToDrillPitchMapping;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *SteeringAngleToDrillRollMapping;

    UPROPERTY(EditDefaultsOnly)
    float MaximumRollAdjustment;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *SteeringAngleToDrillYawMapping;

    UPROPERTY(EditDefaultsOnly)
    float BirdsEyeDotVal;

    UPROPERTY(EditDefaultsOnly)
    float WormsEyeDotVal;

    UPROPERTY(EditDefaultsOnly)
    float MaxSlope;

    UPROPERTY(EditDefaultsOnly)
    float MaxDrillSlope;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UControlComponent *ControlComponent;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UDeformEventReceiver *DeformEventReceiver;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UPowerComponent *PowerComponent;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *DeformVisualizer;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *FoliageDestructionVisualizer;

    UPROPERTY(Export, VisibleAnywhere)
    USceneComponent *ExcavationDeformationOriginMarker;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *TunnelBoringUI_Wrapper;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *PivotingUI_Wrapper;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UParticleSystemComponent *TerrainDeformationParticles;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *TiltIndicatorWrapper;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *TiltUpIndicatorWrapper;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *TiltDownIndicatorWrapper;

    UPROPERTY(BlueprintAssignable)
    FDrillAudioEvent OnDrillMotorAudioChanged;

    UPROPERTY(BlueprintAssignable)
    FDrillAudioEvent OnTerrainBeingDrilledAudioChanged;

    UPROPERTY(BlueprintAssignable)
    FOnSampledTerrainMaterialChanged OnSampledTerrainMaterialChanged;

    UPROPERTY(EditDefaultsOnly)
    float SlopeGaugeExtent;

    UPROPERTY()
    ARoverBase *TunnelBoringRover;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<APhysicalItem> CraneSubclass;

    UPROPERTY(ReplicatedUsing = OnRep_VehicleDrillSedimentReplicationData)
    FVehicleDrillSedimentReplicationData VehicleDrillReplicatedSedimentState;

    UPROPERTY(SaveGame)
    int32 ConsumedSedimentDebt;

public:
    AVehicleDrill();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void UpdateTerrainDeformationParticles(bool SystemEnabled, int32 HardnessDelta);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateSlopeIndicator(float SlopeDegree);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateSedimentGauge(float CurrentSedimentAvailalbe, float CurrentSedimentCapacity);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdatePlayerAccentIndex(int32 PlayerAccentIndex);

    UFUNCTION(BlueprintImplementableEvent)
    void UpdateDeformationNormal(FVector DeformationNormal);

public:
    UFUNCTION(BlueprintCallable)
    void ToggleDrillUsageForTunnelBoring();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerUpdateToolState(bool ToolIsActive, EVehicleDrillToolMode DrillMode);

protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerRequestNewMaterialWithTerrainProperties(AAstroPlanet *Planet, const FVoxelMaterialProperties &TerrainProperties, UMaterialInterface *CustomMaterial, int32 creativeModePaintMaterialIndex);

    UFUNCTION()
    void ResetExcessTerrainCollectionFlag();

    UFUNCTION(BlueprintImplementableEvent)
    void PlayDrillStartWithInsufficientSoilEffect();

    UFUNCTION(BlueprintImplementableEvent)
    void PlayDrillStartWithInsufficientPowerEffect();

public:
    UFUNCTION()
    void OnRep_VehicleDrillSedimentReplicationData();

    UFUNCTION()
    void OnRep_VehicleDrillReplicationData();

protected:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastPlayDrillStartWithInsufficientSoilEffect();

    UFUNCTION(NetMulticast, Reliable)
    void MulticastPlayDrillStartWithInsufficientPowerEffect();

public:
    UFUNCTION(BlueprintPure)
    bool IsToolActive() const;

protected:
    UFUNCTION()
    void HandleVehicleUnmanned(AAstroPlayerController *VehicleDriver);

    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController *VehicleDriver);

    UFUNCTION()
    void HandleTunnelBoringDrillBecameActiveOnMyRover(AVehicleDrill *DrillThatBecameActive);

    UFUNCTION()
    void HandleTerraianDeformationDensityDeltaReceived(float DensityDelta);

    UFUNCTION()
    void HandleRemovedFromSlot(bool NewOwner);

    UFUNCTION()
    void HandlePlacedInSlot();

    UFUNCTION()
    void HandleDummyDrillRemovedFromSlot(AVehicleDrill *DummyDrillRemoved);

    UFUNCTION()
    void HandleDestroyedWhileInSlot(APhysicalItem *DestroyedActor);

    UFUNCTION()
    void HandleDeactivatedAsExcavator();

    UFUNCTION()
    void HandleActivatedAsExcavator();

    UFUNCTION(BlueprintImplementableEvent)
    UParticleSystem *GetSubtractParticleEffect(int32 HardnessDelta);

public:
    UFUNCTION(BlueprintPure)
    bool DidCollectExcessTerrain() const;
};
