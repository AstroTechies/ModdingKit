#include "RandomDistributionProperties.h"

FRandomDistributionProperties::FRandomDistributionProperties() {
    this->VarianceLevel = 0;
    this->Radius = 0.00f;
    this->SurfaceType = EPlacementType::Ground;
    this->SurfaceOffset = 0.00f;
    this->OrientationMode = EPlacementOrientation::AlignToSurfaceNormal;
    this->RandomPitch = 0.00f;
    this->RandomYaw = 0.00f;
    this->UniformScale = false;
    this->MaxAlignmentThresholdDegrees = 0.00f;
    this->MinAlignmentThresholdDegrees = 0.00f;
    this->MaxProjectionDistance = 0.00f;
    this->DensityThreshold = 0.00f;
}

