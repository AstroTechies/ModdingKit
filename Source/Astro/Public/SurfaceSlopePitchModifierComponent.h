#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "SurfaceSlopePitchModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class USurfaceSlopePitchModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float UpperLimit;

    UPROPERTY(EditAnywhere)
    float LowerLimit;

    USurfaceSlopePitchModifierComponent();
};
