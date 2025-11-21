#include "MultiTool.h"
#include "Components/InputComponent.h"
#include "Activation.h"
#include "Net/UnrealNetwork.h"

UMultiTool::UMultiTool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PlayerPointSymbol = NULL;
    this->LerpSpeed = 3.00f;
    this->ActionReadyRatio = 0.33f;
    this->GamepadCursorSpeed = 800.00f;
    this->SmallItemMaxDistance = 3800.00f;
    this->FocusMinDistance = 400.00f;
    this->IndicatorScale = 0.00f;
    this->TraceDistance = 10000.00f;
    this->PlanetTraceDistance = 10000000.00f;
    this->PlanetSelectDistance = 3000000.00f;
    this->IndicatorClass = NULL;
    this->BaseToolTier = 4;
    this->MaxDistance = 2800.00f;
    this->MaxInteractionWidgetDistance = 1000.00f;
    this->DisplayInteractionWidgetsWhenUsingCursor = false;
    this->SelectionRotateSpeed = 180.00f;
    this->SelectionRotateAcceleration = 360.00f;
    this->DrivingInteractionTooltipExpansionSpeedMultiplier = 4.00f;
    this->Indicator = NULL;
    this->ActionReadySelectionAmount = 0.00f;
    this->CursorOverCursorNotifyActor = NULL;
    this->CursorOverCursorNotifySecondaryActor = NULL;
    this->CursorOverCursorNotifyComponent = NULL;
    this->ShowCursor = true;
    this->CameraContext = NULL;
    this->ObjectSelectedInputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("ObjectSelectedInputComponent"));
    this->InteractionWidgetInputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("InteractionWidgetInputComponent"));
    this->PlayerDrivingInputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("PlayerDrivingInputComponent"));
    this->FocusedTooltipInputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("FocusedTooltipInputComponent"));
    this->CharacterControlActivator = NULL;
    this->m_currentSelection = NULL;
    this->PreviousRepSelection = NULL;
    this->ToolActive = CreateDefaultSubobject<UActivation>(TEXT("usingTool"));
    this->CurrentSelectionComponent = NULL;
    this->CurrentDrivingActor = NULL;
    this->CurrentFocusedTooltip = NULL;
    this->DrivingTooltip = NULL;
    this->SwapItemNewItem = NULL;
    this->SwapItemCurrentlyHeld = NULL;
    this->ClickablesSuppressionCount = 0;
}

void UMultiTool::UnSuppressClickables() {
}

bool UMultiTool::TryToggleActorCracked(AActor* targetActor, bool bIsClickInteraction) {
    return false;
}

void UMultiTool::SuppressClickables() {
}

void UMultiTool::StowDeformTool() {
}

void UMultiTool::ServerUpdateCurrSelectionHasTerrainTraceHit_Implementation(bool bNewHasTerrainTraceHit) {
}
bool UMultiTool::ServerUpdateCurrSelectionHasTerrainTraceHit_Validate(bool bNewHasTerrainTraceHit) {
    return true;
}

void UMultiTool::ServerTraceForSlotConnection_Implementation(APlayController* Controller, ASlotConnection* SlotConnection, FVector TraceStart, FVector traceDirection) {
}
bool UMultiTool::ServerTraceForSlotConnection_Validate(APlayController* Controller, ASlotConnection* SlotConnection, FVector TraceStart, FVector traceDirection) {
    return true;
}

void UMultiTool::ServerSwapItem_Implementation(APhysicalItem* ItemInSlot, APhysicalItem* CurrentlyHeldItem, bool bIsTerrainComponent, UPrimitiveComponent* HitComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal) {
}
bool UMultiTool::ServerSwapItem_Validate(APhysicalItem* ItemInSlot, APhysicalItem* CurrentlyHeldItem, bool bIsTerrainComponent, UPrimitiveComponent* HitComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal) {
    return true;
}

void UMultiTool::ServerSlotItem_Implementation(APhysicalItem* Actor, FSlotReference Slot, int32 SubslotIndex) {
}
bool UMultiTool::ServerSlotItem_Validate(APhysicalItem* Actor, FSlotReference Slot, int32 SubslotIndex) {
    return true;
}

void UMultiTool::ServerSelectItem_Implementation(APhysicalItem* Item, bool bPartOfSwap) {
}
bool UMultiTool::ServerSelectItem_Validate(APhysicalItem* Item, bool bPartOfSwap) {
    return true;
}

void UMultiTool::ServerSelectionDuplicate_Implementation(APhysicalItem* Item) {
}
bool UMultiTool::ServerSelectionDuplicate_Validate(APhysicalItem* Item) {
    return true;
}

void UMultiTool::ServerSelectionDelete_Implementation(APhysicalItem* Item) {
}
bool UMultiTool::ServerSelectionDelete_Validate(APhysicalItem* Item) {
    return true;
}

void UMultiTool::ServerQuickClickMissionEvent_Implementation(APhysicalItem* Item) {
}
bool UMultiTool::ServerQuickClickMissionEvent_Validate(APhysicalItem* Item) {
    return true;
}

void UMultiTool::ServerQuickClick_Implementation(APhysicalItem* Item) {
}
bool UMultiTool::ServerQuickClick_Validate(APhysicalItem* Item) {
    return true;
}

void UMultiTool::ServerMakeSlotConnection_Implementation(ASlotConnection* Actor, UPrimitiveComponent* hitPrimitive, FVector HitLocation, FVector_NetQuantizeNormal HitNormal, FSlotReference Slot) {
}
bool UMultiTool::ServerMakeSlotConnection_Validate(ASlotConnection* Actor, UPrimitiveComponent* hitPrimitive, FVector HitLocation, FVector_NetQuantizeNormal HitNormal, FSlotReference Slot) {
    return true;
}

void UMultiTool::ServerInsertIntoRailConnection_Implementation(APhysicalItem* Item, UPrimitiveComponent* HitComponent, bool terrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal, int32 railConnectionID) {
}
bool UMultiTool::ServerInsertIntoRailConnection_Validate(APhysicalItem* Item, UPrimitiveComponent* HitComponent, bool terrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal, int32 railConnectionID) {
    return true;
}

void UMultiTool::ServerEmplaceInSlot_Implementation(APhysicalItem* Item, const FSlotReference& Slot, int32 SubslotIndex, bool PhysicalMovement) {
}
bool UMultiTool::ServerEmplaceInSlot_Validate(APhysicalItem* Item, const FSlotReference& Slot, int32 SubslotIndex, bool PhysicalMovement) {
    return true;
}

void UMultiTool::ServerDropItem_Implementation(APhysicalItem* Item, UPrimitiveComponent* HitComponent, bool terrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal) {
}
bool UMultiTool::ServerDropItem_Validate(APhysicalItem* Item, UPrimitiveComponent* HitComponent, bool terrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal) {
    return true;
}

void UMultiTool::ServerCrackCrackableActorComponent_Implementation(UCrackableActorComponent* crackedCrackableActorComponent) {
}
bool UMultiTool::ServerCrackCrackableActorComponent_Validate(UCrackableActorComponent* crackedCrackableActorComponent) {
    return true;
}

void UMultiTool::ServerCloseCrackableActorComponent_Implementation(UCrackableActorComponent* closedCrackableActorComponent, bool bIsClickInteraction) {
}
bool UMultiTool::ServerCloseCrackableActorComponent_Validate(UCrackableActorComponent* closedCrackableActorComponent, bool bIsClickInteraction) {
    return true;
}

void UMultiTool::ServerClickActuatorRerouteNode_Implementation(UActuatorComponent* Actuator, APhysicalItem* Item, const FVector StartPos, const FActuatorConnectorRef& connectorRef) {
}
bool UMultiTool::ServerClickActuatorRerouteNode_Validate(UActuatorComponent* Actuator, APhysicalItem* Item, const FVector StartPos, const FActuatorConnectorRef& connectorRef) {
    return true;
}

void UMultiTool::ServerClickActuatorCable_Implementation(UActuatorComponent* Actuator, const FActuatorCableRef& inCableRef) {
}
bool UMultiTool::ServerClickActuatorCable_Validate(UActuatorComponent* Actuator, const FActuatorCableRef& inCableRef) {
    return true;
}

void UMultiTool::ServerClearSlotEmplacement_Implementation(APhysicalItem* Item) {
}
bool UMultiTool::ServerClearSlotEmplacement_Validate(APhysicalItem* Item) {
    return true;
}

void UMultiTool::RouteWidgetUseUnhandled(TEnumAsByte<EInputEvent> InputType) {
}

void UMultiTool::RouteInteractionWidgetUseRepeat() {
}

void UMultiTool::RouteInteractionWidgetUseRelease() {
}

void UMultiTool::RouteInteractionWidgetUsePress() {
}

void UMultiTool::RouteInteractionDrivingUseRelease() {
}

void UMultiTool::RouteInteractionDrivingUsePress() {
}

void UMultiTool::RouteInteractionDrivingAux2Release() {
}

void UMultiTool::RouteInteractionDrivingAux2Press() {
}

void UMultiTool::RouteInteractionDrivingAux1Release() {
}

void UMultiTool::RouteInteractionDrivingAux1Press() {
}

void UMultiTool::RouteInteractionCatalogActivated() {
}

void UMultiTool::RouteFocusedTooltipInteractionActivated(FName ActionName) {
}

void UMultiTool::RouteFocusedTooltipInputUnhandled(TEnumAsByte<EInputEvent> InputType, FName ActionName) {
}

void UMultiTool::RouteDrivingUseInteraction() {
}

void UMultiTool::RouteDrivingTooltipInteractionActivated(FName ActionName) {
}

void UMultiTool::RouteDrivingTooltipInputUnhandled(TEnumAsByte<EInputEvent> InputType, FName ActionName) {
}

void UMultiTool::ResetSuppressClickables() {
}

void UMultiTool::PushInteractionOverride(AActor* Actor, USceneComponent* PivotComponent, UClickableComponent* clickable) {
}

void UMultiTool::PopInteractionOverride(AActor* Actor) {
}

void UMultiTool::OnTooltipWantsFocusChange(UTooltipComponent* TooltipComponent, bool WantsFocus) {
}

void UMultiTool::OnSelectionQuickUseHeld() {
}

bool UMultiTool::OnSelectionQuickUse() {
    return false;
}

void UMultiTool::OnSelectionDuplicate() {
}

void UMultiTool::OnSelectionDelete() {
}

void UMultiTool::OnRep_CurrentSelection() {
}

void UMultiTool::OnPlayerDeathBegin() {
}

void UMultiTool::OnItemReplicationDataChanged(APhysicalItem* Item) {
}


void UMultiTool::OnFocusedTooltipActorDestroyed(AActor* DestroyedActor) {
}

void UMultiTool::OnCrackedCrackableActorComponentCrackedChanged(UCrackableActorComponent* CrackableActorComponent, bool bIsCracked) {
}

void UMultiTool::MouseDownPickupItem(APhysicalItem* Item, UPrimitiveComponent* Component, bool snapToCursor) {
}

bool UMultiTool::IsHoldingItem() const {
    return false;
}

void UMultiTool::HandleBackpackOpenedOrClosed(bool IsOpen) {
}

AActor* UMultiTool::GetMissionLogActor() const {
    return NULL;
}

AActor* UMultiTool::GetCatalogActor() const {
    return NULL;
}

void UMultiTool::DropItem() {
}

void UMultiTool::DoSecondaryInteraction() {
}

bool UMultiTool::DidInteractionEndThisFrame() {
    return false;
}

bool UMultiTool::CursorControlActive() const {
    return false;
}

void UMultiTool::CloseAllOpenCrackables() {
}

void UMultiTool::ClientSwapHeldItemDropped_Implementation() {
}
bool UMultiTool::ClientSwapHeldItemDropped_Validate() {
    return true;
}

void UMultiTool::ClientSwapFinished_Implementation() {
}
bool UMultiTool::ClientSwapFinished_Validate() {
    return true;
}

void UMultiTool::ClientDenyCrackCrackableActorComponent_Implementation(UCrackableActorComponent* crackedCrackableActorComponent) {
}
bool UMultiTool::ClientDenyCrackCrackableActorComponent_Validate(UCrackableActorComponent* crackedCrackableActorComponent) {
    return true;
}

bool UMultiTool::AreClickablesSuppressed() {
    return false;
}

void UMultiTool::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UMultiTool, m_currentSelection);
}


