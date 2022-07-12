#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
#include "ClickResult.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=VoxelMaterialProperties -FallbackName=VoxelMaterialProperties
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "EnableSignalDelegate.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=VoxelMaterial -FallbackName=VoxelMaterial
#include "EDeformToolSedimentTankReservesState.h"
#include "EAugmentProperty.h"
#include "ReplicatedBrushState.h"
#include "ReplicatedCreativeColorPickState.h"
#include "ReplicatedAugmentState.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=EDeformType -FallbackName=EDeformType
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "EDeformType.h"
#include "VoxelMaterialProperties.h"
#include "VoxelMaterial.h"
#include "DeformTool.generated.h"

class APlayController;
class AActor;
class UParticleSystemComponent;
class ATerrainBrush;
class USceneComponent;
class UActivation;
class AAstroCharacter;
class UDeformEventReceiver;
class UPowerComponent;
class UItemType;
class UAugmentComponent;
class UDeformToolCameraContext;
class AAstroPlanet;
class UClickQuery;
class UMaterialInterface;
class UDeformTargetComponent;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* FXSpawnComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UDeformEventReceiver* EventReceiver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UAugmentComponent*> AttachedAugments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UAugmentComponent*> EquippedAugments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* DeformEffectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* BurnoffEffectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UDeformToolCameraContext* CameraContext;
    
    UPROPERTY(EditAnywhere)
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
    
    ADeformTool();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION()
    bool UpdateTerrainSample(AAstroPlanet* Planet, const FVector& Location);
    
    UFUNCTION()
    void UpdateAugmentModifiedProperties();
    
    UFUNCTION()
    void TryEquipAugment(UAugmentComponent* augment, EAugmentProperty augmentProperty);
    
    UFUNCTION()
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
    
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerSendSampledTerrainUpdate(const FVector& Location);
    
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerSendBrushUpdates(const FReplicatedBrushState& repState);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerRequestNewMaterialWithTerrainProperties(AAstroPlanet* Planet, const FVoxelMaterialProperties& TerrainProperties, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex);
    
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerEndDeforming();
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerDoDeformTarget(UDeformTargetComponent* deformTarget);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCreativeModeColorPick(const FVector& Location);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCreativeModeColorChange(const FVoxelMaterialProperties& Properties, const FVector& Location, UMaterialInterface* CustomMaterial, int32 creativeModePaintMaterialIndex);
    
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerBeginDeforming();
    
    UFUNCTION()
    void PhysicalItemUnslotted(APhysicalItem* ItemOwner);
    
    UFUNCTION()
    void PhysicalItemSlotted(APhysicalItem* ItemOwner);
    
    UFUNCTION()
    void OnUseLegacyAddModeChanged(bool UseLegacyAddMode);
    
    UFUNCTION()
    void OnReplicated_TerrainSample();
    
    UFUNCTION()
    void OnReplicated_ColorPickState();
    
public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnInteraction(const FClickResult& Click);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnDeformBegin();
    
private:
    UFUNCTION()
    void OnCreativeModeActiveStateChanged(bool IsEnabled);
    
public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnBrushSpawn();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnAttemptedToPickColor();
    
    UFUNCTION(BlueprintPure)
    bool IsToolDeployed();
    
    UFUNCTION(BlueprintImplementableEvent)
    bool InteractActorTick(AActor* interactActor);
    
    UFUNCTION(BlueprintCallable)
    void IncrementCreativeBaseDeformationIntensity(float Delta);
    
    UFUNCTION(BlueprintCallable)
    void IncrementCreativeBaseBrushDeformationScale(float Delta);
    
private:
    UFUNCTION(BlueprintPure)
    bool HasTankReservesNecessaryToAdditivelyDeform();
    
    UFUNCTION(BlueprintPure)
    bool HasSpaceLeftInTanks();
    
    UFUNCTION()
    void HandleTerrainTool(APlayController* Controller, const FHitResult& toolHit, const FClickResult& ClickResult, bool startedInteraction, bool isUsingTool, bool justActivated, bool canUse);
    
public:
    UFUNCTION(BlueprintPure)
    float GetSedimentFlowRate();
    
    UFUNCTION(BlueprintPure)
    float GetSedimentDeformationDelta();
    
    UFUNCTION(BlueprintPure)
    float GetSedimentAvailable();
    
private:
    UFUNCTION()
    bool GetPowerLevelInhibitedFromAugment();
    
public:
    UFUNCTION(BlueprintPure)
    bool GetOwnerBackpackRasied();
    
private:
    UFUNCTION()
    FVoxelMaterial GetMaterialFromAugment();
    
    UFUNCTION(BlueprintPure)
    bool GetIsIgnoringTerrainHardnessCreative();
    
public:
    UFUNCTION(BlueprintNativeEvent)
    bool GetIsDeforming();
    
    UFUNCTION(BlueprintImplementableEvent)
    bool GetIsActive();
    
private:
    UFUNCTION()
    bool GetFixedAlignmentFromAugment();
    
public:
    UFUNCTION()
    float GetEffectiveIndicatorScale();
    
    UFUNCTION()
    float GetEffectiveDeformationIntensity();
    
    UFUNCTION()
    float GetEffectiveBrushScale();
    
    UFUNCTION(BlueprintPure)
    float GetDeformTier() const;
    
    UFUNCTION(BlueprintNativeEvent)
    FVector GetDeformLocation();
    
    UFUNCTION(BlueprintPure)
    bool GetDeformationIsActive();
    
private:
    UFUNCTION()
    float GetDeformationIntensityModifierFromAugment();
    
public:
    UFUNCTION(BlueprintPure)
    float GetCreativeToolRange();
    
    UFUNCTION(BlueprintPure)
    float GetCreativeDeformationIntensityNormalized();
    
    UFUNCTION(BlueprintPure)
    float GetCreativeBaseDeformationIntensity();
    
    UFUNCTION(BlueprintPure)
    float GetCreativeBaseBrushDeformationScale();
    
private:
    UFUNCTION()
    float GetBrushSizeModifierFromAugment();
    
public:
    UFUNCTION(BlueprintPure)
    float GetAugmentedTerrainHardness();
    
private:
    UFUNCTION()
    void DetermineSedimentTankAmount();
    
    UFUNCTION()
    void Deactivated();
    
    UFUNCTION()
    void CycleModeRight();
    
    UFUNCTION()
    void CycleModeLeft();
    
public:
    UFUNCTION()
    void CheckForOrphanedTool();
    
private:
    UFUNCTION()
    void CheckAugmentsHavePower();
    
    UFUNCTION()
    void ChangeInAttachedAugments();
    
public:
    UFUNCTION()
    float AuthorityGetEffectiveHardnessTier();
    
    UFUNCTION()
    void AdjustSedimentTankAmountFromDeformationDelta(float deformationDelta);
    
private:
    UFUNCTION()
    void Activated();
    
};

