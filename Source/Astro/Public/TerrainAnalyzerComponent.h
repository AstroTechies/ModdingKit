#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Chaos/ChaosEngineInterface.h"
#include "VoxelMaterialProperties.h"
#include "TerrainAnalyzerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTerrainAnalyzerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AnalyzedTerrainRetainsHardness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseFillRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bAnalysisHasStarted: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnReplicated_AnalysisIsComplete, meta=(AllowPrivateAccess=true))
    uint8 bAnalysisIsComplete: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAnalysisInProgress: 1;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnReplicated_AnalyzedTerrainMaterialSample, meta=(AllowPrivateAccess=true))
    FVoxelMaterialProperties AnalyzedTerrainMaterialSample;
    
public:
    UTerrainAnalyzerComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void TryGetTerrainFromColor(bool completeIfSuccessful);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAnalysisInProgress(bool InProgress);
    
private:
    UFUNCTION(BlueprintCallable)
    void SampledTerrainChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnReplicated_AnalyzedTerrainMaterialSample();
    
    UFUNCTION(BlueprintCallable)
    void OnReplicated_AnalysisIsComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnAugmentUnequipped();
    
    UFUNCTION(BlueprintCallable)
    void OnAugmentEquipped();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EPhysicalSurface> GetAnalyzedMaterialSurfaceType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetAnalyzedMaterialColor() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void EndDeform();
    
    UFUNCTION(BlueprintCallable)
    void BeginDeform();
    
    UFUNCTION(BlueprintCallable)
    void AttemptAnalysis(float DeltaTime);
    
};

