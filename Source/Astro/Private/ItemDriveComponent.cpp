#include "ItemDriveComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UItemDriveComponent::UItemDriveComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->SendEventEvery = 60.00f;
    this->ExoRequestRocketClass = NULL;
    this->TradeShipDatabase = NULL;
    this->PredictedItemDriveProgress = 0;
    this->OfficialItemDriveProgress = -1;
}

void UItemDriveComponent::UpdateActiveItemDriveStage() {
}

void UItemDriveComponent::ServerUpdateProgress_Implementation(FProgressPredictionData updatedPredictedProgress, int32 updatedOfficialProgress) {
}
bool UItemDriveComponent::ServerUpdateProgress_Validate(FProgressPredictionData updatedPredictedProgress, int32 updatedOfficialProgress) {
    return true;
}

void UItemDriveComponent::OnRep_UnclaimedPhysicalItemRewards() {
}

void UItemDriveComponent::OnRep_PredictedProgress() {
}

void UItemDriveComponent::HandlePlayerEventSent(bool success, const FString& EventName, int32 EventId) {
}

void UItemDriveComponent::HandlePlayerEventResponse(bool success, const FString& EventName, int32 EventId) {
}

int32 UItemDriveComponent::GetNextStageThresholdAtStage(int32 StageIndex) const {
    return 0;
}

int32 UItemDriveComponent::GetItemValueAtStage(TSubclassOf<UItemType> ItemType, int32 StageIndex) {
    return 0;
}

int32 UItemDriveComponent::GetItemValue(TSubclassOf<UItemType> ItemType) {
    return 0;
}

FText UItemDriveComponent::GetEventDisplayName() const {
    return FText::GetEmpty();
}

FText UItemDriveComponent::GetEventDisplayDescription() const {
    return FText::GetEmpty();
}

void UItemDriveComponent::ClientRefreshPlayerStatistic_Implementation() {
}

int32 UItemDriveComponent::AuthorityAddItemsInSlotsToSendCache(TArray<FSlotReference> Slots) {
    return 0;
}

void UItemDriveComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UItemDriveComponent, UnclaimedPhysicalItemRewards);
    DOREPLIFETIME(UItemDriveComponent, PredictedProgress);
}


