#include "PlayerProximityTickComponent.h"

class AActor;
class UActorComponent;
class UPlayerProximityTickComponent;
class UPrimitiveComponent;
class UShapeComponent;

void UPlayerProximityTickComponent::SetProximitySphere(float Radius) {
}

void UPlayerProximityTickComponent::SetProximityShape(UShapeComponent* inProximityShape) {
}

void UPlayerProximityTickComponent::OnTrackedPlayerDestroyed(AActor* DestroyedActor) {
}

TArray<AActor*> UPlayerProximityTickComponent::GetOverlappingPlayers() {
    return TArray<AActor*>();
}

UPlayerProximityTickComponent* UPlayerProximityTickComponent::GetActorPlayerProximityTickComponent(AActor* Actor) {
    return NULL;
}

TArray<AActor*> UPlayerProximityTickComponent::GetActorOverlappingPlayers(AActor* Actor) {
    return TArray<AActor*>();
}

void UPlayerProximityTickComponent::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void UPlayerProximityTickComponent::CheckAndDisableTick() {
}

void UPlayerProximityTickComponent::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& OverlapInfo) {
}

void UPlayerProximityTickComponent::AddManagedComponents(const TArray<UActorComponent*>& Components) {
}

void UPlayerProximityTickComponent::AddManagedComponent(UActorComponent* Component) {
}

UPlayerProximityTickComponent::UPlayerProximityTickComponent() {
    this->InitialSphereRadius = 3000.00f;
    this->bManageActorTick = true;
    this->bCanIgnoreCreativeModeHazardInvisibility = false;
    this->bAutoHandleCriticalComponents = true;
    this->ProximityShape = NULL;
}

