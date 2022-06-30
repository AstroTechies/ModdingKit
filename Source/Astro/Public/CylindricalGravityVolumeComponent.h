#pragma once
#include "CoreMinimal.h"
#include "CustomGravityVolumeComponent.h"
#include "CylindricalGravityVolumeComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UCylindricalGravityVolumeComponent : public UCustomGravityVolumeComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    float CylinderRadius;

    UPROPERTY(EditAnywhere)
    float CylinderHeight;

    UPROPERTY(EditAnywhere)
    bool bApplyGravityOutward;

public:
    UCylindricalGravityVolumeComponent();
};
