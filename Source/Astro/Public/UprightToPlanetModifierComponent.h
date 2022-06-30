#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "UprightToPlanetModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UUprightToPlanetModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 bUseTargetLocation : 1;

    UUprightToPlanetModifierComponent();
};
