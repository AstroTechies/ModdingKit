#include "ResourceExtractorState.h"

FResourceExtractorState::FResourceExtractorState() {
    this->CacheIndex = 0;
    this->ProcessingIndex = 0;
    this->AnimProgress = 0.00f;
    this->AnimStage = EExtractorAnimStage::Holding;
    this->LegStage = EExtractorLegStage::Extended;
    this->ActiveGroupID = 0;
    this->CycleProgress = 0.00f;
    this->CycleProgressAtHammerLift = 0.00f;
}

