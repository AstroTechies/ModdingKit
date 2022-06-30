#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FrameTargetModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UFrameTargetModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float HeightOffset;

    UFrameTargetModifierComponent();
};
