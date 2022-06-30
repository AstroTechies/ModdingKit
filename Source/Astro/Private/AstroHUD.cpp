#include "AstroHUD.h"

class UAstropediaCarouselWidget;

bool AAstroHUD::IsStoreActive() {
    return false;
}

void AAstroHUD::HandlePlayerDeathBegins() {
}

void AAstroHUD::HandleOnCreativeShowCreativeDroneUIChanged(bool ShowUI) {
}

void AAstroHUD::DestroyStoreWidget() {
}

void AAstroHUD::CreateStoreWidget() {
}

bool AAstroHUD::CreateReconnectWidget() {
    return false;
}

UAstropediaCarouselWidget* AAstroHUD::CreateAstropediaWidget(EAstroGameMenuTutorialSlideDeckKey slideDeck, EAstroGameMenuTutoriaSlideCardKey slideCard) {
    return NULL;
}

AAstroHUD::AAstroHUD() {
    this->PlayWidget = NULL;
    this->CreativeDroneOverlayClass = NULL;
    this->AstropediaWidgetClass = NULL;
    this->ReconnectWidgetClass = NULL;
    this->EmoteWheelWidgetClass = NULL;
    this->ActionWheelWidgetClass = NULL;
    this->PlayWidgetInstance = NULL;
    this->CreativeDroneOverlayInstance = NULL;
    this->ReconnectWidgetInstance = NULL;
    this->MOTDBackgroundTexture = NULL;
}

