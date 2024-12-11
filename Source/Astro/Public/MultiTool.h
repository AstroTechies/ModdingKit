#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/NetSerialization.h"
#include "ClickResult.h"
#include "InteractionTarget.h"
#include "SlotClickResult.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "MultiTool.generated.h"

class AActor;
class APhysicalItem;
class APlayController;
class ASlotConnection;
class UActivation;
class UActuatorComponent;
class UClickableComponent;
class UControlActivatorComponent;
class UControlSymbol;
class UCrackableActorComponent;
class UInputComponent;
class UMultitoolCameraContext;
class UPrimitiveComponent;
class USceneComponent;
class UTooltipComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UMultiTool : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UControlSymbol> PlayerPointSymbol;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActionReadyRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GamepadCursorSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SmallItemMaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FocusMinDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IndicatorScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlanetTraceDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlanetSelectDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> IndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseToolTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxInteractionWidgetDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisplayInteractionWidgetsWhenUsingCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SelectionRotateSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SelectionRotateAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DrivingInteractionTooltipExpansionSpeedMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Indicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActionReadySelectionAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CursorOverCursorNotifyActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CursorOverCursorNotifySecondaryActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* CursorOverCursorNotifyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowCursor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMultitoolCameraContext* CameraContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputComponent* ObjectSelectedInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputComponent* InteractionWidgetInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputComponent* PlayerDrivingInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputComponent* FocusedTooltipInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControlActivatorComponent* CharacterControlActivator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentSelection, meta=(AllowPrivateAccess=true))
    APhysicalItem* m_currentSelection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* PreviousRepSelection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector m_secondaryStartLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClickResult m_secondaryClick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* ToolActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* CurrentSelectionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CurrentDrivingActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCrackableActorComponent*> CurrentCrackedComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInteractionTarget> InteractionOverrideStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTooltipComponent* CurrentFocusedTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTooltipComponent* DrivingTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* SwapItemNewItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* SwapItemCurrentlyHeld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotClickResult LastClickSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference LastHoverSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ClickablesSuppressionCount;
    
public:
    UMultiTool(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UnSuppressClickables();
    
    UFUNCTION(BlueprintCallable)
    bool TryToggleActorCracked(AActor* targetActor, bool bIsClickInteraction);
    
    UFUNCTION(BlueprintCallable)
    void SuppressClickables();
    
    UFUNCTION(BlueprintCallable)
    void StowDeformTool();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateCurrSelectionHasTerrainTraceHit(bool bNewHasTerrainTraceHit);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerTraceForSlotConnection(APlayController* Controller, ASlotConnection* SlotConnection, FVector TraceStart, FVector traceDirection);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSwapItem(APhysicalItem* ItemInSlot, APhysicalItem* CurrentlyHeldItem, bool bIsTerrainComponent, UPrimitiveComponent* HitComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSlotItem(APhysicalItem* Actor, FSlotReference Slot, int32 SubslotIndex);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSelectItem(APhysicalItem* Item, bool bPartOfSwap);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSelectionDuplicate(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSelectionDelete(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerQuickClickMissionEvent(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerQuickClick(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerMakeSlotConnection(ASlotConnection* Actor, UPrimitiveComponent* hitPrimitive, FVector HitLocation, FVector_NetQuantizeNormal HitNormal, FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerInsertIntoRailConnection(APhysicalItem* Item, UPrimitiveComponent* HitComponent, bool terrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal, int32 railConnectionID);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerEmplaceInSlot(APhysicalItem* Item, const FSlotReference& Slot, int32 SubslotIndex, bool PhysicalMovement);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDropItem(APhysicalItem* Item, UPrimitiveComponent* HitComponent, bool terrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerCrackCrackableActorComponent(UCrackableActorComponent* crackedCrackableActorComponent);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerCloseCrackableActorComponent(UCrackableActorComponent* closedCrackableActorComponent, bool bIsClickInteraction);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerClickActuatorRerouteNode(UActuatorComponent* Actuator, APhysicalItem* Item, const FVector StartPos, int32 ConnectionId);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerClickActuatorCable(UActuatorComponent* Actuator, int32 ConnectionId);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerClearSlotEmplacement(APhysicalItem* Item);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RouteWidgetUseUnhandled(TEnumAsByte<EInputEvent> InputType);
    
    UFUNCTION(BlueprintCallable)
    void RouteInteractionWidgetUseRepeat();
    
    UFUNCTION(BlueprintCallable)
    void RouteInteractionWidgetUseRelease();
    
    UFUNCTION(BlueprintCallable)
    void RouteInteractionWidgetUsePress();
    
    UFUNCTION(BlueprintCallable)
    void RouteInteractionDrivingUseRelease();
    
    UFUNCTION(BlueprintCallable)
    void RouteInteractionDrivingUsePress();
    
    UFUNCTION(BlueprintCallable)
    void RouteInteractionDrivingAux2Release();
    
    UFUNCTION(BlueprintCallable)
    void RouteInteractionDrivingAux2Press();
    
    UFUNCTION(BlueprintCallable)
    void RouteInteractionDrivingAux1Release();
    
    UFUNCTION(BlueprintCallable)
    void RouteInteractionDrivingAux1Press();
    
    UFUNCTION(BlueprintCallable)
    void RouteInteractionCatalogActivated();
    
    UFUNCTION(BlueprintCallable)
    void RouteFocusedTooltipInteractionActivated(FName ActionName);
    
    UFUNCTION(BlueprintCallable)
    void RouteFocusedTooltipInputUnhandled(TEnumAsByte<EInputEvent> InputType, FName ActionName);
    
    UFUNCTION(BlueprintCallable)
    void RouteDrivingUseInteraction();
    
    UFUNCTION(BlueprintCallable)
    void RouteDrivingTooltipInteractionActivated(FName ActionName);
    
    UFUNCTION(BlueprintCallable)
    void RouteDrivingTooltipInputUnhandled(TEnumAsByte<EInputEvent> InputType, FName ActionName);
    
public:
    UFUNCTION(BlueprintCallable)
    void ResetSuppressClickables();
    
    UFUNCTION(BlueprintCallable)
    void PushInteractionOverride(AActor* Actor, USceneComponent* PivotComponent, UClickableComponent* clickable);
    
    UFUNCTION(BlueprintCallable)
    void PopInteractionOverride(AActor* Actor);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTooltipWantsFocusChange(UTooltipComponent* TooltipComponent, bool WantsFocus);
    
    UFUNCTION(BlueprintCallable)
    void OnSelectionQuickUseHeld();
    
    UFUNCTION(BlueprintCallable)
    bool OnSelectionQuickUse();
    
    UFUNCTION(BlueprintCallable)
    void OnSelectionDuplicate();
    
    UFUNCTION(BlueprintCallable)
    void OnSelectionDelete();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentSelection();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnPlayerDeathBegin();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnItemReplicationDataChanged(APhysicalItem* Item);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInitializeComponent();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnFocusedTooltipActorDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnCrackedCrackableActorComponentCrackedChanged(UCrackableActorComponent* CrackableActorComponent, bool bIsCracked);
    
    UFUNCTION(BlueprintCallable)
    void MouseDownPickupItem(APhysicalItem* Item, UPrimitiveComponent* Component, bool snapToCursor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHoldingItem() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleBackpackOpenedOrClosed(bool IsOpen);
    
public:
    UFUNCTION(BlueprintCallable)
    AActor* GetMissionLogActor() const;
    
    UFUNCTION(BlueprintCallable)
    AActor* GetCatalogActor() const;
    
    UFUNCTION(BlueprintCallable)
    void DropItem();
    
protected:
    UFUNCTION(BlueprintCallable)
    void DoSecondaryInteraction();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DidInteractionEndThisFrame();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CursorControlActive() const;
    
    UFUNCTION(BlueprintCallable)
    void CloseAllOpenCrackables();
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientSwapHeldItemDropped();
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientSwapFinished();
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientDenyCrackCrackableActorComponent(UCrackableActorComponent* crackedCrackableActorComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreClickablesSuppressed();
    
};

