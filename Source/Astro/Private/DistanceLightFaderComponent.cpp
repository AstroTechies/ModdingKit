#include "DistanceLightFaderComponent.h"
#include "Net/UnrealNetwork.h"

void UDistanceLightFaderComponent::UpdateLightVisibility(bool setVisible) {
}

void UDistanceLightFaderComponent::UpdateLightIntensity(float NewIntensity) {
}

void UDistanceLightFaderComponent::UpdateLightFadeWithVisibility(FVector otherObjectLocation, bool setVisible) {
}

void UDistanceLightFaderComponent::AuthoritySetLightWantsToBeOn(const bool wantsToBeOn) {
}

void UDistanceLightFaderComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UDistanceLightFaderComponent, bIsUsingVirtualLight);
    DOREPLIFETIME(UDistanceLightFaderComponent, REP_LightWantsToBeOn);
}

UDistanceLightFaderComponent::UDistanceLightFaderComponent() {
    this->bIsUsingVirtualLight = false;
    this->LightIntensity = 0.00f;
    this->LightSquaredDist = 40000000.00f;
    this->LightVisible = false;
    this->REP_LightWantsToBeOn = 255;
    this->LightComponent = NULL;
    this->WithVisibilityComponent = NULL;
}

