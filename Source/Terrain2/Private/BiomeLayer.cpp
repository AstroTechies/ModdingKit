#include "BiomeLayer.h"

FBiomeLayer::FBiomeLayer() {
    this->VoxelFunction = NULL;
    this->VoxelFunctionOptimized = NULL;
    this->SharedBoundedModifierList = NULL;
    this->UpperMarginZone = 0.00f;
    this->LowerMarginZone = 0.00f;
    this->UpperTransitionZone = 0.00f;
    this->LowerTransitionZone = 0.00f;
}

