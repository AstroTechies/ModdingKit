#include "ItemComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UItemComponent::UItemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StartingAmount = 0.00f;
    this->Discrete = false;
    // If this is a canister, how much can it hold?
    this->Capacity = 1.00f;
    this->ItemType = NULL;
    this->storedSubItemType = NULL;
    this->Amount = 0;
}

int32 UItemComponent::TakeItemRateDelta(float Rate, float DeltaTime) {
    return 0;
}

int32 UItemComponent::TakeItemRate(float Rate) {
    return 0;
}

int32 UItemComponent::TakeItem(int32 TakeAmount) {
    return 0;
}

void UItemComponent::SetItemUsingFullness(TSubclassOf<UItemType> NewItemType, float Fullness, bool suppressItemDrainedFillChangeEventBroadcast) {
}

void UItemComponent::SetItem(TSubclassOf<UItemType> NewItemType, int32 NewAmount, bool suppressItemDrainedFillChangeEventBroadcast) {
}

float UItemComponent::SetAmountUsingFullness(float newFullness, bool suppressItemDrainedFillChangeEventBroadcast) {
    return 0.0f;
}

int32 UItemComponent::SetAmount(int32 NewAmount, bool suppressItemDrainedFillChangeEventBroadcast) {
    return 0;
}

void UItemComponent::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void UItemComponent::OnRepAmount(int32 previousAmount) {
}

void UItemComponent::OnRep() {
}

bool UItemComponent::IsFull() const {
    return false;
}

bool UItemComponent::IsEmptyContainer() const {
    return false;
}

bool UItemComponent::IsEmpty() const {
    return false;
}

bool UItemComponent::IsContainer() const {
    return false;
}

bool UItemComponent::HaveItem(TSubclassOf<UItemType> Type) const {
    return false;
}

TSubclassOf<UItemType> UItemComponent::GetStoredSubItemTypeClass() const {
    return NULL;
}

UItemType* UItemComponent::GetStoredSubItemTypeCDO() const {
    return NULL;
}

float UItemComponent::GetRecipeAmount() const {
    return 0.0f;
}

TSubclassOf<UItemType> UItemComponent::GetLiteralItemTypeClass() const {
    return NULL;
}

UItemType* UItemComponent::GetLiteralItemTypeCDO() const {
    return NULL;
}

int32 UItemComponent::GetInstanceCount(int32 maxNumInstances) const {
    return 0;
}

TSubclassOf<UItemType> UItemComponent::GetFunctionalItemTypeClass() const {
    return NULL;
}

UItemType* UItemComponent::GetFunctionalItemTypeCDO() const {
    return NULL;
}

float UItemComponent::GetFullness() const {
    return 0.0f;
}

int32 UItemComponent::GetAmount() const {
    return 0;
}

UItemComponent* UItemComponent::GetActorItemComponent(AActor* Actor) {
    return NULL;
}

void UItemComponent::ForceChangePrimaryItemTypeAndStoredSubItemTypeWithAmount(TSubclassOf<UItemType> primaryItemType, TSubclassOf<UItemType> NewStoredSubItemType, int32 NewAmount, bool suppressItemDrainedFillChangeEventBroadcast) {
}

void UItemComponent::ClearContainer() {
}

int32 UItemComponent::AddItemRateDelta(TSubclassOf<UItemType> Type, float Rate, float DeltaTime) {
    return 0;
}

int32 UItemComponent::AddItemRate(TSubclassOf<UItemType> Type, float Rate) {
    return 0;
}

int32 UItemComponent::AddItem(TSubclassOf<UItemType> Type, int32 AddAmount, bool Actual) {
    return 0;
}

bool UItemComponent::AcceptsChangeInAmountForItemType(TSubclassOf<UItemType> itemTypeForChange, bool changeIsPositive) const {
    return false;
}

void UItemComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UItemComponent, ItemType);
    DOREPLIFETIME(UItemComponent, storedSubItemType);
    DOREPLIFETIME(UItemComponent, Amount);
}


