#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "EExoRequestStatus.h"
#include "ExoRequestReward.h"
#include "ExoRequestModuleBase.generated.h"

class UTradeShipComponent;
class UTradeShipDockComponent_ItemDrive;
class UItemDriveComponent;
class AActor;
class APlayController;
class UTexture;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UItemDriveComponent* ActiveItemDrive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UItemDriveComponent* LocalItemDrive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AActor* ShipActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, ReplicatedUsing=OnRep_ExoRequestModuleData, meta=(AllowPrivateAccess=true))
    UTradeShipComponent* TradeShipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    UFUNCTION()
    void OnRep_ExoRequestModuleData();
    
public:
    UFUNCTION(BlueprintPure)
    bool ItemDriveAcceptsItem(APhysicalItem* Item) const;
    
protected:
    UFUNCTION(BlueprintPure)
    bool IsEventActive() const;
    
    UFUNCTION(BlueprintPure)
    bool HasUnclaimedPhysicalItemRewards(APlayController* PlayController) const;
    
    UFUNCTION(BlueprintPure)
    UTexture* GetEventInputIcon() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void AuthoritySetShipAttachedToDock(bool IsAttached);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityDeliverItems();
    
    UFUNCTION(BlueprintCallable)
    void ActivatedThroughControlPanel(APlayController* ClickingPlayer);
    
};

