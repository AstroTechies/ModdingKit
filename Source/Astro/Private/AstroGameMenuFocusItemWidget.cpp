#include "AstroGameMenuFocusItemWidget.h"

void UAstroGameMenuFocusItemWidget::SetInteractionBlocked_Implementation(bool NewIsInteractionBlocked) {
}

bool UAstroGameMenuFocusItemWidget::IsInteractionBlocked() {
    return false;
}

FVector2D UAstroGameMenuFocusItemWidget::GetMenuFocusWidgetSize_Implementation() {
    return FVector2D{};
}

bool UAstroGameMenuFocusItemWidget::GetIsBeingDragged() const {
    return false;
}

bool UAstroGameMenuFocusItemWidget::GetIsBeingDiscretelyEdited() const {
    return false;
}

void UAstroGameMenuFocusItemWidget::ForceCommitDiscreteEditing() {
}

bool UAstroGameMenuFocusItemWidget::AttemptToCommitDiscreteEdit() {
    return false;
}

UAstroGameMenuFocusItemWidget::UAstroGameMenuFocusItemWidget() {
    this->FocusBGImageOverlaySlot = NULL;
    this->FocusBGImage = NULL;
    this->DragEditStartDeadzone = 5.00f;
    this->bBlockFocusAudio = false;
    this->bBlockUseAudio = false;
    this->bDiscreteEditCannotBeCommittedWithButtonInput = false;
    this->bIsFocused = false;
    this->bIsLastUsed = false;
    this->bEditTimeForceNotInteractive = false;
    this->bCanBeCancelled = true;
}

