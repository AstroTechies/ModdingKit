#pragma once
#include "CoreMinimal.h"
#include "SunlightDetectorComponent.h"
#include "SolarPowerComponent.generated.h"

class UPowerComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API USolarPowerComponent : public USunlightDetectorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float MinPowerOutput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float MaxPowerOutput;

private:
    UPROPERTY(Export)
    UPowerComponent *PowerComponent;

public:
    USolarPowerComponent();
};
