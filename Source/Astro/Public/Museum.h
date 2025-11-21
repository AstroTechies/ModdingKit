#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESinkType.h"
#include "MegaStructure.h"
#include "OnMilestoneAchievedDelegate.h"
#include "OnMilestoneRewardClaimedDelegate.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "Museum.generated.h"

class APhysicalItem;
class UItemType;
class UMuseumSinkMilestones;
class UResourceSinkValues;

UCLASS(Blueprintable)
class AMuseum : public AMegaStructure {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ClaimableResourceMilestones, meta=(AllowPrivateAccess=true))
    TArray<uint8> ClaimableResourceMilestones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ClaimableByteMilestones, meta=(AllowPrivateAccess=true))
    TArray<uint8> ClaimableByteMilestones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ClaimablePowerMilestones, meta=(AllowPrivateAccess=true))
    TArray<uint8> ClaimablePowerMilestones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ClaimableSeedMilestones, meta=(AllowPrivateAccess=true))
    TArray<uint8> ClaimableSeedMilestones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerUnitsNeededPerDonationReward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerTolerance;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceSinkValues* SinkValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESinkType, UMuseumSinkMilestones*> Milestones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_PowerConsumption, meta=(AllowPrivateAccess=true))
    int32 PowerConsumption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ByteConsumption, meta=(AllowPrivateAccess=true))
    int32 ByteConsumption;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_TotalBytesSunk, meta=(AllowPrivateAccess=true))
    int64 TotalBytesSunk;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_TotalSeedSinkScore, meta=(AllowPrivateAccess=true))
    int64 TotalSeedSinkScore;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_TotalResourceSinkScore, meta=(AllowPrivateAccess=true))
    int64 TotalResourceSinkScore;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_NextResourceMilestoneIndex, meta=(AllowPrivateAccess=true))
    int8 NextResourceMilestoneIndex;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_NextSeedMilestoneIndex, meta=(AllowPrivateAccess=true))
    int8 NextSeedMilestoneIndex;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_NextByteMilestoneIndex, meta=(AllowPrivateAccess=true))
    int8 NextByteMilestoneIndex;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_NextPowerMilestoneIndex, meta=(AllowPrivateAccess=true))
    int8 NextPowerMilestoneIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsResourceMilestoneComplete: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsSeedMilestoneComplete: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsByteMilestoneComplete: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsPowerMilestoneComplete: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bAreAllMilestonesComplete: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bHasSaveData: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 PowerBroadcastRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_TotalPowerSunk, meta=(AllowPrivateAccess=true))
    float REP_TotalPowerSunk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float TotalPowerSunk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConsumptionRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CanisterConsumptionRateMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnedItemOffsetMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_PowerSatisfactionThisFrame, meta=(AllowPrivateAccess=true))
    float REP_PowerSatisfactionThisFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float PowerRequiredForBuffs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UItemType>, int32> AmountDrainedPerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<uint8, ESinkType> ClaimedMilestoneRewards;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnPowerConsumptionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnByteConsumptionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal TotalPowerSunkChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal TotalBytesSunkChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal TotalSeedSinkScoreChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal TotalResourceSinkScoreChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnServerClearButton;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMilestoneAchieved OnResourceMilestoneAchieved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMilestoneAchieved OnByteMilestoneAchieved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMilestoneAchieved OnSeedMilestoneAchieved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMilestoneAchieved OnPowerMilestoneAchieved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMilestoneRewardClaimed OnMilestoneRewardClaimed;
    
public:
    AMuseum(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetSeedSlotFromRef(const FSlotReference& inSlotRef);
    
    UFUNCTION(BlueprintCallable)
    void SetResourceSlotFromRef(const FSlotReference& inSlotRef);
    
    UFUNCTION(BlueprintCallable)
    void SendEventToServerToClearButton();
    
    UFUNCTION(BlueprintCallable)
    void PresentToastNotificationForMilestone(const FText inTitle);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSlotEvent(APhysicalItem* inItem);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TotalSeedSinkScore() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TotalResourceSinkScore() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TotalPowerSunk() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TotalBytesSunk() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_PowerSatisfactionThisFrame() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_PowerConsumption() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_NextSeedMilestoneIndex() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_NextResourceMilestoneIndex() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_NextPowerMilestoneIndex() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_NextByteMilestoneIndex() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_ClaimableSeedMilestones();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_ClaimableResourceMilestones();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_ClaimablePowerMilestones();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_ClaimableByteMilestones();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_ByteConsumption() const;
    
    UFUNCTION(BlueprintCallable)
    void OnItemUnslotted(APhysicalItem* inItem);
    
    UFUNCTION(BlueprintCallable)
    void OnItemSlotted(APhysicalItem* inItem);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidMilestoneIndex(const ESinkType inSinkType, const uint8 inIndex) const;
    
    UFUNCTION(BlueprintPure)
    int64 GetTotalSeedSinkScore() const;
    
    UFUNCTION(BlueprintPure)
    int64 GetTotalResourceSinkScore() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalPowerSunk() const;
    
    UFUNCTION(BlueprintPure)
    int64 GetTotalByteConsumption() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPowerRequiredForBuffs() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPowerConsumption() const;
    
    UFUNCTION(BlueprintPure)
    float GetPercentage_Helper(const int64 inCurrent, const int64 inGoal) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetNextSeedMilestone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetNextResourceMilestone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetNextPowerMilestone() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetNextByteMilestone() const;
    
    UFUNCTION(BlueprintCallable)
    UMuseumSinkMilestones* GetMilestoneData(const ESinkType inSinkType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetByteConsumption() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAreAllSeedMilestonesComplete() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAreAllResourceMilestonesComplete() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAreAllPowerMilestonesComplete() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAreAllByteMilestonesComplete() const;
    
    UFUNCTION(BlueprintCallable)
    void ClaimReward(const ESinkType inSinkType, const uint8 inMilestoneIndex, const FTransform& inDropPosition);
    
    UFUNCTION(BlueprintCallable)
    void AuthoritySetPowerConsumption(const int32 inPowerConsumption);
    
    UFUNCTION(BlueprintCallable)
    void AuthoritySetByteConsumption(const int32 inByteConsumption);
    
};

