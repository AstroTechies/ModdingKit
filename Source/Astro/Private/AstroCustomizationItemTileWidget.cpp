#include "AstroCustomizationItemTileWidget.h"

UAstroCustomizationItemTileWidget::UAstroCustomizationItemTileWidget() {
    this->customizationItem = NULL;
    this->bIsLocked = false;
    this->bIsNew = false;
    this->DesiredGridIndex = 0;
    this->TileBackgroundTexture = NULL;
    this->TileMiddlegroundTexture = NULL;
    this->TileForegroundTexture = NULL;
}

void UAstroCustomizationItemTileWidget::SetTexturesDeferred() {
}


