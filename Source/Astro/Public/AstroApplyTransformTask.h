#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTask.h"
#include "TransformCompletedDelegate.h"
#include "AstroApplyTransformTask.generated.h"

class UAstroAction;
class UAstroApplyTransformTask;
class UCurveFloat;
class UCurveVector;
class USceneComponent;

UCLASS(Blueprintable)
class ASTRO_API UAstroApplyTransformTask : public UGameplayTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransformCompleted OnTransformCompleted;
    
    UAstroApplyTransformTask();

    UFUNCTION(BlueprintCallable)
    void SetTargetRelativeTransform(const FTransform& TargetRelativeTransform, UCurveFloat* relativeTransformProgressCurve);
    
    UFUNCTION(BlueprintCallable)
    static UAstroApplyTransformTask* CreateAstroApplyTransformTask(UAstroAction* OwningAction, FName TaskInstanceName, USceneComponent* SceneComponent, float Duration, UCurveVector* LocationCurve, UCurveVector* RotationCurve, UCurveVector* ScaleCurve);
    
};

