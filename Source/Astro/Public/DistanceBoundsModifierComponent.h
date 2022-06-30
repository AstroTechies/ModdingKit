#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "DistanceBoundsModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UDistanceBoundsModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float InnerBound;

    UPROPERTY(EditAnywhere)
    float OuterBound;

    UPROPERTY(EditAnywhere)
    float CorrectionSpeed;

    UPROPERTY(EditAnywhere)
    uint8 bMaintainHeightOnCorrection : 1;

    UDistanceBoundsModifierComponent();
};
