#pragma once
#include "CoreMinimal.h"
#include "AstroPlayMontageAction.h"
#include "AstroPackagingAction.generated.h"

class UCurveFloat;
class UCurveVector;

UCLASS(Abstract, Blueprintable)
class ASTRO_API UAstroPackagingAction : public UAstroPlayMontageAction {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* LocationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* RotationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* ScaleCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemInterpolationTargetComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ItemTargetInterpolationProgressCurve;
    
public:
    UAstroPackagingAction();
};

