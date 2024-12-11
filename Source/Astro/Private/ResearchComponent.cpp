#include "ResearchComponent.h"

FResearchComponent::FResearchComponent() {
    this->bWantsToResearch = false;
    this->bIsResearching = false;
    this->CurrentPowerLevelRatio = 0.00f;
    this->CurrentResearchRateMultiplier = 0.00f;
    this->CurrentResearchPointsPerMinute = 0.00f;
}

