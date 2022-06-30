#include "AstroGameMenuScrollBarBase.h"

class UAstroGameMenuFocusItemWidget;
class UAstroGameMenuSubPaneWidget;

void UAstroGameMenuScrollBarBase::SetScrollBarHandlePositionNormalized(float NormalizedPosition) {
}

void UAstroGameMenuScrollBarBase::SetScrollBarHandlePosition(float Position) {
}

bool UAstroGameMenuScrollBarBase::IsScrollBarActive() const {
    return false;
}

void UAstroGameMenuScrollBarBase::HandleTargetFocusItemChanged(UAstroGameMenuFocusItemWidget* FocusItem, EFocusItemFocusChangeCause FocusChangeCause) {
}


float UAstroGameMenuScrollBarBase::GetScrollBarHandlePositionNormalized() const {
    return 0.0f;
}

float UAstroGameMenuScrollBarBase::GetScrollBarHandlePosition() const {
    return 0.0f;
}

void UAstroGameMenuScrollBarBase::DeactivateScrollBar() {
}

void UAstroGameMenuScrollBarBase::AddScrollDelta(float ScrollDelta) {
}

void UAstroGameMenuScrollBarBase::ActivateScrollBar(float NewViewableHeightOfScrollTargetContainer, float VerticalPaddingOfScrollTargetContainer, UAstroGameMenuSubPaneWidget* NewScrollBarTarget) {
}

UAstroGameMenuScrollBarBase::UAstroGameMenuScrollBarBase() {
    this->ScrollBarTarget = NULL;
    this->ScrollBarHandleWidget = NULL;
    this->ScrollBarBGWidget = NULL;
}

