#include "AstroTakePictureAction.h"

UAstroTakePictureAction::UAstroTakePictureAction() {
    this->RequiredResources = 4;
    this->PhotoWidgetType = NULL;
    this->PictureImageCaptureDelay = 0.00f;
    this->PhotoWidgetDisplayDelay = 0.00f;
    this->bPhotoWidgetForInstigatorOnly = false;
    this->DisplayPhotoWidgetForPlayersWithinDistance = 5000.00f;
}

void UAstroTakePictureAction::SetInstigator(APlayerController* Instigator) {
}

void UAstroTakePictureAction::OnTakePictureTaskCompleted() {
}

void UAstroTakePictureAction::OnPictureImageCaptureDelayComplete() {
}

void UAstroTakePictureAction::OnPhotoWidgetDisplayDelayComplete() {
}

void UAstroTakePictureAction::BroadcastTakePictureCountdownPing() {
}


