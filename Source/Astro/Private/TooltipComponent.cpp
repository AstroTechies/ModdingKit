#include "TooltipComponent.h"

UTooltipComponent::UTooltipComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsActorDefaultTooltip = true;
    this->TooltipArchetype = ETooltipArchetype::Custom;
    this->VisibilityControl = ETooltipVisibilityControl::ShowOnFocus;
    this->bRemainsVisibleWhenHeld = false;
    this->bSuppressOtherTooltipsWhenExpanded = false;
    this->bAlwaysShowLiteralItemType = false;
    this->bSuppressTooltipUse = false;
    this->AnchorReferenceComponent = NULL;
    this->bCanDisplayWhenCracked = false;
    this->ToolTipWidget = NULL;
    this->PrimaryProximitySphereBadge = NULL;
    this->SecondaryProximitySphereBadge = NULL;
    this->ProximitySphereDetails = NULL;
    this->InputRespondingCollider = NULL;
    this->LocalPawnDisplayingProximityTooltip = NULL;
}

void UTooltipComponent::UpdateWidgetOverrideDisplayData(FName overrideName, const FTooltipWidgetDisplayData& DisplayData) {
}

void UTooltipComponent::UpdateWidgetOverrideDescriptionText(FName overrideName, FText newDescription) {
}

void UTooltipComponent::UpdateCorrectedPivotLocation() {
}

void UTooltipComponent::UpdateActiveHoldInput() {
}

void UTooltipComponent::StopCurrentHoldAction(bool InputActionSucceeded) {
}

void UTooltipComponent::SetupTooltipReferenceAnchor() {
}

void UTooltipComponent::SetupTooltipForItemType(const UItemType* ItemType) {
}

void UTooltipComponent::SetupTooltipForCurrentDisplaySettings() {
}

void UTooltipComponent::SetTooltipTitle(FText NewTitle) {
}

void UTooltipComponent::SetTooltipBadgeImage(UObject* ResourceObjectBadge) {
}

void UTooltipComponent::SetTooltipBadgeColor(FLinearColor NewBadgeColor) {
}

void UTooltipComponent::SetInputRespondingCollider(UPrimitiveComponent* NewInputRespondingCollider) {
}

void UTooltipComponent::SetHasFocus(bool bInHasFocus) {
}

void UTooltipComponent::SetDesiredTooltipState(ETooltipState NewState) {
}

void UTooltipComponent::SetCustomTooltipReferenceAnchor(USceneComponent* CustomReferenceAnchor) {
}

void UTooltipComponent::PushTooltipWidgetOverride(FName overrideName, ETooltipVisibilityControl overrideVisibilityControl, bool bInApplyAnchorReferenceOverride, FName AnchorReferenceOverride, bool bInApplyScreenOffsetOverride, FVector2D ScreenOffsetOverride, bool bInRemainsVisibleWhenHeld, bool bInSuppressOtherTooltipsWhenExpanded, bool bInOverrideUseAndExaminePrompts, const FTooltipWidgetDisplayData& DisplayData, const FTooltipProximityBadgeVisibilityData& proximityData) {
}

void UTooltipComponent::PopTooltipWidgetOverride(FName overrideName) {
}

void UTooltipComponent::OnUseContextChanged(EUseContext UseContext) {
}

void UTooltipComponent::OnTooltipWidgetStateChanged() {
}

void UTooltipComponent::OnSecondaryProximitySphereEndOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex) {
}

void UTooltipComponent::OnSecondaryProximitySphereBeginOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UTooltipComponent::OnProximitySphereEndOverlapDetails(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex) {
}

void UTooltipComponent::OnProximitySphereBeginOverlapDetails(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UTooltipComponent::OnPrimaryProximitySphereEndOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex) {
}

void UTooltipComponent::OnPrimaryProximitySphereBeginOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UTooltipComponent::OnOwningSlotCrackedStateChanged(UCrackableActorComponent* CrackableActorComponent, bool IsCracked) {
}

void UTooltipComponent::OnOwningItemReleasedFromSlot(bool NewOwner) {
}

void UTooltipComponent::OnOwningItemPlacedInSlot() {
}

void UTooltipComponent::OnOwnerUseAvailabilityChanged(bool bIsUsable) {
}

void UTooltipComponent::OnOwnerItemTypeChanged() {
}

void UTooltipComponent::OnInteractionActivated(FName ActionName) {
}

void UTooltipComponent::OnInputUnhandled(TEnumAsByte<EInputEvent> InputType, FName ActionName) {
}

void UTooltipComponent::OnActionInputReleased(FName ActionName) {
}

void UTooltipComponent::OnActionInputPressed(FName ActionName) {
}

bool UTooltipComponent::HasTooltipOverride(FName overrideName) {
    return false;
}

ETooltipVisibilityControl UTooltipComponent::GetVisibilityControl() const {
    return ETooltipVisibilityControl::ShowOnFocus;
}

ETooltipProximityState UTooltipComponent::GetProximityState() const {
    return ETooltipProximityState::WithinPrimaryProximity;
}

bool UTooltipComponent::GetHasFocus() const {
    return false;
}

ETooltipState UTooltipComponent::GetDesiredState() const {
    return ETooltipState::Collapsed;
}

AActor* UTooltipComponent::GetActorThisTooltipIsFor() {
    return NULL;
}

void UTooltipComponent::FullyPresentTooltip() {
}


