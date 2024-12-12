#include "TeleportationBubble.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ActorAttachmentsComponent.h"
#include "Net/UnrealNetwork.h"

ATeleportationBubble::ATeleportationBubble(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicateMovement = true;
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->ActorAttachComponent = CreateDefaultSubobject<UActorAttachmentsComponent>(TEXT("ActorAttachments"));
    this->BubbleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BubbleMesh"));
    this->ProxyBubbleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArrivalCollision"));
    this->BubbleExpansionTime = 0.00f;
    this->BubbleExpansionCurve = NULL;
    this->CharacterBeingTeleported = NULL;
    this->DestinationType = ETeleportationDestinationType::ExactLocation;
    this->TeleportationState = ETeleportationBubbleState::Uninitialized;
    this->BubbleExpansionTimeRemaining = 0.00f;
    this->BubbleMesh->SetupAttachment(RootComponent);
    this->ProxyBubbleMesh->SetupAttachment(RootComponent);
}

bool ATeleportationBubble::TickPostArrivalEffects_Implementation() {
    return false;
}

bool ATeleportationBubble::TickExpansionEffects_Implementation() {
    return false;
}

bool ATeleportationBubble::TickArrivalExpansionEffects_Implementation() {
    return false;
}

bool ATeleportationBubble::TickAbortionEffects_Implementation() {
    return false;
}

void ATeleportationBubble::TeleportCharacterToPosition(AAstroCharacter* characterToTeleport, const FVector& TargetLocation) {
}

void ATeleportationBubble::TeleportCharacterToGateObject(AAstroCharacter* characterToTeleport, const FGateObjectReference& GateObjectRef) {
}

void ATeleportationBubble::OnRep_ReplicationData() {
}

void ATeleportationBubble::OnCharacterCompletedBubbleExit(AActor* characterActor) {
}

void ATeleportationBubble::OnCharacterCompletedBubbleEntry(AActor* characterActor) {
}





void ATeleportationBubble::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ATeleportationBubble, ReplicationData);
}


