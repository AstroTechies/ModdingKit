#include "AstroGameMenuTabBarButtonWidget.h"

UAstroGameMenuTabBarButtonWidget::UAstroGameMenuTabBarButtonWidget() {
    this->IsAutoUsedWhenTabNavigatedTo = true;
    this->SubPaneLeftClass = NULL;
    this->SubPaneRightClass = NULL;
    this->TabBarSelectionIndex = 0;
}

bool UAstroGameMenuTabBarButtonWidget::GetShouldHideTab_Implementation() {
    return false;
}


