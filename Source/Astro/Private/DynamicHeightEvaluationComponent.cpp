#include "DynamicHeightEvaluationComponent.h"
#include "Net/UnrealNetwork.h"

UDynamicHeightEvaluationComponent::UDynamicHeightEvaluationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurrentDynamicHeight = 0.00f;
}

void UDynamicHeightEvaluationComponent::SetCurrentDynamicHeight(float Height) {
}

void UDynamicHeightEvaluationComponent::OnRep_OnCurrentDynamicHeightChanged() {
}

float UDynamicHeightEvaluationComponent::GetCurrentDynamicHeight() {
    return 0.0f;
}

void UDynamicHeightEvaluationComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UDynamicHeightEvaluationComponent, CurrentDynamicHeight);
}


