#include "AstroApplyTransformTask.h"

UAstroApplyTransformTask::UAstroApplyTransformTask() : UGameplayTask(FObjectInitializer()) {
}

void UAstroApplyTransformTask::SetTargetRelativeTransform(const FTransform& TargetRelativeTransform, UCurveFloat* relativeTransformProgressCurve) {
}

UAstroApplyTransformTask* UAstroApplyTransformTask::CreateAstroApplyTransformTask(UAstroAction* OwningAction, FName TaskInstanceName, USceneComponent* SceneComponent, float Duration, UCurveVector* LocationCurve, UCurveVector* RotationCurve, UCurveVector* ScaleCurve) {
    return NULL;
}


