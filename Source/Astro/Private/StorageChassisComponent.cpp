#include "StorageChassisComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class APlayerController;
class UItemType;
class APhysicalItem;
class AActor;
class USlotOrganizationRule;
class UStorageChassisComponent;

void UStorageChassisComponent::TertiaryUse(APlayerController* Controller) {
}

void UStorageChassisComponent::SlotEvent(APhysicalItem* Item) {
}

bool UStorageChassisComponent::QueryTertiary(APlayerController* Controller, FTransform& OutTransform) {
    return false;
}

void UStorageChassisComponent::OnRep_SlotIndicatorLocations() {
}

void UStorageChassisComponent::OnRep_ActorAttachments() {
}

void UStorageChassisComponent::OnPlayerEnterExitAttachment(bool Entered) {
}

void UStorageChassisComponent::OnOwnerDestroyed(AActor* Owner) {
}

void UStorageChassisComponent::ItemAmountChangeEvent() {
}

TArray<FSlotReference> UStorageChassisComponent::GetUnmanagedSlots(bool bCheckingFullness) const {
    return TArray<FSlotReference>();
}

UStorageChassisComponent* UStorageChassisComponent::GetOutermostStorage(AActor* Actor, bool Inclusive) {
    return NULL;
}

UStorageChassisComponent* UStorageChassisComponent::GetActorStorageChassisComponent(AActor* Actor) {
    return NULL;
}

USlotOrganizationRule* UStorageChassisComponent::FindRuleByName(FName RuleName) {
    return NULL;
}

int32 UStorageChassisComponent::ChangeDeformationDeltaInConnectedSlotNetwork(int32 sedimentAmount, TSubclassOf<UItemType> deformedItemType) {
    return 0;
}

void UStorageChassisComponent::CalculateItemReservesInConnectedSlotNetwork(TSubclassOf<UItemType> ItemType, int32& outCurrentStoredItemAmount, int32& outMaxStorageSize) {
}

bool UStorageChassisComponent::AuthorityPlaceItemInLocalStorage(APhysicalItem* Item) {
    return false;
}

bool UStorageChassisComponent::AuthorityPlaceItemInConnectedSlotNetwork(APhysicalItem* Item, AActor* SourceOwner) {
    return false;
}

void UStorageChassisComponent::AuthorityApplyOrganizationRules() {
}

int32 UStorageChassisComponent::AddItem(TSubclassOf<UItemType> ItemType, int32 ItemAmount) {
    return 0;
}

void UStorageChassisComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UStorageChassisComponent, ActorAttachments);
    DOREPLIFETIME(UStorageChassisComponent, OwnerFacingBack);
    DOREPLIFETIME(UStorageChassisComponent, SlotIndicatorLocations);
}

UStorageChassisComponent::UStorageChassisComponent() {
    this->CanExit = true;
    this->IndicateExit = true;
    this->OwnerFacingBack = false;
    this->TertiaryUsable = false;
    this->SaveOnEnter = false;
    this->CanTransferItemsAcrossConnections = false;
    this->bPrioritizeNestedStorage = true;
    this->bPassActuateEventsToSlottedItems = true;
    this->bCanNest = true;
    this->IsSpawnPoint = false;
    this->IsNewPlayerSpawnPoint = false;
    this->IsDefaultSpawnPoint = false;
    this->SpawnPointPriority = 0;
}

