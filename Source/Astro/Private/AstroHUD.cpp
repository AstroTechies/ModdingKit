#include "AstroHUD.h"

AAstroHUD::AAstroHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DebugDisplay.AddDefaulted(1);
    this->PlayWidget = NULL;
    this->CreativeDroneOverlayClass = NULL;
//    this->StoreWidgetClass = NULL;
    this->AstropediaWidgetClass = NULL;
    this->ReconnectWidgetClass = NULL;
    this->EmoteWheelWidgetClass = NULL;
    this->ActionWheelWidgetClass = NULL;
//    this->StoreWidgetInstance = NULL;
    this->StoreIsLoading = false;
    this->PlayWidgetInstance = NULL;
    this->CreativeDroneOverlayInstance = NULL;
    this->ReconnectWidgetInstance = NULL;
    this->MOTDBackgroundTexture = NULL;
    this->FullscreenMOTDBackgroundTexture = NULL;
}

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


