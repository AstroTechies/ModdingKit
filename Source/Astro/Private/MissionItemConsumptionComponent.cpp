#include "MissionItemConsumptionComponent.h"
#include "Net/UnrealNetwork.h"

UMissionItemConsumptionComponent::UMissionItemConsumptionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->ConsumptionRate = 1.00f;
    this->ConsumptionSlotEjectionForce = 250000.00f;
    this->ConsumptionSlotOrganizationRule = NULL;
    this->RequestState = EMissionItemRequestState::RequestsUninitalized;
    this->ConsumptionProgress = 0.00f;
}

void UMissionItemConsumptionComponent::OnRep_RequestsState(EMissionItemRequestState prevState) {
}

void UMissionItemConsumptionComponent::OnRep_ConsumptionProgress(float prevProgress) {
}

void UMissionItemConsumptionComponent::InitializeMissionRequests_Internal() {
}

void UMissionItemConsumptionComponent::HandleRequestObjectiveUpdated(FName missionId, const FAstroMissionObjectiveProgress& objectiveProgress, int32 objectiveIndex) {
}

void UMissionItemConsumptionComponent::HandleRequestMissionCompleted(FName missionId) {
}

void UMissionItemConsumptionComponent::HandleRequestMissionActivated(FName missionId) {
}

void UMissionItemConsumptionComponent::HandleOnSetItem(APhysicalItem* Item) {
}

void UMissionItemConsumptionComponent::HandleOnReleaseItem(APhysicalItem* Item) {
}

EMissionItemRequestState UMissionItemConsumptionComponent::GetRequestState() {
    return EMissionItemRequestState::RequestsUninitalized;
}

float UMissionItemConsumptionComponent::GetCurrentConsumptionProgress() {
    return 0.0f;
}

void UMissionItemConsumptionComponent::AuthorityInitializeMissionRequests(const TArray<FName>& NewRequestMissionIDs) {
}

void UMissionItemConsumptionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UMissionItemConsumptionComponent, RequestState);
    DOREPLIFETIME(UMissionItemConsumptionComponent, ConsumptionProgress);
}


