#include "AstroSlateFocusWidgetContainer.h"

class UAstroSlateFocusWidget;

void UAstroSlateFocusWidgetContainer::RestoreLastFocus() {
}

void UAstroSlateFocusWidgetContainer::ChildWidgetFocusHighlightChanged(UAstroSlateFocusWidget* FocusWidget) {
}

UAstroSlateFocusWidgetContainer::UAstroSlateFocusWidgetContainer() {
    this->ChildWidgetWithFocusHighlight = NULL;
}

