#include "ResearchReplicationData.h"

FResearchReplicationData::FResearchReplicationData() {
    this->ResearchState = EResearchState::WaitingForSubjects;
    this->CurrentPowerLevelRatio = 0.00f;
    this->CurrentResearchRateMultiplier = 0.00f;
    this->CurrentResearchPointsPerMinute = 0.00f;
}

