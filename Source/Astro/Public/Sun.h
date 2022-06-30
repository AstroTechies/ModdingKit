#pragma once
#include "CoreMinimal.h"
#include "SolarBody.h"
#include "Sun.generated.h"

class UDirectionalLightComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ASun : public ASolarBody
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, VisibleDefaultsOnly, meta = (AllowPrivateAccess = true))
    UDirectionalLightComponent *SunLight;

    ASun();
};
