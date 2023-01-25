#include "Repackager.h"
#include "AstroActionComponent.h"
#include "Net/UnrealNetwork.h"

class AActor;

void ARepackager::UpdateRepackagingTarget() {
}



void ARepackager::InitiateRepackaging() {
}

void ARepackager::HandleRepackagingTargetEndPlay(AActor* Actor) {
}

void ARepackager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARepackager, TargetState);
}

ARepackager::ARepackager() {
    this->ActionComponent = CreateDefaultSubobject<UAstroActionComponent>(TEXT("ActionComponent"));
    this->TargetState = ERepackagingTargetState::None;
    this->RepackActionType = NULL;
}

