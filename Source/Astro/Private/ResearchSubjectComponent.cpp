#include "ResearchSubjectComponent.h"

FResearchSubjectComponent::FResearchSubjectComponent() {
    this->CurrentResearchPhaseIndex = 0;
    this->CurrentResearchPhaseSecondsElapsed = 0.00f;
    this->ResearchStartTimestamp = 0.00f;
    this->ExpirationTimestamp = 0.00f;
}

