#include "AstroGameMenuWidget.h"

UAstroGameMenuWidget::UAstroGameMenuWidget() {
    this->ScrollBarSpacer = NULL;
    this->ScrollBarWidget = NULL;
    this->ActiveSubPaneWidget = NULL;
    this->ActiveTabBarWidget = NULL;
    this->ActivePopoutWidget = NULL;
    this->MinimumMenuWidth = 500.00f;
    this->ScrollDelta = 20.00f;
    this->ScrollBarContainerWidget = NULL;
    this->PopoutConnectorWidget = NULL;
}




void UAstroGameMenuWidget::RequestNavigation(EGameMenuNavigationCommand NavCommand) {
}

void UAstroGameMenuWidget::ReCalculateMenuSize() {
}


void UAstroGameMenuWidget::LockControls(bool bLockControls) {
}


void UAstroGameMenuWidget::HandleDebugMenuVisbilityChanged(bool IsVisible) {
}


















