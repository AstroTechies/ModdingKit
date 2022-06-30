#include "AstroInterpolateItemTask.h"

class UAstroAction;
class APhysicalItem;
class UCurveFloat;
class UAstroInterpolateItemTask;

void UAstroInterpolateItemTask::OnTargetItemMotionStateChanged() {
}

UAstroInterpolateItemTask* UAstroInterpolateItemTask::CreateAstroInterpolateItemTask(UAstroAction* OwningAction, FName TaskInstanceName, APhysicalItem* ItemToInterpolate, FTransform TargetTransform, float InterpolationDuration, bool bMaintainAttachmentDuringMovement, UCurveFloat* OptionalInterpolationProgressCurve) {
    return NULL;
}

UAstroInterpolateItemTask::UAstroInterpolateItemTask(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

