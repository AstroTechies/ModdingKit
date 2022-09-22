#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "OnSlotEventSignalDelegate.h"
#include "SlotReference.h"
#include "EnterExitSignalDelegate.h"
#include "SlotIndicatorLocation.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "StorageChassisComponent.generated.h"

class USlotOrganizationRule;
class UActorAttachmentsComponent;
class UStorageChassisComponent;
class APlayerController;
class APhysicalItem;
class AActor;
class UItemType;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, ReplicatedUsing=OnRep_ActorAttachments, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UStorageChassisComponent*> ChildStorageChassis;
    
    UPROPERTY(EditAnywhere, Export, SaveGame)
    TWeakObjectPtr<UStorageChassisComponent> OverrideParentStorage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UStorageChassisComponent*> OverrideChildStorageChassis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActorAttachmentsComponent*> PrevActorAttachments;
    
public:
    UStorageChassisComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void TertiaryUse(APlayerController* Controller);
    
    UFUNCTION()
    void SlotEvent(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    bool QueryTertiary(APlayerController* Controller, FTransform& OutTransform);
    
protected:
    UFUNCTION()
    void OnRep_SlotIndicatorLocations();
    
    UFUNCTION()
    void OnRep_ActorAttachments();
    
private:
    UFUNCTION()
    void OnPlayerEnterExitAttachment(bool Entered);
    
    UFUNCTION()
    void OnOwnerDestroyed(AActor* Owner);
    
public:
    UFUNCTION()
    void ItemAmountChangeEvent();
    
    UFUNCTION(BlueprintPure)
    TArray<FSlotReference> GetUnmanagedSlots(bool bCheckingFullness) const;
    
    UFUNCTION(BlueprintPure)
    static UStorageChassisComponent* GetOutermostStorage(AActor* Actor, bool Inclusive);
    
    UFUNCTION(BlueprintPure)
    static UStorageChassisComponent* GetActorStorageChassisComponent(AActor* Actor);
    
    UFUNCTION(BlueprintPure)
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

