#pragma once
#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "UObject/NoExportTypes.h"
#include "AstroInterpolateItemTask.generated.h"

class UAstroInterpolateItemTask;
class UAstroAction;
class APhysicalItem;
class UCurveFloat;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroInterpolateItemTask : public UGameplayTask
{
    GENERATED_BODY()
public:
    UAstroInterpolateItemTask(const FObjectInitializer &ObjectInitializer);
    UFUNCTION()
    void OnTargetItemMotionStateChanged();

    UFUNCTION(BlueprintCallable)
    static UAstroInterpolateItemTask *CreateAstroInterpolateItemTask(UAstroAction *OwningAction, FName TaskInstanceName, APhysicalItem *ItemToInterpolate, FTransform TargetTransform, float InterpolationDuration, bool bMaintainAttachmentDuringMovement, UCurveFloat *OptionalInterpolationProgressCurve);
};
