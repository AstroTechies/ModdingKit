#include "PhysicalResource.h"

APhysicalResource::APhysicalResource(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DestroyOnDrain = true;
}


void APhysicalResource::PostDrained() {
}


bool APhysicalResource::IsFull() {
    return false;
}

bool APhysicalResource::IsEmpty() {
    return false;
}

float APhysicalResource::GetFullness() {
    return 0.0f;
}


