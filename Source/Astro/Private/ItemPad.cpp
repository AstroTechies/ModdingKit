#include "ItemPad.h"
#include "Net/UnrealNetwork.h"

class UAstroSaveCustomArchiveProxy;
class UPrimitiveComponent;
class UItemPad;
class AActor;

void UItemPad::StartInWorld() {
}

void UItemPad::SpawnPad(bool withTool, UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

void UItemPad::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void UItemPad::ReleaseFromSlot(bool NewOwner) {
}

void UItemPad::PlaceInSlot() {
}

void UItemPad::PickUpFromWorld(bool PhysicalMovement) {
}

void UItemPad::OnRep_Pad() {
}

void UItemPad::OnDeformationComplete(const FDeformationParamsT2& deformationParams) {
}

void UItemPad::MotionStateChanged() {
}

void UItemPad::EmplaceInSlot() {
}

void UItemPad::DropInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal) {
}

UItemPad* UItemPad::ActorItemPad(AActor* Actor) {
    return NULL;
}

void UItemPad::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UItemPad, Pad);
}

UItemPad::UItemPad() {
    this->AutoSpawn = true;
    this->ManuallyReplicatePadTransform = true;
    this->PadClass = NULL;
    this->Pad = NULL;
}

