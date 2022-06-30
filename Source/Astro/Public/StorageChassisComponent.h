#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "EnterExitSignalDelegate.h"
#include "SlotReference.h"
#include "OnSlotEventSignalDelegate.h"
#include "SignalDelegate.h"
#include "SlotIndicatorLocation.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "StorageChassisComponent.generated.h"

class USlotOrganizationRule;
class UActorAttachmentsComponent;
class UStorageChassisComponent;
class APlayerController;
class APhysicalItem;
class AActor;
class UItemType;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UStorageChassisComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnSlotEventSignal OnSlotEvent;

    UPROPERTY()
    FSignal OnSlotsReset;

    UPROPERTY(BlueprintAssignable)
    FSignal OnItemAmountChangeEvent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> ExcludeSlots;

    UPROPERTY(BlueprintReadWrite, Export, ReplicatedUsing = OnRep_ActorAttachments, meta = (AllowPrivateAccess = true))
    TArray<UActorAttachmentsComponent *> ActorAttachments;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    bool CanExit;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool IndicateExit;

    UPROPERTY(BlueprintReadWrite, Replicated, SaveGame, meta = (AllowPrivateAccess = true))
    bool OwnerFacingBack;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool TertiaryUsable;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool SaveOnEnter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool CanTransferItemsAcrossConnections;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> RailSlots;

    UPROPERTY(BlueprintAssignable)
    FSignal OnTertiaryUse;

    UPROPERTY(BlueprintAssignable)
    FEnterExitSignal OnTertiaryEnterExit;

protected:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> Slots;

    UPROPERTY(Export)
    TArray<UStorageChassisComponent *> ChildStorageChassis;

    UPROPERTY(Export, SaveGame)
    UStorageChassisComponent *OverrideParentStorage;

    UPROPERTY(Export)
    TArray<UStorageChassisComponent *> OverrideChildStorageChassis;

    UPROPERTY(EditDefaultsOnly, Export)
    TArray<USlotOrganizationRule *> OrganizationRules;

    UPROPERTY(ReplicatedUsing = OnRep_SlotIndicatorLocations)
    TArray<FSlotIndicatorLocation> SlotIndicatorLocations;

    UPROPERTY()
    TArray<FSlotIndicatorLocation> PreviousSlotIndicatorLocations;

    UPROPERTY(EditDefaultsOnly)
    uint8 bPrioritizeNestedStorage : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bPassActuateEventsToSlottedItems : 1;

    UPROPERTY(EditDefaultsOnly, SaveGame)
    uint8 bCanNest : 1;

private:
    UPROPERTY(EditDefaultsOnly)
    bool IsSpawnPoint;

    UPROPERTY(EditDefaultsOnly)
    bool IsNewPlayerSpawnPoint;

    UPROPERTY(EditDefaultsOnly)
    bool IsDefaultSpawnPoint;

    UPROPERTY(EditDefaultsOnly)
    int32 SpawnPointPriority;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference RespawnCameraReference;

    UPROPERTY(Export, Transient)
    TArray<UActorAttachmentsComponent *> PrevActorAttachments;

public:
    UStorageChassisComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void TertiaryUse(APlayerController *Controller);

    UFUNCTION()
    void SlotEvent(APhysicalItem *Item);

    UFUNCTION(BlueprintCallable)
    bool QueryTertiary(APlayerController *Controller, FTransform &OutTransform);

protected:
    UFUNCTION()
    void OnRep_SlotIndicatorLocations();

    UFUNCTION()
    void OnRep_ActorAttachments();

private:
    UFUNCTION()
    void OnPlayerEnterExitAttachment(bool Entered);

    UFUNCTION()
    void OnOwnerDestroyed(AActor *Owner);

public:
    UFUNCTION()
    void ItemAmountChangeEvent();

    UFUNCTION(BlueprintPure)
    TArray<FSlotReference> GetUnmanagedSlots() const;

    UFUNCTION(BlueprintPure)
    static UStorageChassisComponent *GetOutermostStorage(AActor *Actor, bool Inclusive);

    UFUNCTION(BlueprintPure)
    static UStorageChassisComponent *GetActorStorageChassisComponent(AActor *Actor);

    UFUNCTION(BlueprintPure)
    USlotOrganizationRule *FindRuleByName(FName RuleName);

    UFUNCTION(BlueprintCallable)
    int32 ChangeDeformationDeltaInConnectedSlotNetwork(int32 sedimentAmount, TSubclassOf<UItemType> deformedItemType);

    UFUNCTION(BlueprintCallable)
    void CalculateItemReservesInConnectedSlotNetwork(TSubclassOf<UItemType> ItemType, int32 &outCurrentStoredItemAmount, int32 &outMaxStorageSize);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityPlaceItemInLocalStorage(APhysicalItem *Item);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityPlaceItemInConnectedSlotNetwork(APhysicalItem *Item, AActor *SourceOwner);

protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityApplyOrganizationRules();

public:
    UFUNCTION(BlueprintCallable)
    int32 AddItem(TSubclassOf<UItemType> ItemType, int32 ItemAmount);
};
