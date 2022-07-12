#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "GameplayTask.h"
#include "TransformCompletedDelegate.h"
#include "AstroApplyTransformTask.generated.h"

class USceneComponent;
class UCurveFloat;
class UAstroApplyTransformTask;
class UCurveVector;
class UAstroAction;

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

