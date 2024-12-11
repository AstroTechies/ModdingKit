#pragma once
#include "CoreMinimal.h"
//#include "AstroPlayFabEventData.h"
//#include "AstroPlayFabItemDriveStage.h"
#include "Components/ActorComponent.h"
#include "ItemDriveReward.h"
#include "PendingInGameItemRewards.h"
#include "PlayFabPPlayerStatisticRefreshedDelegateDelegate.h"
#include "ProgressPredictionData.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "ItemDriveComponent.generated.h"

class UItemType;
class UTexture2D;
class UTradeShipDatabase;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UItemDriveComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SendEventEvery;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPlayFabTitleDataRefreshed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayFabPPlayerStatisticRefreshedDelegate OnPlayFabStatisticRefreshed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UItemType>, int32> ItemValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemDriveReward> Rewards;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FAstroPlayFabEventData ActiveEvent;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    FAstroPlayFabItemDriveStage ActiveEventItemDriveStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTexture2D*> ItemDriveStageIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* ExoRequestRocketClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTradeShipDatabase* TradeShipDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 PredictedItemDriveProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 OfficialItemDriveProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_UnclaimedPhysicalItemRewards, meta=(AllowPrivateAccess=true))
    TArray<FPendingInGameItemRewards> UnclaimedPhysicalItemRewards;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_PredictedProgress, meta=(AllowPrivateAccess=true))
    FProgressPredictionData PredictedProgress;
    
public:
    UItemDriveComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UpdateActiveItemDriveStage();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateProgress(FProgressPredictionData updatedPredictedProgress, int32 updatedOfficialProgress);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_UnclaimedPhysicalItemRewards();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_PredictedProgress();
    
    UFUNCTION(BlueprintCallable)
    void HandlePlayerEventSent(bool success, const FString& EventName, int32 EventId);
    
    UFUNCTION(BlueprintCallable)
    void HandlePlayerEventResponse(bool success, const FString& EventName, int32 EventId);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNextStageThresholdAtStage(int32 StageIndex) const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetItemValueAtStage(TSubclassOf<UItemType> ItemType, int32 StageIndex);
    
    UFUNCTION(BlueprintCallable)
    int32 GetItemValue(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetEventDisplayName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetEventDisplayDescription() const;
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRefreshPlayerStatistic();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    int32 AuthorityAddItemsInSlotsToSendCache(TArray<FSlotReference> Slots);
    
};

