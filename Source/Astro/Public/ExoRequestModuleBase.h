#pragma once
#include "CoreMinimal.h"
#include "EExoRequestStatus.h"
#include "ExoRequestReward.h"
#include "PhysicalItem.h"
#include "ExoRequestModuleBase.generated.h"

class AActor;
class APlayController;
class UItemDriveComponent;
class UTexture;
class UTradeShipComponent;
class UTradeShipDockComponent_ItemDrive;

UCLASS(Abstract, Blueprintable)
class AExoRequestModuleBase : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TestClassName;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DeliveryNotificationText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LaunchByteCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemDriveProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EventProgressBarMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EventProgressBarMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ExoRequestModuleData, meta=(AllowPrivateAccess=true))
    EExoRequestStatus RequestStatus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExoRequestReward> Rewards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemDriveComponent* ActiveItemDrive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemDriveComponent* LocalItemDrive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AActor* ShipActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, ReplicatedUsing=OnRep_ExoRequestModuleData, meta=(AllowPrivateAccess=true))
    UTradeShipComponent* TradeShipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTradeShipDockComponent_ItemDrive* TradeShipDockComponentItemDrive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCanClaimPendingRewardForFree: 1;
    
public:
    AExoRequestModuleBase();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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
    UFUNCTION(BlueprintCallable)
    void OnRep_ExoRequestModuleData();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ItemDriveAcceptsItem(APhysicalItem* Item) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEventActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasUnclaimedPhysicalItemRewards(APlayController* PlayController) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture* GetEventInputIcon() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void AuthoritySetShipAttachedToDock(bool IsAttached);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityDeliverItems();
    
    UFUNCTION(BlueprintCallable)
    void ActivatedThroughControlPanel(APlayController* ClickingPlayer);
    
};

