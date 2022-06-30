#include "AstroApplyTransformTask.h"

class UAstroAction;
class UCurveFloat;
class USceneComponent;
class UCurveVector;
class UAstroApplyTransformTask;

void UAstroApplyTransformTask::SetTargetRelativeTransform(const FTransform& TargetRelativeTransform, UCurveFloat* relativeTransformProgressCurve) {
}

UAstroApplyTransformTask* UAstroApplyTransformTask::CreateAstroApplyTransformTask(UAstroAction* OwningAction, FName TaskInstanceName, USceneComponent* SceneComponent, float Duration, UCurveVector* LocationCurve, UCurveVector* RotationCurve, UCurveVector* ScaleCurve) {
    return NULL;
}

UAstroApplyTransformTask::UAstroApplyTransformTask(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

