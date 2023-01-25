#include "AstroApplyTransformTask.h"

class UAstroAction;
class UAstroApplyTransformTask;
class UCurveFloat;
class UCurveVector;
class USceneComponent;

void UAstroApplyTransformTask::SetTargetRelativeTransform(const FTransform& TargetRelativeTransform, UCurveFloat* relativeTransformProgressCurve) {
}

UAstroApplyTransformTask* UAstroApplyTransformTask::CreateAstroApplyTransformTask(UAstroAction* OwningAction, FName TaskInstanceName, USceneComponent* SceneComponent, float Duration, UCurveVector* LocationCurve, UCurveVector* RotationCurve, UCurveVector* ScaleCurve) {
    return NULL;
}

UAstroApplyTransformTask::UAstroApplyTransformTask() : UGameplayTask(FObjectInitializer()) {
}

