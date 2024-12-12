#include "AstroPackagingAction.h"

UAstroPackagingAction::UAstroPackagingAction() {
    this->RequiredResources = 3;
    this->LocationCurve = NULL;
    this->RotationCurve = NULL;
    this->ScaleCurve = NULL;
    this->ItemTargetInterpolationProgressCurve = NULL;
}


