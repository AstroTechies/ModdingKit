#include "AstroInterpolateItemTask.h"

class APhysicalItem;
class UAstroAction;
class UAstroInterpolateItemTask;
class UCurveFloat;

void UAstroInterpolateItemTask::OnTargetItemMotionStateChanged() {
}

UAstroInterpolateItemTask* UAstroInterpolateItemTask::CreateAstroInterpolateItemTask(UAstroAction* OwningAction, FName TaskInstanceName, APhysicalItem* ItemToInterpolate, FTransform TargetTransform, float InterpolationDuration, bool bMaintainAttachmentDuringMovement, UCurveFloat* OptionalInterpolationProgressCurve) {
    return NULL;
}

UAstroInterpolateItemTask::UAstroInterpolateItemTask() : UGameplayTask(FObjectInitializer()) {
}

