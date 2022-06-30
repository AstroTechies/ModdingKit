#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FixedPitchModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UFixedPitchModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float UpperLimit;

    UPROPERTY(EditAnywhere)
    float LowerLimit;

    UFixedPitchModifierComponent();
};
