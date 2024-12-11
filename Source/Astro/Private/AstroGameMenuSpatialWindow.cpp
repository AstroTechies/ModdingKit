#include "AstroGameMenuSpatialWindow.h"

UAstroGameMenuSpatialWindow::UAstroGameMenuSpatialWindow() {
}

FVector2D UAstroGameMenuSpatialWindow::GetUnboundedDimensionOfSubPane_Implementation() {
    return FVector2D{};
}

float UAstroGameMenuSpatialWindow::GetTotalHeightOfSubPaneFocusItemWidgets() const {
    return 0.0f;
}

float UAstroGameMenuSpatialWindow::GetMaxWidthOfSubPaneFocusItemWidgets() const {
    return 0.0f;
}

FVector2D UAstroGameMenuSpatialWindow::GetLocalPositionOfFocusItemWidget(UAstroGameMenuFocusItemWidget* FocusItemWidget) const {
    return FVector2D{};
}


