#include "TooltipProximityBadgeVisibilityData.h"

FTooltipProximityBadgeVisibilityData::FTooltipProximityBadgeVisibilityData() {
    this->BadgeProximityRadius = 0.00f;
    this->DetailsProximityRadius = 0.00f;
    this->bHasSecondaryLongDistanceBadge = false;
    this->bSecondaryLongDistanceBadgeAlwaysVisible = false;
    this->SecondaryLongDistanceBadgeProximityRadius = 0.00f;
    this->ResourceObjectSecondaryLongDistanceBadge = NULL;
    this->ResourceObjectSecondaryLongDistanceBadgeBackground = NULL;
}

