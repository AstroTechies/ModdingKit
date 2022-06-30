#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "ExoRequestReward.h"
#include "EExoRequestStatus.h"
#include "ExoRequestModuleBase.generated.h"

class UTradeShipDockComponent_ItemDrive;
class UItemDriveComponent;
class UTradeShipComponent;
class AActor;
class APlayController;
class UTexture;

UCLASS(Blueprintable, Abstract)
class AExoRequestModuleBase : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName TestClassName;

protected:
    UPROPERTY(EditDefaultsOnly)
    FText DeliveryNotificationText;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 CurrentScore;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    int32 LaunchByteCost;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 ItemDriveProgress;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 EventProgressBarMax;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    int32 EventProgressBarMin;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_ExoRequestModuleData, meta = (AllowPrivateAccess = true))
    EExoRequestStatus RequestStatus;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FExoRequestReward> Rewards;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UItemDriveComponent *ActiveItemDrive;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UItemDriveComponent *LocalItemDrive;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    AActor *ShipActor;

    UPROPERTY(BlueprintReadWrite, Export, ReplicatedUsing = OnRep_ExoRequestModuleData, meta = (AllowPrivateAccess = true))
    UTradeShipComponent *TradeShipComponent;

    UPROPERTY(Export)
    UTradeShipDockComponent_ItemDrive *TradeShipDockComponentItemDrive;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 bCanClaimPendingRewardForFree : 1;

public:
    AExoRequestModuleBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UpdateScore();

    UFUNCTION(BlueprintCallable)
    void UpdateRewardData();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateProgressBar();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateModuleState();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateEventIcon();

    UFUNCTION(BlueprintCallable)
    void UpdateActiveItemDrive();

    UFUNCTION(BlueprintCallable)
    void UpdateActiveEvent();

protected:
    UFUNCTION()
    void OnRep_ExoRequestModuleData();

public:
    UFUNCTION(BlueprintPure)
    bool ItemDriveAcceptsItem(APhysicalItem *Item) const;

protected:
    UFUNCTION(BlueprintPure)
    bool IsEventActive() const;

    UFUNCTION(BlueprintPure)
    bool HasUnclaimedPhysicalItemRewards(APlayController *PlayController) const;

    UFUNCTION(BlueprintPure)
    UTexture *GetEventInputIcon() const;

public:
    UFUNCTION(BlueprintCallable)
    void AuthoritySetShipAttachedToDock(bool IsAttached);

    UFUNCTION(BlueprintCallable)
    void AuthorityDeliverItems();

    UFUNCTION(BlueprintCallable)
    void ActivatedThroughControlPanel(APlayController *ClickingPlayer);
};
