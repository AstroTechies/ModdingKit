#include "TerrainAnalyzerComponent.h"
#include "Net/UnrealNetwork.h"

UTerrainAnalyzerComponent::UTerrainAnalyzerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AnalyzedTerrainRetainsHardness = false;
    this->BaseFillRate = 0.40f;
    this->bAnalysisHasStarted = false;
    this->bAnalysisIsComplete = false;
    this->bAnalysisInProgress = false;
}

void UTerrainAnalyzerComponent::TryGetTerrainFromColor(bool completeIfSuccessful) {
}


void UTerrainAnalyzerComponent::SampledTerrainChanged() {
}

void UTerrainAnalyzerComponent::OnReplicated_AnalyzedTerrainMaterialSample() {
}

void UTerrainAnalyzerComponent::OnReplicated_AnalysisIsComplete() {
}

void UTerrainAnalyzerComponent::OnAugmentUnequipped() {
}

void UTerrainAnalyzerComponent::OnAugmentEquipped() {
}

TEnumAsByte<EPhysicalSurface> UTerrainAnalyzerComponent::GetAnalyzedMaterialSurfaceType() const {
    return SurfaceType_Default;
}

FLinearColor UTerrainAnalyzerComponent::GetAnalyzedMaterialColor() const {
    return FLinearColor{};
}

void UTerrainAnalyzerComponent::EndDeform() {
}

void UTerrainAnalyzerComponent::BeginDeform() {
}

void UTerrainAnalyzerComponent::AttemptAnalysis(float DeltaTime) {
}

void UTerrainAnalyzerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UTerrainAnalyzerComponent, bAnalysisIsComplete);
    DOREPLIFETIME(UTerrainAnalyzerComponent, AnalyzedTerrainMaterialSample);
}


