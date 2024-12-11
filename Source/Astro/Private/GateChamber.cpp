#include "GateChamber.h"
#include "RaycastTerrainSurfaceComponent.h"

AGateChamber::AGateChamber(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RaycastTerrainSurfaceComponent = CreateDefaultSubobject<URaycastTerrainSurfaceComponent>(TEXT("RaycastTerrainSurface"));
    this->RaycastTerrainSurfaceComponent->SetupAttachment(RootComponent);
}


