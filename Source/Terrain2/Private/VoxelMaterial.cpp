#include "VoxelMaterial.h"

FVoxelMaterial::FVoxelMaterial() {
    this->SurfaceType = SurfaceType_Default;
    this->HardnessLevel = 0;
    this->CustomMaterial = NULL;
    this->MaterialInstance = NULL;
}

