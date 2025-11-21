#include "DeployableAnchorComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UDeployableAnchorComponent::UDeployableAnchorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->platformPreviewIndicatorSlotWrapper = NULL;
    this->terrainPreviewIndicatorSlotWrapper_MS = NULL;
    this->terrainPreviewIndicatorSlotWrapper_DBP = NULL;
    this->bCanDeploy = false;
    this->bIsPlaced = false;
    this->bCanShowPreview = true;
    this->Offset = 0.00f;
    this->PackagePreviewIndicatorSlotWrapper = NULL;
    this->LineTraceDistance = 3000.00f;
    this->SkyTraceDistance = 15000.00f;
    this->GroundTraceDistance = 500.00f;
    this->BuildingPlatformToSpawn = NULL;
    this->InvalidPlacementMaterial = NULL;
    this->MegaStructureToSpawn = NULL;
    this->TerrainPlatformPreview = NULL;
    this->MegaStructurePreviewRadius = 0.00f;
    this->BuildingPlatformPreviewRadius = 0.00f;
    this->bRequiresTerrainTrace = false;
    this->bIsPlacementValid = false;
}

void UDeployableAnchorComponent::UnpackAnchor() {
}

bool UDeployableAnchorComponent::ShowPlatformPreviewWithMaterial(UMaterialInterface* matInstance) {
    return false;
}

void UDeployableAnchorComponent::ShowAllPreviews(bool bForcePreview) {
}

void UDeployableAnchorComponent::SetupAnchor(const TSubclassOf<UItemType>& PlatformToDeployItemType, const TSubclassOf<UItemType>& MegaStructureToBuildItemType, const TSubclassOf<UItemType>& TerrainPlatformPreviewItemType) {
}

void UDeployableAnchorComponent::SetTerrainPreviewSlotMS(const FSlotReference& NewTerrainPreviewSlot_MS) {
}

void UDeployableAnchorComponent::SetTerrainPreviewSlotDBP(const FSlotReference& NewTerrainPreviewSlot_DBP) {
}

void UDeployableAnchorComponent::SetTerrainPreviewIndicatorSlotWrapperMS(USceneComponent* NewTerrainPreviewIndicatorSlotWrapper_MS) {
}

void UDeployableAnchorComponent::SetTerrainPreviewIndicatorSlotWrapperDBP(USceneComponent* NewTerrainPreviewIndicatorSlotWrapper_DBP) {
}

void UDeployableAnchorComponent::SetStoredItemType(const TSubclassOf<UItemType>& inItemType) {
}

void UDeployableAnchorComponent::SetPlatformSlot(const FSlotReference& NewPlatformSlot) {
}

void UDeployableAnchorComponent::SetPlatformPreviewIndicatorSlotWrapper(USceneComponent* NewPlatformPreviewIndicatorSlotWrapper) {
}

void UDeployableAnchorComponent::SetPackagePreviewIndicatorSlotWrapper(USceneComponent* NewPackagePreviewIndicatorSlotWrapper) {
}

void UDeployableAnchorComponent::SetNeedsTerrainTrace(const bool bInNeedsTerrainTrace) {
}

void UDeployableAnchorComponent::SetMaterialOnAllIndicators(UMaterialInterface* matInstance, bool bForcePreview) {
}

void UDeployableAnchorComponent::SetIsPlaced(const bool inIsPlaced) {
}

void UDeployableAnchorComponent::SetInvalidPlacementMaterial(UMaterialInterface* inMaterial) {
}

void UDeployableAnchorComponent::SetCanShowPreview(const bool inCanShowPreview) {
}

void UDeployableAnchorComponent::SetCanDeploy(const bool inCanDeploy) {
}

void UDeployableAnchorComponent::Moved(bool bFromTool) {
}

bool UDeployableAnchorComponent::IsCurrentPlacementValid() const {
    return false;
}

void UDeployableAnchorComponent::EndCursorOver(AActor* Actor) {
}

void UDeployableAnchorComponent::DropInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

void UDeployableAnchorComponent::ClearAllIndicators() {
}

void UDeployableAnchorComponent::BeginCursorOver(AActor* Actor) {
}

void UDeployableAnchorComponent::AnchorUnemplacedFromSlot() {
}

void UDeployableAnchorComponent::AnchorReleasedFromSlot(bool NewOwner) {
}

void UDeployableAnchorComponent::AnchorPlacedInSlot() {
}

void UDeployableAnchorComponent::AnchorEmplacedInSlot() {
}

void UDeployableAnchorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UDeployableAnchorComponent, bCanDeploy);
    DOREPLIFETIME(UDeployableAnchorComponent, bIsPlaced);
    DOREPLIFETIME(UDeployableAnchorComponent, bCanShowPreview);
}


