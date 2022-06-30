#pragma once
#include "CoreMinimal.h"
#include "CustomGravityVolumeComponent.h"
#include "SphericalGravityVolumeComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API USphericalGravityVolumeComponent : public UCustomGravityVolumeComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    float SphereRadius;

    UPROPERTY(EditAnywhere)
    bool bApplyGravityOutward;

public:
    USphericalGravityVolumeComponent();
};
