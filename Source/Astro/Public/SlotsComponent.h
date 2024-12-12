#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineBaseTypes.h"
#include "ESlotConfiguration.h"
#include "ESlotConnectorType.h"
#include "ESlotType.h"
#include "Slot.h"
#include "SlotIndicatorDefinition.h"
#include "SlotReference.h"
#include "SlotTransition.h"
#include "Templates/SubclassOf.h"
#include "SlotsComponent.generated.h"

class AActor;
class AAstroPlayerController;
class APhysicalItem;
class ASlotConnection;
class UAstroSaveCustomArchiveProxy;
class UItemType;
class USlotBehavior;
class USlotDelegates;
class USlotsComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USlotsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPreserveLegacyVisuals: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlot> Slots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SlotTransitions, meta=(AllowPrivateAccess=true))
    TArray<FSlotTransition> SlotTransitions;
    
private:
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_SlotClickability, meta=(AllowPrivateAccess=true))
    TArray<uint32> ReplicatedSlotClickability;
    
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_SlotsAcceptItems, meta=(AllowPrivateAccess=true))
    TArray<uint32> ReplicatedSlotsAcceptItems;
    
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_SlotRuleStatus, meta=(AllowPrivateAccess=true))
    TArray<uint32> ReplicatedSlotRuleStatus;
    
public:
    USlotsComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    static bool TakeSlotItemOfTypeFromOther(FSlotReference Slot, FSlotReference Other, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable)
    static bool TakeSlotItemFromOther(FSlotReference Slot, FSlotReference Other);
    
    UFUNCTION(BlueprintCallable)
    static bool SpawnItemTypeInSlotWithDefaultContainer(FSlotReference Slot, TSubclassOf<UItemType> Type, TSubclassOf<UItemType> DefaultContainerType, bool StartFull);
    
    UFUNCTION(BlueprintCallable)
    static bool SpawnItemTypeInSlot(FSlotReference Slot, TSubclassOf<UItemType> Type, bool StartFull);
    
    UFUNCTION(BlueprintCallable)
    static APhysicalItem* SpawnActorInSlot(FSlotReference Slot, TSubclassOf<APhysicalItem> Class);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SlotValidSlow(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SlotValid(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SlotsEqual(FSlotReference A, FSlotReference B);
    
    UFUNCTION(BlueprintCallable)
    static int32 SlotPushIndicatorItemTypes(FSlotReference Slot, int32 Count, TArray<int32>& OutSubslotIndices, const FSlotIndicatorDefinition& IndicatorDefinition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SlotPowerIncomingOnly(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SlotIsTrailerHitch(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 SlotGetTier(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 SlotGetNumIndicators(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    static void SlotEnable(FSlotReference Slot, bool Enable);
    
    UFUNCTION(BlueprintCallable)
    static void SlotDestroyIndicators(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    static int32 SlotAttemptToPushIndicatorIntoSpecificSubslot(const FSlotReference& Slot, int32 SubslotIndex, const FSlotIndicatorDefinition& IndicatorDefinition);
    
    UFUNCTION(BlueprintCallable)
    static bool SlotAttemptToChangeItemAmountNormalized(FSlotReference Slot, TSubclassOf<UItemType> ItemType, float normalizedAmount);
    
    UFUNCTION(BlueprintCallable)
    static bool SlotAddIndicatorItemTypeAttemptPackage(FSlotReference Slot, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    static bool SlotAddIndicatorItemType(FSlotReference Slot, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    static bool SlotAddIndicatorItemAttemptPackage(FSlotReference Slot, TSubclassOf<APhysicalItem> Type);
    
    UFUNCTION(BlueprintCallable)
    static bool SlotAddIndicatorItem(FSlotReference Slot, TSubclassOf<APhysicalItem> Type);
    
    UFUNCTION(BlueprintCallable)
    static bool SlotAcceptsItemTypeWithChangeInAmount(FSlotReference Slot, TSubclassOf<UItemType> ItemType, bool isChangePositive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SlotAcceptsItem(FSlotReference Slot, APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void SetTracePrimitivesAsleep(bool bAreAsleep);
    
    UFUNCTION(BlueprintCallable)
    void SetStreamingPowerConnectionsMergePowerNodes(FSlotReference Slot, bool MergeNodes);
    
    UFUNCTION(BlueprintCallable)
    static void SetSlotRelativeTransform(FSlotReference Slot, FTransform Transform);
    
    UFUNCTION(BlueprintCallable)
    static void SetSlotHidden(FSlotReference SlotRef, bool bIsHidden);
    
    UFUNCTION(BlueprintCallable)
    static void SetSlotClickable(FSlotReference A, bool clickable);
    
    UFUNCTION(BlueprintCallable)
    static void SetSlotBreakable(FSlotReference Slot, bool Breakable);
    
    UFUNCTION(BlueprintCallable)
    static void SetSlotAcceptsUnslottableItems(FSlotReference SlotRef, bool bAcceptsUnslottableItems);
    
    UFUNCTION(BlueprintCallable)
    static void SetSlotAcceptsItems(FSlotReference A, bool bAcceptsItems);
    
private:
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable)
    static void ReleaseSlotItemForce(FSlotReference Slot, float RandomForce);
    
    UFUNCTION(BlueprintCallable)
    static void ReleaseItemWithEjectionImpulse(FSlotReference Slot, APhysicalItem* Item, bool NewOwner, bool FromTool, FVector ejectionImpulse, FVector ejectionImpulseOffset);
    
    UFUNCTION(BlueprintCallable)
    static void ReleaseItem(FSlotReference Slot, APhysicalItem* Item, bool NewOwner, bool FromTool, float RandomForce);
    
    UFUNCTION(BlueprintCallable)
    void OnSlotItemDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnSlotIndicatorClicked(FSlotReference Slot, TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SlotTransitions();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_SlotsAcceptItems();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SlotRuleStatus();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_SlotClickability();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastCancelSlotBehaviorTerrainInterpolation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSlotReference MakeReference(FName SlotName) const;
    
    UFUNCTION(BlueprintCallable)
    static ASlotConnection* MakeExclusiveConnection(FSlotReference A, FSlotReference B, TSubclassOf<ASlotConnection> OverrideType);
    
    UFUNCTION(BlueprintCallable)
    static ASlotConnection* MakeConnection(FSlotReference A, FSlotReference B, TSubclassOf<ASlotConnection> OverrideType, bool Visible, bool PlaySounds);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetStreamingPowerConnectionsMergePowerNodes(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetStreamingPowerConnectionsCanChangeMergePowerNodes(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ESlotType GetSlotType(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform GetSlotTransform(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform GetSlotRelativeTransform(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APhysicalItem* GetSlotPrimaryItem(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static USlotsComponent* GetSlotOwner(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ESlotConfiguration GetSlotOrientationConfiguration(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<UStaticMeshComponent*> GetSlotLegacyMeshes(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<APhysicalItem*> GetSlotItems(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APhysicalItem* GetSlotItem(FSlotReference Slot, int32 SubslotIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<ASlotConnection*> GetSlotExternalConnections(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static USlotDelegates* GetSlotDelegates(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ESlotConnectorType GetSlotConnectorType(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlotReference GetSlotConnectedSlot(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<USlotBehavior*> GetSlotBehaviors(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    static void EmplaceSlotItem(FSlotReference Slot, APhysicalItem* Item, bool SnapTo, bool weld);
    
    UFUNCTION(BlueprintCallable)
    static void DestroySlotItem(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    static void ConnectPowerToItem(FSlotReference SlotRef, APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    static void BreakAllSlotConnections(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    void AuxUseRight(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> InputEvent);
    
    UFUNCTION(BlueprintCallable)
    void AuxUseLeft(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> InputEvent);
    
    UFUNCTION(BlueprintCallable)
    void AuxUseAll(AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> InputEvent);
    
    UFUNCTION(BlueprintCallable)
    void AuxUse(FSlotReference AuxSlot, AAstroPlayerController* Controller, TEnumAsByte<EInputEvent> InputEvent);
    
};

