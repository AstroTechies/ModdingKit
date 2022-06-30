#include "PrinterComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class UItemType;
class AControlPanel;
class UClickQuery;
class APhysicalItem;
class UAstroSaveCustomArchiveProxy;
class AActor;
class UPrinterComponent;

void UPrinterComponent::UnlockedItemsChanged(const TArray<TSubclassOf<UItemType>>& NewUnlockedItems) {
}

void UPrinterComponent::StartPrinting() {
}

APhysicalItem* UPrinterComponent::SpawnPrintedItem() {
    return NULL;
}

void UPrinterComponent::SetText(FText Text) {
}

void UPrinterComponent::SetRequiresPower(bool printerRequiresPower) {
}

void UPrinterComponent::SetRepackageModeEnabled(bool modeEnabled) {
}

void UPrinterComponent::SetPrintSpeed(float Speed) {
}

void UPrinterComponent::SetPrinterOutputSlot(const FSlotReference& Slot) {
}

void UPrinterComponent::SetLocalIsVisible(bool IsVisible) {
}

void UPrinterComponent::SetItemsAvailableToRepackage(TArray<TWeakObjectPtr<APhysicalItem>> itemsToRepackage, int32 DefaultSelectionIndex) {
}

void UPrinterComponent::SetCanUse(bool bCanUse) {
}

void UPrinterComponent::SetBlueprints(TArray<TSubclassOf<APhysicalItem>> newBlueprints) {
}

void UPrinterComponent::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void UPrinterComponent::RemoveIgnoredActorForPrintAreaValidation(AActor* ignoredActor) {
}

bool UPrinterComponent::PrinterClickQuery(UClickQuery* Query) {
    return false;
}

void UPrinterComponent::OnRep_Progress() {
}

void UPrinterComponent::OnRep_PrintState() {
}

void UPrinterComponent::OnRep_PrinterStateAtomic() {
}

void UPrinterComponent::OnRep_PrinterOutputSlot() {
}

void UPrinterComponent::OnRep_CurrentBlueprintItem() {
}

void UPrinterComponent::OnPrinterDestroyed(AActor* DestroyedActor) {
}

void UPrinterComponent::OnAuthorityControlPanelCrackedChanged(AControlPanel* ControlPanel) {
}

void UPrinterComponent::IncrementBlueprint(bool doServerIncrement) {
}

void UPrinterComponent::HideBlueprint() {
}

void UPrinterComponent::HandleCreativeCatalogUnlockedChanged() {
}

int32 UPrinterComponent::GetTotalAvailableBlueprintCount() const {
    return 0;
}

bool UPrinterComponent::GetRepackageModeEngaged() const {
    return false;
}

FTransform UPrinterComponent::GetPrintingTransform() {
    return FTransform{};
}

float UPrinterComponent::GetPrintingHeight() {
    return 0.0f;
}

bool UPrinterComponent::GetPrinting() const {
    return false;
}

bool UPrinterComponent::GetItemIndicatorVisible() const {
    return false;
}

bool UPrinterComponent::GetItemIndicatorHidden() const {
    return false;
}

bool UPrinterComponent::GetHasAllIngredients() const {
    return false;
}

int32 UPrinterComponent::GetCurrentUnlockedBlueprintIndex() const {
    return 0;
}

TSubclassOf<APhysicalItem> UPrinterComponent::GetCurrentItem() const {
    return NULL;
}

bool UPrinterComponent::GetCharging() const {
    return false;
}

bool UPrinterComponent::GetCanUse() const {
    return false;
}

bool UPrinterComponent::GetCanPrint() const {
    return false;
}

TArray<int32> UPrinterComponent::GetAvailableIngredientCounts() const {
    return TArray<int32>();
}

void UPrinterComponent::FinishPrinting() {
}

void UPrinterComponent::DecrementBlueprint(bool doServerIncrement) {
}

void UPrinterComponent::DeactivateBlueprint() {
}

void UPrinterComponent::CreateIndicatorFromItem(APhysicalItem* Owner) {
}

void UPrinterComponent::CreateIndicatorFromClass(TSubclassOf<APhysicalItem> Class) {
}

bool UPrinterComponent::CanReserveSlotsAcceptItemForActiveRecipe(APhysicalItem* Item) {
    return false;
}

void UPrinterComponent::CancelPrint(bool restoreIngredients) {
}

void UPrinterComponent::AddIgnoredActorForPrintAreaValidation(AActor* ignoredActor) {
}

UPrinterComponent* UPrinterComponent::ActorPrinterComponent(AActor* Actor) {
    return NULL;
}

void UPrinterComponent::ActivateBlueprint() {
}

void UPrinterComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPrinterComponent, REP_PrinterState);
}

UPrinterComponent::UPrinterComponent() {
    this->CurrentBlueprintIndex = -1;
    this->CurrentPackageableItem = NULL;
    this->CurrentRepackageableItemIndex = 0;
    this->RecipesRequireProgression = true;
    this->RequireResources = true;
    this->HideIndicatorWithoutFullRecipe = false;
    this->RequiresPower = true;
    this->StreamsPower = false;
    this->ConsumeFromStorageSlots = false;
    this->AllowPrintCompletionWithoutPower = true;
    this->RequiredPowerOffset = 0.00f;
    this->PrintSpeed = 0.25f;
    this->PackageUpPrintedItems = false;
    this->ShortcutButtons = true;
    this->EmplaceItemAfterPrint = true;
    this->InteractionEnabled = false;
    this->LocalIsVisible = true;
    this->PrintingActive = false;
    this->ValidatePrintAreaOpen = false;
    this->PrintAreaClearRadius = 500.00f;
    this->Progress = 0.00f;
    this->ProgressOverride = -1.00f;
    this->SlotIndicatorIndex = -1;
    this->RepackageModeEngaged = false;
    this->PrintingMaterialDynamic = NULL;
}

