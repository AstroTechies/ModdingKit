#include "AstroTakePictureEmoteAction.h"

UAstroTakePictureEmoteAction::UAstroTakePictureEmoteAction() {
    this->RequiredResources = 5;
    this->PhotoWidgetType = NULL;
    this->DisplayPhotoWidgetForPlayersWithinDistance = 5000.00f;
    this->bPhotoWidgetForInstigatorOnly = false;
}

void UAstroTakePictureEmoteAction::OnTakePictureTaskCompleted() {
}


