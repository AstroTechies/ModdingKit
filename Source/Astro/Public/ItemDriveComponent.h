#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "ItemDriveReward.h"
#include "SignalDelegate.h"
#include "PendingInGameItemRewards.h"
#include "ProgressPredictionData.h"
#include "SlotReference.h"
#include "ItemDriveComponent.generated.h"

class UItemType;
class UTexture2D;
class UTradeShipDatabase;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UItemDriveComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float SendEventEvery;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TMap<TSubclassOf<UItemType>, int32> ItemValues;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FItemDriveReward> Rewards;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<UTexture2D *> ItemDriveStageIcons;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UClass *ExoRequestRocketClass;

    UPROPERTY(EditDefaultsOnly)
    UTradeShipDatabase *TradeShipDatabase;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    int32 PredictedItemDriveProgress;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    int32 OfficialItemDriveProgress;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_UnclaimedPhysicalItemRewards)
    TArray<FPendingInGameItemRewards> UnclaimedPhysicalItemRewards;

protected:
    UPROPERTY(ReplicatedUsing = OnRep_PredictedProgress)
    FProgressPredictionData PredictedProgress;

public:
    UItemDriveComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UpdateActiveItemDriveStage();

protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerUpdateProgress(FProgressPredictionData updatedPredictedProgress, int32 updatedOfficialProgress);

    UFUNCTION()
    void OnRep_UnclaimedPhysicalItemRewards();

    UFUNCTION()
    void OnRep_PredictedProgress();

    UFUNCTION()
    void HandlePlayerEventSent(bool success, const FString &EventName, int32 EventId);

    UFUNCTION()
    void HandlePlayerEventResponse(bool success, const FString &EventName, int32 EventId);

public:
    UFUNCTION(BlueprintPure)
    int32 GetNextStageThresholdAtStage(int32 StageIndex) const;

    UFUNCTION(BlueprintCallable)
    int32 GetItemValueAtStage(TSubclassOf<UItemType> ItemType, int32 StageIndex);

    UFUNCTION(BlueprintCallable)
    int32 GetItemValue(TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintPure)
    FText GetEventDisplayName() const;

    UFUNCTION(BlueprintPure)
    FText GetEventDisplayDescription() const;

    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRefreshPlayerStatistic();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    int32 AuthorityAddItemsInSlotsToSendCache(TArray<FSlotReference> Slots);
};
