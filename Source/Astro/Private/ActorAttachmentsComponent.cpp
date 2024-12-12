#include "ActorAttachmentsComponent.h"
#include "Net/UnrealNetwork.h"

UActorAttachmentsComponent::UActorAttachmentsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->MaxAttachedPlayerCount = 0;
    this->UsePlanetCameraUp = false;
    this->AllowFreeCam = false;
    this->DisableViewTargetChangeOnExit = false;
    this->EntryInterpolationTime = 1.25f;
    this->EntryInterpolationEaseOutExponent = 3.00f;
    this->ExitInterpolationTime = 0.75f;
    this->ExitInterpolationEaseOutExponent = 3.00f;
    this->DetachGroundedTrace = 0.00f;
    this->CanEnter = true;
    this->ExitSuppressionCount = 0;
}

AAstroPlayerController* UActorAttachmentsComponent::TryGetFirstAttachedPlayer(bool bIgnoreExiting) {
    return NULL;
}

bool UActorAttachmentsComponent::TogglePlayerAttachedStorage(APlayerController* Controller, UStorageChassisComponent* storage, bool& Toggled, bool bImmediate, bool bForce) {
    return false;
}

bool UActorAttachmentsComponent::ToggleClickPlayerAttached(bool& Toggled) {
    return false;
}

bool UActorAttachmentsComponent::ToggleAttached(AActor* Actor, bool& Toggled, bool setViewTarget, bool bImmediate) {
    return false;
}

void UActorAttachmentsComponent::SetupAttachedViewTargetsDelayed() {
}

void UActorAttachmentsComponent::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy) {
}

void UActorAttachmentsComponent::PushExitSuppression() {
}

void UActorAttachmentsComponent::PopExitSuppression() {
}

void UActorAttachmentsComponent::OnRep_Attachments() {
}

void UActorAttachmentsComponent::OnAttachedActorDestroyed(AActor* DestroyedActor) {
}

bool UActorAttachmentsComponent::HasPlayer() {
    return false;
}

bool UActorAttachmentsComponent::HasController(APlayController* Controller) {
    return false;
}

bool UActorAttachmentsComponent::HasClickPlayer() {
    return false;
}

bool UActorAttachmentsComponent::HasActor(AActor* Actor, int32& outIndex) {
    return false;
}

AActor* UActorAttachmentsComponent::GetFirstAttachedActor(bool bIgnoreExiting) {
    return NULL;
}

FTransform UActorAttachmentsComponent::GetDetachTransform(int32 I) const {
    return FTransform{};
}

FTransform UActorAttachmentsComponent::GetAttachTransform(int32 I) const {
    return FTransform{};
}

void UActorAttachmentsComponent::FinishExiting(int32 I) {
}

void UActorAttachmentsComponent::DetachAll(bool bImmediate) {
}

bool UActorAttachmentsComponent::CanExit() const {
    return false;
}

TArray<APlayController*> UActorAttachmentsComponent::AttachedArrayPlayers(const TArray<UActorAttachmentsComponent*>& Attachments) {
    return TArray<APlayController*>();
}

bool UActorAttachmentsComponent::AttachedArrayHasPlayer(const TArray<UActorAttachmentsComponent*>& Attachments) {
    return false;
}

UActorAttachmentsComponent* UActorAttachmentsComponent::AttachedArrayHasActor(const TArray<UActorAttachmentsComponent*>& Attachments, AActor* Actor, int32& outIndex) {
    return NULL;
}

USceneComponent* UActorAttachmentsComponent::AttachedArrayAvailable(const TArray<UActorAttachmentsComponent*>& Attachments, const FVector& Location) {
    return NULL;
}

UActorAttachmentsComponent* UActorAttachmentsComponent::ActorActorAttachmentsComponent(AActor* Actor) {
    return NULL;
}

void UActorAttachmentsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorAttachmentsComponent, AttachmentStates);
}


