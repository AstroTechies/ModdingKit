#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "SpaceshipCameraContext.generated.h"

class UOrbitalNavigationComponent;

UCLASS(Blueprintable, Blueprintable)
class USpaceshipCameraContext : public UCameraContext
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Export, Transient)
    UOrbitalNavigationComponent *OrbitalNavComponent;

public:
    USpaceshipCameraContext();
};
