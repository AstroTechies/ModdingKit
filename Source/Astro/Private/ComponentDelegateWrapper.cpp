#include "ComponentDelegateWrapper.h"

class UPrimitiveComponent;
class AActor;

void UComponentDelegateWrapper::OnComponentHit(UPrimitiveComponent* ThisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void UComponentDelegateWrapper::OnActorClick(AActor* Actor, FKey Key) {
}

UComponentDelegateWrapper::UComponentDelegateWrapper() {
}

