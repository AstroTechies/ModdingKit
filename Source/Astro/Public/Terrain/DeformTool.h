// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TerrainBrush.h"
#include "Utilities/ActivationSignals.h"
#include "Items/PhysicalItem.h"
#include "DeformTool.generated.h"

class APlayController;
class AAstroCharacter;
class AAstroPlanet;
class UClickQuery;
class UPowerComponent;
class UAugmentComponent;

UENUM()
enum class EDeformToolSedimentTankReservesState : uint8 {
	NoReserves = 0,
	ReservesEmpty = 1,
	ReservesPartiallyFull = 2,
	ReservesFull = 3
};

UENUM()
enum class EDeformType : uint8 {
	Subtract = 0,
	Add = 1,
	Flatten = 2,
	ColorPick = 3,
	ColorPaint = 4,
	CountCreative = 5,
	Crater = 6,
	FlattenSubtractOnly = 7,
	FlattenAddOnly = 8,
	TrueFlatStamp = 9,
	PlatformSurface = 10,
	Count = 11
};

UCLASS()
class ASTRO_API ADeformTool : public APhysicalItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetDeformTier();
	UFUNCTION(BlueprintCallable, BlueprintPure) FVector GetDeformLocation();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool GetIsDeforming();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool GetOwnerBackpackRasied();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetAugmentedTerrainHardness();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetEffectiveBrushScale();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetEffectiveIndicatorScale();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetEffectiveDeformationIntensity();
	UFUNCTION(BlueprintCallable, BlueprintPure) float AuthorityGetEffectiveHardnessTier();
	UFUNCTION(BlueprintCallable) void AdjustSedimentTankAmountFromDeformationDelta(float deformationDelta);
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetSedimentFlowRate();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetSedimentDeformationDelta();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetSedimentAvailable();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool GetDeformationIsActive();
	UFUNCTION(BlueprintCallable) void CheckForOrphanedTool();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool IsToolDeployed();
	UFUNCTION(BlueprintCallable) void IncrementCreativeBaseDeformationIntensity(float delta);
	UFUNCTION(BlueprintCallable) void IncrementCreativeBaseBrushDeformationScale(float delta);
	UFUNCTION(BlueprintCallable) void SetCreativeBaseDeformationIntensity(float newVal);
	UFUNCTION(BlueprintCallable) void SetCreativeToolRange(float newVal);
	UFUNCTION(BlueprintCallable) void SetCreativeBaseDeformationScale(float newVal);
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetCreativeToolRange();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetCreativeBaseDeformationIntensity();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetCreativeDeformationIntensityNormalized();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetCreativeBaseBrushDeformationScale();
	UFUNCTION(BlueprintCallable) void OnReplicated_TerrainSample();
	UFUNCTION(BlueprintCallable) void OnReplicated_ColorPickState();
	UFUNCTION(BlueprintCallable) void Activated();
	UFUNCTION(BlueprintCallable) void Deactivated();
	UFUNCTION(BlueprintCallable) void CycleModeRight();
	UFUNCTION(BlueprintCallable) void CycleModeLeft();
	UFUNCTION(BlueprintCallable) void OnUseLegacyAddModeChanged(bool useLegacyAddMode);
	UFUNCTION(BlueprintCallable) void OnCreativeModeActiveStateChanged(bool isEnabled);
	UFUNCTION(BlueprintCallable, BlueprintPure) bool HasTankReservesNecessaryToAdditivelyDeform();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool HasSpaceLeftInTanks();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetBrushSizeModifierFromAugment();
	UFUNCTION(BlueprintCallable, BlueprintPure) float GetDeformationIntensityModifierFromAugment();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool GetPowerLevelInhibitedFromAugment();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool GetFixedAlignmentFromAugment();
	UFUNCTION(BlueprintCallable) bool UpdateTerrainSample(AAstroPlanet* Planet, FVector Location);
	UFUNCTION(BlueprintCallable) void ToolClickQuery(UClickQuery* clickQuery);
	UFUNCTION(BlueprintCallable) void PhysicalItemSlotted(APhysicalItem* ItemOwner);
	UFUNCTION(BlueprintCallable) void PhysicalItemUnslotted(APhysicalItem* ItemOwner);
	UFUNCTION(BlueprintCallable) void ChangeInAttachedAugments();
	UFUNCTION(BlueprintCallable) void CheckAugmentsHavePower();
	UFUNCTION(BlueprintCallable) void UpdateAugmentModifiedProperties();
	UFUNCTION(BlueprintCallable) void DetermineSedimentTankAmount();
	UFUNCTION(BlueprintCallable, BlueprintPure) bool GetIsIgnoringTerrainHardnessCreative();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FLinearColor NeutralTerrainColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FName> ParticleEmitterNames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FName> AudioSurfaceTypeSwitchState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector HitLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector HitNormal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> DeformFXActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<ATerrainBrush> TerrainBrushActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FEnableSignal OnDeformToolEquippedStateChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable) FSignal OnSampledTerrainMaterialChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EDeformToolSedimentTankReservesState bSedimentTankReservesState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) APlayController* OwningController;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AAstroCharacter* OwningCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ATerrainBrush* TerrainBrush;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USceneComponent* FXSpawnComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UPowerComponent* PowerComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float BaseBrushDeformationScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float BaseBrushIndicatorScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float BaseDeformationItensity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float BaseCreativeDeformationIntensity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CreativeBaseDeformationIntensityMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CreativeBaseDeformationIntensityMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CreativeBaseBrushDeformationScaleMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CreativeBaseBrushDeformationScaleMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CreativeToolRangeMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CreativeBaseBrushDeformationIntensityAdjustmentIncrement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CreativeBaseBrushDeformationScaleAdjustmentIncrement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float SphereCastRatio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float LerpRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float PlayerSafeZone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float ToolRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float LowPowerMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float SedimentBaseRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float SedimentDeformationRatio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float SedimentFullySuppliedAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FXFrequency;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FXSubtractVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FXAddVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FXRadialVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FXSubtractVelocityRandomness;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FXScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FXScaleRandomness;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FXSubtractSpawnHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float FXAddSpawnHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float MiningValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<UAugmentComponent *> AttachedAugments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<UAugmentComponent *> EquippedAugments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float TotalSedimentAvailable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float TotalSedimentCapacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float SedimentDeformationDelta;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float DeformTier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EDeformType Operation;
};
