#include "LockingMechanismView.h"
#include "Net/UnrealNetwork.h"

ULockingMechanismView::ULockingMechanismView() {
    this->bIsOpen = false;
    this->LinkedLockingMechanism = NULL;
    this->Definition = NULL;
}

void ULockingMechanismView::OnRep_IsOpen() {
}

void ULockingMechanismView::OnOpenStateChanged(ULockingMechanism* LockingMechanism, const FLockChangedEventMetadata& EventData) {
}

void ULockingMechanismView::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ULockingMechanismView, bIsOpen);
}


