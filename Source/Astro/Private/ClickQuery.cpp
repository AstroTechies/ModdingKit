#include "ClickQuery.h"

UClickQuery::UClickQuery() {
}

void UClickQuery::SetResultTertiary(AActor* Actor, AActor* ViewActor, EClickBehavior Behavior) {
}

bool UClickQuery::SetResultStorage(UStorageChassisComponent* storage, FSlotReference PrimarySlot) {
    return false;
}

bool UClickQuery::SetResultSlotPrimaryAsConnectionOnly(FSlotReference Slot) {
    return false;
}

bool UClickQuery::SetResultSlotPrimary(FSlotReference Slot, bool Replace) {
    return false;
}

void UClickQuery::SetResultSecondary(AActor* Actor, AActor* ViewActor, EClickBehavior Behavior) {
}

void UClickQuery::SetResultPrimary(AActor* Actor, AActor* ViewActor, EClickBehavior Behavior) {
}

void UClickQuery::SetResultComponentPrimary(UPrimitiveComponent* Component) {
}

void UClickQuery::ResetPrimaryClickResult() {
}

void UClickQuery::ResetClickResultExceptForSecondary(AActor* Actor) {
}

void UClickQuery::ResetClickResultExceptForHoverComponent() {
}

void UClickQuery::ResetClickResult() {
}

FSlotReference UClickQuery::QueryCameraFacingSlotFromArray(AActor* Actor, const TArray<FSlotReference> Slots) {
    return FSlotReference{};
}

bool UClickQuery::HavePrimaryResult() const {
    return false;
}

AActor* UClickQuery::GetSecondaryActor() const {
    return NULL;
}

FSlotReference UClickQuery::GetPrimarySlot() const {
    return FSlotReference{};
}

UPrimitiveComponent* UClickQuery::GetPrimaryComponent() const {
    return NULL;
}

AActor* UClickQuery::GetPrimaryActor() const {
    return NULL;
}

AActor* UClickQuery::GetInteractingActor() const {
    return NULL;
}

FVector UClickQuery::GetHitLocation() const {
    return FVector{};
}

UPrimitiveComponent* UClickQuery::GetHitComponent() const {
    return NULL;
}

AActor* UClickQuery::GetHitActor() const {
    return NULL;
}

APlayController* UClickQuery::GetController() const {
    return NULL;
}

AActor* UClickQuery::GetClickActor() const {
    return NULL;
}

UClickQuery* UClickQuery::ClickQuery() {
    return NULL;
}


