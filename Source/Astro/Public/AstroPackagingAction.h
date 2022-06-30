#pragma once
#include "CoreMinimal.h"
#include "AstroPlayMontageAction.h"
#include "AstroPackagingAction.generated.h"

class UCurveVector;
class UCurveFloat;

UCLASS(Blueprintable, Abstract)
class ASTRO_API UAstroPackagingAction : public UAstroPlayMontageAction
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    UCurveVector *LocationCurve;

    UPROPERTY(EditDefaultsOnly)
    UCurveVector *RotationCurve;

    UPROPERTY(EditDefaultsOnly)
    UCurveVector *ScaleCurve;

    UPROPERTY(EditDefaultsOnly)
    FName ItemInterpolationTargetComponentName;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *ItemTargetInterpolationProgressCurve;

public:
    UAstroPackagingAction();
};
