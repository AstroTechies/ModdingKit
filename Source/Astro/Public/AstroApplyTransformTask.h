#pragma once
#include "CoreMinimal.h"
#include "GameplayTask.h"
#include "TransformCompletedDelegate.h"
#include "UObject/NoExportTypes.h"
#include "AstroApplyTransformTask.generated.h"

class USceneComponent;
class UAstroAction;
class UCurveFloat;
class UAstroApplyTransformTask;
class UCurveVector;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroApplyTransformTask : public UGameplayTask
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FTransformCompleted OnTransformCompleted;

    UAstroApplyTransformTask(const FObjectInitializer &ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetTargetRelativeTransform(const FTransform &TargetRelativeTransform, UCurveFloat *relativeTransformProgressCurve);

    UFUNCTION(BlueprintCallable)
    static UAstroApplyTransformTask *CreateAstroApplyTransformTask(UAstroAction *OwningAction, FName TaskInstanceName, USceneComponent *SceneComponent, float Duration, UCurveVector *LocationCurve, UCurveVector *RotationCurve, UCurveVector *ScaleCurve);
};
