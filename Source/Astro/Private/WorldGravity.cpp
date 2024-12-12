#include "WorldGravity.h"

UWorldGravity::UWorldGravity(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Enable = true;
    this->DisableIfNoTerrain = true;
    this->bAdhocPhysicsGeneration = false;
    this->bIsSleeping = false;
    this->TerrainLODAtLastSleep = 255;
}

void UWorldGravity::OnComponentSleep(UPrimitiveComponent* SleepingComponent, FName BoneName) {
}

void UWorldGravity::OnComponentAwake(UPrimitiveComponent* WakingComponent, FName BoneName) {
}


