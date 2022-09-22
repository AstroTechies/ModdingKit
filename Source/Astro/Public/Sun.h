#pragma once
#include "CoreMinimal.h"
#include "SolarBody.h"
#include "Components/DirectionalLightComponent.h"
#include "Sun.generated.h"

class UDirectionalLightComponent;

UCLASS(Blueprintable)
class ASTRO_API ASun : public ASolarBody {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UDirectionalLightComponent* SunLight;
    
    ASun();
};

