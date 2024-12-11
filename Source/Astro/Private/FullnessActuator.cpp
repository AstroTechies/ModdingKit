#include "FullnessActuator.h"
#include "ActuatorComponent.h"
#include "Net/UnrealNetwork.h"

AFullnessActuator::AFullnessActuator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ActuatorComponent = CreateDefaultSubobject<UActuatorComponent>(TEXT("Actuator"));
    this->MostRecentEvent = EFullnessActuatorEventType::None;
    this->bWasEmpty = false;
    this->bWasFull = false;
    this->EventTypeFlags = 0;
    this->FullnessResponseMode = EFullnessActuatorResponseMode::FullOrEmpty;
}

void AFullnessActuator::OnRep_TargetItem() {
}

void AFullnessActuator::OnRep_MostRecentEvent() {
}

void AFullnessActuator::OnRep_FullnessResponseMode() {
}

void AFullnessActuator::HandleReleasedFromSlot(bool NewOwner) {
}

void AFullnessActuator::HandlePlacedInSlot() {
}

void AFullnessActuator::AuthorityRespondToMotionStateChange() {
}

void AFullnessActuator::AuthorityCycleFullnessResponseMode() {
}

void AFullnessActuator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AFullnessActuator, TargetItem);
    DOREPLIFETIME(AFullnessActuator, MostRecentEvent);
    DOREPLIFETIME(AFullnessActuator, FullnessResponseMode);
}


