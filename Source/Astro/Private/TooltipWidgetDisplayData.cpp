#include "TooltipWidgetDisplayData.h"

FTooltipWidgetDisplayData::FTooltipWidgetDisplayData() {
    this->ResourceObjectBadge = NULL;
    this->ResourceObjectBadgeBackground = NULL;
    this->PresentationStyle = ETooltipPresentationStyleTypes::StandardTooltip;
    this->AnimationDirection = ETooltipAnimationDirection::LeftToRight;
    this->OpenAstropediaDeck = EAstroGameMenuTutorialSlideDeckKey::Invalid;
    this->OpenAstropediaCard = EAstroGameMenuTutoriaSlideCardKey::Invalid;
}

