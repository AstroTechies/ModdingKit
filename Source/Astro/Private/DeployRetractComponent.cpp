#include "DeployRetractComponent.h"
#include "Net/UnrealNetwork.h"

UDeployRetractComponent::UDeployRetractComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsDeployed = false;
    this->bPendingDeployed = false;
    this->DeployMontage = NULL;
    this->RetractMontage = NULL;
    this->DeployedCollision = NULL;
    this->RetractedCollision = NULL;
}

void UDeployRetractComponent::OnRep_PendingDeployed() {
}

void UDeployRetractComponent::OnRep_IsDeployed() {
}

void UDeployRetractComponent::OnDeployRetractMontageActionEnded(UAstroAction* montageAction) {
}

void UDeployRetractComponent::AuthorityRetract() {
}

void UDeployRetractComponent::AuthorityDeploy() {
}

void UDeployRetractComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UDeployRetractComponent, bIsDeployed);
    DOREPLIFETIME(UDeployRetractComponent, bPendingDeployed);
}


