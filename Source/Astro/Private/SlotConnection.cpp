#include "SlotConnection.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/SplineMeshComponent.h"
#include "AdaptiveTickComponent.h"
#include "Net/UnrealNetwork.h"

class AActor;
class APhysicalItem;
class UAstroSaveCustomArchiveProxy;
class UPrimitiveComponent;

void ASlotConnection::ServerUpdateClientMotion_Implementation(FSlotConnectionClientMotionData motionData) {
}
bool ASlotConnection::ServerUpdateClientMotion_Validate(FSlotConnectionClientMotionData motionData) {
    return true;
}

void ASlotConnection::ServerReleaseCable_Implementation() {
}
bool ASlotConnection::ServerReleaseCable_Validate() {
    return true;
}

void ASlotConnection::ServerDoTimedDestruction_Implementation() {
}
bool ASlotConnection::ServerDoTimedDestruction_Validate() {
    return true;
}

void ASlotConnection::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void ASlotConnection::PlaceExtenderForHeldCable(APhysicalItem* ExtenderBundle) {
}

void ASlotConnection::OnTetherAttachComponentHasOxygenChanged(bool bHasOxygen) {
}

void ASlotConnection::OnSelfDestroyed(AActor* Actor) {
}

void ASlotConnection::OnSelfClicked(AActor* Actor, FKey Key) {
}



void ASlotConnection::OnRep_SlotData() {
}


void ASlotConnection::OnHoverOtherSlot_Implementation(FSlotReference Slot) {
}

void ASlotConnection::OnFullyRetracted() {
}

void ASlotConnection::OnDisconnected_Implementation() {
}

void ASlotConnection::OnConnected_Implementation() {
}

void ASlotConnection::MulticastBeginHoverOverSlotFX_Implementation() {
}

void ASlotConnection::MakeConnection(FSlotReference Slot, bool PlaySounds) {
}

void ASlotConnection::MakeComponentConnection(UPrimitiveComponent* Component, const FVector& Location, const FVector& Normal) {
}

FSlotReference ASlotConnection::GetOtherSlot(FSlotReference Slot) const {
    return FSlotReference{};
}

FVector ASlotConnection::GetEndpointLocation(bool allowConnections) {
    return FVector{};
}

FVector ASlotConnection::GetCurveNormal(float Alpha, float Tensile) const {
    return FVector{};
}

FVector ASlotConnection::GetCurveLocation(float Alpha, float Tensile) const {
    return FVector{};
}

bool ASlotConnection::GetConnectionMidpoint(FVector& outVector) {
    return false;
}

bool ASlotConnection::CanConnect(FSlotReference Slot) {
    return false;
}

void ASlotConnection::BreakImmediately() {
}

void ASlotConnection::Break() {
}

void ASlotConnection::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASlotConnection, clickable);
    DOREPLIFETIME(ASlotConnection, m_replicationData);
    DOREPLIFETIME(ASlotConnection, m_replicationMotionData);
}

ASlotConnection::ASlotConnection() {
    this->ExtenderItemTypeUnbundled = NULL;
    this->PhysicsConstraintConeStiffness = 200.00f;
    this->PhysicsConstraintTwistStiffness = 200.00f;
    this->PhysicsConstraintLinearStiffness = 400.00f;
    this->JointOffset = 50.00f;
    this->Swing1LimitDegrees = 45.00f;
    this->Swing2LimitDegrees = 30.00f;
    this->TwistLimitDegrees = 15.00f;
    this->AdjustDistance = 1.00f;
    this->BreakDistance = 1100.00f;
    this->DragDistance = 1000.00f;
    this->ComponentBreakDistance = 0.00f;
    this->MinConnectionLength = 300.00f;
    this->UseSourceScale = true;
    this->StretchForce = 2000.00f;
    this->SourceForceBias = 0.50f;
    this->StretchDampening = 0.50f;
    this->Stretchy = true;
    this->CanAttachAny = false;
    this->ConnectorVerticalOffsetWhileDragging = 0.00f;
    this->ConnectionSpawnedByIndicator = NULL;
    this->ConnectorMesh = NULL;
    this->ConnectorHoverInSlotForwardOffset = 0.00f;
    this->SlotConstraint = NULL;
    this->ConstraintBuilt = false;
    this->ConstraintSleeping = false;
    this->Built = false;
    this->Visible = true;
    this->TargetTetherLocation = false;
    this->clickable = true;
    this->BreakImmediate = false;
    this->CanConnectComponents = false;
    this->CanConnectSlots = true;
    this->bHighlightTargetedPhysicalItem = false;
    this->OverrideUnbreakable = false;
    this->UsePhysicsConstraint = false;
    this->Destroying = false;
    this->IsIndicator = false;
    this->ClickableAfterRelease = false;
    this->bCarriesOxygen = false;
    this->bTraceIgnoreSelf = true;
    this->bTraceIgnoreParent = true;
    this->bNoProximitySlotSelect = false;
    this->SourceTense = true;
    this->TargetTense = true;
    this->TargetConnectorTense = true;
    this->UseSplineCable = false;
    this->AlignWithSurfaceNormal = false;
    this->GravityTension = 0.00f;
    this->CurveTension = 1.50f;
    this->CurrentConnectionLength = 0.00f;
    this->ConnectionLength = 0.00f;
    this->SegmentLength = 200.00f;
    this->SegmentScale = 0.20f;
    this->Connector = NULL;
    this->HangingActor = NULL;
    this->SegmentComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Segments"));
    this->SplineMeshComponent = CreateDefaultSubobject<USplineMeshComponent>(TEXT("SplineMesh"));
    this->CableExtendSpeed = 0.00f;
    this->ConnectionLengthAudioEventInterval = 100.00f;
    this->AdaptiveTickComponent = CreateDefaultSubobject<UAdaptiveTickComponent>(TEXT("AdaptiveTickComponent"));
    this->SourcePoint = NULL;
    this->TargetPoint = NULL;
    this->ConnectedComponent = NULL;
}

