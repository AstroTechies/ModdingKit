#include "RailComponent.h"

URailComponent::URailComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MoveSpeed = 400.00f;
    this->OwnerConnection = NULL;
}

bool URailComponent::SendItem(APhysicalItem* Item, AActor* Source) {
    return false;
}

void URailComponent::MulticastSendRail_Implementation(bool Immediate) {
}


