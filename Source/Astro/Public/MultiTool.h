#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "SlotClickResult.h"
#include "ClickResult.h"
#include "InteractionTarget.h"
#include "SlotReference.h"
#include "Engine/NetSerialization.h"
#include "Engine/EngineBaseTypes.h"
#include "MultiTool.generated.h"

class UInputComponent;
class AActor;
class USceneComponent;
class UMultitoolCameraContext;
class APhysicalItem;
class UControlSymbol;
class UPrimitiveComponent;
class UControlActivatorComponent;
class UActivation;
class ASlotConnection;
class UCrackableActorComponent;
class UTooltipComponent;
class APlayController;
class UActuatorComponent;
class UClickableComponent;

UCLASS(Blueprintable, Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UMultiTool : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UControlSymbol> PlayerPointSymbol;

    UPROPERTY(EditAnywhere)
    float LerpSpeed;

    UPROPERTY(EditAnywhere)
    float ActionReadyRatio;

    UPROPERTY(EditAnywhere)
    float GamepadCursorSpeed;

    UPROPERTY(EditAnywhere)
    float SmallItemMaxDistance;

    UPROPERTY(EditAnywhere)
    float FocusMinDistance;

    UPROPERTY(EditAnywhere)
    float IndicatorScale;

    UPROPERTY(EditAnywhere)
    float TraceDistance;

    UPROPERTY(EditAnywhere)
    float PlanetTraceDistance;

    UPROPERTY(EditAnywhere)
    float PlanetSelectDistance;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> IndicatorClass;

    UPROPERTY(EditAnywhere)
    int32 BaseToolTier;

    UPROPERTY(EditAnywhere)
    float MaxDistance;

    UPROPERTY(EditAnywhere)
    float MaxInteractionWidgetDistance;

    UPROPERTY(EditAnywhere)
    bool DisplayInteractionWidgetsWhenUsingCursor;

    UPROPERTY(EditAnywhere)
    float SelectionRotateSpeed;

    UPROPERTY(EditAnywhere)
    float SelectionRotateAcceleration;

    UPROPERTY(EditAnywhere)
    float DrivingInteractionTooltipExpansionSpeedMultiplier;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AActor *Indicator;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float ActionReadySelectionAmount;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AActor *CursorOverCursorNotifyActor;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AActor *CursorOverCursorNotifySecondaryActor;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UPrimitiveComponent *CursorOverCursorNotifyComponent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool ShowCursor;

protected:
    UPROPERTY(Export)
    UMultitoolCameraContext *CameraContext;

    UPROPERTY(Export)
    UInputComponent *ObjectSelectedInputComponent;

    UPROPERTY(Export)
    UInputComponent *InteractionWidgetInputComponent;

    UPROPERTY(Export)
    UInputComponent *PlayerDrivingInputComponent;

    UPROPERTY(Export)
    UInputComponent *FocusedTooltipInputComponent;

    UPROPERTY(Export)
    UControlActivatorComponent *CharacterControlActivator;

    UPROPERTY(ReplicatedUsing = OnRep_CurrentSelection)
    APhysicalItem *m_currentSelection;

    UPROPERTY()
    APhysicalItem *PreviousRepSelection;

    UPROPERTY()
    FVector m_secondaryStartLocation;

    UPROPERTY()
    FClickResult m_secondaryClick;

    UPROPERTY()
    UActivation *ToolActive;

    UPROPERTY(Export)
    UPrimitiveComponent *CurrentSelectionComponent;

    UPROPERTY()
    AActor *CurrentDrivingActor;

    UPROPERTY(Export)
    TArray<UCrackableActorComponent *> CurrentCrackedComponents;

    UPROPERTY()
    TArray<FInteractionTarget> InteractionOverrideStack;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UTooltipComponent *CurrentFocusedTooltip;

    UPROPERTY(Export)
    UTooltipComponent *DrivingTooltip;

    UPROPERTY()
    APhysicalItem *SwapItemNewItem;

    UPROPERTY()
    APhysicalItem *SwapItemCurrentlyHeld;

    UPROPERTY()
    FSlotClickResult LastClickSlot;

    UPROPERTY()
    FSlotReference LastHoverSlot;

    UPROPERTY()
    uint8 ClickablesSuppressionCount;

public:
    UMultiTool();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UnSuppressClickables();

    UFUNCTION(BlueprintCallable)
    bool TryToggleActorCracked(AActor *targetActor, bool bIsClickInteraction);

    UFUNCTION(BlueprintCallable)
    void SuppressClickables();

    UFUNCTION(BlueprintCallable)
    void StowDeformTool();

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerTraceForSlotConnection(APlayController *Controller, ASlotConnection *SlotConnection, FVector TraceStart, FVector traceDirection);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSwapItem(APhysicalItem *ItemInSlot, APhysicalItem *CurrentlyHeldItem, bool bIsTerrainComponent, UPrimitiveComponent *HitComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSlotItem(APhysicalItem *Actor, FSlotReference Slot, int32 SubslotIndex);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSelectItem(APhysicalItem *Item, bool bPartOfSwap);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSelectionDuplicate(APhysicalItem *Item);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSelectionDelete(APhysicalItem *Item);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerQuickClickMissionEvent(APhysicalItem *Item);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerQuickClick(APhysicalItem *Item);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerMakeSlotConnection(ASlotConnection *Actor, UPrimitiveComponent *hitPrimitive, FVector HitLocation, FVector_NetQuantizeNormal HitNormal, FSlotReference Slot);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerEmplaceInSlot(APhysicalItem *Item, const FSlotReference &Slot, int32 SubslotIndex, bool PhysicalMovement);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerDropItem(APhysicalItem *Item, UPrimitiveComponent *HitComponent, bool terrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal);

protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCrackCrackableActorComponent(UCrackableActorComponent *crackedCrackableActorComponent);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCloseCrackableActorComponent(UCrackableActorComponent *closedCrackableActorComponent, bool bIsClickInteraction);

public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerClickActuatorRerouteNode(UActuatorComponent *Actuator, APhysicalItem *Item, const FVector StartPos, int32 ConnectionId);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerClickActuatorCable(UActuatorComponent *Actuator, int32 ConnectionId);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerClearSlotEmplacement(APhysicalItem *Item);

protected:
    UFUNCTION()
    void RouteWidgetUseUnhandled(EInputEvent InputType);

    UFUNCTION()
    void RouteInteractionWidgetUseRepeat();

    UFUNCTION()
    void RouteInteractionWidgetUseRelease();

    UFUNCTION()
    void RouteInteractionWidgetUsePress();

    UFUNCTION()
    void RouteInteractionDrivingUseRelease();

    UFUNCTION()
    void RouteInteractionDrivingUsePress();

    UFUNCTION()
    void RouteInteractionDrivingAux2Release();

    UFUNCTION()
    void RouteInteractionDrivingAux2Press();

    UFUNCTION()
    void RouteInteractionDrivingAux1Release();

    UFUNCTION()
    void RouteInteractionDrivingAux1Press();

    UFUNCTION()
    void RouteInteractionCatalogActivated();

    UFUNCTION()
    void RouteFocusedTooltipInteractionActivated(FName ActionName);

    UFUNCTION()
    void RouteFocusedTooltipInputUnhandled(EInputEvent InputType, FName ActionName);

    UFUNCTION()
    void RouteDrivingUseInteraction();

    UFUNCTION()
    void RouteDrivingTooltipInteractionActivated(FName ActionName);

    UFUNCTION()
    void RouteDrivingTooltipInputUnhandled(EInputEvent InputType, FName ActionName);

public:
    UFUNCTION(BlueprintCallable)
    void PushInteractionOverride(AActor *Actor, USceneComponent *PivotComponent, UClickableComponent *clickable);

    UFUNCTION(BlueprintCallable)
    void PopInteractionOverride(AActor *Actor);

protected:
    UFUNCTION()
    void OnTooltipWantsFocusChange(UTooltipComponent *TooltipComponent, bool WantsFocus);

    UFUNCTION()
    void OnSelectionQuickUseHeld();

    UFUNCTION(BlueprintCallable)
    bool OnSelectionQuickUse();

    UFUNCTION(BlueprintCallable)
    void OnSelectionDuplicate();

    UFUNCTION(BlueprintCallable)
    void OnSelectionDelete();

    UFUNCTION()
    void OnRep_CurrentSelection();

public:
    UFUNCTION()
    void OnPlayerDeathBegin();

protected:
    UFUNCTION()
    void OnItemReplicationDataChanged(APhysicalItem *Item);

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnInitializeComponent();

protected:
    UFUNCTION()
    void OnFocusedTooltipActorDestroyed(AActor *DestroyedActor);

public:
    UFUNCTION()
    void OnCrackedCrackableActorComponentCrackedChanged(UCrackableActorComponent *CrackableActorComponent, bool bIsCracked);

    UFUNCTION(BlueprintCallable)
    void MouseDownPickupItem(APhysicalItem *Item, UPrimitiveComponent *Component, bool snapToCursor);

    UFUNCTION(BlueprintPure)
    bool IsHoldingItem() const;

    UFUNCTION()
    AActor *GetMissionLogActor() const;

    UFUNCTION()
    AActor *GetCatalogActor() const;

    UFUNCTION(BlueprintCallable)
    void DropItem();

protected:
    UFUNCTION()
    void DoSecondaryInteraction();

public:
    UFUNCTION(BlueprintPure)
    bool DidInteractionEndThisFrame();

    UFUNCTION(BlueprintPure)
    bool CursorControlActive() const;

    UFUNCTION(BlueprintCallable)
    void CloseAllOpenCrackables();

    UFUNCTION(Client, Reliable, WithValidation)
    void ClientSwapHeldItemDropped();

    UFUNCTION(Client, Reliable, WithValidation)
    void ClientSwapFinished();

protected:
    UFUNCTION(Client, Reliable, WithValidation)
    void ClientDenyCrackCrackableActorComponent(UCrackableActorComponent *crackedCrackableActorComponent);

public:
    UFUNCTION(BlueprintPure)
    bool AreClickablesSuppressed();
};
