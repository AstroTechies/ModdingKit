#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=VoxelMaterialProperties -FallbackName=VoxelMaterialProperties
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "VoxelMaterialProperties.h"
#include "VehicleDrillReplicationData.h"
#include "VehicleDrillOperationConstants.h"
#include "EnableSignalDelegate.h"
#include "OnDummyDrillRemovedDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "DrillAudioEventDelegate.h"
#include "OnSampledTerrainMaterialChangedDelegate.h"
#include "VehicleDrillSedimentReplicationData.h"
#include "EVehicleDrillToolMode.h"
#include "VehicleDrill.generated.h"

class USceneComponent;
class AVehicleDrill;
class ARoverBase;
class UCurveFloat;
class UControlComponent;
class UDeformEventReceiver;
class UPowerComponent;
class UParticleSystemComponent;
class AAstroPlanet;
class UMaterialInterface;
class AAstroPlayerController;
class UParticleSystem;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UControlComponent* ControlComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UDeformEventReceiver* DeformEventReceiver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* DeformVisualizer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* FoliageDestructionVisualizer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* ExcavationDeformationOriginMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* TunnelBoringUI_Wrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* PivotingUI_Wrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* TerrainDeformationParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* TiltIndicatorWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* TiltUpIndicatorWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    AVehicleDrill();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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
    void ServerRequestNewMaterialWithTerrainProperties(AAstroPlanet* Planet, const FVoxelMaterialProperties& TerrainProperties, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex);
    
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
    void HandleVehicleUnmanned(AAstroPlayerController* VehicleDriver);
    
    UFUNCTION()
    void HandleVehicleManned(AAstroPlayerController* VehicleDriver);
    
    UFUNCTION()
    void HandleTunnelBoringDrillBecameActiveOnMyRover(AVehicleDrill* DrillThatBecameActive);
    
    UFUNCTION()
    void HandleTerraianDeformationDensityDeltaReceived(float DensityDelta);
    
    UFUNCTION()
    void HandleRemovedFromSlot(bool NewOwner);
    
    UFUNCTION()
    void HandlePlacedInSlot();
    
    UFUNCTION()
    void HandleDummyDrillRemovedFromSlot(AVehicleDrill* DummyDrillRemoved);
    
    UFUNCTION()
    void HandleDestroyedWhileInSlot(APhysicalItem* DestroyedActor);
    
    UFUNCTION()
    void HandleDeactivatedAsExcavator();
    
    UFUNCTION()
    void HandleActivatedAsExcavator();
    
    UFUNCTION(BlueprintImplementableEvent)
    UParticleSystem* GetSubtractParticleEffect(int32 HardnessDelta);
    
public:
    UFUNCTION(BlueprintPure)
    bool DidCollectExcessTerrain() const;
    
};

