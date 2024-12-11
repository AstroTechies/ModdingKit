#include "AstroCustomizationTileGridWidget.h"

UAstroCustomizationTileGridWidget::UAstroCustomizationTileGridWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->LoadedAssetCount = 0;
    this->CustomizationTileWidgetClass = NULL;
    this->OutfitTileWidgetClass = NULL;
}

void UAstroCustomizationTileGridWidget::ReturnOutfitTile(UAstroOutfitTileWidget* TileWidget) {
}

void UAstroCustomizationTileGridWidget::ReturnCustomizationTile(UAstroCustomizationTileWidget* TileWidget) {
}

UAstroOutfitTileWidget* UAstroCustomizationTileGridWidget::RequestOutfitTile() {
    return NULL;
}

UAstroCustomizationTileWidget* UAstroCustomizationTileGridWidget::RequestCustomizationTile() {
    return NULL;
}

void UAstroCustomizationTileGridWidget::AsyncLoadCustomizationAssetType(ECharacterCustomizationType customizationType) {
}

void UAstroCustomizationTileGridWidget::AssetLoadedCallback(ECharacterCustomizationType customizationType, int32 Index) {
}

void UAstroCustomizationTileGridWidget::AddCustomizationTileAtDesiredIndex(UWrapBox* WrapBoxContainer, UAstroCustomizationItemTileWidget* Tile) {
}


