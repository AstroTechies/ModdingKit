#include "AstroMissionObjectiveProgress.h"

FAstroMissionObjectiveProgress::FAstroMissionObjectiveProgress() {
    this->Goal = 0.00f;
    this->StartingValue = 0.00f;
    this->Progress = 0.00f;
    this->LastNotifiedProgressValue = 0.00f;
    this->ProgressNotifyThreshold = 0.00f;
    this->NavpointGroup = ENavpointGroup::None;
    this->Planet = EPlanetIdentifier::None;
    this->ObjectiveType = EAstroMissionObjectiveType::HarvestResource;
    this->bIsOverrideObjective = false;
    this->bIsOptional = false;
    this->bIsPlanetExclude = false;
    this->bIsHiddenObjective = false;
    this->ProgressType = EAstroMissionObjectiveProgressType::Increment;
}

