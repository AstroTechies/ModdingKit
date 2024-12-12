#include "AstroRepackAction.h"

UAstroRepackAction::UAstroRepackAction() {
    this->bMoveRepackingItemAboveTarget = false;
    this->InterpolateToTopOfTargetDuration = 0.00f;
    this->InterpolateToTopOfTargetProgressCurve = NULL;
    this->ItemToRepackage = NULL;
    this->Repackager = NULL;
    this->ItemToRepackageType = NULL;
    this->ReclaimableRewardOwnerPlayerIDHash = 0;
    this->IndicatorComponent = NULL;
    this->PackageTypeToSpawn = NULL;
    this->PackagedItemType = NULL;
}

void UAstroRepackAction::OnInterpolationToTopOfTargetFinished() {
}


