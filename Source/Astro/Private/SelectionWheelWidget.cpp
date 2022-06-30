#include "SelectionWheelWidget.h"

class APlayController;


void USelectionWheelWidget::SetCurrentSelection(int32 Selection) {
}

bool USelectionWheelWidget::SelectionOptionTypeIsValid(APlayController* Controller, EAstroSelectionWheelOptionType OptionType) {
    return false;
}

void USelectionWheelWidget::InitializeOptionWidget(int32 OptionIndex) {
}

void USelectionWheelWidget::HandleSelectionMade(int32 SelectionIndex) {
}

USelectionWheelWidget::USelectionWheelWidget() {
    this->OptionWidgetClass = NULL;
    this->CurrentSelection = 0;
}

