#include "OutputOrganizationRule.h"
#include "EIndicatorTooltipType.h"

UOutputOrganizationRule::UOutputOrganizationRule() {
    this->IndicatorType = EIndicatorTooltipType::CraftingOutputPreview;
    this->bPushUnwantedItems = false;
}


