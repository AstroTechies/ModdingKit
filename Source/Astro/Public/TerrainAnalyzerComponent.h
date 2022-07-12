#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=VoxelMaterialProperties -FallbackName=VoxelMaterialProperties
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
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
    UTerrainAnalyzerComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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

