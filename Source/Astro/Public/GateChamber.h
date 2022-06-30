#pragma once
#include "CoreMinimal.h"
#include "GateObject.h"
#include "GateChamber.generated.h"

class URaycastTerrainSurfaceComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AGateChamber : public AGateObject
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export, VisibleAnywhere)
    URaycastTerrainSurfaceComponent *RaycastTerrainSurfaceComponent;

public:
    AGateChamber();
};
