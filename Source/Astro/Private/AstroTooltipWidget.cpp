#include "AstroTooltipWidget.h"







bool UAstroTooltipWidget::HasValidInteractionPromptInArray(const TArray<FInteractionPromptEntryData>& InteractionPromptData) {
    return false;
}

bool UAstroTooltipWidget::HasBadge() const {
    return false;
}

UAstroTooltipWidget::UAstroTooltipWidget() {
    this->ExpandBadgeTime = 0.35f;
    this->CollapseBadgeTime = 0.25f;
    this->ExpandDetailsTime = 0.40f;
    this->CollapseDetailsTime = 0.30f;
    this->CurrentState = ETooltipState::Collapsed;
    this->CurrentAnimation = ETooltipAnimation::None;
    this->AnimationProgressRatio = 0.00f;
    this->bUseInteractionVisiblityOverriden = false;
}

