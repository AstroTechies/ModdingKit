#include "WorldGravity.h"

class UPrimitiveComponent;

void UWorldGravity::OnComponentSleep(UPrimitiveComponent* SleepingComponent, FName BoneName) {
}

void UWorldGravity::OnComponentAwake(UPrimitiveComponent* WakingComponent, FName BoneName) {
}

UWorldGravity::UWorldGravity() {
    this->Enable = true;
    this->DisableIfNoTerrain = true;
    this->bAdhocPhysicsGeneration = false;
    this->bIsSleeping = false;
    this->TerrainLODAtLastSleep = 255;
}

