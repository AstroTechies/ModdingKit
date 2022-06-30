#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EnableSignalDelegate.h"
#include "PhysicalItem.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ReplicatedBrushState.h"
#include "SignalDelegate.h"
#include "VoxelMaterial.h"
#include "EDeformToolSedimentTankReservesState.h"
#include "EDeformType.h"
#include "ReplicatedCreativeColorPickState.h"
#include "ReplicatedAugmentState.h"
#include "VoxelMaterialProperties.h"
#include "EAugmentProperty.h"
#include "Engine/EngineTypes.h"
#include "ClickResult.h"
#include "DeformTool.generated.h"

class ATerrainBrush;
class USceneComponent;
class UPowerComponent;
class AActor;
class UActivation;
class APlayController;
class AAstroCharacter;
class UDeformEventReceiver;
class UAugmentComponent;
class UMaterialInterface;
class UParticleSystemComponent;
class UDeformToolCameraContext;
class AAstroPlanet;
class UClickQuery;
class UItemType;
class UDeformTargetComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ADeformTool : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FLinearColor NeutralTerrainColor;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference DeformEffectReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference BurnoffEffectReference;

    UPROPERTY(EditDefaultsOnly)
    TArray<FName> ParticleEmitterNames;

    UPROPERTY(EditDefaultsOnly)
    TArray<FName> AudioSurfaceTypeSwitchState;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector HitLocation;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector HitNormal;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> DeformFXActor;

    UPROPERTY(EditAnywhere)
    TSubclassOf<ATerrainBrush> TerrainBrushActor;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnDeformToolEquippedStateChanged;

    UPROPERTY()
    FSignal OnSampledTerrainMaterialChanged;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVoxelMaterial SampledTerrainMaterial;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVoxelMaterial PaintingTerrainMaterial;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVoxelMaterial TerrainBrushMaterial;

    UPROPERTY(BlueprintReadWrite, Replicated, meta = (AllowPrivateAccess = true))
    EDeformToolSedimentTankReservesState bSedimentTankReservesState;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *usingTool;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    APlayController *OwningController;

    UPROPERTY(Transient)
    AAstroCharacter *OwningCharacter;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    ATerrainBrush *TerrainBrush;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *FXSpawnComponent;

    UPROPERTY(Export)
    UDeformEventReceiver *EventReceiver;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UPowerComponent *PowerComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BaseBrushDeformationScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BaseBrushIndicatorScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BaseDeformationItensity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BaseCreativeDeformationIntensity;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float CreativeBaseDeformationIntensityMin;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float CreativeBaseDeformationIntensityMax;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float CreativeBaseBrushDeformationScaleMin;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float CreativeBaseBrushDeformationScaleMax;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float CreativeToolRangeMax;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CreativeBaseBrushDeformationIntensityAdjustmentIncrement;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CreativeBaseBrushDeformationScaleAdjustmentIncrement;

    UPROPERTY(EditAnywhere)
    float SphereCastRatio;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LerpRate;

    UPROPERTY(EditAnywhere)
    float PlayerSafeZone;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ToolRange;

    UPROPERTY(EditAnywhere)
    float LowPowerMultiplier;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SedimentBaseRate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SedimentDeformationRatio;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SedimentFullySuppliedAmount;

    UPROPERTY(EditAnywhere)
    float FXFrequency;

    UPROPERTY(EditAnywhere)
    float FXSubtractVelocity;

    UPROPERTY(EditAnywhere)
    float FXAddVelocity;

    UPROPERTY(EditAnywhere)
    float FXRadialVelocity;

    UPROPERTY(EditAnywhere)
    float FXSubtractVelocityRandomness;

    UPROPERTY(EditAnywhere)
    float FXScale;

    UPROPERTY(EditAnywhere)
    float FXScaleRandomness;

    UPROPERTY(EditAnywhere)
    float FXSubtractSpawnHeight;

    UPROPERTY(EditAnywhere)
    float FXAddSpawnHeight;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float MiningValue;

private:
    UPROPERTY(Replicated)
    FReplicatedBrushState RepBrushState;

    UPROPERTY(Replicated)
    FReplicatedAugmentState RepAugmentState;

    UPROPERTY(ReplicatedUsing = OnReplicated_ColorPickState)
    FReplicatedCreativeColorPickState RepCreativeColorPickState;

    UPROPERTY(ReplicatedUsing = OnReplicated_TerrainSample)
    FVoxelMaterialProperties RepTerrainSample;

    UPROPERTY(Export)
    TArray<UAugmentComponent *> AttachedAugments;

    UPROPERTY(Export)
    TArray<UAugmentComponent *> EquippedAugments;

    UPROPERTY(Export, Transient)
    UParticleSystemComponent *DeformEffectComponent;

    UPROPERTY(Export, Transient)
    UParticleSystemComponent *BurnoffEffectComponent;

    UPROPERTY(Export)
    UDeformToolCameraContext *CameraContext;

    UPROPERTY()
    uint32 BrushMaterialIndex;

    UPROPERTY(Replicated)
    float TotalSedimentAvailable;

    UPROPERTY(Replicated)
    float TotalSedimentCapacity;

    UPROPERTY(Replicated)
    float SedimentDeformationDelta;

    UPROPERTY(EditAnywhere)
    float DeformTier;

public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    EDeformType Operation;

private:
    UPROPERTY(Replicated)
    uint8 bDeformationActive : 1;

    UPROPERTY(Replicated)
    uint8 bDeformationFullPower : 1;

    UPROPERTY(Replicated)
    uint8 bCreativeModeIgnoreHardness : 1;

public:
    UPROPERTY(EditAnywhere)
    uint8 IsOwnedTool : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 ToolActive : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 TerrainStreamEffectsActive : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 AudioBurnOffPlaying : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 MinedMineral : 1;

    ADeformTool();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    bool UpdateTerrainSample(AAstroPlanet *Planet, const FVector &Location);

    UFUNCTION()
    void UpdateAugmentModifiedProperties();

    UFUNCTION()
    void TryEquipAugment(UAugmentComponent *augment, EAugmentProperty augmentProperty);

    UFUNCTION()
    void ToolClickQuery(UClickQuery *ClickQuery);

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
    void ServerSendSampledTerrainUpdate(const FVector &Location);

    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerSendBrushUpdates(const FReplicatedBrushState &repState);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerRequestNewMaterialWithTerrainProperties(AAstroPlanet *Planet, const FVoxelMaterialProperties &TerrainProperties, UMaterialInterface *CustomMaterial, int32 creativeModePaintMaterialIndex);

    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerEndDeforming();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerDoDeformTarget(UDeformTargetComponent *deformTarget);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCreativeModeColorPick(const FVector &Location);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCreativeModeColorChange(const FVoxelMaterialProperties &Properties, const FVector &Location, UMaterialInterface *CustomMaterial, int32 creativeModePaintMaterialIndex);

    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerBeginDeforming();

    UFUNCTION()
    void PhysicalItemUnslotted(APhysicalItem *ItemOwner);

    UFUNCTION()
    void PhysicalItemSlotted(APhysicalItem *ItemOwner);

    UFUNCTION()
    void OnUseLegacyAddModeChanged(bool UseLegacyAddMode);

    UFUNCTION()
    void OnReplicated_TerrainSample();

    UFUNCTION()
    void OnReplicated_ColorPickState();

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnInteraction(const FClickResult &Click);

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
    bool InteractActorTick(AActor *interactActor);

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
    void HandleTerrainTool(APlayController *Controller, const FHitResult &toolHit, const FClickResult &ClickResult, bool startedInteraction, bool isUsingTool, bool justActivated, bool canUse);

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
