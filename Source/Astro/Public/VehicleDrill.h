#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "VoxelMaterialProperties.h"
#include "DrillAudioEventDelegate.h"
#include "EVehicleDrillToolMode.h"
#include "EnableSignalDelegate.h"
#include "OnDummyDrillRemovedDelegate.h"
#include "OnSampledTerrainMaterialChangedDelegate.h"
#include "PhysicalItem.h"
#include "Templates/SubclassOf.h"
#include "VehicleDrillOperationConstants.h"
#include "VehicleDrillReplicationData.h"
#include "VehicleDrillSedimentReplicationData.h"
#include "VehicleDrill.generated.h"

class AAstroPlanet;
class AAstroPlayerController;
class ARoverBase;
class AVehicleDrill;
class UControlComponent;
class UCurveFloat;
class UDeformEventReceiver;
class UMaterialInterface;
class UParticleSystem;
class UParticleSystemComponent;
class UPowerComponent;
class USceneComponent;
class UStorageChassisComponent;

UCLASS(Blueprintable)
class AVehicleDrill : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SedimentDeformationRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor NeutralTerrainColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NeutralDotProdBetweenCameraAndRoverUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_VehicleDrillReplicationData, meta=(AllowPrivateAccess=true))
    FVehicleDrillReplicationData VehicleDrillReplicatedState;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnToolActiveChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnDrillCollectedExcessTerrainChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDummyDrillRemoved OnDummyDrillReleasedFromSlot;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<AVehicleDrill*> DummyLinkedDrills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeformationTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FoliageDestructionMassThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FoliageDestructionOriginOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DestructionRadiusScaleFromDeformSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVehicleDrillOperationConstants TunnelBoringDeformationConstants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVehicleDrillOperationConstants ExcavationDeformationConstants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExcessTerrainCollectedThresholdForBurnoffEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CameraPitchToDrillPitchMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* SteeringAngleToDrillRollMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumRollAdjustment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* SteeringAngleToDrillYawMapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BirdsEyeDotVal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WormsEyeDotVal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSlope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDrillSlope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControlComponent* ControlComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDeformEventReceiver* DeformEventReceiver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* DeformVisualizer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* FoliageDestructionVisualizer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* ExcavationDeformationOriginMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TunnelBoringUI_Wrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PivotingUI_Wrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* TerrainDeformationParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TiltIndicatorWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TiltUpIndicatorWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TiltDownIndicatorWrapper;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDrillAudioEvent OnDrillMotorAudioChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDrillAudioEvent OnTerrainBeingDrilledAudioChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSampledTerrainMaterialChanged OnSampledTerrainMaterialChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlopeGaugeExtent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARoverBase* TunnelBoringRover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APhysicalItem> CraneSubclass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_VehicleDrillSedimentReplicationData, meta=(AllowPrivateAccess=true))
    FVehicleDrillSedimentReplicationData VehicleDrillReplicatedSedimentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ConsumedSedimentDebt;
    
public:
    AVehicleDrill(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateTerrainDeformationParticles(bool SystemEnabled, int32 HardnessDelta);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateSlopeIndicator(float SlopeDegree);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateSedimentGauge(float CurrentSedimentAvailalbe, float CurrentSedimentCapacity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdatePlayerAccentIndex(int32 PlayerAccentIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateDeformationNormal(FVector DeformationNormal);
    
public:
    UFUNCTION(BlueprintCallable)
    void ToggleDrillUsageForTunnelBoring();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateToolState(bool ToolIsActive, EVehicleDrillToolMode DrillMode);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRequestNewMaterialWithTerrainProperties(AAstroPlanet* Planet, const FVoxelMaterialProperties& TerrainProperties, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex);
    
    UFUNCTION(BlueprintCallable)
    void ResetExcessTerrainCollectionFlag();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayDrillStartWithInsufficientSoilEffect();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayDrillStartWithInsufficientPowerEffect();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRep_VehicleDrillSedimentReplicationData();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_VehicleDrillReplicationData();
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastPlayDrillStartWithInsufficientSoilEffect();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastPlayDrillStartWithInsufficientPowerEffect();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsToolActive() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleVehicleUnmanned(AAstroPlayerController* VehicleDriver);
    
    UFUNCTION(BlueprintCallable)
    void HandleVehicleManned(AAstroPlayerController* VehicleDriver);
    
    UFUNCTION(BlueprintCallable)
    void HandleTunnelBoringDrillBecameActiveOnMyRover(AVehicleDrill* DrillThatBecameActive);
    
    UFUNCTION(BlueprintCallable)
    void HandleTerraianDeformationDensityDeltaReceived(float DensityDelta);
    
    UFUNCTION(BlueprintCallable)
    void HandleRemovedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void HandlePlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void HandleDummyDrillRemovedFromSlot(AVehicleDrill* DummyDrillRemoved);
    
    UFUNCTION(BlueprintCallable)
    void HandleDestroyedWhileInSlot(APhysicalItem* DestroyedActor);
    
    UFUNCTION(BlueprintCallable)
    void HandleDeactivatedAsExcavator();
    
    UFUNCTION(BlueprintCallable)
    void HandleActivatedAsExcavator();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UParticleSystem* GetSubtractParticleEffect(int32 HardnessDelta);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStorageChassisComponent* GetOutermostStorage();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DidCollectExcessTerrain() const;
    
};

