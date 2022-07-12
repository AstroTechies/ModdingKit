#include "ComponentDelegateWrapper.h"

class AActor;
class UPrimitiveComponent;

void UComponentDelegateWrapper::OnComponentHit(UPrimitiveComponent* ThisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void UComponentDelegateWrapper::OnActorClick(AActor* Actor, FKey Key) {
}

UComponentDelegateWrapper::UComponentDelegateWrapper() {
}

