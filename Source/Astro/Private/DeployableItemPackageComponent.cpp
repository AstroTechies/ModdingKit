#include "DeployableItemPackageComponent.h"
#include "Templates/SubclassOf.h"

UDeployableItemPackageComponent::UDeployableItemPackageComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PackagePreviewIndicatorSlotWrapper = NULL;
    this->PackageVisualsWrapper = NULL;
    this->OwningItem = NULL;
    this->UnpackIndicatorRoot = NULL;
    this->DoNotAutoDestroyOnUnpack = false;
}

void UDeployableItemPackageComponent::SetupPackagedItem(TSubclassOf<UItemType> ItemTypeToDeploy) {
}

void UDeployableItemPackageComponent::SetupHideIndicatorTimer() {
}

void UDeployableItemPackageComponent::SetCrateMaterialInstance(UTexture* OverlayTexture) {
}

UPrimitiveComponent* UDeployableItemPackageComponent::PreDeployPackagedItem() {
    return NULL;
}

void UDeployableItemPackageComponent::PackageUnemplacedFromSlot() {
}

void UDeployableItemPackageComponent::PackageSetCardinalDirection() {
}

void UDeployableItemPackageComponent::PackageReleasedFromSlot(bool NewOwner) {
}

void UDeployableItemPackageComponent::PackagePlacedInSlot() {
}

void UDeployableItemPackageComponent::PackageEmplacedInSlot() {
}

void UDeployableItemPackageComponent::OnItemComponentChanged() {
}

void UDeployableItemPackageComponent::Moved(bool FromTool) {
}

void UDeployableItemPackageComponent::HideIndicator() {
}

void UDeployableItemPackageComponent::GeneralSlotEvent(APhysicalItem* Item) {
}

void UDeployableItemPackageComponent::EndCursorOver(AActor* Actor) {
}

void UDeployableItemPackageComponent::DropInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

void UDeployableItemPackageComponent::DeployPackagedItem() {
}

void UDeployableItemPackageComponent::ClearHideIndicatorTimer() {
}

void UDeployableItemPackageComponent::BeginCursorOver(AActor* Actor) {
}


