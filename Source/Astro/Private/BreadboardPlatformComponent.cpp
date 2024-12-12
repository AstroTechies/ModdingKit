#include "BreadboardPlatformComponent.h"
#include "Net/UnrealNetwork.h"

UBreadboardPlatformComponent::UBreadboardPlatformComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->LockdownSpikes = NULL;
    this->AnimationCurve = NULL;
    this->REP_LockdownEnabled = false;
    this->LockdownAnimationDuration = 0.33f;
    this->LockdownAnimationTravelDistance = 40.00f;
    this->OwningItem = NULL;
}

void UBreadboardPlatformComponent::OnRep_LockdownEnabledChanged() {
}

void UBreadboardPlatformComponent::AuthoritySetLockdownEnabled(bool lockdownEnabled) {
}

void UBreadboardPlatformComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UBreadboardPlatformComponent, REP_LockdownEnabled);
}


