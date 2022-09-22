#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "SlotClickResult.h"
#include "ClickResult.h"
#include "SlotReference.h"
#include "InteractionTarget.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantizeNormal -FallbackName=Vector_NetQuantizeNormal
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
#include "MultiTool.generated.h"

class UPrimitiveComponent;
class AActor;
class UInputComponent;
class UTooltipComponent;
class UMultitoolCameraContext;
class UControlSymbol;
class APhysicalItem;
class UControlActivatorComponent;
class UActivation;
class UCrackableActorComponent;
class APlayController;
class ASlotConnection;
class UActuatorComponent;
class USceneComponent;
class UClickableComponent;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* CursorOverCursorNotifyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowCursor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UMultitoolCameraContext* CameraContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UInputComponent* ObjectSelectedInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UInputComponent* InteractionWidgetInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UInputComponent* PlayerDrivingInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UInputComponent* FocusedTooltipInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* CurrentSelectionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CurrentDrivingActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UCrackableActorComponent*> CurrentCrackedComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInteractionTarget> InteractionOverrideStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTooltipComponent* CurrentFocusedTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTooltipComponent* DrivingTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* SwapItemNewItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* SwapItemCurrentlyHeld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotClickResult LastClickSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference LastHoverSlot;
    
    UPROPERTY(EditAnywhere)
    uint8 ClickablesSuppressionCount;
    
public:
    UMultiTool();
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
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerUpdateCurrSelectionHasTerrainTraceHit(bool bNewHasTerrainTraceHit);
    
public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerTraceForSlotConnection(APlayController* Controller, ASlotConnection* SlotConnection, FVector TraceStart, FVector traceDirection);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSwapItem(APhysicalItem* ItemInSlot, APhysicalItem* CurrentlyHeldItem, bool bIsTerrainComponent, UPrimitiveComponent* HitComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSlotItem(APhysicalItem* Actor, FSlotReference Slot, int32 SubslotIndex);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSelectItem(APhysicalItem* Item, bool bPartOfSwap);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSelectionDuplicate(APhysicalItem* Item);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSelectionDelete(APhysicalItem* Item);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerQuickClickMissionEvent(APhysicalItem* Item);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerQuickClick(APhysicalItem* Item);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerMakeSlotConnection(ASlotConnection* Actor, UPrimitiveComponent* hitPrimitive, FVector HitLocation, FVector_NetQuantizeNormal HitNormal, FSlotReference Slot);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerInsertIntoRailConnection(APhysicalItem* Item, UPrimitiveComponent* HitComponent, bool terrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal, int32 railConnectionID);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerEmplaceInSlot(APhysicalItem* Item, const FSlotReference& Slot, int32 SubslotIndex, bool PhysicalMovement);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerDropItem(APhysicalItem* Item, UPrimitiveComponent* HitComponent, bool terrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCrackCrackableActorComponent(UCrackableActorComponent* crackedCrackableActorComponent);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCloseCrackableActorComponent(UCrackableActorComponent* closedCrackableActorComponent, bool bIsClickInteraction);
    
public:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerClickActuatorRerouteNode(UActuatorComponent* Actuator, APhysicalItem* Item, const FVector StartPos, int32 ConnectionId);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerClickActuatorCable(UActuatorComponent* Actuator, int32 ConnectionId);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerClearSlotEmplacement(APhysicalItem* Item);
    
protected:
    UFUNCTION()
    void RouteWidgetUseUnhandled(TEnumAsByte<EInputEvent> InputType);
    
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
    void RouteFocusedTooltipInputUnhandled(TEnumAsByte<EInputEvent> InputType, FName ActionName);
    
    UFUNCTION()
    void RouteDrivingUseInteraction();
    
    UFUNCTION()
    void RouteDrivingTooltipInteractionActivated(FName ActionName);
    
    UFUNCTION()
    void RouteDrivingTooltipInputUnhandled(TEnumAsByte<EInputEvent> InputType, FName ActionName);
    
public:
    UFUNCTION(BlueprintCallable)
    void PushInteractionOverride(AActor* Actor, USceneComponent* PivotComponent, UClickableComponent* clickable);
    
    UFUNCTION(BlueprintCallable)
    void PopInteractionOverride(AActor* Actor);
    
protected:
    UFUNCTION()
    void OnTooltipWantsFocusChange(UTooltipComponent* TooltipComponent, bool WantsFocus);
    
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
    void OnItemReplicationDataChanged(APhysicalItem* Item);
    
public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnInitializeComponent();
    
protected:
    UFUNCTION()
    void OnFocusedTooltipActorDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION()
    void OnCrackedCrackableActorComponentCrackedChanged(UCrackableActorComponent* CrackableActorComponent, bool bIsCracked);
    
    UFUNCTION(BlueprintCallable)
    void MouseDownPickupItem(APhysicalItem* Item, UPrimitiveComponent* Component, bool snapToCursor);
    
    UFUNCTION(BlueprintPure)
    bool IsHoldingItem() const;
    
protected:
    UFUNCTION()
    void HandleBackpackOpenedOrClosed(bool IsOpen);
    
public:
    UFUNCTION()
    AActor* GetMissionLogActor() const;
    
    UFUNCTION()
    AActor* GetCatalogActor() const;
    
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
    void ClientDenyCrackCrackableActorComponent(UCrackableActorComponent* crackedCrackableActorComponent);
    
public:
    UFUNCTION(BlueprintPure)
    bool AreClickablesSuppressed();
    
};

