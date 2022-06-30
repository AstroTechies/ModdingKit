#include "AstroGameMenuFocusItemContainerWidget.h"

class UAstroGameMenuFocusItemWidget;

void UAstroGameMenuFocusItemContainerWidget::RemoveMouseFocusSuppression(EMouseFocusChangeSuppressionSource MouseSuppression) {
}


bool UAstroGameMenuFocusItemContainerWidget::IsMouseFocusSuppressed() const {
    return false;
}

void UAstroGameMenuFocusItemContainerWidget::HandleLastUsedItemChanged(bool IsLastUsedItem, UAstroGameMenuFocusItemWidget* LastUsedWidget) {
}

void UAstroGameMenuFocusItemContainerWidget::HandleFocusedItemChanged(bool IsFocused, UAstroGameMenuFocusItemWidget* FocusedWidget, EFocusItemFocusChangeCause FocusChangeCause) {
}

UAstroGameMenuFocusItemWidget* UAstroGameMenuFocusItemContainerWidget::GetCurrentFocusItem() const {
    return NULL;
}

FEventReply UAstroGameMenuFocusItemContainerWidget::AttemptToUseFocusedItemViaMouse() {
    return FEventReply{};
}

FEventReply UAstroGameMenuFocusItemContainerWidget::AttemptToToggleEditFocusedItem() {
    return FEventReply{};
}

FEventReply UAstroGameMenuFocusItemContainerWidget::AttemptToStartDragEditFocusedItem(const FVector2D& MousePos) {
    return FEventReply{};
}

FEventReply UAstroGameMenuFocusItemContainerWidget::AttemptToIncrementCurrentlyEditedItem() {
    return FEventReply{};
}

FEventReply UAstroGameMenuFocusItemContainerWidget::AttemptToDecrementCurrentlyEditedItem() {
    return FEventReply{};
}

FEventReply UAstroGameMenuFocusItemContainerWidget::AttemptToCancelDragOrEditFocusItem() {
    return FEventReply{};
}

void UAstroGameMenuFocusItemContainerWidget::AddMouseFocusSuppression(EMouseFocusChangeSuppressionSource MouseSuppression) {
}

UAstroGameMenuFocusItemContainerWidget::UAstroGameMenuFocusItemContainerWidget() {
    this->CurrentlyFocusedItem = NULL;
    this->LastUsedItem = NULL;
}

