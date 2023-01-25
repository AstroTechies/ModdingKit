#include "BreadboardPrinterComponent.h"
#include "Net/UnrealNetwork.h"

class AActor;
class APhysicalItem;
class UAstroSaveCustomArchiveProxy;
class UPrimitiveComponent;

void UBreadboardPrinterComponent::ValidatePackageableItemsInRange() {
}

void UBreadboardPrinterComponent::UpdateBreadboardPrinter(float DeltaTime) {
}

void UBreadboardPrinterComponent::SetRepackageModeEnabled(bool modeEnabled) {
}

void UBreadboardPrinterComponent::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void UBreadboardPrinterComponent::OnRep_OutputSlotTransform() {
}

void UBreadboardPrinterComponent::OnRep_IsInProductionMode() {
}

void UBreadboardPrinterComponent::OnRep_AutoTerminateProductionMode() {
}

void UBreadboardPrinterComponent::OnRep_AnimationStateChange() {
}

void UBreadboardPrinterComponent::OnPrintAreaOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void UBreadboardPrinterComponent::OnPrintAreaOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void UBreadboardPrinterComponent::HandlePrintStarted() {
}

void UBreadboardPrinterComponent::HandlePrintFinished(APhysicalItem* PrintedItem) {
}

void UBreadboardPrinterComponent::HandlePrintCanceled() {
}

FSlotReference UBreadboardPrinterComponent::GetSlotForItemTier(const TArray<FSlotReference>& Slots, const APhysicalItem* itemCDO, bool neededSlotTierCanBeOccupied) const {
    return FSlotReference{};
}

bool UBreadboardPrinterComponent::GetSelectionEnabled() {
    return false;
}

float UBreadboardPrinterComponent::GetPrintheadHeight() {
    return 0.0f;
}

float UBreadboardPrinterComponent::GetPrintheadExtension() {
    return 0.0f;
}

bool UBreadboardPrinterComponent::GetPrinterAvailable() {
    return false;
}

bool UBreadboardPrinterComponent::GetPreviewEnabled() {
    return false;
}

bool UBreadboardPrinterComponent::CheckPrinterDeployed() const {
    return false;
}

void UBreadboardPrinterComponent::AuthoritySetProductionModeEnabled(bool ProductionModeEnabled) {
}

void UBreadboardPrinterComponent::AuthoritySetAutoTerminateProductionModeEnabled(bool AutoTerminateProductionModeEnabled) {
}

void UBreadboardPrinterComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UBreadboardPrinterComponent, REP_AnimationData);
    DOREPLIFETIME(UBreadboardPrinterComponent, REP_OutputSlotTransform);
    DOREPLIFETIME(UBreadboardPrinterComponent, bIsProductionModeEnabled);
    DOREPLIFETIME(UBreadboardPrinterComponent, bAutoTerminateProductionMode);
}

UBreadboardPrinterComponent::UBreadboardPrinterComponent() {
    this->PrintShaderThickness = 35.00f;
    this->CanPrintToSelfPlatform = true;
    this->PrintSpeedScalar = 1.00f;
    this->PrintSurfaceRadius = 250.00f;
    this->OutOfRangeDuration = 5.00f;
    this->AutoShutdownEnabled = false;
    this->ActivationRange = 0.00f;
    this->ExtensionLerpThreshold = 100.00f;
    this->CalculatePrintheadAnimationValues = true;
    this->ExtensionLerpSpeed = 500.00f;
    this->HeightLerpSpeed = 3.00f;
    this->PrintheadNeutralSocketName = TEXT("printheadNeutral_socket");
    this->PrintheadDeployedSocketName = TEXT("printhead_socket");
    this->PrintheadActualSocketName = TEXT("printhead_socket_actual");
    this->PrintAreaRoot = NULL;
    this->GroundOutputSlot = NULL;
    this->PrinterMesh = NULL;
    this->PrintAreaCollider = NULL;
    this->PrintingOntoItem = false;
    this->RoomToPrint = false;
    this->PrintheadHeight_Current = 0.00f;
    this->PrintheadExtension_Current = 0.00f;
    this->OwnerPhysicalItem = NULL;
    this->PrinterComponent = NULL;
    this->PowerComponent = NULL;
    this->ClickableComponent = NULL;
    this->SelectedBlueprint = NULL;
    this->bOverlapListInitialized = false;
    this->InitialPrintSlotOffset = 0.00f;
    this->bIsProductionModeEnabled = false;
    this->bAutoTerminateProductionMode = true;
}

