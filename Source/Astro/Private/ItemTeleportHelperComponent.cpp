#include "ItemTeleportHelperComponent.h"

class AActor;

bool UItemTeleportHelperComponent::FindValidSpawnLocationAroundTarget(AActor* Target, const TArray<AActor*>& ActorsToIgnore, ELineOfSightBehavior faceTarget, FVector& outLoc, FRotator& outRot) {
    return false;
}

UItemTeleportHelperComponent::UItemTeleportHelperComponent() {
    this->MinLocationDistance = 4500.00f;
    this->MaxLocationDistance = 5500.00f;
    this->MaxTeleportHeight = 2000.00f;
    this->MinTeleportHeight = -4000.00f;
    this->SightDistance = 1000.00f;
    this->LOSHeightOffset = 300.00f;
    this->AngleStride = 2.00f;
    this->MaxStartAngleOffset = 90.00f;
    this->TerrainDensityThreshold = 0.70f;
    this->MinSurfaceDot = 0.20f;
    this->MaxFindAttempts = 10;
    this->ShowTrace = EDrawDebugTrace::None;
}

