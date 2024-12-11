#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "EDeformType.h"
#include "VoxelMaterial.h"
#include "VoxelMaterialProperties.h"
#include "ClickResult.h"
#include "EAugmentProperty.h"
#include "EDeformToolSedimentTankReservesState.h"
#include "EnableSignalDelegate.h"
#include "PhysicalItem.h"
#include "ReplicatedAugmentState.h"
#include "ReplicatedBrushState.h"
#include "ReplicatedCreativeColorPickState.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "DeformTool.generated.h"

class AActor;
class AAstroCharacter;
class AAstroPlanet;
class APlayController;
class ATerrainBrush;
class UActivation;
class UAugmentComponent;
class UClickQuery;
class UDeformEventReceiver;
class UDeformTargetComponent;
class UDeformToolCameraContext;
class UItemType;
class UMaterialInterface;
class UParticleSystemComponent;
class UPowerComponent;
class USceneComponent;

UCLASS(Blueprintable)
class ASTRO_API ADeformTool : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor NeutralTerrainColor;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference DeformEffectReference;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference BurnoffEffectReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ParticleEmitterNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AudioSurfaceTypeSwitchState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HitLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HitNormal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> DeformFXActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ATerrainBrush> TerrainBrushActor;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnDeformToolEquippedStateChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSampledTerrainMaterialChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoxelMaterial SampledTerrainMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoxelMaterial PaintingTerrainMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoxelMaterial TerrainBrushMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EDeformToolSedimentTankReservesState bSedimentTankReservesState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* usingTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayController* OwningController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAstroCharacter* OwningCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ATerrainBrush* TerrainBrush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* FXSpawnComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDeformEventReceiver* EventReceiver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseBrushDeformationScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseBrushIndicatorScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseDeformationItensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseCreativeDeformationIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CreativeBaseDeformationIntensityMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CreativeBaseDeformationIntensityMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CreativeBaseBrushDeformationScaleMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CreativeBaseBrushDeformationScaleMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CreativeToolRangeMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CreativeBaseBrushDeformationIntensityAdjustmentIncrement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CreativeBaseBrushDeformationScaleAdjustmentIncrement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SphereCastRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerSafeZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToolRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LowPowerMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SedimentBaseRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SedimentDeformationRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SedimentFullySuppliedAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FXFrequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FXSubtractVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FXAddVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FXRadialVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FXSubtractVelocityRandomness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FXScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FXScaleRandomness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FXSubtractSpawnHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FXAddSpawnHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MiningValue;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FReplicatedBrushState RepBrushState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FReplicatedAugmentState RepAugmentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnReplicated_ColorPickState, meta=(AllowPrivateAccess=true))
    FReplicatedCreativeColorPickState RepCreativeColorPickState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnReplicated_TerrainSample, meta=(AllowPrivateAccess=true))
    FVoxelMaterialProperties RepTerrainSample;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAugmentComponent*> AttachedAugments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAugmentComponent*> EquippedAugments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* DeformEffectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* BurnoffEffectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDeformToolCameraContext* CameraContext;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 BrushMaterialIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float TotalSedimentAvailable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float TotalSedimentCapacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float SedimentDeformationDelta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeformTier;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDeformType Operation;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bDeformationActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bDeformationFullPower: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bCreativeModeIgnoreHardness: 1;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 IsOwnedTool: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ToolActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 TerrainStreamEffectsActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 AudioBurnOffPlaying: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MinedMineral: 1;
    
    ADeformTool(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    bool UpdateTerrainSample(AAstroPlanet* Planet, const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    void UpdateAugmentModifiedProperties();
    
    UFUNCTION(BlueprintCallable)
    void TryEquipAugment(UAugmentComponent* augment, EAugmentProperty augmentProperty);
    
    UFUNCTION(BlueprintCallable)
    void ToolClickQuery(UClickQuery* ClickQuery);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSubclassOf<UItemType> TakeTerrainResource();
    
    UFUNCTION(BlueprintCallable)
    void SetSuspendBrushPositionUpdate(bool doSuspend);
    
    UFUNCTION(BlueprintCallable)
    void SetCreativeToolRange(float NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetCreativeBaseDeformationScale(float NewVal);
    
    UFUNCTION(BlueprintCallable)
    void SetCreativeBaseDeformationIntensity(float NewVal);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetIsIgnoringTerrainHardnessCreative(bool IgnoreTerrainHardness);
    
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerSendSampledTerrainUpdate(const FVector& Location);
    
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerSendBrushUpdates(const FReplicatedBrushState& repState);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRequestNewMaterialWithTerrainProperties(AAstroPlanet* Planet, const FVoxelMaterialProperties& TerrainProperties, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex);
    
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerEndDeforming();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDoDeformTarget(UDeformTargetComponent* deformTarget);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerCreativeModeColorPick(const FVector& Location);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerCreativeModeColorChange(const FVoxelMaterialProperties& Properties, const FVector& Location, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex);
    
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerBeginDeforming();
    
    UFUNCTION(BlueprintCallable)
    void PhysicalItemUnslotted(APhysicalItem* ItemOwner);
    
    UFUNCTION(BlueprintCallable)
    void PhysicalItemSlotted(APhysicalItem* ItemOwner);
    
    UFUNCTION(BlueprintCallable)
    void OnUseLegacyAddModeChanged(bool UseLegacyAddMode);
    
    UFUNCTION(BlueprintCallable)
    void OnReplicated_TerrainSample();
    
    UFUNCTION(BlueprintCallable)
    void OnReplicated_ColorPickState();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInteraction(const FClickResult& Click);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeformBegin();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCreativeModeActiveStateChanged(bool IsEnabled);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBrushSpawn();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAttemptedToPickColor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsToolDeployed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool InteractActorTick(AActor* interactActor);
    
    UFUNCTION(BlueprintCallable)
    void IncrementCreativeBaseDeformationIntensity(float Delta);
    
    UFUNCTION(BlueprintCallable)
    void IncrementCreativeBaseBrushDeformationScale(float Delta);
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTankReservesNecessaryToAdditivelyDeform();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasSpaceLeftInTanks();
    
    UFUNCTION(BlueprintCallable)
    void HandleTerrainTool(APlayController* Controller, const FHitResult& toolHit, const FClickResult& ClickResult, bool startedInteraction, bool endedInteraction, bool isUsingTool, bool justActivated, bool canUse);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector GetToolNozzleLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSedimentFlowRate();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSedimentDeformationDelta();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSedimentAvailable();
    
private:
    UFUNCTION(BlueprintCallable)
    bool GetPowerLevelInhibitedFromAugment();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetOwnerBackpackRasied();
    
private:
    UFUNCTION(BlueprintCallable)
    FVoxelMaterial GetMaterialFromAugment();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsIgnoringTerrainHardnessCreative();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool GetIsDeforming();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool GetIsActive();
    
private:
    UFUNCTION(BlueprintCallable)
    bool GetFixedAlignmentFromAugment();
    
public:
    UFUNCTION(BlueprintCallable)
    float GetEffectiveIndicatorScale();
    
    UFUNCTION(BlueprintCallable)
    float GetEffectiveDeformationIntensity();
    
    UFUNCTION(BlueprintCallable)
    float GetEffectiveBrushScale();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDeformTier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetDeformLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDeformationIsActive();
    
private:
    UFUNCTION(BlueprintCallable)
    float GetDeformationIntensityModifierFromAugment();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCreativeToolRange();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCreativeDeformationIntensityNormalized();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCreativeBaseDeformationIntensity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCreativeBaseBrushDeformationScale();
    
private:
    UFUNCTION(BlueprintCallable)
    float GetBrushSizeModifierFromAugment();
    
public:
    UFUNCTION(BlueprintCallable)
    bool GetAugmentStateRevertModifications();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAugmentedTerrainHardness();
    
private:
    UFUNCTION(BlueprintCallable)
    void DetermineSedimentTankAmount();
    
    UFUNCTION(BlueprintCallable)
    void Deactivated();
    
    UFUNCTION(BlueprintCallable)
    void CycleModeRight();
    
    UFUNCTION(BlueprintCallable)
    void CycleModeLeft();
    
public:
    UFUNCTION(BlueprintCallable)
    void CheckForOrphanedTool();
    
private:
    UFUNCTION(BlueprintCallable)
    void CheckAugmentsHavePower();
    
    UFUNCTION(BlueprintCallable)
    void ChangeInAttachedAugments();
    
public:
    UFUNCTION(BlueprintCallable)
    float AuthorityGetEffectiveHardnessTier();
    
    UFUNCTION(BlueprintCallable)
    void AdjustSedimentTankAmountFromDeformationDelta(float deformationDelta);
    
private:
    UFUNCTION(BlueprintCallable)
    void Activated();
    
};

