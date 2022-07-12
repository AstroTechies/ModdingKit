#include "AstroMissionObjective.h"

FAstroMissionObjective::FAstroMissionObjective() {
    this->TargetTypeList = NULL;
    this->SecondaryTargetTypeList = NULL;
    this->Value = 0.00f;
    this->StartingValue = 0.00f;
    this->ProgressNotifyThreshold = 0.00f;
    this->NavpointGroup = ENavpointGroup::None;
    this->Planet = EPlanetIdentifier::None;
    this->ObjectiveType = EAstroMissionObjectiveType::HarvestResource;
    this->bIsOverrideObjective = false;
    this->bIsOptional = false;
    this->bIsHiddenObjective = false;
    this->bIsPlanetExclude = false;
    this->ProgressType = EAstroMissionObjectiveProgressType::Increment;
}

