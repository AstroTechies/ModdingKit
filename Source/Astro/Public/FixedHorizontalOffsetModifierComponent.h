#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FixedHorizontalOffsetModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UFixedHorizontalOffsetModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float UpperLimit;

    UPROPERTY(EditAnywhere)
    float LowerLimit;

    UFixedHorizontalOffsetModifierComponent();
};
