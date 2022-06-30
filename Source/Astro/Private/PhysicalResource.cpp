#include "PhysicalResource.h"


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

APhysicalResource::APhysicalResource() {
    this->DestroyOnDrain = true;
}

