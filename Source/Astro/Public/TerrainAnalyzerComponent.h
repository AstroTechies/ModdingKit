#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "VoxelMaterialProperties.h"
#include "TerrainAnalyzerComponent.generated.h"

UCLASS(Blueprintable, Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTerrainAnalyzerComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool AnalyzedTerrainRetainsHardness;

    UPROPERTY(EditAnywhere)
    float BaseFillRate;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    uint8 bAnalysisHasStarted : 1;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnReplicated_AnalysisIsComplete, meta = (AllowPrivateAccess = true))
    uint8 bAnalysisIsComplete : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 bAnalysisInProgress : 1;

private:
    UPROPERTY(SaveGame, ReplicatedUsing = OnReplicated_AnalyzedTerrainMaterialSample)
    FVoxelMaterialProperties AnalyzedTerrainMaterialSample;

public:
    UTerrainAnalyzerComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void TryGetTerrainFromColor(bool completeIfSuccessful);

public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAnalysisInProgress(bool InProgress);

private:
    UFUNCTION()
    void SampledTerrainChanged();

    UFUNCTION()
    void OnReplicated_AnalyzedTerrainMaterialSample();

    UFUNCTION()
    void OnReplicated_AnalysisIsComplete();

    UFUNCTION()
    void OnAugmentUnequipped();

    UFUNCTION()
    void OnAugmentEquipped();

public:
    UFUNCTION(BlueprintPure)
    TEnumAsByte<EPhysicalSurface> GetAnalyzedMaterialSurfaceType() const;

    UFUNCTION(BlueprintPure)
    FLinearColor GetAnalyzedMaterialColor() const;

private:
    UFUNCTION()
    void EndDeform();

    UFUNCTION()
    void BeginDeform();

    UFUNCTION()
    void AttemptAnalysis(float DeltaTime);
};
