#include "AstroActionComponent.h"
#include "Templates/SubclassOf.h"

UAstroActionComponent::UAstroActionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UAstroActionComponent::StartActionInstance(UAstroAction* Action, EAstroActionNetworking Networking) {
    return false;
}

bool UAstroActionComponent::StartAction(TSubclassOf<UAstroAction> ActionType) {
    return false;
}

void UAstroActionComponent::ServerRequestStartAction_Implementation(const FAstroActionRequestPayload& payload) {
}
bool UAstroActionComponent::ServerRequestStartAction_Validate(const FAstroActionRequestPayload& payload) {
    return true;
}

void UAstroActionComponent::ServerRequestInterruptAction_Implementation(const FAstroActionIdentifier& actionToInterruptIdentifier) {
}
bool UAstroActionComponent::ServerRequestInterruptAction_Validate(const FAstroActionIdentifier& actionToInterruptIdentifier) {
    return true;
}

void UAstroActionComponent::OnActionEnded(UAstroAction* EndedAction) {
}

void UAstroActionComponent::MulticastStartAction_Implementation(const FAstroActionRequestPayload& payload) {
}
bool UAstroActionComponent::MulticastStartAction_Validate(const FAstroActionRequestPayload& payload) {
    return true;
}

void UAstroActionComponent::MulticastInterruptAction_Implementation(const FAstroActionIdentifier& interruptedActionIdentifier) {
}
bool UAstroActionComponent::MulticastInterruptAction_Validate(const FAstroActionIdentifier& interruptedActionIdentifier) {
    return true;
}

UAstroAction* UAstroActionComponent::CreateAction(TSubclassOf<UAstroAction> ActionType) {
    return NULL;
}

void UAstroActionComponent::ClientDenyStartActionRequest_Implementation(const FAstroActionIdentifier& deniedActionIdentifier) {
}
bool UAstroActionComponent::ClientDenyStartActionRequest_Validate(const FAstroActionIdentifier& deniedActionIdentifier) {
    return true;
}


