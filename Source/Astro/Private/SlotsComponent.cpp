#include "SlotsComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class APhysicalItem;
class UItemType;
class USlotBehavior;
class AActor;
class UAstroSaveCustomArchiveProxy;
class ASlotConnection;
class USlotsComponent;
class UStaticMeshComponent;
class USlotDelegates;
class AAstroPlayerController;

bool USlotsComponent::TakeSlotItemOfTypeFromOther(FSlotReference Slot, FSlotReference Other, TSubclassOf<UItemType> Type) {
    return false;
}

bool USlotsComponent::TakeSlotItemFromOther(FSlotReference Slot, FSlotReference Other) {
    return false;
}

bool USlotsComponent::SpawnItemTypeInSlotWithDefaultContainer(FSlotReference Slot, TSubclassOf<UItemType> Type, TSubclassOf<UItemType> DefaultContainerType, bool StartFull) {
    return false;
}

bool USlotsComponent::SpawnItemTypeInSlot(FSlotReference Slot, TSubclassOf<UItemType> Type, bool StartFull) {
    return false;
}

APhysicalItem* USlotsComponent::SpawnActorInSlot(FSlotReference Slot, TSubclassOf<APhysicalItem> Class) {
    return NULL;
}

bool USlotsComponent::SlotValidSlow(FSlotReference Slot) {
    return false;
}

bool USlotsComponent::SlotValid(FSlotReference Slot) {
    return false;
}

bool USlotsComponent::SlotsEqual(FSlotReference A, FSlotReference B) {
    return false;
}

int32 USlotsComponent::SlotPushIndicatorItemTypes(FSlotReference Slot, int32 Count, TArray<int32>& OutSubslotIndices, const FSlotIndicatorDefinition& IndicatorDefinition) {
    return 0;
}

bool USlotsComponent::SlotPowerIncomingOnly(FSlotReference Slot) {
    return false;
}

bool USlotsComponent::SlotIsTrailerHitch(FSlotReference Slot) {
    return false;
}

int32 USlotsComponent::SlotGetTier(FSlotReference Slot) {
    return 0;
}

int32 USlotsComponent::SlotGetNumIndicators(FSlotReference Slot) {
    return 0;
}

void USlotsComponent::SlotEnable(FSlotReference Slot, bool Enable) {
}

void USlotsComponent::SlotDestroyIndicators(FSlotReference Slot) {
}

int32 USlotsComponent::SlotAttemptToPushIndicatorIntoSpecificSubslot(const FSlotReference& Slot, int32 SubslotIndex, const FSlotIndicatorDefinition& IndicatorDefinition) {
    return 0;
}

bool USlotsComponent::SlotAttemptToChangeItemAmountNormalized(FSlotReference Slot, TSubclassOf<UItemType> ItemType, float normalizedAmount) {
    return false;
}

bool USlotsComponent::SlotAddIndicatorItemTypeAttemptPackage(FSlotReference Slot, TSubclassOf<UItemType> ItemType) {
    return false;
}

bool USlotsComponent::SlotAddIndicatorItemType(FSlotReference Slot, TSubclassOf<UItemType> ItemType) {
    return false;
}

bool USlotsComponent::SlotAddIndicatorItemAttemptPackage(FSlotReference Slot, TSubclassOf<APhysicalItem> Type) {
    return false;
}

bool USlotsComponent::SlotAddIndicatorItem(FSlotReference Slot, TSubclassOf<APhysicalItem> Type) {
    return false;
}

bool USlotsComponent::SlotAcceptsItemTypeWithChangeInAmount(FSlotReference Slot, TSubclassOf<UItemType> ItemType, bool isChangePositive) {
    return false;
}

bool USlotsComponent::SlotAcceptsItem(FSlotReference Slot, APhysicalItem* Item) {
    return false;
}

void USlotsComponent::SetTracePrimitivesAsleep(bool bAreAsleep) {
}

void USlotsComponent::SetSlotRelativeTransform(FSlotReference Slot, FTransform Transform) {
}

void USlotsComponent::SetSlotHidden(FSlotReference SlotRef, bool bIsHidden) {
}

void USlotsComponent::SetSlotClickable(FSlotReference A, bool clickable) {
}

void USlotsComponent::SetSlotBreakable(FSlotReference Slot, bool Breakable) {
}

void USlotsComponent::SetSlotAcceptsUnslottableItems(FSlotReference SlotRef, bool bAcceptsUnslottableItems) {
}

void USlotsComponent::SetSlotAcceptsItems(FSlotReference A, bool bAcceptsItems) {
}

void USlotsComponent::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void USlotsComponent::ReleaseSlotItemForce(FSlotReference Slot, float RandomForce) {
}

void USlotsComponent::ReleaseItemWithEjectionImpulse(FSlotReference Slot, APhysicalItem* Item, bool NewOwner, bool FromTool, FVector ejectionImpulse, FVector ejectionImpulseOffset) {
}

void USlotsComponent::ReleaseItem(FSlotReference Slot, APhysicalItem* Item, bool NewOwner, bool FromTool, float RandomForce) {
}

void USlotsComponent::OnSlotItemDestroyed(AActor* Actor) {
}

void USlotsComponent::OnSlotIndicatorClicked(FSlotReference Slot, TSubclassOf<UItemType> Type) {
}

void USlotsComponent::OnRep_SlotTransitions() {
}

void USlotsComponent::OnRep_SlotsAcceptItems() {
}

void USlotsComponent::OnRep_SlotRuleStatus() {
}

void USlotsComponent::OnRep_SlotClickability() {
}

void USlotsComponent::MulticastCancelSlotBehaviorTerrainInterpolation_Implementation() {
}

FSlotReference USlotsComponent::MakeReference(FName SlotName) const {
    return FSlotReference{};
}

ASlotConnection* USlotsComponent::MakeExclusiveConnection(FSlotReference A, FSlotReference B, TSubclassOf<ASlotConnection> OverrideType) {
    return NULL;
}

ASlotConnection* USlotsComponent::MakeConnection(FSlotReference A, FSlotReference B, TSubclassOf<ASlotConnection> OverrideType, bool Visible) {
    return NULL;
}

ESlotType USlotsComponent::GetSlotType(FSlotReference Slot) {
    return ESlotType::Power;
}

FTransform USlotsComponent::GetSlotTransform(FSlotReference Slot) {
    return FTransform{};
}

FTransform USlotsComponent::GetSlotRelativeTransform(FSlotReference Slot) {
    return FTransform{};
}

APhysicalItem* USlotsComponent::GetSlotPrimaryItem(FSlotReference Slot) {
    return NULL;
}

USlotsComponent* USlotsComponent::GetSlotOwner(FSlotReference Slot) {
    return NULL;
}

ESlotConfiguration USlotsComponent::GetSlotOrientationConfiguration(FSlotReference Slot) {
    return ESlotConfiguration::Vertical;
}

TArray<UStaticMeshComponent*> USlotsComponent::GetSlotLegacyMeshes(FSlotReference Slot) {
    return TArray<UStaticMeshComponent*>();
}

TArray<APhysicalItem*> USlotsComponent::GetSlotItems(FSlotReference Slot) {
    return TArray<APhysicalItem*>();
}

APhysicalItem* USlotsComponent::GetSlotItem(FSlotReference Slot, int32 SubslotIndex) {
    return NULL;
}

TArray<ASlotConnection*> USlotsComponent::GetSlotExternalConnections(FSlotReference Slot) {
    return TArray<ASlotConnection*>();
}

USlotDelegates* USlotsComponent::GetSlotDelegates(FSlotReference Slot) {
    return NULL;
}

ESlotConnectorType USlotsComponent::GetSlotConnectorType(FSlotReference Slot) {
    return ESlotConnectorType::Plug;
}

FSlotReference USlotsComponent::GetSlotConnectedSlot(FSlotReference Slot) {
    return FSlotReference{};
}

TArray<USlotBehavior*> USlotsComponent::GetSlotBehaviors(FSlotReference Slot) {
    return TArray<USlotBehavior*>();
}

void USlotsComponent::EmplaceSlotItem(FSlotReference Slot, APhysicalItem* Item, bool SnapTo, bool weld) {
}

void USlotsComponent::DestroySlotItem(FSlotReference Slot) {
}

void USlotsComponent::ConnectPowerToItem(FSlotReference SlotRef, APhysicalItem* Item) {
}

void USlotsComponent::BreakAllSlotConnections(FSlotReference Slot) {
}

void USlotsComponent::AuxUseRight(AAstroPlayerController* Controller, EInputEvent InputEvent) {
}

void USlotsComponent::AuxUseLeft(AAstroPlayerController* Controller, EInputEvent InputEvent) {
}

void USlotsComponent::AuxUseAll(AAstroPlayerController* Controller, EInputEvent InputEvent) {
}

void USlotsComponent::AuxUse(FSlotReference AuxSlot, AAstroPlayerController* Controller, EInputEvent InputEvent) {
}

void USlotsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(USlotsComponent, SlotTransitions);
    DOREPLIFETIME(USlotsComponent, ReplicatedSlotClickability);
    DOREPLIFETIME(USlotsComponent, ReplicatedSlotsAcceptItems);
    DOREPLIFETIME(USlotsComponent, ReplicatedSlotRuleStatus);
}

USlotsComponent::USlotsComponent() {
    this->bPreserveLegacyVisuals = true;
}

