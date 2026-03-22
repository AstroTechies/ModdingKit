#include "TooltipWidgetOverride.h"

FTooltipWidgetOverride::FTooltipWidgetOverride() {
    this->VisibilityControlOverride = ETooltipVisibilityControl::ShowOnFocus;
    this->bApplyAnchorReferenceComponentOverride = false;
    this->bApplyScreenOffsetOverride = false;
    this->bRemainsVisibleWhenHeldOverride = false;
    this->bSuppressOtherTooltipsWhenExpandedOverride = false;
    this->bOverrideUseAndExaminePrompts = false;
}

