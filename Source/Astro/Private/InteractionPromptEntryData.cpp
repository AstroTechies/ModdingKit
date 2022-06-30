#include "InteractionPromptEntryData.h"

FInteractionPromptEntryData::FInteractionPromptEntryData() {
    this->AxisScale = 0.00f;
    this->IsAxisInput = false;
    this->InteractionType = EInputKeyInteractionType::Hold;
    this->HoldAnimationProgress = 0.00f;
}

