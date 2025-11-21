#include "MuseumState.h"

FMuseumState::FMuseumState() {
    this->PowerConsumption = 0;
    this->ByteConsumption = 0;
    this->TotalBytesSunk = 0;
    this->TotalSeedSinkScore = 0;
    this->TotalResourceSinkScore = 0;
    this->NextResourceMilestoneIndex = 0;
    this->NextSeedMilestoneIndex = 0;
    this->NextByteMilestoneIndex = 0;
    this->NextPowerMilestoneIndex = 0;
    this->bIsResourceMilestoneComplete = false;
    this->bIsSeedMilestoneComplete = false;
    this->bIsByteMilestoneComplete = false;
    this->bIsPowerMilestoneComplete = false;
    this->bAreAllMilestonesComplete = false;
    this->TotalPowerSunk = 0.00f;
}

