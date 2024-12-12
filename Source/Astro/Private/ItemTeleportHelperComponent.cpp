#include "ItemTeleportHelperComponent.h"

UItemTeleportHelperComponent::UItemTeleportHelperComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinLocationDistance = 4500.00f;
    this->MaxLocationDistance = 5500.00f;
    this->MaxTeleportHeight = 2000.00f;
    this->MinTeleportHeight = -4000.00f;
    this->bSkipBiomeCheck = false;
    this->SightDistance = 1000.00f;
    this->LOSHeightOffset = 300.00f;
    this->AngleStride = 2.00f;
    this->MaxStartAngleOffset = 90.00f;
    this->TerrainDensityThreshold = 0.70f;
    this->MinSurfaceDot = 0.20f;
    this->MaxFindAttempts = 10;
    this->ShowTrace = EDrawDebugTrace::None;
}

bool UItemTeleportHelperComponent::FindValidSpawnLocationNearSelf(const FVector& targetLoc, const TArray<AActor*>& ActorsToIgnore, ELineOfSightBehavior faceTarget, FVector& outLoc, FRotator& outRot) {
    return false;
}

bool UItemTeleportHelperComponent::FindValidSpawnLocationAroundTarget(AActor* Target, const TArray<AActor*>& ActorsToIgnore, ELineOfSightBehavior faceTarget, FVector& outLoc, FRotator& outRot) {
    return false;
}

bool UItemTeleportHelperComponent::FindValidSpawnLocation(const FVector& targetLoc, const FVector& currLoc, const TArray<AActor*>& ActorsToIgnore, ELineOfSightBehavior faceTarget, FVector& outLoc, FRotator& outRot) {
    return false;
}


