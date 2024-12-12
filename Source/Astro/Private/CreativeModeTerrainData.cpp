#include "CreativeModeTerrainData.h"

FCreativeModeTerrainData::FCreativeModeTerrainData() {
    this->TerrainHardnessOverride = 0;
    this->TerrainSurfaceTypeOverride = SurfaceType_Default;
    this->PaintPalette = NULL;
    this->SpecialPaletteIndex = 0;
    this->World = NULL;
}

