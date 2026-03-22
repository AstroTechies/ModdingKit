#include "ThresholdAchievementDefinition.h"

FThresholdAchievementDefinition::FThresholdAchievementDefinition() {
    this->AchievementKey = EAstroAchievementKeys::TutorialDone;
    this->bUseNamedThresholds = false;
    this->Threshold = 0.00f;
}

