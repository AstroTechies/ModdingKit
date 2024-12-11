#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "SpaceshipCameraContext.generated.h"

class UOrbitalNavigationComponent;

UCLASS(Blueprintable)
class USpaceshipCameraContext : public UCameraContext {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOrbitalNavigationComponent* OrbitalNavComponent;
    
public:
    USpaceshipCameraContext();

};

