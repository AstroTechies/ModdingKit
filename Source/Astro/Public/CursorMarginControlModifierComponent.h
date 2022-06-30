#pragma once
#include "CoreMinimal.h"
#include "ECameraDOF.h"
#include "CameraModifierComponent.h"
#include "ECameraControlMask.h"
#include "CursorMarginControlModifierComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UCursorMarginControlModifierComponent : public UCameraModifierComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    ECameraDOF ControlledDOF;

    UPROPERTY(EditAnywhere)
    uint8 bInverted : 1;

    UPROPERTY(EditAnywhere)
    float LeftMargin;

    UPROPERTY(EditAnywhere)
    float RightMargin;

    UPROPERTY(EditAnywhere)
    float TopMargin;

    UPROPERTY(EditAnywhere)
    float BottomMargin;

    UPROPERTY(EditAnywhere)
    float MaxSpeed;

    UPROPERTY(EditAnywhere)
    float MaxTargetValue;

    UPROPERTY(EditAnywhere)
    float MinTargetValue;

    UPROPERTY(EditAnywhere)
    ECameraControlMask ControlMask;

    UCursorMarginControlModifierComponent();
};
