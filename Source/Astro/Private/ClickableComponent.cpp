#include "ClickableComponent.h"
#include "Net/UnrealNetwork.h"

UClickableComponent::UClickableComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->PositioningComponent = NULL;
    this->PrimaryIndicatorMesh = NULL;
    this->SecondaryIndicatorMesh = NULL;
    this->PrimaryIndicatorScale = 0.33f;
    this->PrimaryHoverHeight = 70.00f;
    this->SecondaryIndicatorScale = 0.33f;
    this->BackpackInteraction = false;
    this->ShowPrimaryIndicator = true;
    this->ShowPrimaryIcon = true;
    this->CaptureDeformTool = false;
    this->EncapsulateChildren = false;
    this->DisablePrimitiveClicks = false;
    this->ReplaceChildren = false;
    this->AllowNonOwnerClicks = false;
    this->LocalPrimitiveClicksOnly = false;
    this->CaptureViewActor = true;
    this->UnencapsulateChildren = false;
    this->Unclickable = false;
    this->NoGamepadAutoselect = false;
    this->Unmovable = false;
    this->bSlowVirtualCursorOnHover = true;
    this->bExcludeNonInteractPrimitivesFromGamepadAutoFocus = false;
    this->HasUseInteractionByDefault = false;
    this->HasAuxSlotUseByDefault = false;
    this->HasActuatorUseByDefault = false;
    this->HasUseWhilePlayerDriving = false;
    this->HasInfoOnlyTooltipWhilePlayerDriving = false;
    this->UseActionRequriesHold = true;
    this->bUseOverridePivotOffset = false;
    this->SecondaryInteractionTime = 0.33f;
    this->DefaultUseContext = EUseContext::UC_Use;
}

void UClickableComponent::SetInteractionRedirectActor(AActor* Actor, USceneComponent* PivotComponent) {
}

void UClickableComponent::SetActiveUseContext(EUseContext NewUseContext) {
}

void UClickableComponent::PushUseSuppression_AuthorityOnly(const FName SuppressionId, EUseType useTypeFlags) {
}

void UClickableComponent::PushOrPopUseSuppression_AuthorityOnly(FName SuppressionId, bool shouldSuppress, EUseType useTypeFlags) {
}

void UClickableComponent::PopUseSuppression_AuthorityOnly(const FName SuppressionId) {
}

void UClickableComponent::OnRep_UseSuppressionState() {
}

bool UClickableComponent::HasInteractionRedirect() {
    return false;
}

bool UClickableComponent::GetUseCapability(EUseType useType) {
    return false;
}

bool UClickableComponent::GetUseAvailability(const APlayerController* Instigator, EUseType useType) {
    return false;
}

USceneComponent* UClickableComponent::GetPositionComponent() const {
    return NULL;
}

USceneComponent* UClickableComponent::GetActorClickableOrRoot(AActor* Actor) {
    return NULL;
}

UClickableComponent* UClickableComponent::GetActorClickableOrDefault(AActor* Actor) {
    return NULL;
}

EUseContext UClickableComponent::GetActiveUseContext() const {
    return EUseContext::UC_Use;
}

UClickableComponent* UClickableComponent::ActorClickable(AActor* Actor) {
    return NULL;
}

void UClickableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UClickableComponent, UnencapsulateChildren);
    DOREPLIFETIME(UClickableComponent, UseSuppressionState);
}


