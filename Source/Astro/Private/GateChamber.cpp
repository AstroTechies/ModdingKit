#include "GateChamber.h"
#include "RaycastTerrainSurfaceComponent.h"

AGateChamber::AGateChamber() {
    this->RaycastTerrainSurfaceComponent = CreateDefaultSubobject<URaycastTerrainSurfaceComponent>(TEXT("RaycastTerrainSurface"));
}

