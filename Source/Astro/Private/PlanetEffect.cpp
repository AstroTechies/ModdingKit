#include "PlanetEffect.h"

class UActorComponent;
class AActor;

void UPlanetEffect::TriggerUpdate() {
}

void UPlanetEffect::SetActorIgnoreForAI(AActor* Actor, bool bSetIgnore) {
}

void UPlanetEffect::AddManagedComponent(UActorComponent* Component) {
}

UPlanetEffect::UPlanetEffect() {
    this->SphereRadius = 7000.00f;
    this->bSimLocal = false;
    this->bAutoHandleCriticalComponents = true;
}

