#include "PlanetEffect.h"

UPlanetEffect::UPlanetEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SphereRadius = 7000.00f;
    this->bSimLocal = false;
    this->bAutoHandleCriticalComponents = true;
}

void UPlanetEffect::TriggerUpdate() {
}

void UPlanetEffect::SetActorIgnoreForAI(AActor* Actor, bool bSetIgnore) {
}

void UPlanetEffect::AddManagedComponent(UActorComponent* Component) {
}


