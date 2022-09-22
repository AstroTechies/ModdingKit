#include "AstroApplyTransformTask.h"

class UAstroApplyTransformTask;
class UCurveVector;
class USceneComponent;
class UCurveFloat;
class UAstroAction;

void UAstroApplyTransformTask::SetTargetRelativeTransform(const FTransform& TargetRelativeTransform, UCurveFloat* relativeTransformProgressCurve) {
}

UAstroApplyTransformTask* UAstroApplyTransformTask::CreateAstroApplyTransformTask(UAstroAction* OwningAction, FName TaskInstanceName, USceneComponent* SceneComponent, float Duration, UCurveVector* LocationCurve, UCurveVector* RotationCurve, UCurveVector* ScaleCurve) {
    return NULL;
}

UAstroApplyTransformTask::UAstroApplyTransformTask() : UGameplayTask(FObjectInitializer()) {
}

