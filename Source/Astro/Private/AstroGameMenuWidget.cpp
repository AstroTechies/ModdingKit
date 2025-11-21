#include "AstroGameMenuWidget.h"

UAstroGameMenuWidget::UAstroGameMenuWidget() {
    this->ScrollBarSpacerLeft = NULL;
    this->ScrollBarSpacerRight = NULL;
    this->ScrollBarWidgetLeft = NULL;
    this->ScrollBarWidgetRight = NULL;
    this->ActiveSubPaneWidget = NULL;
    this->SubPaneWidgetLeft = NULL;
    this->SubPaneWidgetRight = NULL;
    this->ActiveTabBarWidget = NULL;
    this->TabBarWidgetLeft = NULL;
    this->TabBarWidgetRight = NULL;
    this->ActivePopoutWidget = NULL;
    this->ActivePopoutWidgetAnchorPanel = NULL;
    this->MinimumMenuWidthLeft = 500.00f;
    this->MinimumMenuWidthRight = 500.00f;
    this->ScrollDelta = 20.00f;
    this->ScrollBarContainerWidgetLeft = NULL;
    this->ScrollBarContainerWidgetRight = NULL;
    this->PopoutConnectorWidget = NULL;
}


void UAstroGameMenuWidget::ShowWarningsMenuPane() {
}

void UAstroGameMenuWidget::ShowMarketingMenuPane() {
}

void UAstroGameMenuWidget::ShowGameMenuWarningWidget(EGameMenuWarningWidgetTypes warningType) {
}


void UAstroGameMenuWidget::SetSubpaneHoverTarget(ESubpaneIdentifier hoverTarget) {
}

void UAstroGameMenuWidget::SetSaveErrorText(FText saveErrorText) {
}

void UAstroGameMenuWidget::SetRightPanelHidden(bool isHidden) {
}

void UAstroGameMenuWidget::SetCurrentPlayfabFailureReason(FAstroCGMPlayfabFailureReason failureReason) {
}

void UAstroGameMenuWidget::RequestNavigation(EGameMenuNavigationCommand NavCommand) {
}

void UAstroGameMenuWidget::ReCalculateMenuSize() {
}


void UAstroGameMenuWidget::LockControls(bool bLockControls) {
}

void UAstroGameMenuWidget::HideGameMenuWarningWidget(EGameMenuWarningWidgetTypes warningType) {
}


void UAstroGameMenuWidget::HandleDebugMenuVisbilityChanged(bool IsVisible) {
}








ESubpaneIdentifier UAstroGameMenuWidget::GetSubpaneHoverTarget() const {
    return ESubpaneIdentifier::Left;
}













bool UAstroGameMenuWidget::GetIsRightPanelHidden() const {
    return false;
}


FVector2D UAstroGameMenuWidget::GetCachedBoundedSizeOfMenuPanelRight() const {
    return FVector2D{};
}

FVector2D UAstroGameMenuWidget::GetCachedBoundedSizeOfMenuPanelLeft() const {
    return FVector2D{};
}



bool UAstroGameMenuWidget::GetAnyGameMenuWarningVisible() {
    return false;
}



