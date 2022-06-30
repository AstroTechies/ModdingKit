#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "EDeformType.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "VoxelMaterial.h"
#include "TerrainBrush.generated.h"

class UMaterialInstanceDynamic;
class UDeformTargetComponent;
class UParticleSystemComponent;
class UTexture2D;
class UItemType;
class UTooltipComponent;
class USceneComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ATerrainBrush : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    EDeformType ActiveOperation;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 LastTerrainHardness;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float BrushIndicatorScale;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float BrushIndicatorIntensity;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float BrushIndicatorUsing;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 bBrushIndicatorCanUse : 1;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UDeformTargetComponent *TargetComponent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector BrushLocation;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector BrushNormal;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FTransform TargetTransform;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 PlayerAccentIndex;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float GaugePercent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float GaugeCapacity;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float LowSedimentThreshold;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference DeformEffectReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference AddBrushReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference SubtractBrushReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference FlatBrushReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference ColorPaintBrushReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference ColorPickerBrushReference;

    UPROPERTY(Export, Transient)
    UParticleSystemComponent *DeformEffectComponent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UMaterialInstanceDynamic *BrushDiscMaterial;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UTexture2D *HardnessTextureLevel0;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UTexture2D *HardnessTextureLevel1;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UTexture2D *HardnessTextureLevel2;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UTexture2D *HardnessTextureLevel3;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    UTexture2D *FlattenGridTexture;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool IsLocalBrush;

private:
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UItemType>> LowPriorityResourceTooltipTypes;

    UPROPERTY(EditDefaultsOnly)
    float ResourceNodeTooltipBadgeAutoCollapseDelay;

    UPROPERTY(EditDefaultsOnly)
    float ResourceNodeTooltipDetailsAutoExpandDelay;

    UPROPERTY(EditDefaultsOnly)
    float CursorDetailsExpansionMovementTolerance;

    UPROPERTY(EditDefaultsOnly)
    float ThrottledNativeTickInterval;

    UPROPERTY(Export, Transient)
    UTooltipComponent *ResourceNodeTooltipComponent;

    UPROPERTY(Transient)
    TSubclassOf<UItemType> CurrentItemTypeForResourceTooltip;

    UPROPERTY(Export, Transient)
    USceneComponent *AddBrushComponent;

    UPROPERTY(Export, Transient)
    USceneComponent *SubtractBrushComponent;

    UPROPERTY(Export, Transient)
    USceneComponent *FlatBrushComponent;

    UPROPERTY(Export, Transient)
    USceneComponent *ColorPickerBrushComponent;

    UPROPERTY(Export, Transient)
    USceneComponent *ColorPaintBrushComponent;

public:
    ATerrainBrush();
    UFUNCTION(BlueprintCallable)
    void ShowBrushElements(EDeformType deformType, bool showElement);

    UFUNCTION(BlueprintCallable)
    void SetResourceTooltipSuppression(bool SuppressResourceTooltip);

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnDeactivate();

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnBrushColorChanged(const FVoxelMaterial &TerrainMaterial);

    UFUNCTION(BlueprintImplementableEvent)
    void OnActivate();

    UFUNCTION(BlueprintCallable)
    void ManageTerrainHardnessTexture();

protected:
    UFUNCTION(BlueprintImplementableEvent)
    UTooltipComponent *GetResourceNodeTooltip();

public:
    UFUNCTION(BlueprintCallable)
    void ChangeBrushOperation(EDeformType NewType);
};
