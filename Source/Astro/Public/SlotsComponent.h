#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotIndicatorDefinition.h"
#include "Components/ActorComponent.h"
#include "Slot.h"
#include "SlotTransition.h"
#include "SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ESlotType.h"
#include "ESlotConfiguration.h"
#include "ESlotConnectorType.h"
#include "Engine/EngineBaseTypes.h"
#include "SlotsComponent.generated.h"

class USlotDelegates;
class UItemType;
class APhysicalItem;
class UAstroSaveCustomArchiveProxy;
class USlotBehavior;
class AActor;
class ASlotConnection;
class USlotsComponent;
class UStaticMeshComponent;
class AAstroPlayerController;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class USlotsComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 bPreserveLegacyVisuals : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FSlot> Slots;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_SlotTransitions, meta = (AllowPrivateAccess = true))
    TArray<FSlotTransition> SlotTransitions;

private:
    UPROPERTY(Transient, ReplicatedUsing = OnRep_SlotClickability)
    TArray<uint32> ReplicatedSlotClickability;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_SlotsAcceptItems)
    TArray<uint32> ReplicatedSlotsAcceptItems;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_SlotRuleStatus)
    TArray<uint32> ReplicatedSlotRuleStatus;

public:
    USlotsComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    static bool TakeSlotItemOfTypeFromOther(FSlotReference Slot, FSlotReference Other, TSubclassOf<UItemType> Type);

    UFUNCTION(BlueprintCallable)
    static bool TakeSlotItemFromOther(FSlotReference Slot, FSlotReference Other);

    UFUNCTION(BlueprintCallable)
    static bool SpawnItemTypeInSlotWithDefaultContainer(FSlotReference Slot, TSubclassOf<UItemType> Type, TSubclassOf<UItemType> DefaultContainerType, bool StartFull);

    UFUNCTION(BlueprintCallable)
    static bool SpawnItemTypeInSlot(FSlotReference Slot, TSubclassOf<UItemType> Type, bool StartFull);

    UFUNCTION(BlueprintCallable)
    static APhysicalItem *SpawnActorInSlot(FSlotReference Slot, TSubclassOf<APhysicalItem> Class);

    UFUNCTION(BlueprintPure)
    static bool SlotValidSlow(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static bool SlotValid(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static bool SlotsEqual(FSlotReference A, FSlotReference B);

    UFUNCTION(BlueprintCallable)
    static int32 SlotPushIndicatorItemTypes(FSlotReference Slot, int32 Count, TArray<int32> &OutSubslotIndices, const FSlotIndicatorDefinition &IndicatorDefinition);

    UFUNCTION(BlueprintPure)
    static bool SlotPowerIncomingOnly(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static bool SlotIsTrailerHitch(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static int32 SlotGetTier(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static int32 SlotGetNumIndicators(FSlotReference Slot);

    UFUNCTION(BlueprintCallable)
    static void SlotEnable(FSlotReference Slot, bool Enable);

    UFUNCTION(BlueprintCallable)
    static void SlotDestroyIndicators(FSlotReference Slot);

    UFUNCTION(BlueprintCallable)
    static int32 SlotAttemptToPushIndicatorIntoSpecificSubslot(const FSlotReference &Slot, int32 SubslotIndex, const FSlotIndicatorDefinition &IndicatorDefinition);

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

    UFUNCTION(BlueprintPure)
    static bool SlotAcceptsItem(FSlotReference Slot, APhysicalItem *Item);

    UFUNCTION(BlueprintCallable)
    void SetTracePrimitivesAsleep(bool bAreAsleep);

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
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

public:
    UFUNCTION(BlueprintCallable)
    static void ReleaseSlotItemForce(FSlotReference Slot, float RandomForce);

    UFUNCTION(BlueprintCallable)
    static void ReleaseItemWithEjectionImpulse(FSlotReference Slot, APhysicalItem *Item, bool NewOwner, bool FromTool, FVector ejectionImpulse, FVector ejectionImpulseOffset);

    UFUNCTION(BlueprintCallable)
    static void ReleaseItem(FSlotReference Slot, APhysicalItem *Item, bool NewOwner, bool FromTool, float RandomForce);

    UFUNCTION()
    void OnSlotItemDestroyed(AActor *Actor);

    UFUNCTION()
    void OnSlotIndicatorClicked(FSlotReference Slot, TSubclassOf<UItemType> Type);

    UFUNCTION()
    void OnRep_SlotTransitions();

protected:
    UFUNCTION()
    void OnRep_SlotsAcceptItems();

    UFUNCTION()
    void OnRep_SlotRuleStatus();

    UFUNCTION()
    void OnRep_SlotClickability();

public:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastCancelSlotBehaviorTerrainInterpolation();

    UFUNCTION(BlueprintPure)
    FSlotReference MakeReference(FName SlotName) const;

    UFUNCTION(BlueprintCallable)
    static ASlotConnection *MakeExclusiveConnection(FSlotReference A, FSlotReference B, TSubclassOf<ASlotConnection> OverrideType);

    UFUNCTION(BlueprintCallable)
    static ASlotConnection *MakeConnection(FSlotReference A, FSlotReference B, TSubclassOf<ASlotConnection> OverrideType, bool Visible);

    UFUNCTION(BlueprintPure)
    static ESlotType GetSlotType(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static FTransform GetSlotTransform(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static FTransform GetSlotRelativeTransform(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static APhysicalItem *GetSlotPrimaryItem(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static USlotsComponent *GetSlotOwner(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static ESlotConfiguration GetSlotOrientationConfiguration(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static TArray<UStaticMeshComponent *> GetSlotLegacyMeshes(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static TArray<APhysicalItem *> GetSlotItems(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static APhysicalItem *GetSlotItem(FSlotReference Slot, int32 SubslotIndex);

    UFUNCTION(BlueprintPure)
    static TArray<ASlotConnection *> GetSlotExternalConnections(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static USlotDelegates *GetSlotDelegates(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static ESlotConnectorType GetSlotConnectorType(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static FSlotReference GetSlotConnectedSlot(FSlotReference Slot);

    UFUNCTION(BlueprintPure)
    static TArray<USlotBehavior *> GetSlotBehaviors(FSlotReference Slot);

    UFUNCTION(BlueprintCallable)
    static void EmplaceSlotItem(FSlotReference Slot, APhysicalItem *Item, bool SnapTo, bool weld);

    UFUNCTION(BlueprintCallable)
    static void DestroySlotItem(FSlotReference Slot);

    UFUNCTION(BlueprintCallable)
    static void ConnectPowerToItem(FSlotReference SlotRef, APhysicalItem *Item);

    UFUNCTION(BlueprintCallable)
    static void BreakAllSlotConnections(FSlotReference Slot);

    UFUNCTION(BlueprintCallable)
    void AuxUseRight(AAstroPlayerController *Controller, EInputEvent InputEvent);

    UFUNCTION(BlueprintCallable)
    void AuxUseLeft(AAstroPlayerController *Controller, EInputEvent InputEvent);

    UFUNCTION(BlueprintCallable)
    void AuxUseAll(AAstroPlayerController *Controller, EInputEvent InputEvent);

    UFUNCTION(BlueprintCallable)
    void AuxUse(FSlotReference AuxSlot, AAstroPlayerController *Controller, EInputEvent InputEvent);
};
