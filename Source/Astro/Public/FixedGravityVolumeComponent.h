#pragma once
#include "CoreMinimal.h"
#include "CustomGravityVolumeComponent.h"
#include "FixedGravityVolumeComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UFixedGravityVolumeComponent : public UCustomGravityVolumeComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    float BoxExtent;

    UPROPERTY(EditAnywhere)
    bool bApplyGravityUpward;

public:
    UFixedGravityVolumeComponent();
};
