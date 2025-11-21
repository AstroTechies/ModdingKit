#include "ActuatorComponent.h"
#include "Net/UnrealNetwork.h"

UActuatorComponent::UActuatorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bUseShapeCast = false;
    this->CableMeshes = NULL;
    this->CableMaterial = NULL;
    this->ConnectorMeshes = NULL;
    this->ConnectorMaterial = NULL;
    this->RerouteNodeMeshes = NULL;
    this->RerouteNodeMaterial = NULL;
    this->Bounds = NULL;
    this->SlotsComponent = NULL;
    this->RerouteNodeTooltip = NULL;
    this->RerouteNodeTooltipAnchor = NULL;
    this->ActuatorChannel = EActuatorChannel::None;
}

void UActuatorComponent::OnRerouteNodeEndCursorOver(UPrimitiveComponent* TouchedComponent) {
}

void UActuatorComponent::OnRep_Connections() {
}

void UActuatorComponent::MulticastPlayConnectionAudio_Implementation(const FString& AudioEvent, FVector Location, FRotator Rotation) {
}

void UActuatorComponent::MulticastOnActuate_Implementation(EFullnessActuatorEventType EventType) {
}

void UActuatorComponent::LocalUseRerouteNode() {
}

void UActuatorComponent::HandleTracePrimitiveDestroyed(FSlotReference Slot) {
}

void UActuatorComponent::HandleTracePrimitiveCreated(FSlotReference Slot) {
}

void UActuatorComponent::HandleRemovedFromSlot() {
}

void UActuatorComponent::HandleQueryClickable(UClickQuery* Query) {
}

void UActuatorComponent::HandlePlacedInSlot() {
}

void UActuatorComponent::HandleDestroyed(AActor* DestroyedActor) {
}

TArray<FSlotReference> UActuatorComponent::GetConnectors() const {
    return TArray<FSlotReference>();
}

void UActuatorComponent::AuthorityScheduleActuation(APlayController* Instigator, int32 tickDelay, EFullnessActuatorEventType FullnessActuatorEventType, const UObject* UniqueReference, bool makeUnique, EAuxSlotType slotTypeToTrigger) {
}

void UActuatorComponent::AuthorityHandleSlotClick(FSlotReference clickedSlot) {
}

void UActuatorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActuatorComponent, Connections);
}


