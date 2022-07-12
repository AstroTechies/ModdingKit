#pragma once
#include "CoreMinimal.h"
#include "GateObject.h"
#include "GateChamber.generated.h"

class URaycastTerrainSurfaceComponent;

UCLASS(Blueprintable)
class ASTRO_API AGateChamber : public AGateObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    URaycastTerrainSurfaceComponent* RaycastTerrainSurfaceComponent;
    
public:
    AGateChamber();
};

