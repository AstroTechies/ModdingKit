#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "EnterExitSignalDelegate.h"
#include "OnSlotEventSignalDelegate.h"
#include "SignalDelegate.h"
#include "SlotIndicatorLocation.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "StorageChassisComponent.generated.h"

class AActor;
class APhysicalItem;
class APlayerController;
class UActorAttachmentsComponent;
class UItemType;
class USlotOrganizationRule;
class UStorageChassisComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UStorageChassisComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSlotEventSignal OnSlotEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSlotsReset;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnItemAmountChangeEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ExcludeSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ExcludedChildSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, ReplicatedUsing=OnRep_ActorAttachments, meta=(AllowPrivateAccess=true))
    TArray<UActorAttachmentsComponent*> ActorAttachments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool CanExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IndicateExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    bool OwnerFacingBack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TertiaryUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SaveOnEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanTransferItemsAcrossConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> RailSlots;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnTertiaryUse;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnterExitSignal OnTertiaryEnterExit;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> Slots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStorageChassisComponent*> ChildStorageChassis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStorageChassisComponent> OverrideParentStorage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStorageChassisComponent*> OverrideChildStorageChassis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USlotOrganizationRule*> OrganizationRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SlotIndicatorLocations, meta=(AllowPrivateAccess=true))
    TArray<FSlotIndicatorLocation> SlotIndicatorLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotIndicatorLocation> PreviousSlotIndicatorLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPrioritizeNestedStorage: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPassActuateEventsToSlottedItems: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCanNest: 1;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsSpawnPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsNewPlayerSpawnPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsDefaultSpawnPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpawnPointPriority;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference RespawnCameraReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActorAttachmentsComponent*> PrevActorAttachments;
    
public:
    UStorageChassisComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void TertiaryUse(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void SlotEvent(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    bool QueryTertiary(APlayerController* Controller, FTransform& OutTransform);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_SlotIndicatorLocations();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ActorAttachments();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlayerEnterExitAttachment(bool Entered);
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerDestroyed(AActor* Owner);
    
public:
    UFUNCTION(BlueprintCallable)
    void ItemAmountChangeEventDrained(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void ItemAmountChangeEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FSlotReference> GetUnmanagedSlots(bool bCheckingFullness) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UStorageChassisComponent* GetOutermostStorage(AActor* Actor, bool Inclusive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UStorageChassisComponent* GetActorStorageChassisComponent(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USlotOrganizationRule* FindRuleByName(FName RuleName);
    
    UFUNCTION(BlueprintCallable)
    int32 ChangeDeformationDeltaInConnectedSlotNetwork(int32 sedimentAmount, TSubclassOf<UItemType> deformedItemType);
    
    UFUNCTION(BlueprintCallable)
    void CalculateItemReservesInConnectedSlotNetwork(TSubclassOf<UItemType> ItemType, int32& outCurrentStoredItemAmount, int32& outMaxStorageSize);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityPlaceItemInLocalStorage(APhysicalItem* Item);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityPlaceItemInConnectedSlotNetwork(APhysicalItem* Item, AActor* SourceOwner);
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityApplyOrganizationRules();
    
public:
    UFUNCTION(BlueprintCallable)
    int32 AddItem(TSubclassOf<UItemType> ItemType, int32 ItemAmount);
    
};

