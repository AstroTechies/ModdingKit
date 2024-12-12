#include "AstroInterpolateItemTask.h"

UAstroInterpolateItemTask::UAstroInterpolateItemTask() : UGameplayTask(FObjectInitializer()) {
}

void UAstroInterpolateItemTask::OnTargetItemMotionStateChanged() {
}

UAstroInterpolateItemTask* UAstroInterpolateItemTask::CreateAstroInterpolateItemTask(UAstroAction* OwningAction, FName TaskInstanceName, APhysicalItem* ItemToInterpolate, FTransform TargetTransform, float InterpolationDuration, bool bMaintainAttachmentDuringMovement, UCurveFloat* OptionalInterpolationProgressCurve) {
    return NULL;
}


