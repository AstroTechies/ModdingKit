#include "AstroTakePictureEmoteAction.h"

void UAstroTakePictureEmoteAction::OnTakePictureTaskCompleted() {
}

UAstroTakePictureEmoteAction::UAstroTakePictureEmoteAction() {
    this->PhotoWidgetType = NULL;
    this->DisplayPhotoWidgetForPlayersWithinDistance = 5000.00f;
    this->bPhotoWidgetForInstigatorOnly = false;
}

